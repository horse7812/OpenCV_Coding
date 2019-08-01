// vs2017
// opencv 4.1.0

// 图像算术运算
// 两幅图像进行算术运算，要求图像的数据类型、通道数、图像大小（即高和宽）均必须相同
// 然后对应的像素或对应像素的对应通道进行算术运算

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; 
using namespace std; 

int main(int argc, char** argv)
{
    //【1】 读入两张图像并显示，这两张图像符合图像算术运算的要求
    Mat srcImg1 = imread("C:/OpenCV_test/OpenCV_Coding/picture/8.jpg");  // Linux Logo
    Mat srcImg2 = imread("C:/OpenCV_test/OpenCV_Coding/picture/9.jpg");  // Windows Logo

    if (srcImg1.empty() || srcImg2.empty())
    {
        printf("Could not find the image..\n"); 
        system("pause");
        return -1; 
    }

    namedWindow("007-Demo-srcImg1", WINDOW_AUTOSIZE);
    imshow("007-Demo-srcImg1", srcImg1); 

    namedWindow("007-Demo-srcImg2", WINDOW_AUTOSIZE);
    imshow("007-Demo-srcImg2", srcImg2); 

    // 【2】加
    Mat add_result = Mat::zeros(srcImg1.size(), srcImg1.type());  // 创建一个空白图像

    add(srcImg1, srcImg2, add_result);  // 调用函数add()

    namedWindow("007-Demo-add_result", WINDOW_AUTOSIZE);
    imshow("007-Demo-add_result", add_result);

    // 【3】减
    Mat sub_result = Mat::zeros(srcImg1.size(), srcImg1.type());  // 创建一个空白图像

    subtract(srcImg1, srcImg2, sub_result);  // 调用函数subtract()

    namedWindow("007-Demo-sub_result", WINDOW_AUTOSIZE);
    imshow("007-Demo-sub_result", sub_result);

    // 【4】乘
    Mat mul_result = Mat::zeros(srcImg1.size(), srcImg1.type());  // 创建一个空白图像

    multiply(srcImg1, srcImg2, mul_result);  // 调用函数multiply()

    namedWindow("007-Demo-mul_result", WINDOW_AUTOSIZE);
    imshow("007-Demo-mul_result", mul_result); 

    // 【5】除
    Mat div_result = Mat::zeros(srcImg1.size(), srcImg1.type());  // 创建一个空白图像

    divide(srcImg1, srcImg2, div_result);  //调用函数divide()

    namedWindow("007-Demo-div_result", WINDOW_AUTOSIZE);
    imshow("007-Demo-div_result", div_result); 

    // 【6】手写 add 效果
    Mat my_add_result = Mat::zeros(srcImg1.size(), srcImg1.type());  // 创建一个空白图像

    int height = srcImg1.rows;  // 由于srcImg1和srcImg2大小相同，此处仅用srcImg1来提取图像的高、宽、通道数
    int width = srcImg1.cols; 
    int ch = srcImg1.channels();

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (ch == 3)
            {
                // 获取图像srcImg1像素点(row,col)各通道的值
                int b1 = srcImg1.at<Vec3b>(row, col)[0];
                int g1 = srcImg1.at<Vec3b>(row, col)[1];
                int r1 = srcImg1.at<Vec3b>(row, col)[2];

                // 获取图像srcImg2像素点(row,col)各通道的值
                int b2 = srcImg2.at<Vec3b>(row, col)[0];
                int g2 = srcImg2.at<Vec3b>(row, col)[1];
                int r2 = srcImg2.at<Vec3b>(row, col)[2]; 

                // 对应像素点的对应通道值相加，赋给图像my_add_result对应像素点的对应各通道
                my_add_result.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b1 + b2);   // 给图像my_add_result像素点(row, col)的b通道写入值
                my_add_result.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g1 + g2);   // 给图像my_add_result像素点(row, col)的g通道写入值
                my_add_result.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r1 + r2);   // 给图像my_add_result像素点(row, col)的r通道写入值
            }

            if (ch == 1)
            {
                // 获取图像srcImg1像素点(row,col)的值
                int v1 = srcImg1.at<uchar>(row, col);

                // 获取图像srcImg2像素点(row,col)的值
                int v2 = srcImg2.at<uchar>(row, col); 

                // 对应像素点的值相加，赋给图像my_add_result的像素点(row,col)
                my_add_result.at<uchar>(row, col) = saturate_cast<uchar>(v1 + v2); 
            }
        }
    }

    namedWindow("007-Demo-my_add_result", WINDOW_AUTOSIZE); 
    imshow("007-Demo-my_add_result", my_add_result); 

    // 【7】改变图像的亮度
    Mat mask = Mat::zeros(srcImg1.size(), srcImg1.type());  
    Mat brightnessImg = Mat::zeros(srcImg1.size(), srcImg1.type());  
    
    /*
    add(srcImg1, mask, brightnessImg);   // 此时亮度不会发生变化
    */

    /*
    mask = Scalar(100,100,100);
    add(srcImg1, mask, brightnessImg);  // 此时亮度增加
    */

    ///*
    mask = Scalar(100,100,100); 
    subtract(srcImg1, mask, brightnessImg); // 此时亮度减少
    //*/

    namedWindow("007-Demo-bright", WINDOW_AUTOSIZE);
    imshow("007-Demo-bright", brightnessImg);

    // 【8】函数addWeighted()的使用
    Mat dstImg = Mat::zeros(srcImg1.size(), srcImg1.type());

    addWeighted(srcImg1, 0.5, mask, 0.5, 0.0, dstImg);

    namedWindow("007-Demo-addWeighted", WINDOW_AUTOSIZE);
    imshow("007-Demo-addWeighted", dstImg);

    waitKey(0);
    destroyAllWindows();

    return 0; 
}