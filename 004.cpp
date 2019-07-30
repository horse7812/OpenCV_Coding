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
    t1 = Scalar(255, 0, 0);  //����Scalar����Ϊͼ���ÿ������д��ֵ   // ÿ�������ϣ�ͨ��������ΪB G R

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

    // creat 4   �����е�ͼ��������ͼ��
    Mat srcImg = imread("C:/Users/90307/Desktop/picture/2.jpg");  // ����һ�����е�ͼ��

    if (srcImg.empty())
    {
        printf("Could not find the image..\n");
        system("pause");
        return -1; 
    }

    Mat t4 = srcImg;  // ���ø�ֵ�ķ�ʽ����ͼ��t4��srcImgָ��ͬһ��DataBlock  // �����ʱ�޸�t4��Ҳ�����޸���srcImg����ôt5��t6Ҳ��ı�
    Mat t5 = srcImg.clone();  // ���ÿ�¡�ķ�ʽ����ͼ��t5��srcImgָ��ͬ��DataBlock
    Mat t6;
    srcImg.copyTo(t6); // ���ÿ����ķ�ʽ����ͼ��t6��SrcImgָ��ͬ��DataBlock

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