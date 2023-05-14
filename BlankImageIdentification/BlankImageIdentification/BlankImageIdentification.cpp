// BlankImageIdentification.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <Windows.h>
#include <filesystem>
#include <cstdio>

namespace fs = std::filesystem;

using namespace cv;
using namespace std;

Rect box;

#ifdef _DEBUG
#define CV_TEST_BUILD_CONFIG "Debug"
#else
#define CV_TEST_BUILD_CONFIG "Release"
#endif

//int main(int argc, char* argv[])
int main()
{

    //string imagepath = "c:/users/ay00049700/downloads/problem-2";
    cout << "Enter path: ";
    string imagepath;
    getline(std::cin, imagepath);

    if (!fs::exists(imagepath))
    {
        cout << "Path does not exist" << endl;
        return 0;
    }

    vector<string> filenames;
    // Read all the .jpg images present in the folder
    glob(imagepath + "/*.jpg", filenames, false);

    //string filename = imagepath + "Image-15.jpg";
    for (const auto& filename : filenames)
    {
        //Load image and convert the image into binary image
        Mat image = imread(filename, IMREAD_GRAYSCALE);
        threshold(image, image, 127, 255, THRESH_BINARY);

        // sliding window to traverse over image
        int windows_n_rows = 60;
        int windows_n_cols = 60;
        int stepslide = 30;
        Rect windows(0, 0, windows_n_rows, windows_n_cols);
        Mat roiInitial = image(windows);

        // mean and std dev of initial ROI
        Scalar mean, stddev;
        meanStdDev(roiInitial, mean, stddev);
        auto stdDevInitial = stddev[0];
        auto stdDevWindow = 0;
        auto count = 0, total = 0;

        for (int row = 0; row < image.rows - windows_n_rows; row += stepslide)
        {
            for (int col = 0; col < image.cols - windows_n_cols; col += stepslide)
            {
                Rect windows(col, row, windows_n_rows, windows_n_cols);
                Mat roi = image(windows);

                Scalar mean, stddev;
                meanStdDev(roi, mean, stddev);
                stdDevWindow = stddev[0];
                //bool areidentical = !cv::norm(roiInitial, roi, NORM_L1);

                // compare ROI properties of 2 sub-images
                if ((stdDevInitial != stdDevWindow))
                {
                    count++;
                }
                total++;

            }
        }
        // Assign image characterization value to each image
        string file = filename.substr(filename.find_last_of("\\/") + 1, filename.size() - 1);
        if (count < 20)
        {
            cout << file << ": " << "Blank Image" << endl;
        }
        else
        {
            cout << file << ": " << "Non-Blank Image" << endl;
        }
    }

    //clear buffer, wait for input to close program
    cout << "Press enter key to exit ...";
    cin.clear(); 
    cin.ignore(INT_MAX, '\n');
    cin.get();
    return 0;
}
