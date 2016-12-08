//
//  homework1.cpp
//  digitImage_learn
//
//  Created by zhangxun on 2016/11/16.
//  Copyright © 2016年 zx. All rights reserved.
//

#include "homework1.hpp"

int handle_face()
{
    // /Volumes/zx 3/研究生/研究生课程资料/计算机图形学/2016-2017DIP/homework/1/beauty.jpg
    Mat src1 = imread("/Volumes/zx 3/研究生/研究生课程资料/计算机图形学/2016-2017DIP/homework/1/beauty.jpg");
    if(!src1.data)
    {
        cout << "homework1 src1 read error" << endl;
        exit(-1);
    }
    
    Mat structure = getStructuringElement(MORPH_RECT, Size(10,1));
    
    
    Mat guassian_src1,result_src1;
    
    imshow("homework1 src", src1);
    
    //orginal image + gaussian image
    //GaussianBlur(src1, guassian_src1, Size(3,3),100);

    medianBlur(src1, guassian_src1, 7);
    
    imshow("after gaussian",guassian_src1);
    
//    Point anchor(-1,-1);
//    float delta = 0.0;
//    filter2D(src1, guassian_src1, CV_32FC1, guassian_src1, anchor, delta, BORDER_REPLICATE);
    
    
    add(guassian_src1, guassian_src1, guassian_src1);
    add(guassian_src1, src1, guassian_src1);
    subtract(guassian_src1, 1, guassian_src1);
    
    addWeighted(src1, 0.5, guassian_src1, 0.5, 0, result_src1);
    
    
    
    imshow("result",result_src1);

    
    while (true) {
        if(waitKey()==27)
            break;
    }
    
    return 0;
}