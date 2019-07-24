// IDE:VS2017
// OpenCV 4.1.0

#include <opencv2/opencv.hpp>  // ����opencvͷ�ļ�
#include <iostream>

using namespace cv;  // ����cv�����ռ�
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

    namedWindow("001-Demo", WINDOW_AUTOSIZE);  // ����ͼ����ʾ����
    imshow("001-Demo", srcImage);  // ��ʾͼ��

    waitKey(0);  // �ȴ����������
    destroyAllWindows();  // �ر����еĴ���

    return 0;
}
