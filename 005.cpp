// vs2017
// opencv 4.1.0

// ��OpenCV�У����صķ��������ַ�ʽ��1. ���鷽ʽ��2. ָ�뷽ʽ
// ָ�뷽ʽ�����鷽ʽ��
// �����Ƚ������鷽ʽ

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; 
using namespace std; 

int main(int argc, char** argv)
{
    Mat srcImg = imread("C:/OpenCV_test/OpenCV_Coding/picture/1.jpg");  // ����ͼ��

    if (srcImg.empty())  // ���û�гɹ�����ͼ��
    {
        printf("Could not find the image..\n");
        system("pause");
        return -1; 
    }

    namedWindow("005-Demo-1", WINDOW_AUTOSIZE);  // ����ͼ����ʾ����
    imshow("005-Demo-1", srcImg);  // ��ʾͼ��

    // �������������ͼ��srcImg����ÿ������ֵȡ��

    int height = srcImg.rows;    // ��ȡͼ�������
    int width = srcImg.cols;     // ��ȡͼ�������
    int ch = srcImg.channels();  // ��ȡͼ���ͨ����

    Mat dstImg = Mat::zeros(height, width, srcImg.type());  // ����һ���հ�ͼ��

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (ch == 3)  // ���srcImg��3ͨ����ͼ��
            {
                Vec3b bgr = srcImg.at<Vec3b>(row, col);  // typedef Vec<uchar, 3> Vec3b; 
                // ���ͼ����3ͨ��������ÿ��ͨ������uchar���ͣ���ʹ��Vec3b
                int blue = bgr[0];
                int green = bgr[1];
                int red = bgr[2];
                dstImg.at<Vec3b>(row, col)[0] = 255 - blue;  // ��ͼ��dstImg��(row,col)λ�õ�bͨ����ֵ
                dstImg.at<Vec3b>(row, col)[1] = 255 - green; // ��ͼ��dstImg��(row,col)λ�õ�gͨ����ֵ
                dstImg.at<Vec3b>(row, col)[2] = 255 - red;   // ��ͼ��dstImg��(row,col)λ�õ�rͨ����ֵ

                /*  ����д�����з�ʽ
                    Vec3b bgr = srcImg.at<Vec3b>(row, col);
                    bgr[0] = 255 - bgr[0];
                    bgr[1] = 255 - bgr[1];
                    bgr[2] = 255 - bgr[2];
                    dstImg.at<Vec3b>(row, col) = bgr;
                */
            }

            if (ch == 1)  // ���srcImg�ǵ�ͨ����ͼ��
            {
                int grayValue = srcImg.at<uchar>(row, col); 
                dstImg.at<uchar>(row, col) = 255 - grayValue; 
            }
        }
    }

    namedWindow("005-Demo-2", WINDOW_AUTOSIZE);  // ����ͼ����ʾ����
    imshow("005-Demo-2", dstImg);  // ��ʾͼ��
     
    waitKey(0);
    destroyAllWindows();

    return 0; 
}