// vs2017
// opencv 4.1.0

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; 
using namespace std;

int main(int argc, char** argv)
{
    Mat srcImg = imread("C:/Users/90307/Desktop/picture/2.jpg", IMREAD_COLOR);
    // 参数IMREAD_COLOR是函数imread()的默认值

    if (srcImg.empty())
    {
        printf("Could not find the image..\n");
        system("pause");
        return -1; 
    }

    namedWindow("003-Demo", WINDOW_AUTOSIZE);
    imshow("003-Demo", srcImg);

    int width = srcImg.cols;  // 获取图像的列数
    int height = srcImg.rows;  // 获取图像的行数
    int dim = srcImg.channels();  // 获取图像的通道数

    printf("width = %d\n", width);
    printf("height = %d\n", height);
    printf("dim = %d\n", dim);

    waitKey(0);
    destroyAllWindows();

    return 0;
}