// IDE:VS2017
// OpenCV 4.1.0

#include <opencv2/opencv.hpp>  // ����opencvͷ�ļ�
#include <iostream>

using namespace cv;  // ����cv�����ռ�
using namespace std;

int main(int argc, char** argv)
{
    Mat srcImage = imread("C:/OpenCV-4.1.0/opencv/sources/samples/data/opencv-logo.png", IMREAD_UNCHANGED);
    // ��ȡ��͸��ͨ����ͼ��ʱ������ѡ��IMREAD_UNCHANGED

    if (srcImage.empty())
    {
        printf("Could not find the image..\n");
        system("pause");
        return -1;
    }

    namedWindow("002-Demo", WINDOW_AUTOSIZE);  // ����ͼ����ʾ����
    imshow("002-Demo", srcImage);  // ��ʾͼ��

    waitKey(0);  // �ȴ����������
    destroyAllWindows();  // �ر����еĴ���

    return 0;
}