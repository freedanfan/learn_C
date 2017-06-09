/*
 *
 * 功能：对所有的正样本进行尺度归一化
 *
 */

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>
#include "iostream"

using namespace std;
using namespace cv;


int main(int argc,char* argv[]){

	//--1.读入图片
	FILE *writer;
	FILE *reader;
	char strLine[50];
	string s="pos/pos_forigner/10050-123.avi_1_0.jpg";
	cout <<s << endl;
	char path[70];
	int i=1;
	char name[20];
	char txt[128];   

	if((reader=fopen("pos/pos_forigner.lst","r")) ==NULL)
		{
			printf("Open Failed");
			return -1;
		}
	
	fgets(strLine,100,reader);
	sprintf(path,"pos/%s",strLine);
	s =path;
							//s = "pos/"+strLine;

	printf("pos/%s",strLine);
	printf("%s",path);
	cout <<s << endl;
  					//"pos/pos_forigner/10050-123.avi_0_0.jpg"
	Mat image = imread(s.c_str());   //图片读取灰度化改变尺寸并保存到相应文件夹

	writer=fopen("pos.txt","w");
	//cvtColor(image,image,CV_RGB2GRAY);
	//Mat dstImage = Mat::zeros(30,30,CV_8UC1);
	//resize(image,dstImage,dstImage.size());
	//sprintf(name,"resize_pos/%d.jpg",i);
	//imwrite(name,dstImage);

	 
	//memset(txt,0,sizeof(txt));//生成描述文本
	//sprintf(txt,"%s 1 0 0 30 30",name);
	//if(fputs(txt,writer)==EOF)  printf("txt error ");
	imshow("1",image);
	waitKey(0);
	fclose(writer);
}
