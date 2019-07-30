// vs2017
// opencv 4.1.0

// 在OpenCV中，像素的访问有两种方式：1. 数组方式；2. 指针方式
// 指针方式比数组方式快
// 这里先介绍数组方式

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; 
using namespace std; 

int main(int argc, char** argv)
{
    Mat srcImg = imread("C:/OpenCV_test/OpenCV_Coding/picture/1.jpg");  // 读入图像

    if (srcImg.empty())  // 如果没有成功读入图像
    {
        printf("Could not find the image..\n");
        system("pause");
        return -1; 
    }

    namedWindow("005-Demo-1", WINDOW_AUTOSIZE);  // 创建图像显示窗口
    imshow("005-Demo-1", srcImg);  // 显示图像

    // 接下来，想遍历图像srcImg，给每个像素值取反

    int height = srcImg.rows;    // 获取图像的行数
    int width = srcImg.cols;     // 获取图像的列数
    int ch = srcImg.channels();  // 获取图像的通道数

    Mat dstImg = Mat::zeros(height, width, srcImg.type());  // 创建一个空白图像

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (ch == 3)  // 如果srcImg是3通道的图像
            {
                Vec3b bgr = srcImg.at<Vec3b>(row, col);  // typedef Vec<uchar, 3> Vec3b; 
                // 如果图像是3通道，并且每个通道都是uchar类型，则使用Vec3b
                int blue = bgr[0];
                int green = bgr[1];
                int red = bgr[2];
                dstImg.at<Vec3b>(row, col)[0] = 255 - blue;  // 给图像dstImg的(row,col)位置的b通道赋值
                dstImg.at<Vec3b>(row, col)[1] = 255 - green; // 给图像dstImg的(row,col)位置的g通道赋值
                dstImg.at<Vec3b>(row, col)[2] = 255 - red;   // 给图像dstImg的(row,col)位置的r通道赋值

                /*  或者写成下列方式
                    Vec3b bgr = srcImg.at<Vec3b>(row, col);
                    bgr[0] = 255 - bgr[0];
                    bgr[1] = 255 - bgr[1];
                    bgr[2] = 255 - bgr[2];
                    dstImg.at<Vec3b>(row, col) = bgr;
                */
            }

            if (ch == 1)  // 如果srcImg是单通道的图像
            {
                int grayValue = srcImg.at<uchar>(row, col); 
                dstImg.at<uchar>(row, col) = 255 - grayValue; 
            }
        }
    }

    namedWindow("005-Demo-2", WINDOW_AUTOSIZE);  // 创建图像显示窗口
    imshow("005-Demo-2", dstImg);  // 显示图像
     
    waitKey(0);
    destroyAllWindows();

    return 0; 
}