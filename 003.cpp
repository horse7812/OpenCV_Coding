// vs2017
// opencv 4.1.0

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; 
using namespace std;

int main(int argc, char** argv)
{
    Mat srcImg = imread("C:/Users/90307/Desktop/picture/2.jpg", IMREAD_COLOR);
    // ����IMREAD_COLOR�Ǻ���imread()��Ĭ��ֵ

    if (srcImg.empty())
    {
        printf("Could not find the image..\n");
        system("pause");
        return -1; 
    }

    namedWindow("003-Demo", WINDOW_AUTOSIZE);
    imshow("003-Demo", srcImg);

    int width = srcImg.cols;  // ��ȡͼ�������
    int height = srcImg.rows;  // ��ȡͼ�������
    int dim = srcImg.channels();  // ��ȡͼ���ͨ����

    printf("width = %d\n", width);
    printf("height = %d\n", height);
    printf("dim = %d\n", dim);

    waitKey(0);
    destroyAllWindows();

    return 0;
}