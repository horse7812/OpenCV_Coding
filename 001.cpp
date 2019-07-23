// IDE:VS2017
// OpenCV 4.1.0

#include <opencv2/opencv.hpp>  // 包含opencv头文件
#include <iostream>

using namespace cv;  // 包含cv命名空间
using namespace std; 

int main(int argc, char** argv)
{
    Mat srcImage = imread("C:/Users/90307/Desktop/picture/4.jpg");

    if (srcImage.empty())
    {
        printf("Could not find the image..\n");
        system("pause");
        return -1;
    }

    namedWindow("Input", WINDOW_AUTOSIZE);  // 创建图像显示窗口
    imshow("Input", srcImage);  // 显示图像

    waitKey(0);  // 等待任意键按下
    destroyAllWindows();  // 关闭所有的窗口
    
    return 0;
}
