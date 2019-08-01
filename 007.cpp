// vs2017
// opencv 4.1.0

// ͼ����������
// ����ͼ������������㣬Ҫ��ͼ����������͡�ͨ������ͼ���С�����ߺͿ���������ͬ
// Ȼ���Ӧ�����ػ��Ӧ���صĶ�Ӧͨ��������������

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; 
using namespace std; 

int main(int argc, char** argv)
{
    //��1�� ��������ͼ����ʾ��������ͼ�����ͼ�����������Ҫ��
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

    // ��2����
    Mat add_result = Mat::zeros(srcImg1.size(), srcImg1.type());  // ����һ���հ�ͼ��

    add(srcImg1, srcImg2, add_result);  // ���ú���add()

    namedWindow("007-Demo-add_result", WINDOW_AUTOSIZE);
    imshow("007-Demo-add_result", add_result);

    // ��3����
    Mat sub_result = Mat::zeros(srcImg1.size(), srcImg1.type());  // ����һ���հ�ͼ��

    subtract(srcImg1, srcImg2, sub_result);  // ���ú���subtract()

    namedWindow("007-Demo-sub_result", WINDOW_AUTOSIZE);
    imshow("007-Demo-sub_result", sub_result);

    // ��4����
    Mat mul_result = Mat::zeros(srcImg1.size(), srcImg1.type());  // ����һ���հ�ͼ��

    multiply(srcImg1, srcImg2, mul_result);  // ���ú���multiply()

    namedWindow("007-Demo-mul_result", WINDOW_AUTOSIZE);
    imshow("007-Demo-mul_result", mul_result); 

    // ��5����
    Mat div_result = Mat::zeros(srcImg1.size(), srcImg1.type());  // ����һ���հ�ͼ��

    divide(srcImg1, srcImg2, div_result);  //���ú���divide()

    namedWindow("007-Demo-div_result", WINDOW_AUTOSIZE);
    imshow("007-Demo-div_result", div_result); 

    // ��6����д add Ч��
    Mat my_add_result = Mat::zeros(srcImg1.size(), srcImg1.type());  // ����һ���հ�ͼ��

    int height = srcImg1.rows;  // ����srcImg1��srcImg2��С��ͬ���˴�����srcImg1����ȡͼ��ĸߡ���ͨ����
    int width = srcImg1.cols; 
    int ch = srcImg1.channels();

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (ch == 3)
            {
                // ��ȡͼ��srcImg1���ص�(row,col)��ͨ����ֵ
                int b1 = srcImg1.at<Vec3b>(row, col)[0];
                int g1 = srcImg1.at<Vec3b>(row, col)[1];
                int r1 = srcImg1.at<Vec3b>(row, col)[2];

                // ��ȡͼ��srcImg2���ص�(row,col)��ͨ����ֵ
                int b2 = srcImg2.at<Vec3b>(row, col)[0];
                int g2 = srcImg2.at<Vec3b>(row, col)[1];
                int r2 = srcImg2.at<Vec3b>(row, col)[2]; 

                // ��Ӧ���ص�Ķ�Ӧͨ��ֵ��ӣ�����ͼ��my_add_result��Ӧ���ص�Ķ�Ӧ��ͨ��
                my_add_result.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b1 + b2);   // ��ͼ��my_add_result���ص�(row, col)��bͨ��д��ֵ
                my_add_result.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g1 + g2);   // ��ͼ��my_add_result���ص�(row, col)��gͨ��д��ֵ
                my_add_result.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r1 + r2);   // ��ͼ��my_add_result���ص�(row, col)��rͨ��д��ֵ
            }

            if (ch == 1)
            {
                // ��ȡͼ��srcImg1���ص�(row,col)��ֵ
                int v1 = srcImg1.at<uchar>(row, col);

                // ��ȡͼ��srcImg2���ص�(row,col)��ֵ
                int v2 = srcImg2.at<uchar>(row, col); 

                // ��Ӧ���ص��ֵ��ӣ�����ͼ��my_add_result�����ص�(row,col)
                my_add_result.at<uchar>(row, col) = saturate_cast<uchar>(v1 + v2); 
            }
        }
    }

    namedWindow("007-Demo-my_add_result", WINDOW_AUTOSIZE); 
    imshow("007-Demo-my_add_result", my_add_result); 

    // ��7���ı�ͼ�������
    Mat mask = Mat::zeros(srcImg1.size(), srcImg1.type());  
    Mat brightnessImg = Mat::zeros(srcImg1.size(), srcImg1.type());  
    
    /*
    add(srcImg1, mask, brightnessImg);   // ��ʱ���Ȳ��ᷢ���仯
    */

    /*
    mask = Scalar(100,100,100);
    add(srcImg1, mask, brightnessImg);  // ��ʱ��������
    */

    ///*
    mask = Scalar(100,100,100); 
    subtract(srcImg1, mask, brightnessImg); // ��ʱ���ȼ���
    //*/

    namedWindow("007-Demo-bright", WINDOW_AUTOSIZE);
    imshow("007-Demo-bright", brightnessImg);

    // ��8������addWeighted()��ʹ��
    Mat dstImg = Mat::zeros(srcImg1.size(), srcImg1.type());

    addWeighted(srcImg1, 0.5, mask, 0.5, 0.0, dstImg);

    namedWindow("007-Demo-addWeighted", WINDOW_AUTOSIZE);
    imshow("007-Demo-addWeighted", dstImg);

    waitKey(0);
    destroyAllWindows();

    return 0; 
}