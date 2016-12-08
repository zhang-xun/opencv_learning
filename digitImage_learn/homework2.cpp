//
//  homework2.cpp
//  digitImage_learn
//
//  Created by zhangxun on 2016/11/16.
//  Copyright © 2016年 zx. All rights reserved.
//

#include "homework2.hpp"


int handleline()
{
    // /Volumes/zx 3/研究生/研究生课程资料/计算机图形学/2016-2017DIP/homework/2/LENNA3.JPG
    // /Volumes/zx 3/研究生/研究生课程资料/计算机图形学/2016-2017DIP/homework/2/Fig0809(a).tif
    Mat src2 = imread("/Volumes/zx 3/研究生/研究生课程资料/计算机图形学/2016-2017DIP/homework/2/Fig0809(a).tif",0);
    
    if(!src2.data)
    {
        cout << "homework2 src2 read error" << endl;
        exit(-1);
    }
    Mat linesrc2 = imread("/Volumes/zx 3/研究生/研究生课程资料/计算机图形学/2016-2017DIP/homework/2/linelenna.jpg",0);
    if(!linesrc2.data)
    {
        cout << "homework2 linesrc2 read error" << endl;
        exit(-1);
    }
    
    Mat structure = getStructuringElement(MORPH_RECT, Size(1,10));
    
    
    Mat desthomework2,laplacian_dest,sobel_dest,result_dest,canny_dest;
    //medianBlur(desthomework2, desthomework2, 3);
    
    Mat mediankernel = getStructuringElement(MORPH_RECT, Size(1,10));
    
    
    //中值滤波
    //erode(linesrc2, linesrc2, structure);
    medianBlur(linesrc2, desthomework2, 9);
    //medianBlur(desthomework2, desthomework2, 5);
    imshow("medianBlur2", desthomework2);
    //filter2D(linesrc2, desthomework2, linesrc2.depth(),structure);
    //blur(<#InputArray src#>, <#OutputArray dst#>, <#Size ksize#>)
    
    
    
    //获取高频信息
    Laplacian( src2, laplacian_dest, src2.depth(), 1, 1, 0, BORDER_DEFAULT );
    subtract(canny_dest, 100, canny_dest);
    imshow("laplacian", laplacian_dest);

    Sobel(src2, sobel_dest, src2.depth(), 1, 1);
    imshow("sobel", sobel_dest);
    
    Canny(src2, canny_dest, 50, 100);
    imshow("canny ", canny_dest);
    subtract(canny_dest, 245, canny_dest);
    
    Mat white_canny;
    threshold(canny_dest, white_canny, 40, 255, THRESH_BINARY_INV);
    imshow("canny reverser ", white_canny);
    
    cout <<"canny depth" <<  canny_dest.depth() << endl;
    cout <<"sobel depth" << sobel_dest.depth() << endl;
    cout <<"laaplacian depth"  << laplacian_dest.depth() << endl;
    cout << "median depth" << desthomework2.depth() << endl;
    //将高频信息与中值滤波后的结果权值相加
    
    
    //add(canny_dest,desthomework2,result_dest);
    add(laplacian_dest, desthomework2, result_dest);
    //addWeighted(desthomework2, 1, laplacian_dest, 1, 50, result_dest);
    
    medianBlur(result_dest, result_dest, 7);
    //add(laplacian_dest,result_dest,result_dest);
    addWeighted(result_dest, 1, laplacian_dest, 0.25, 50, result_dest);
    //均值化
    //equalizeHist(result_dest, result_dest);
    
    
    imshow("srclinelena", linesrc2);
    imshow("wanted lena", src2);
    imshow("homework2 linelena", result_dest);
    
    return 0;
}