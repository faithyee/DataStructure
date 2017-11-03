//
// Created by yewmf on 2017/11/3.
//

#ifndef UNION_C
#define UNION_C

#include "02_Union.h"

void PrintElem(LElemtype_Sq e);         //测试函数，打印整型

/* 并集函数列表 */
void Union(SqList *La, SqList Lb){
    //把La并Lb的集合赋予La
    int La_len, Lb_len;
    int i;
    LElemtype_Sq  e;

    //先获取La、Lb 顺序表的长度
    La_len = ListLength_Sq(*La);
    Lb_len = ListLength_Sq(Lb);

    //然后遍历Lb，看Lb中每个元素是否和La表中的每个元素相等，如果不相等，则插入La中
    for(i = 1; i<= Lb_len; i++){

        GetElem_Sq(Lb, i, &e);

        if(!LocateElem_Sq(*La, e, equal )){
            ListInsert_Sq(La, ++La_len, e);
        }
    }
}

Status equal(LElemtype_Sq e1, LElemtype_Sq e2){

    return e1==e2? TRUE:FALSE;
}

void testUnion(){
    SqList La, Lb;
    LElemtype_Sq a[5] = {5, 2, 1, 3, 9};
    LElemtype_Sq b[7] = {7, 2, 6, 9, 11, 13, 10};
    int i;

    InitList_Sq(&La);                   //初始化La
    for(i = 1; i<= 5; i++){
        ListInsert_Sq(&La, i, a[i - 1]);
    }

    InitList_Sq(&Lb);                   //初始化Lb
    for(i = 1; i<= 7; i++){
        ListInsert_Sq(&Lb, i, b[i - 1]);
    }

    printf("La = ");                    //输出La
    ListTraverse_Sq(La, PrintElem);

    printf("\n");
    printf("Lb = ");
    ListTraverse_Sq(Lb, PrintElem);
    printf("\n");
    printf("\n");

    printf("La = La n Lb = ");
    Union(&La, Lb);
    ListTraverse_Sq(La, PrintElem);
    printf("\n");

    return 0;
}

void PrintElem(LElemtype_Sq e){
    printf("%d ",e);
}

#endif