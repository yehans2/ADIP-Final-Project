#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include "MyForm.h"
#pragma comment(lib, "Gdi32.lib")

using namespace System;
using namespace System::IO;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace Project1;
using namespace std;
using namespace msclr::interop;
using namespace cv;

int left1 = 0;
int right1 = 0;
int jj1, ii2, ii1, jj2;

Mat inrange(Mat img, int H, int S, int V);
Mat imgInput, imgOutput, img_Navi;
vector<Mat> imgs;


void read_Image(int size, const char* filePath);
vector<Mat> rigntVconcat(vector<Mat>& img, int mseSize);
vector<Mat> downHconcat(vector<Mat>& img, int mseSize);
double right_MSE(Mat Matl, Mat Mat2);
double down_MSE(Mat Matl, Mat Mat2);
Mat puzzle1(const char* filepath);
Mat K_mean(Mat Img);
Mat closedImg(Mat img, int mask);

Mat Navigation_temp();
void mouseEvent_RGBvalue(int evt, int x, int y, int flags, void* param);
int findMap(int x, int y);
Mat Navigation();
void mouseRGBvalue(Mat img);

[STAThreadAttribute]

void main(/*array<String^>^ args*/) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::MyForm frm;
	Application::Run(% frm);
}

Bitmap^ MatToHbitmap(Mat inputImg) {
	Mat src;
	inputImg.copyTo(src);
	cvtColor(src, src, COLOR_BGR2BGRA);
	HBITMAP hBit = CreateBitmap(src.cols, src.rows, 1, 32, src.data);
	Bitmap^ bmp = Bitmap::FromHbitmap((IntPtr)hBit);

	return bmp;
}
void MyForm::show_bigimg()
{
	imshow("img", imgOutput);
}
void MyForm::Read_image(){
	Stream^ myStream;
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

	openFileDialog1->InitialDirectory = "c:\\";
	openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true; 

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		pictureBox1->ImageLocation = openFileDialog1->FileName;
		pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;

		if ((myStream = openFileDialog1->OpenFile()) != nullptr)
		{
			// Insert code to read the stream here.
			myStream->Close();
		}
	}

	cv::String img_path = marshal_as<std::string>(openFileDialog1->FileName);
	 imgInput = imread(img_path);
	 imgOutput = imgInput.clone();

	Bitmap^ bmp = MatToHbitmap(imgInput);
	pictureBox2->Image = bmp;
	pictureBox2->SizeMode = PictureBoxSizeMode::StretchImage; 
}
void MyForm::k_mean1()
{
	imgOutput = K_mean(imgInput);
	Bitmap^ bmp = MatToHbitmap(imgOutput);
	pictureBox2->Image = bmp;
	pictureBox2->Image = bmp;
}
void MyForm::R_ValueChange() {
	int H,S,V;
	H = trackbar_H->Value;
	S = trackbar_S->Value;
	V = trackbar_V->Value;
	imgOutput = inrange(imgInput,H,S,V);
	Mat out = imgOutput.clone();
	Bitmap^ bmp = MatToHbitmap(out);
	pictureBox2->Image = bmp;
}
Mat inrange(Mat img, int H, int S, int V)
{
	Mat img_hsv;
	Mat  dst1;
	cvtColor(img, img_hsv, COLOR_BGR2HSV);
	Scalar lower_yellow = Scalar(H, S, V);
	Scalar upper_yellow = Scalar(H + 30, 255, 255);
	inRange(img_hsv, lower_yellow, upper_yellow, dst1);
	return dst1;
}
void MyForm::puzzle()
{
	cv::String img_path = marshal_as<std::string>(textBox3->Text);
	const char* filepath = img_path.c_str();
	std::string s= img_path.c_str();
	char from = '\\';
	char to = '/';
	std::replace(s.begin(), s.end(), from, to);
	Mat p= puzzle1(s.c_str());

	imgInput = p.clone();
	imgOutput = imgInput.clone();

	Bitmap^ bmp = MatToHbitmap(p);
	pictureBox1->Image = bmp;
	pictureBox2->Image = bmp;
	pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
	pictureBox2->SizeMode = PictureBoxSizeMode::StretchImage;

}
void MyForm::detect_road()
{
	Mat hi = inrange(imgInput,10,20,130);
	Bitmap^ bmp = MatToHbitmap(hi);
	pictureBox2->Image = bmp;
	pictureBox2->Image = bmp;
}
void MyForm::closed()
{
	int mask;
	mask = trackBar4->Value;
	Mat open_result = closedImg(imgOutput, mask);
	Bitmap^ bmp = MatToHbitmap(open_result);
	pictureBox2->Image = bmp;
	pictureBox2->Image = bmp;
}
void MyForm::blur()
{
	GaussianBlur(imgInput, imgInput, cv::Size(9, 9), 0);
	Bitmap^ bmp = MatToHbitmap(imgInput);
	pictureBox2->Image = bmp;
	pictureBox2->Image = bmp;
}
Mat closedImg(Mat img,int mask)
{
	dilate(img, img, Mat::ones(cv::Size(mask, mask), CV_8UC1), cv::Point(-1, -1), 2);
	/*erode(img, img, Mat::ones(cv::Size(mask, mask), CV_8UC1), cv::Point(-1, -1), 2);*/

	return img;
}
void MyForm::saveimg()
{
	imwrite("img.jpg", imgOutput);
}
Mat puzzle1(const char* filepath)
{
	vector<Mat> rightVconcat_vector;
	vector<Mat> downHconcat_vector;
	int picAccount = 6;
	int mseSize = 70;
	read_Image(picAccount, filepath);
	rightVconcat_vector = rigntVconcat(imgs, mseSize);
	downHconcat_vector = downHconcat(rightVconcat_vector, mseSize);
	//imshow("fianl", downHconcat_vector.at(0));

	return downHconcat_vector.at(0);
}
void read_Image(int size, const char* filePath)
{
	cv::String path(filePath);
	vector<cv::String> str;
	glob(path, str, false);
	cout << "road size : " << str.size() << endl;
	if (str.size() == 0)
		cout << "Image not found.\n" << endl;
	for (int i = 0; i < str.size(); i++) {
		imgs.push_back(imread(str[i]));
	}
	for (int i = 0; i < str.size(); i++) {
		resize(imgs.at(i), imgs.at(i), cv::Size(imgs.at(0).cols, imgs.at(0).rows));
	}
}
vector<Mat> rigntVconcat(vector<Mat>& img, int mseSize) {
	double mse;
	vector<Mat> imgtemp;
	for (int i = 0; i < img.size(); i++) {
		front:
		for (int j = 0; j < img.size(); j++) {
			mse = right_MSE(img.at(i), img.at(j));
			if (mse < mseSize) {
				Mat img1;
				hconcat(img.at(i), img.at(j), img1);
				img.at(i) = img1;
				goto front;
			}
		}
	}
	cout << img.size() << endl;
	int ans = 0;
	for (int i = 0; i < img.size(); i++) {
		int lengh = img.at(i).cols;
		ans = max(ans, lengh);
	}
	for (int i = 0; i < img.size(); i++) {
		if (img.at(i).cols == ans) {
			imgtemp.push_back(img.at(i));
		}
	}
	return imgtemp;
}
vector<Mat> downHconcat(vector<Mat>& img, int mseSize) {
	double mse;
	vector<Mat> imgtemp;

	for (int i = 0; i < img.size(); i++) {
		back:
		for (int j = 0; j < img.size(); j++) {
			mse = down_MSE(img.at(i), img.at(j));
			if (mse < mseSize) {
				Mat img1;
				vconcat(img.at(i), img.at(j), img1);
				img.at(i) = img1;
				goto back;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < img.size(); i++) {
		int lengh = img.at(i).rows;
		ans = max(ans, lengh);
	}
	for (int i = 0; i < img.size(); i++) {
		if (img.at(i).rows == ans) {
			imgtemp.push_back(img.at(i));
		}
	}
	return imgtemp;
}
double right_MSE(Mat Matl, Mat Mat2) {
	if (Matl.empty() || Mat2.empty()) {
		exit;
	}
	Mat right = Matl(Range(0, Matl.rows), Range(Matl.cols - 1, Matl.cols));
	Mat left = Mat2(Range(0, Mat2.rows), Range(0, 1));
	Mat Diff;

	right.convertTo(right, CV_32F);
	left.convertTo(left, CV_32F);
	Diff.convertTo(Diff, CV_32F);
	absdiff(right, left, Diff);
	Diff = Diff.mul(Diff);
	Scalar S = sum(Diff);
	double sse;
	if (Diff.channels() == 3)
		sse = S.val[0] + S.val[1] + S.val[2];
	else
		sse = S.val[0];

	int nTotalElement = left.channels() * left.total();
	double mse = (sse / (double)nTotalElement);
	return mse;
}
double down_MSE(Mat Matl, Mat Mat2) {
	if (Matl.empty() || Mat2.empty()) {
		return 1;
	}
	Mat down = Matl(Range(Matl.rows - 1, Matl.rows), Range(0, Matl.cols));
	Mat up = Mat2(Range(0, 1), Range(0, Mat2.cols));
	Mat Diff;

	down.convertTo(down, CV_32F);
	up.convertTo(up, CV_32F);
	Diff.convertTo(Diff, CV_32F);
	absdiff(down, up, Diff);
	Diff = Diff.mul(Diff);
	Scalar S = sum(Diff);
	double sse;
	if (Diff.channels() == 3)
		sse = S.val[0] + S.val[1] + S.val[2];
	else
		sse = S.val[0];
	int nTotalElement = up.channels() * up.total();
	double mse = (sse / (double)nTotalElement);
	return mse;
}
Mat K_mean(Mat Img)
{
	Mat ImgHSV;
	cvtColor(Img, ImgHSV, COLOR_BGR2HSV);

	Mat ImgData(Img.rows * Img.cols, 1, CV_32FC3);
	Mat_<Vec3b>::iterator itImg = ImgHSV.begin<Vec3b>();
	Mat_<Vec3f>::iterator itData = ImgData.begin<Vec3f>();


	for (; itImg != ImgHSV.end<Vec3b>(); ++itImg, ++itData)
		*itData = *itImg;


	Mat ImgLabel, ImgCenter;
	kmeans(ImgData, 15, ImgLabel, TermCriteria(TermCriteria::EPS + TermCriteria::MAX_ITER, 10, 1.0), 3, KMEANS_PP_CENTERS, ImgCenter);

	Mat ImgRes(Img.size(), CV_8UC3);
	Mat_<Vec3b>::iterator itRes = ImgRes.begin<Vec3b>();
	Mat_<int>::iterator itLabel = ImgLabel.begin<int>();
	for (; itLabel != ImgLabel.end<int>(); ++itLabel, ++itRes)
		*itRes = ImgCenter.at<Vec3f>(*itLabel, 0);
	return ImgRes;
}	
void MyForm::Navigation1()
{
	Navigation();
}
Mat Navigation()
{
	img_Navi =imgOutput.clone();
	Mat imgclone = img_Navi.clone();
	Mat img_input = Mat::zeros(img_Navi.rows, img_Navi.cols, CV_8UC1);
	cvtColor(imgclone, imgclone, cv::COLOR_GRAY2BGR);


	for (int i = 0; i < img_Navi.rows; i++) {
		for (int j = 0; j < img_Navi.cols; j++) {
			if ((int)img_Navi.at<uchar>(i, j)== 255) {
				img_Navi.at<uchar>(i, j) = 0;
			}
			else {
				img_Navi.at<uchar>(i, j) = 1;
			}
		}
	}
	Mat img_navi;
	mouseRGBvalue(imgclone);
	while (left1 == 1 && right1 == 1)
	{
		img_navi = Navigation_temp();
		left1 = 0;
		right1 = 0;
		break;
	}
	return img_navi;
}
Mat Navigation_temp() {
	findMap(ii1, jj1);
	Mat img2 =imgInput.clone();
	for (int i = 0; i < img_Navi.rows; i++) {
		for (int j = 0; j < img_Navi.cols; j++) {
			if ((int)img_Navi.at<uchar>(i, j) == 2 && j < jj2) {
				img_Navi.at<uchar>(i, j) = 255;
			}
			else {
				img_Navi.at<uchar>(i, j) = 0;
			}
		}
	}
	dilate(img_Navi, img_Navi, Mat::ones(cv::Size(5, 5), CV_8UC1), cv::Point(-1, -1), 2);
	for (int i = 0; i < img_Navi.rows; i++)
	{
		for (int j = 0; j < img_Navi.cols; j++)
		{
			if (img_Navi.at<uchar>(i, j) > 0)
			{
				img2.at<Vec3b>(i, j)[2] = 255;
			}
		}
	}
	circle(img2, cv::Point(jj1, ii1), 20, Scalar(0, 0, 255), FILLED);
	circle(img2, cv::Point(jj2, ii2), 20, Scalar(0, 0, 255), FILLED);
	imshow("navigation road", img2);

	return img2;
}

int findMap(int x, int y) {
	const int PATHWAY_COLOUR = 0;
	const int WALL_COLOUR = 1;
	const int BLOCKED_COLOUR = 3;
	const int PATH_COLOUR = 2;
	if (x < 0 || y < 0 || x >= img_Navi.rows || y >= img_Navi.cols)
		return 0;
	else if ((int)img_Navi.at<uchar>(x, y) != PATHWAY_COLOUR) {
		return 0;
	}
	else if (x == ii2 && y == jj2) {
		img_Navi.at<uchar>(x, y) = PATH_COLOUR;
		return 1;
	}
	else {
		img_Navi.at<uchar>(x, y) = PATH_COLOUR;
		if (findMap(x - 1, y) || findMap(x, y + 1) || findMap(x + 1, y) || findMap(x, y - 1)) {
			return 1;
		}
		img_Navi.at<uchar>(x, y) = BLOCKED_COLOUR;
		return 0;
	}
}


void mouseEvent_RGBvalue(int evt, int x, int y, int flags, void* param) {
	cv::Mat* rgb = (cv::Mat*)param;
	switch (evt)
	{
	case 1:
		jj1 = x;
		ii1 = y;

		printf("[cols=%d,row=%d]=%d\n",
			x, y, (*rgb).at<uchar>(y, x));
		circle(*rgb,cv:: Point(x, y), 10, Scalar(0, 0, 255), FILLED);
		left1++;
		imshow("My Window", *rgb);
		break;
	case 2:
		jj2 = x;
		ii2 = y;
		printf("[cols=%d,row=%d]=%d\n",
			x, y, (*rgb).at<uchar>(y, x));
		circle(*rgb, cv::Point(x, y), 10, Scalar(0, 0, 255), FILLED);
		right1++;
		imshow("My Window", *rgb);
		break;
	}

}
void mouseEvent_xyValue(int evt, int x, int y, int flags, void* param) {
	cv::Mat* rgb = (cv::Mat*)param;
	if (evt == 1) {
		printf("[cols=%d,row=%d]=%d\n",
			x, y, (*rgb).at<uchar>(y, x));
	}
}

void mouseRGBvalue(Mat img) {
	namedWindow("My Window", 1);
	setMouseCallback("My Window", mouseEvent_RGBvalue, &img);
	imshow("My Window", img);
	waitKey(0);
}


