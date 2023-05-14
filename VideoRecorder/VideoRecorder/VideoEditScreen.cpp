
#include "VideoEditScreen.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;
//[STAThread]

//int detectNumWebcams()
//{
//	// Try opening webcams with increasing indexes until one fails to open
//	int numWebcams = 0;
//	while (true)
//	{
//		cv::VideoCapture capture(numWebcams);
//		if (!capture.isOpened())
//			break;
//
//		numWebcams++;
//		cout << numWebcams << endl;
//		string cam = capture.getBackendName();
//		System::String^ camName = gcnew System::String(cam.c_str());
//		editScreen.VideoSourceList->Items->Add(camName);
//	}
//	return numWebcams;
//}

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	VideoRecorder::VideoEditScreen editScreen;
	Application::Run(% editScreen);
}


