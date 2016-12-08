//
//  chapter9.cpp
//  digitImage_learn
//
//  Created by zhangxun on 2016/11/17.
//  Copyright © 2016年 zx. All rights reserved.
//

#include "chapter9.hpp"


int image0905erode()
{
    Mat src0905 = imread("/Volumes/zx 2/研究生/研究生课程资料/计算机图形学/imagedatabase/DIP3E_Original_Images_CH09/Fig0905(a)(wirebond-mask).tif");
    imshow("src0905", src0905);
    Mat s11 = getStructuringElement(MORPH_RECT, Size(11,11));
    Mat s15 = getStructuringElement(MORPH_RECT, Size(15,15));
    Mat s45 = getStructuringElement(MORPH_RECT, Size(45,45));
    
    cout << s11 << endl;
    
    //imshow("s", s);
    Mat dest11,dest15,dest45;
    erode(src0905, dest11, s11);
    erode(src0905, dest15, s15);
    erode(src0905,dest45,s45);
    
    imshow("dest090511", src0905);
    imshow("dest090515", src0905);
    imshow("dest090545", src0905);
    
    
    return 0;
}


int image0907dilate()
{
    Mat src0907 = imread("/Volumes/zx 2/研究生/研究生课程资料/计算机图形学/imagedatabase/DIP3E_Original_Images_CH09/Fig0907(a)(text_gaps_1_and_2_pixels).tif");
    
    
    imshow("src0907", src0907);
    
    
    Mat s = getStructuringElement(MORPH_CROSS, Size(3,3));
    cout << s << endl;
    
    Mat destcross ;
    dilate(src0907, destcross, s);
    
    imshow("destcross", destcross);
    
    
    return 0;
}


int handle_open_close()
{
    Mat src0911 = imread("/Volumes/zx 2/研究生/研究生课程资料/计算机图形学/imagedatabase/DIP3E_Original_Images_CH09/Fig0911(a)(noisy_fingerprint).tif");
    imshow("src0911", src0911);
    
    Mat erode0911,dilate0911,close0911;
    
    Mat s3 = getStructuringElement(MORPH_RECT, Size(3,3));
    
    erode(src0911, erode0911, s3);
    
    dilate(erode0911, dilate0911, s3);
    
    morphologyEx(dilate0911, close0911, MORPH_CLOSE, s3);
    
    
    
    
    imshow("erode0911", erode0911);
    imshow("dilate0911", dilate0911);
    
    imshow("close0911", close0911);
    
    
    
    return 0;
}


int handle_add()
{
    Mat src_add = imread("/Volumes/zx 2/研究生/研究生课程资料/计算机图形学/imagedatabase/DIP3E_Original_Images_CH09/Fig0914(a)(licoln from penny).tif");
    
    Mat erode_add, dest_add;
     Mat s3 = getStructuringElement(MORPH_RECT, Size(3,3));
    erode(src_add, erode_add, s3);
    
    subtract(src_add, erode_add, dest_add);
    
    imshow("边界提取",dest_add);
    
    
    return 0;
}

int handle_holes_0915()
{
    Mat src0915 = imread("/Volumes/zx 2/研究生/研究生课程资料/计算机图形学/imagedatabase/DIP3E_Original_Images_CH09/Fig0914(a)(licoln from penny).tif");
    
    
    
    return 0;
}