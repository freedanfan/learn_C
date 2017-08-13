// usage: g++ -o segment_image segment_image.cpp   -lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui -std=c++11

// This project is prepare for machine leanrning dataset. Segment the picture for getting more training data.Sounge code follows:machmmach




//usage:  g++ -o opencv_test opencv_test.cpp   -lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui -std=c++11





#include <opencv2/opencv.hpp>  

#include <iostream>  





#define HEIGHT 200 	// The ROI's height

#define WIDTH  200  	// The ROI's width

#define	row_step 50	// The step of each loop in picture's row

#define col_step 50 	// The step of each loop in picture's col

#define max_loop_time 10	//the max loop-times that you want = the max number of pictures you will get

#define path_to "/home/qian/Desktop/qian/"  //put the pictures to this path

#define path_from "/home/qian/Desktop/"	// get the picture from this path 

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



	

	int times=1;    //the loop-times per-image

	int nums = 2;	//the number of pictures

	char cfilename[500];

	char filename[100];

	int width,height;

	

	for (int num =1;num<=nums;num++){   //loop in each picture

	





	



	sprintf(filename,"%s%d.png",path_from,num);

	IplImage *img = cvLoadImage(filename);  

	IplImage *image = nullptr;  

  	

	width=img->width;

	height=img->height;



	printf("Picture %d : height= %d,width = %d\n",num,height,width);



	CvRect rect;

	rect.x=0,rect.y=0,rect.width=HEIGHT,rect.height=HEIGHT;



	image = cvCreateImage(cvSize( rect.width, rect.height),IPL_DEPTH_8U,3);  



	for(int row=0;;row=row+row_step){

		if(times>max_loop_time) break;		
		if((row +rect.height)>height) break;



		for(int col=0;;col=col+col_step){



			if((col +rect.width)>width) break;
			if(times>max_loop_time) break;	

			printf("time=%d,row=%d,col=%d\n",times,row,col);


			rect.x=col;

    			cvSetImageROI(img,rect);  

    			cvCopy(img,image);  

  	

			sprintf(cfilename,"%s%d_%d.jpg",path_to,num,times);	//the new_image's path you want to put

			cvSaveImage(cfilename,image);	

		

			times++;



			

		



 	

		}

		rect.y=row; 

		

		

	}

	

	
	times =1;

}

	 



  

    return 0;  

}  






