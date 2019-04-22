// VedieoImporter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/core/core.hpp>  

#include <string.h>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	//VideoCapture cap(0);

	std::string fliePath = "split.avi";
	VideoCapture cap(fliePath);
	cap.set(CAP_PROP_MODE, CAP_MODE_RGB);
	if (!cap.isOpened())
	{
		cout << "Movie open Error" << endl;
		return -1;
	}

	//获取视频帧频
	double rate = cap.get(CV_CAP_PROP_FPS);
	cout << "帧率为:" << " " << rate << endl;
	cout << "总帧数为:" << " " << cap.get(CV_CAP_PROP_FRAME_COUNT) << endl;//输出帧总数

	namedWindow("Movie Player");

	Mat frame;
	Mat edges;

	bool stop = false;
	while (!stop)
	{
		/*cap >> frame;*/
		cap.read(frame);
 
		imshow("Movie Player", frame);

		if (waitKey(30) >= 0)  //waitKey（30） 超时30ms没有按键的时候，返回-1，否则返回键值》0
			stop = true;
	}

	cap.release();
	destroyWindow("Movie Player");
	return 0;
}