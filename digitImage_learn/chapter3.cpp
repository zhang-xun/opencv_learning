//
//  chapter3.cpp
//  digitImage_learn
//
//  Created by zhangxun on 2016/11/18.
//  Copyright © 2016年 zx. All rights reserved.
//

#include "chapter3.hpp"

void handle_equalhist()
{
    Mat src0316 = imread("/Volumes/zx 2/研究生/研究生课程资料/计算机图形学/imagedatabase/DIP3E_Original_Images_CH03/Fig0316(3)(third_from_top).tif",CV_8U);
    
    
    imshow("src0316", src0316);
    
    Mat dest0316;
    
    equalizeHist(src0316, dest0316);
    
    imshow("dest0317", dest0316);
    
}