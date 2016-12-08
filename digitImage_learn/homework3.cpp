//
//  homework3.cpp
//  digitImage_learn
//
//  Created by zhangxun on 2016/11/16.
//  Copyright © 2016年 zx. All rights reserved.
//

#include "homework3.hpp"


int hanlerice()
{
    Mat src3 = imread("/Volumes/zx 3/研究生/研究生课程资料/计算机图形学/2016-2017DIP/homework/3/rice.jpg",CV_8U);
    if(!src3.data)
    {
        cout << "rice src image read error" << endl;
        exit(-1);
    }
    
    //顶帽操作，处理背景颜色中不均匀光照问题，以提高阈值处理的准确度
    
    
    Mat top_src3,threshold_src3;
    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(30,30));
    morphologyEx(src3, top_src3, MORPH_TOPHAT, kernel);
    
    imshow("after top handle", top_src3);
    
    //处理直方图，得到最佳阈值
    
    
    //定义变量
    MatND dstHist;
    int dims = 1;
    float hranges[] = {0,255};
    const float *ranges[] = {hranges};
    int size = 256;
    int channels = 0;
    
    //计算直方图
    calcHist(&top_src3, 1, &channels, Mat(), dstHist, dims, &size, ranges);
    int scale = 1;
    
    Mat dstImage(size*scale, size, CV_8U, Scalar(0));
    //获取最大值和最小值
    double maxValue = 0;
    double minValue = 0;
    minMaxLoc(dstHist, &minValue, &maxValue, 0, 0);
    
    //绘制直方图
    int hpt = saturate_cast<int>(0.9 * size);
    for (int i=0; i<256; i++)
    {
        float binValue = dstHist.at<float>(i);
        int realValue = saturate_cast<int>(binValue * hpt / maxValue);
        rectangle(dstImage, Point(i*scale, size-1), Point((i+1)*scale-1, size-realValue), Scalar(255));
    }
    imshow("灰度直方图", dstImage);
    
    
    
    
    
    
    
    threshold(top_src3, threshold_src3, 55, 100, CV_THRESH_BINARY);
    //adaptiveThreshold(top_src3, threshold_src3, 100, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 3, 5);
    
    imshow("after  threshold ", threshold_src3);
    
    
    //平滑边缘去除边缘相间处
    
 
    
    //读出数据米粒大小、颗粒等数据
    vector<vector<Point>>contours;

    findContours(threshold_src3, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    cout << "first size" << contours.size() << endl;
    for(int i = 0; i < contours.size(); i++)
    {
        for (int j = 0; j < contours[i].size(); j++)
        {
            if ( (contours[i][j].x>=0 and contours[i][j].x < 5) || (contours[i][j].y >= 0  && contours[i][j].y <5)|| (contours[i][j].x <= src3.rows && contours[i][j].x > src3.rows-5 )|| (contours[i][j].y <= src3.cols && contours[i][j].y > src3.cols-5))
            {
                contours.erase(contours.begin()+i);//删除第i个元素
            }
        }
    }
    
    cout << "after size" << contours.size() << endl;
    
    
    
    Mat result(src3.size(), CV_8U, Scalar(255));
    drawContours(result, contours, -1, Scalar(0), 1);
    imshow("result", result);
    
    return 0;
}