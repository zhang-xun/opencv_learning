//
//  main.cpp
//  digitImage_learn
//
//  Created by zhangxun on 16/11/3.
//  Copyright © 2016年 zx. All rights reserved.
//

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>


#include "FT.hpp"
#include "chapter3.hpp"
#include "chapter9.hpp"
#include "homework1.hpp"
#include "homework2.hpp"
#include "homework3.hpp"


using namespace std;
using namespace cv;

void callbackButton2(int state, void *pointer){
    
    cout << "button2 clicked" << endl;
    
}
int main(int argc, const char * argv[]) {
    
    //createButton("button2",callbackButton2,NULL,CV_PUSH_BUTTON,0);
    
    //chapter 3
    //handle_equalhist();
    
    //chapter 9
    
    //image0905erode();
    //image0907dilate();
    //handle_open_close();
    //handle_add();
    
    
    
    
    
    //homework1
    //handle_face();
    //homework2
    handleline();
    
    //homework3 done 
    //hanlerice();
    
    
    while (true) {
        if(waitKey()==27)
            break;
    }
    
    
    
    test_ft();
    
    while (true) {
        if(waitKey()==27)
            break;
    }
    
    
    
    return 0;
    
}


