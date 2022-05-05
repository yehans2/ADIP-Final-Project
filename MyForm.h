#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <msclr\marshal_cppstd.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include<opencv2\stitching.hpp>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <complex>
#include< conio.h >
#include< vector>
#include< math.h >
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <string>
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		void Read_image();
		void R_ValueChange();
		void detect_road();
		void puzzle();
		void show_bigimg();
		void k_mean1();
		void closed();
		void blur();
		void saveimg();
		void Navigation1();
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;




	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Label^ label2;




	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::TrackBar^ trackBar4;




	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::TrackBar^ trackbar_H;

	private: System::Windows::Forms::TrackBar^ trackbar_S;
	private: System::Windows::Forms::TrackBar^ trackbar_V;



	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;


	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label8;




	private: System::Windows::Forms::Button^ btn_readImg;
	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ Blur;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->trackbar_H = (gcnew System::Windows::Forms::TrackBar());
			this->trackbar_S = (gcnew System::Windows::Forms::TrackBar());
			this->trackbar_V = (gcnew System::Windows::Forms::TrackBar());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btn_readImg = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Blur = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_H))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_S))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_V))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label1->Location = System::Drawing::Point(41, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(472, 61);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ADIP Final Project";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(15, 123);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(713, 514);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label2->Location = System::Drawing::Point(247, 650);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(223, 42);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Input Image";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label3->Location = System::Drawing::Point(968, 650);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(254, 42);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Output Image";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(740, 123);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(713, 514);
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// trackBar4
			// 
			this->trackBar4->Location = System::Drawing::Point(1477, 475);
			this->trackBar4->Maximum = 15;
			this->trackBar4->Minimum = 3;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(411, 90);
			this->trackBar4->TabIndex = 1;
			this->trackBar4->Value = 3;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar4_Scroll);
			// 
			// trackbar_H
			// 
			this->trackbar_H->Location = System::Drawing::Point(1536, 268);
			this->trackbar_H->Maximum = 50;
			this->trackbar_H->Name = L"trackbar_H";
			this->trackbar_H->Size = System::Drawing::Size(352, 90);
			this->trackbar_H->TabIndex = 1;
			this->trackbar_H->Scroll += gcnew System::EventHandler(this, &MyForm::R_trackbar_scroll);
			// 
			// trackbar_S
			// 
			this->trackbar_S->Location = System::Drawing::Point(1536, 323);
			this->trackbar_S->Maximum = 50;
			this->trackbar_S->Name = L"trackbar_S";
			this->trackbar_S->Size = System::Drawing::Size(352, 90);
			this->trackbar_S->TabIndex = 1;
			this->trackbar_S->Scroll += gcnew System::EventHandler(this, &MyForm::trackbar_S_Scroll);
			// 
			// trackbar_V
			// 
			this->trackbar_V->Location = System::Drawing::Point(1536, 371);
			this->trackbar_V->Maximum = 255;
			this->trackbar_V->Minimum = 60;
			this->trackbar_V->Name = L"trackbar_V";
			this->trackbar_V->Size = System::Drawing::Size(352, 90);
			this->trackbar_V->TabIndex = 1;
			this->trackbar_V->Value = 60;
			this->trackbar_V->Scroll += gcnew System::EventHandler(this, &MyForm::trackbar_V_Scroll);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(1488, 274);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(28, 25);
			this->label5->TabIndex = 9;
			this->label5->Text = L"H";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(1488, 328);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(27, 25);
			this->label6->TabIndex = 9;
			this->label6->Text = L"S";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(1488, 379);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(27, 25);
			this->label7->TabIndex = 9;
			this->label7->Text = L"V";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(1472, 136);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(433, 31);
			this->textBox3->TabIndex = 5;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(1464, 84);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(239, 31);
			this->label8->TabIndex = 6;
			this->label8->Text = L"Puzzle input path";
			// 
			// btn_readImg
			// 
			this->btn_readImg->Location = System::Drawing::Point(1477, 652);
			this->btn_readImg->Name = L"btn_readImg";
			this->btn_readImg->Size = System::Drawing::Size(129, 73);
			this->btn_readImg->TabIndex = 10;
			this->btn_readImg->Text = L"Read Image";
			this->btn_readImg->UseVisualStyleBackColor = true;
			this->btn_readImg->Click += gcnew System::EventHandler(this, &MyForm::btn_readImg_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1776, 80);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(126, 43);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Puzzle";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(1625, 651);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(124, 74);
			this->button4->TabIndex = 12;
			this->button4->Text = L"show img";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(1732, 194);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(170, 58);
			this->button5->TabIndex = 13;
			this->button5->Text = L"k-mean";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(1487, 432);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 31);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Dilate";
			// 
			// Blur
			// 
			this->Blur->Location = System::Drawing::Point(1477, 194);
			this->Blur->Name = L"Blur";
			this->Blur->Size = System::Drawing::Size(167, 58);
			this->Blur->TabIndex = 15;
			this->Blur->Text = L"blurring";
			this->Blur->UseVisualStyleBackColor = true;
			this->Blur->Click += gcnew System::EventHandler(this, &MyForm::Blur_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1768, 650);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(129, 75);
			this->button1->TabIndex = 16;
			this->button1->Text = L"save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1477, 527);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(420, 105);
			this->button2->TabIndex = 17;
			this->button2->Text = L"Navigation";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 754);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Blur);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->btn_readImg);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->trackbar_V);
			this->Controls->Add(this->trackbar_S);
			this->Controls->Add(this->trackBar4);
			this->Controls->Add(this->trackbar_H);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_H))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_S))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_V))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btn_readImg_Click(System::Object^ sender, System::EventArgs^ e) {
	Read_image();
}

private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	puzzle();
}
private: System::Void R_trackbar_scroll(System::Object^ sender, System::EventArgs^ e) {
	R_ValueChange();
}
private: System::Void trackbar_S_Scroll(System::Object^ sender, System::EventArgs^ e) {
	R_ValueChange();
}
private: System::Void trackbar_V_Scroll(System::Object^ sender, System::EventArgs^ e) {
	R_ValueChange();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	show_bigimg();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	k_mean1();
}
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	/*if (checkBox2->Checked==1)
	{
		opening();
	}
	if (checkBox2->Checked == 0)
	{

	}*/
}
private: System::Void trackBar4_Scroll(System::Object^ sender, System::EventArgs^ e) {
	closed();
}
private: System::Void Blur_Click(System::Object^ sender, System::EventArgs^ e) {
	blur();
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	saveimg();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Navigation1();
}
};
}
