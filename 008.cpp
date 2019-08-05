// vs2017
// opencv 4.1.0

// 图像像素逻辑运算

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; 
using namespace std; 

int main(int argc, char** argv)
{
    //【1】创建一个黄色区域
    Mat src1 = Mat::zeros(Size(400, 400), CV_8UC3); 
    Rect rect(100, 100, 100, 100); // 创建一个矩形区域，rect(x, y, width, height)
    src1(rect) = Scalar(0, 255, 255);  // b  g  r
    namedWindow("008-Demo-src1", WINDOW_AUTOSIZE);
    imshow("008-Demo-src1", src1); 

    //【2】创建一个红色区域
    Mat src2 = Mat::zeros(Size(400, 400), CV_8UC3);
    rect.x = 150;
    rect.y = 150; 
    src2(rect) = Scalar(0, 0, 255);
    namedWindow("008-Demo-src2", WINDOW_AUTOSIZE);
    imshow("008-Demo-src2", src2);
    
    //【3】不带mask的与、或、非、异或
    Mat dst1 = Mat::zeros(src1.size(), src1.type());  // 创建一张空白图像，用于保存结果

    // bitwise_and(src1, src2, dst1); // 与
    // bitwise_or(src1, src2, dst1);  // 或
    // bitwise_not(src1, dst1);  // 非
    // bitwise_not(src2, dst1);  // 非
    bitwise_xor(src1, src2, dst1);  // 异或（相异为1）

    namedWindow("008-Demo-dst1", WINDOW_AUTOSIZE);
    imshow("008-Demo-dst1", dst1); 
 
    //【4】带mask的与、或、非、异或
    // mask的作用：mask对应值为真时，src1和src2参与逻辑运算；mask对应值为假时，src1和src2不参与逻辑运算
    Mat src3 = imread("C:/OpenCV_test/OpenCV_Coding/picture/lena.jpg");

    namedWindow("008-Demo-src3", WINDOW_AUTOSIZE);
    imshow("008-Demo-src3", src3);

    Mat mask = Mat::zeros(src3.size(), CV_8UC1);
    int width = src3.cols / 2;
    int height = src3.rows / 2;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            mask.at<uchar>(row, col) = 255;
        }
    }
    namedWindow("008-Demo-mask", WINDOW_AUTOSIZE);
    imshow("008-Demo-mask", mask);

    Mat dst2 = Mat::zeros(src3.size(), src3.type());

    // bitwise_and(src3, src3, dst2, mask);  // 与
    // bitwise_or(src3, src3, dst2, mask);   // 或
    bitwise_not(src3, dst2, mask);         // 非
    // bitwise_xor(src3, src3, dst2, mask);     // 异或

    namedWindow("008-Demo-dst2", WINDOW_AUTOSIZE);
    imshow("008-Demo-dst2", dst2);

    waitKey(0);
    destroyAllWindows();

    return 0; 
}