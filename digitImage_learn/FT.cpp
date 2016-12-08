//
//  FT.cpp
//  digitImage_learn
//
//  Created by zhangxun on 2016/11/15.
//  Copyright © 2016年 zx. All rights reserved.
//

#include "FT.hpp"

int test_ft()
{
    
    Mat image = imread("/Volumes/zx 2/研究生/研究生课程资料/计算机图形学/2016-2017DIP/homework/1/beauty.jpg");
    //resize(image, image, Size(100,100));
    
    cvtColor(image,image,CV_RGB2GRAY);
    imshow("src_of_FT",image);
    image.convertTo(image,CV_32FC1);
    for(int i=0; i<image.rows; i++)        //中心化
    {
        float *p = image.ptr<float>(i);
        for(int j=0; j<image.cols; j++)
        {
            p[j] = p[j] * pow(-1, i+j);
        }
    }
    
    ////////////////////////////////////////二维基本傅里叶变换//////////////////////////////////////////////////
    
    Mat dftRe = Mat::zeros(image.size(), CV_32FC1);
    Mat dftIm = Mat::zeros(image.size(), CV_32FC1);
    for(int u=0; u<image.rows; u++)
    {
        float *pRe = dftRe.ptr<float>(u);
        float *pIm = dftIm.ptr<float>(u);
        for(int v=0; v<image.cols; v++)
        {
            float sinDft=0, cosDft=0;
            for(int i=0; i<image.rows; i++)
            {
                float *q = image.ptr<float>(i);
                for(int j=0; j<image.cols; j++)
                {
                    float temp = PI2 *((float)u*i/image.rows + (float)v*j/image.cols);
                    sinDft -= q[j] * sin(temp);
                    cosDft += q[j] * cos(temp);
                }
            }
            pRe[v] = sinDft;
            pIm[v] = cosDft;
        }
    }
    divide(dftRe, image.rows*image.rows, dftRe);
    divide(dftIm, image.rows*image.rows, dftIm);
    multiply(dftIm, dftIm, dftIm);
    multiply(dftRe, dftRe, dftRe);
    add(dftRe, dftIm, dftRe);
    pow(dftRe, 0.5, dftRe);
    imshow("mydft", dftRe);
    
    ///////////////////////////////////////快速傅里叶变换/////////////////////////////////////////////////////
    //int oph = getOptimalDFTSize(image.rows);
    //int opw = getOptimalDFTSize(image.cols);
    //Mat padded;
    //copyMakeBorder(image, padded, 0, oph-image.rows, 0, opw-image.cols, BORDER_CONSTANT, Scalar::all(0));
    
    //Mat temp[] = {padded, Mat::zeros(image.size(),CV_32FC1)};
    //Mat complexI;
    //merge(temp, 2, complexI);
    
    //dft(complexI, complexI);    //傅里叶变换
    
    ////显示频谱图
    //split(complexI, temp);
    //Mat aa;
    //magnitude(temp[0], temp[1], aa);
    //divide(aa, oph*opw, aa);
    //imshow("aa",aa);
    
    /////////////////////////////////////////////频域滤波///////////////////////////////////////////////////////
    ////生成频域滤波核
    //Mat gaussianBlur(image.size(), CV_32FC2);
    //Mat gaussianSharpen(image.size(), CV_32FC2);
    //float D0 = 2*50*50.;
    //for(int i=0; i<oph; i++)
    //{
    //    float *p = gaussianBlur.ptr<float>(i);
    //    float *q = gaussianSharpen.ptr<float>(i);
    //    for(int j=0; j<opw; j++)
    //    {
    //        float d = pow(i-oph/2, 2) + pow(j-opw/2, 2);
    //        p[2*j] = expf(-d / D0);
    //        p[2*j+1] = expf(-d / D0);
    
    //        q[2*j] = 1 - expf(-d / D0);
    //        q[2*j+1] = 1 - expf(-d / D0);
    //    }
    //}
    
    ////高斯低通滤波， 高斯高通滤波
    //multiply(complexI, gaussianBlur, gaussianBlur);
    //multiply(complexI, gaussianSharpen, gaussianSharpen);
    
    ////傅里叶反变换
    //dft(gaussianBlur, gaussianBlur, CV_DXT_INVERSE);
    //dft(gaussianSharpen, gaussianSharpen, CV_DXT_INVERSE);
    
    //Mat dstBlur[2], dstSharpen[2];
    //split(gaussianBlur, dstBlur);
    //split(gaussianSharpen, dstSharpen);
    
    //for(int i=0; i<oph; i++)        //中心化
    //{
    //    float *p = dstBlur[0].ptr<float>(i);
    //    float *q = dstSharpen[0].ptr<float>(i);
    //    for(int j=0; j<opw; j++)
    //    {
    //        p[j] = p[j] * pow(-1, i+j);
    //        q[j] = q[j] * pow(-1, i+j);
    //    }
    //}
    //normalize(dstBlur[0], dstBlur[0], 1, 0, CV_MINMAX);
    //normalize(dstSharpen[0], dstSharpen[0], 1, 0, CV_MINMAX);
    //imshow("dstBlur",dstBlur[0]);
    //imshow("dstSharpen",dstSharpen[0]);
    
    waitKey(0);
    
    return 0;
}
