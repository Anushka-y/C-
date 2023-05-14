#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <string>
#include <codecvt>
#include <locale>
#include <array>
#include <windows.h>

namespace VideoRecorder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace cv;


	/// <summary>
	/// Summary for VideoEditScreen
	/// </summary>
	public ref class VideoEditScreen : public System::Windows::Forms::Form
	{
	public:
		VideoEditScreen(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VideoEditScreen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ SelectSourceLabel;
	protected:

	public: System::Windows::Forms::ComboBox^ VideoSourceList;
	private: System::Windows::Forms::Button^ StartButton;
	private: System::Windows::Forms::Button^ StopButton;


	private: System::Windows::Forms::TrackBar^ BrightnessTrackBar;
	private: System::Windows::Forms::TrackBar^ ContrastTrackBar;

	private: System::Windows::Forms::Label^ BrightnessLabel;
	private: System::Windows::Forms::Label^ ContrastLabel;


	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Label^ VideoStreamLabel;
	private: System::Windows::Forms::Panel^ VideoStreamPanel;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker2;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SelectSourceLabel = (gcnew System::Windows::Forms::Label());
			this->VideoSourceList = (gcnew System::Windows::Forms::ComboBox());
			this->StartButton = (gcnew System::Windows::Forms::Button());
			this->StopButton = (gcnew System::Windows::Forms::Button());
			this->BrightnessTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->ContrastTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->BrightnessLabel = (gcnew System::Windows::Forms::Label());
			this->ContrastLabel = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->VideoStreamLabel = (gcnew System::Windows::Forms::Label());
			this->VideoStreamPanel = (gcnew System::Windows::Forms::Panel());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BrightnessTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ContrastTrackBar))->BeginInit();
			this->VideoStreamPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// SelectSourceLabel
			// 
			this->SelectSourceLabel->AutoSize = true;
			this->SelectSourceLabel->Location = System::Drawing::Point(12, 97);
			this->SelectSourceLabel->Name = L"SelectSourceLabel";
			this->SelectSourceLabel->Size = System::Drawing::Size(154, 20);
			this->SelectSourceLabel->TabIndex = 0;
			this->SelectSourceLabel->Text = L"Select Video Source";
			// 
			// VideoSourceList
			// 
			this->VideoSourceList->Enabled = false;
			this->VideoSourceList->FormattingEnabled = true;
			this->VideoSourceList->Location = System::Drawing::Point(14, 128);
			this->VideoSourceList->Margin = System::Windows::Forms::Padding(3, 3, 4, 3);
			this->VideoSourceList->Name = L"VideoSourceList";
			this->VideoSourceList->Size = System::Drawing::Size(202, 28);
			this->VideoSourceList->TabIndex = 1;
			this->VideoSourceList->Text = L"Select Camera";
			// 
			// StartButton
			// 
			this->StartButton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->StartButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StartButton->Location = System::Drawing::Point(32, 168);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Size = System::Drawing::Size(75, 38);
			this->StartButton->TabIndex = 2;
			this->StartButton->Text = L"Start";
			this->StartButton->UseVisualStyleBackColor = false;
			this->StartButton->Click += gcnew System::EventHandler(this, &VideoEditScreen::button1_Click);
			// 
			// StopButton
			// 
			this->StopButton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->StopButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->StopButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->StopButton->Location = System::Drawing::Point(124, 168);
			this->StopButton->Name = L"StopButton";
			this->StopButton->Size = System::Drawing::Size(75, 37);
			this->StopButton->TabIndex = 3;
			this->StopButton->Text = L"Stop";
			this->StopButton->UseCompatibleTextRendering = true;
			this->StopButton->UseVisualStyleBackColor = false;
			this->StopButton->Click += gcnew System::EventHandler(this, &VideoEditScreen::StopButton_Click);
			// 
			// BrightnessTrackBar
			// 
			this->BrightnessTrackBar->BackColor = System::Drawing::SystemColors::ControlLight;
			this->BrightnessTrackBar->Enabled = false;
			this->BrightnessTrackBar->Location = System::Drawing::Point(14, 268);
			this->BrightnessTrackBar->Maximum = 100;
			this->BrightnessTrackBar->Minimum = -100;
			this->BrightnessTrackBar->Name = L"BrightnessTrackBar";
			this->BrightnessTrackBar->Size = System::Drawing::Size(202, 69);
			this->BrightnessTrackBar->TabIndex = 4;
			this->BrightnessTrackBar->TickStyle = System::Windows::Forms::TickStyle::None;
			// 
			// ContrastTrackBar
			// 
			this->ContrastTrackBar->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ContrastTrackBar->Enabled = false;
			this->ContrastTrackBar->LargeChange = 4;
			this->ContrastTrackBar->Location = System::Drawing::Point(14, 358);
			this->ContrastTrackBar->Maximum = 100;
			this->ContrastTrackBar->Name = L"ContrastTrackBar";
			this->ContrastTrackBar->Size = System::Drawing::Size(202, 69);
			this->ContrastTrackBar->TabIndex = 0;
			this->ContrastTrackBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->ContrastTrackBar->Value = 50;
			this->ContrastTrackBar->Scroll += gcnew System::EventHandler(this, &VideoEditScreen::ContrastTrackBar_Scroll);
			// 
			// BrightnessLabel
			// 
			this->BrightnessLabel->AutoSize = true;
			this->BrightnessLabel->Location = System::Drawing::Point(12, 242);
			this->BrightnessLabel->Name = L"BrightnessLabel";
			this->BrightnessLabel->Size = System::Drawing::Size(85, 20);
			this->BrightnessLabel->TabIndex = 6;
			this->BrightnessLabel->Text = L"Brightness";
			// 
			// ContrastLabel
			// 
			this->ContrastLabel->AutoSize = true;
			this->ContrastLabel->Location = System::Drawing::Point(12, 335);
			this->ContrastLabel->Name = L"ContrastLabel";
			this->ContrastLabel->Size = System::Drawing::Size(70, 20);
			this->ContrastLabel->TabIndex = 7;
			this->ContrastLabel->Text = L"Contrast";
			// 
			// VideoStreamLabel
			// 
			this->VideoStreamLabel->AutoSize = true;
			this->VideoStreamLabel->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->VideoStreamLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->VideoStreamLabel->Location = System::Drawing::Point(308, 206);
			this->VideoStreamLabel->Name = L"VideoStreamLabel";
			this->VideoStreamLabel->Size = System::Drawing::Size(186, 32);
			this->VideoStreamLabel->TabIndex = 1;
			this->VideoStreamLabel->Text = L"Video Stream";
			this->VideoStreamLabel->Click += gcnew System::EventHandler(this, &VideoEditScreen::VideoStreamLabel_Click);
			// 
			// VideoStreamPanel
			// 
			this->VideoStreamPanel->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->VideoStreamPanel->Controls->Add(this->VideoStreamLabel);
			this->VideoStreamPanel->Location = System::Drawing::Point(237, 25);
			this->VideoStreamPanel->Name = L"VideoStreamPanel";
			this->VideoStreamPanel->Size = System::Drawing::Size(788, 457);
			this->VideoStreamPanel->TabIndex = 8;
			this->VideoStreamPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VideoEditScreen::VideoStreamPanel_Paint);
			// 
			// VideoEditScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(1084, 568);
			this->Controls->Add(this->VideoStreamPanel);
			this->Controls->Add(this->ContrastLabel);
			this->Controls->Add(this->BrightnessLabel);
			this->Controls->Add(this->ContrastTrackBar);
			this->Controls->Add(this->BrightnessTrackBar);
			this->Controls->Add(this->StopButton);
			this->Controls->Add(this->StartButton);
			this->Controls->Add(this->VideoSourceList);
			this->Controls->Add(this->SelectSourceLabel);
			this->Name = L"VideoEditScreen";
			this->Text = L"VideoEditScreen";
			this->Load += gcnew System::EventHandler(this, &VideoEditScreen::VideoEditScreen_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BrightnessTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ContrastTrackBar))->EndInit();
			this->VideoStreamPanel->ResumeLayout(false);
			this->VideoStreamPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:
		// Find number of webCams attached
		Void detectNumWebcams()
		{
			// Try opening webcams with increasing indexes until one fails to open
			int numWebcams = 0;
			while (true)
			{
				cv::VideoCapture capture(numWebcams);
				if (!capture.isOpened())
					break;

				numWebcams++;
				if (numWebcams > 0)
				{
					VideoSourceList->Enabled = true;
				}
				else
				{
					VideoSourceList->Enabled = false;
				}
				string cam = capture.getBackendName();
				System::String^ camName = gcnew System::String(cam.c_str());
				//Add webCams in dropDown list
				VideoSourceList->Items->Add(camName);
			}
		}

	private: System::Void splitContainer1_Panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void toolStripComboBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void toolStripComboBox1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// On pressing Start, Video will stream on the VideoStream Panel
	// Brightness and Contrast trackbar should enable if camera detected
	VideoStreamLabel->Visible = false;
	BrightnessTrackBar->Enabled = true;
	ContrastTrackBar->Enabled = true;
	cv::VideoCapture capture(VideoSourceList->SelectedIndex);

	// Check if the webcam is opened successfully
	if (!capture.isOpened())
	{
		std::cerr << "Failed to open the webcam!" << std::endl;
		return;
	}

	Mat frame;
	int frameCount = 0;
	while (capture.read(frame))
	{
		// Display the frame in the window
		//Contrast: Increase contrast if value > 1
		//			Decrease contrase if 0 < value < 1

		double contrast = (double)(ContrastTrackBar->Value) / 50;
		frame.convertTo(frame, -1, 1, BrightnessTrackBar->Value);
		frame.convertTo(frame, -1, contrast, 0);
		System::Drawing::Bitmap^ bitmap = gcnew System::Drawing::Bitmap(frame.cols, frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, IntPtr(frame.data));
		VideoStreamPanel->BackgroundImage = bitmap;
		// press esc key to exit cam
		if (waitKey(100) == 27)
		{
			break;
		}
	}
	capture.release();

}
private: System::Void VideoEditScreen_Load(System::Object^ sender, System::EventArgs^ e) {
	detectNumWebcams();	
}
private: System::Void VideoStreamPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

}
private: System::Void StopButton_Click(System::Object^ sender, System::EventArgs^ e) {
	// Reset value to default on Pressing Stop
	VideoStreamLabel->Visible = true;
	BrightnessTrackBar->Enabled = false;
	ContrastTrackBar->Enabled = false;
	VideoStreamPanel->BackgroundImage = nullptr;
	VideoSourceList->Text = L"Select Camera";
	BrightnessTrackBar->Value = 0;
	ContrastTrackBar->Value = 50;
	VideoCapture capture(VideoSourceList->SelectedIndex);
	capture.release();
}
private: System::Void VideoStreamLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ContrastTrackBar_Scroll(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
