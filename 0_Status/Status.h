//
// Created by yewmf on 2017/11/2.
//
/**
 * 内容：相关状态码及宏函数列表
 */

#ifndef INC_0_STATUS_STATUS_H
#define INC_0_STATUS_STATUS_H
#endif //INC_0_STATUS_STATUS_H
/**
 * 状态码
 */
#define TRUE        1   //真
#define FALSE       0   //假
#define YES         1   //是
#define NO          0   //否
#define OK          1   //通过
#define ERROR       0   //错误
#define SUCCESS     1   //成功
#define UNSUCCESS   0   //失败
#define INFEASIBLE  -1  //不可行

#ifndef _MATH_H         //系统中已有此状态码定义，要避免冲突
#define OVERFLOW    -2  //堆栈上溢
#define UNDERFLOW   -3  //堆栈下溢

#ifndef NULL
#define NULL ((void *)0)
#endif

/**
 * 状态码识别类型
 * */
typedef int Status;

/**
 * 宏函数
 */
//函数暂停一段时间
#define Wait(x) \
{\
    double _Loop_Num ;\
    for(_Loop_Num = 0.01; _Loop_Num <= 100000.0*x; _Loop_Num+=0.01)\
    ;\
}//设立一个空循环

//Enter键继续
#define PressEnter\
{\
    fflush(stdin);\
    printf("Press Enter...");\
    getchar();\
    fflush(stdin);\
}

#endif