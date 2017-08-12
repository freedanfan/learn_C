// usage: g++ -o segment_image segment_image.cpp   -lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui -std=c++11

// This project is prepare for Meathion leanrning dataset. Segment the picture for getting more training data.Sounge code follows:machmmach

#include <opencv2/opencv.hpp>  

  

#include <iostream>  





#define HEIGHT 200 	// The ROI's height

#define WIDTH  200  	// The ROI's width

#define	row_step 50	// The step of each loop in picture's row

#define col_step 50 	// The step of each loop in picture's col

#define max_loop_time 100	//the max loop-times that you want = the max number of pictures you will get

using namespace std;  



int main()  

{  



/***************************************************************

			just for test

****************************************************************



int num = 2;

char filename[100];

sprintf(filename,"%d.jpg",num);

IplImage *img = cvLoadImage(filename); 





cvNamedWindow("sub1",0);  

cvShowImage("sub1",img);

int j=1,k=2;

sprintf(filename,"/home/qian/Desktop/qian/%d_%d.png",j,k);

cvSaveImage(filename,img);		



******************************************************************/



	

	int times=1;    //the loop-times 

	int nums = 2;	//the number of pictures

	char cfilename[500];

	

	

	

	for (int num =1;num<=nums;num++){   //loop in each picture

	char filename[100];





	



	sprintf(filename,"%d.png",num);

	IplImage *img = cvLoadImage(filename);  

	IplImage *image = nullptr;  

  	

	int width=img->width;

	int height=img->height;



	printf("Picture %d : height= %d,width = %d\n",num,height,width);



	CvRect rect;

	rect.x=0,rect.y=0,rect.width=HEIGHT,rect.height=HEIGHT;



	image = cvCreateImage(cvSize( rect.width, rect.height),IPL_DEPTH_8U,3);  



	for(int row=0;;row=row+row_step){

		if((row +rect.height)>height) break;



		for(int col=0;;col=col+col_step){



			if((col +rect.width)>width) break;

			printf("row=%d,col=%d\n",row,col);

		

    			cvSetImageROI(img,rect);  

    			cvCopy(img,image);  

  	

			sprintf(cfilename,"/home/qian/Desktop/qian/%d_%d.jpg",num,times);	//the new_image's path you want to put

			cvSaveImage(cfilename,image);	

		

			times++;

			if(times>max_loop_time) return 0;

			rect.x=col;

		



 	

		}

		rect.y=row; 

		

	}

	



}

	 



  

    return 0;  

}  



