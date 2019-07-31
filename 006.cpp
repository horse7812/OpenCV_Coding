// vs2017
// opencv 4.1.0

// ʹ��ָ�����ͼ�񣬶�ͼ����������ȡ��

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv; 
using namespace std; 

int main(int argc, char** argv)
{
    //��1������ԭͼ����ʾͼ��

    Mat srcImg = imread("C:/OpenCV_test/OpenCV_Coding/picture/5.jpg");  // ����ͼ��

    if (srcImg.empty())
    {
        printf("Could not find the image..\n");
        system("pause");
        return -1; 
    }

    namedWindow("006-Demo-1", WINDOW_AUTOSIZE);
    imshow("006-Demo-1", srcImg);  // ��ʾͼ��

    //��2��ָ�뷽ʽ����ͼ��Ȼ���ÿ������ȡ����˼·1��

    /*
        ���Ȼ�ȡͼ������ÿһ�е��׵�ַ��
        Ȼ��ͨ��������[]����ÿ��ͨ���ϵ�ֵ��
    */
    
    Mat dstImg1 = Mat::zeros(srcImg.size(), srcImg.type());  // ����һ���հ�ͼ��

    int height = srcImg.rows;   // ��ȡͼ�������
    int width = srcImg.cols;    // ��ȡͼ�������
    int ch = srcImg.channels(); // ��ȡͼ���ͨ����

    int Row_Element_Number = width * ch;  // ÿһ��Ԫ�صĸ��� = ���� �� ͨ����  // �˴���Ԫ��ָ�������صĸ���ͨ��

    for (int row = 0; row < height; row++)  // ����ɨ��
    {
        uchar* srcImg_current_row = srcImg.ptr<uchar>(row); // ��ȡͼ��srcImg��ǰ�е��׵�ַ��ucharΪ�������ݵ���������
        uchar* dstImg1_current_row = dstImg1.ptr<uchar>(row); // ��ȡͼ��dstImg1��ǰ�е��׵�ַ��ucharΪ�������ݵ���������

        for (int element = 0; element < Row_Element_Number; element++)  // ÿһ���ϣ���ͨ��ɨ��
        {
            dstImg1_current_row[element] = 255 - srcImg_current_row[element];  // ��ͨ���ϵ�ֵȡ��
        }
    }

    namedWindow("006-Demo-2", WINDOW_AUTOSIZE);
    imshow("006-Demo-2", dstImg1);
    
    //��2��ָ�뷽ʽ����ͼ��Ȼ���ÿ������ȡ����˼·2��

    /*
        
        ���Ȼ�ȡͼ������ÿһ�е��׵�ַ��
        Ȼ������ÿһ�е��׵�ַ��Ϊ�������ݣ������飩���׵�ַ�����ʸ������ݡ�
    */

    Mat dstImg2 = Mat::zeros(srcImg.size(), srcImg.type());  // ����һ���հ�ͼ��

    for (int row = 0; row < height; row++)  // ����ɨ��
    {
        uchar* srcImg_current_row = srcImg.ptr<uchar>(row);  // ��ȡͼ��srcImg��ǰ�е��׵�ַ��ucharΪ�������ݵ���������
        uchar* dstImg2_current_row = dstImg2.ptr<uchar>(row);   // ��ȡͼ��dstImg2��ǰ�е��׵�ַ��ucharΪ�������ݵ���������

        for (int col = 0; col < width; col++)  // ����ɨ��
        {
            if (ch == 3)
            {
                int blue = *srcImg_current_row++;
                int green = *srcImg_current_row++;
                int red = *srcImg_current_row++;

                *dstImg2_current_row++ = 255 - blue;
                *dstImg2_current_row++ = 255 - green;
                *dstImg2_current_row++ = 255 - red;
            }

            if (ch == 1)
            {
               int grayValue = *srcImg_current_row++;
               *dstImg2_current_row++ = grayValue;
            }
        }
    }

    namedWindow("006-Demo-3", WINDOW_AUTOSIZE);
    imshow("006-Demo-3", dstImg2);

    
    waitKey(0);
    destroyAllWindows();

    return 0; 
}