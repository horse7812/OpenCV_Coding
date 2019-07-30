// vs2017
// opencv 4.1.0

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // creat 1
    Mat t1 = Mat(256, 256, CV_8UC3);  // Mat(int _rows, int _cols, int _type)
    t1 = Scalar(255, 0, 0);  //函数Scalar用于为图像的每个像素写入值   // 每个像素上，通道的排列为B G R

    /*
        Mat t1 = Mat(256, 256, CV_8UC1);
        t1 = Scalar(0);
    */

    namedWindow("004-Demo-1", WINDOW_AUTOSIZE);
    imshow("004-Demo-1", t1);

    //creat 2
    Mat t2 = Mat(Size(256,256), CV_8UC3);
    t2 = Scalar(0, 255, 0);

    namedWindow("004-Demo-2", WINDOW_AUTOSIZE);
    imshow("004-Demo-2", t2);

    // creat 3
    Mat t3 = Mat::zeros(Size(256,256), CV_8UC3);
    t3 = Scalar(0, 0, 255);

    namedWindow("004-Demo-3", WINDOW_AUTOSIZE);
    imshow("004-Demo-3",t3);

    // creat 4   从现有的图像来创建图像
    Mat srcImg = imread("C:/Users/90307/Desktop/picture/2.jpg");  // 读入一张现有的图像

    if (srcImg.empty())
    {
        printf("Could not find the image..\n");
        system("pause");
        return -1; 
    }

    Mat t4 = srcImg;  // 采用赋值的方式创建图像，t4和srcImg指向同一个DataBlock  // 如果此时修改t4，也就是修改了srcImg，那么t5和t6也会改变
    Mat t5 = srcImg.clone();  // 采用克隆的方式创建图像，t5和srcImg指向不同的DataBlock
    Mat t6;
    srcImg.copyTo(t6); // 采用拷贝的方式创建图像，t6和SrcImg指向不同的DataBlock

    namedWindow("004-Demo-4", WINDOW_AUTOSIZE);
    imshow("004-Demo-4", t4);

    namedWindow("004-Demo-5", WINDOW_AUTOSIZE);
    imshow("004-Demo-5", t5);

    namedWindow("004-Demo-6", WINDOW_AUTOSIZE);
    imshow("004-Demo-6", t6);

    Mat t7 = Mat::zeros(srcImg.size(), srcImg.type());
    // Mat t7 = Mat::ones(srcImg.size(), srcImg.type());

    namedWindow("004-Demo-7", WINDOW_AUTOSIZE);
    imshow("004-Demo-7", t7);

    waitKey(0);
    destroyAllWindows();

    return 0; 
}