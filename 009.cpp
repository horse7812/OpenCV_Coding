// vs2017
// opencv 4.1.0

/*
    ͼ�����ص�ͳ�ƣ�
        1. ��ͼ�����ص����ֵ����Сֵ�����ǵ�λ��
        2. ��Ҷ�ͼ��ľ�ֵ�ͷ���
        3. ���ɫͼ��ľ�ֵ�ͷ���
        4. ���Ҷ�ͼ��ת��Ϊ��ֵͼ��
*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; 
using namespace std; 

int main(int argc, char** argv)
{
    //��1����ͼ�����ص����ֵ����Сֵ�����ǵ�λ��

    Mat src1 = imread("c:/OpenCV_test/OpenCV_Coding/picture/2.jpg", IMREAD_GRAYSCALE);  // �Ҷ�ͼ��

    if (src1.empty())
    {
        printf("Could not find the image..\n");
        system("pause");
        return -1; 
    }

    namedWindow("009-Demo-src1", WINDOW_AUTOSIZE);
    imshow("009-Demo-src1", src1); 

    double minValue;
    double maxValue; 
    Point minLocation;
    Point maxLocation; 
    
    minMaxLoc(src1, &minValue, &maxValue, &minLocation, &maxLocation, Mat());  // ����src��Ϊ��ͨ��ͼ��

    /*
        �������Ҫ���ĸ�����������дΪNULL��
        ���磬
        1. ֻ��Ҫ����Сֵ����λ�ã�minMaxLoc(src, &minValue, NULL, &minLocation, NULL, Mat());
        2. ֻ��Ҫ�����ֵ����λ�ã�minMaxLoc(src, NULL, &maxValue, NULL, &maxLocation, Mat());
        3. ֻ��Ҫ����Сֵ��minMaxLoc(src, &minValue, NULL, NULL, NULL, Mat());
        4. ֻ��Ҫ�����ֵ��minMaxLoc(src, NULL, &maxValue, NULL, NULL, Mat());
        5. ֻ��Ҫ����Сֵ��λ�ã�minMaxLoc(src, NULL, NULL, &minLocation, NULL, Mat());
        6. ֻ��Ҫ�����ֵ��λ�ã�minMaxLoc(src, NULL, NULL, NULL, &maxLocation, Mat());
    */

    printf("minValue:%.2f, maxValue:%.2f\n", minValue, maxValue);
    printf("minLocation:(%d,%d), ", minLocation.x, minLocation.y); 
    printf("maxLocation:(%d,%d)\n", maxLocation.x, maxLocation.y);

    //��2����Ҷ�ͼ��ľ�ֵ�ͷ���

    Mat m1;
    Mat std1;

    meanStdDev(src1, m1, std1, Mat());

    printf("m1 -- height:%d, width:%d, channels:%d\n", m1.rows, m1.cols, m1.channels());  // height:1, width:1, channels:1 
    printf("std1 -- height:%d, width:%d, channels:%d\n", std1.rows, std1.cols, std1.channels());  // height:1, width:1, channels:1

    printf("src1 -- mean:%.2f, std:%.2f\n", m1.at<double>(0,0), std1.at<double>(0,0)); // �����m1��std1���ݶ���double���͵�

    //��3�����ɫͼ��ľ�ֵ�ͷ���

    Mat src2 = imread("c:/OpenCV_test/OpenCV_Coding/picture/2.jpg");  // ��ɫͼ��

    if (src2.empty())
    {
        printf("Could not find the image..\n");
        system("pause");
        return -1;
    }

    namedWindow("009-Demo-src2", WINDOW_AUTOSIZE);
    imshow("009-Demo-src2", src2);

    Mat m2;
    Mat std2;

    meanStdDev(src2, m2, std2, Mat()); 

    printf("m2 -- height:%d, width:%d, channels:%d\n", m2.rows, m2.cols, m2.channels());  // height:3, width:1, channels:1 
    printf("std2 -- height:%d, width:%d, channels:%d\n", std2.rows, std2.cols, std2.channels());  // height:3, width:1, channels:1

    printf("src2_b_channel -- mean:%.2f, std:%.2f\n", m2.at<double>(0,0), std2.at<double>(0,0)); 
    printf("src2_g_channel -- mean:%.2f, std:%.2f\n", m2.at<double>(1,0), std2.at<double>(1,0));
    printf("src2_r_channel -- mean:%.2f, std:%.2f\n", m2.at<double>(2,0), std2.at<double>(2,0));

    //��4�����Ҷ�ͼ��ת��Ϊ��ֵͼ��

    Mat bw = Mat::zeros(src1.size(), CV_8UC1);  // ����һ���հ�ͼ�����ڱ����ֵͼ��

    for (int row = 0; row < src1.rows; row++)
    {
        for (int col = 0; col < src1.cols; col++)
        {
            bw.at<uchar>(row,col) = (src1.at<uchar>(row,col) > m1.at<double>(0,0)) ? 255 : 0;
        }
    }

    namedWindow("009-Demo-bw", WINDOW_AUTOSIZE);
    imshow("009-Demo-bw", bw);

    waitKey(0);
    destroyAllWindows();

    return 0; 
}