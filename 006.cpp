// vs2017
// opencv 4.1.0

// 使用指针遍历图像，对图像所有像素取反

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; 
using namespace std; 

int main(int argc, char** argv)
{
    //【1】读入原图像并显示图像

    Mat srcImg = imread("C:/OpenCV_test/OpenCV_Coding/picture/5.jpg");  // 读入图像

    if (srcImg.empty())
    {
        printf("Could not find the image..\n");
        system("pause");
        return -1; 
    }

    namedWindow("006-Demo-1", WINDOW_AUTOSIZE);
    imshow("006-Demo-1", srcImg);  // 显示图像

    //【2】指针方式遍历图像，然后对每个像素取反【思路1】

    /*
        首先获取图像数据每一行的首地址，
        然后通过操作符[]操作每个通道上的值。
    */
    
    Mat dstImg1 = Mat::zeros(srcImg.size(), srcImg.type());  // 创建一个空白图像

    int height = srcImg.rows;   // 获取图像的行数
    int width = srcImg.cols;    // 获取图像的列数
    int ch = srcImg.channels(); // 获取图像的通道数

    int Row_Element_Number = width * ch;  // 每一行元素的个数 = 列数 × 通道数  // 此处的元素指的是像素的各个通道

    for (int row = 0; row < height; row++)  // 逐行扫描
    {
        uchar* srcImg_current_row = srcImg.ptr<uchar>(row); // 获取图像srcImg当前行的首地址，uchar为像素数据的数据类型
        uchar* dstImg1_current_row = dstImg1.ptr<uchar>(row); // 获取图像dstImg1当前行的首地址，uchar为像素数据的数据类型

        for (int element = 0; element < Row_Element_Number; element++)  // 每一行上，逐通道扫描
        {
            dstImg1_current_row[element] = 255 - srcImg_current_row[element];  // 各通道上的值取反
        }
    }

    namedWindow("006-Demo-2", WINDOW_AUTOSIZE);
    imshow("006-Demo-2", dstImg1);
    
    //【2】指针方式遍历图像，然后对每个像素取反【思路2】

    /*
        
        首先获取图像数据每一行的首地址，
        然后再以每一行的首地址作为该行数据（即数组）的首地址来访问该行数据。
    */

    Mat dstImg2 = Mat::zeros(srcImg.size(), srcImg.type());  // 创建一个空白图像

    for (int row = 0; row < height; row++)  // 逐行扫描
    {
        uchar* srcImg_current_row = srcImg.ptr<uchar>(row);  // 获取图像srcImg当前行的首地址，uchar为像素数据的数据类型
        uchar* dstImg2_current_row = dstImg2.ptr<uchar>(row);   // 获取图像dstImg2当前行的首地址，uchar为像素数据的数据类型

        for (int col = 0; col < width; col++)  // 逐列扫描
        {
            if (ch == 3)
            {
                int blue = *srcImg_current_row++;
                int green = *srcImg_current_row++;
                int red = *srcImg_current_row++;

                *dstImg2_current_row++ = 255 - blue;
                *dstImg2_current_row++ = 255 - green;
                *dstImg2_current_row++ = 255 - red;
            }

            if (ch == 1)
            {
               int grayValue = *srcImg_current_row++;
               *dstImg2_current_row++ = grayValue;
            }
        }
    }

    namedWindow("006-Demo-3", WINDOW_AUTOSIZE);
    imshow("006-Demo-3", dstImg2);

    
    waitKey(0);
    destroyAllWindows();

    return 0; 
}