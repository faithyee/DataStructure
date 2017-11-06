//
// Created by yewmf on 2017/11/6.
//

#ifndef MERGESQLIST_C
#define MERGESQLIST_C

#include "03_MergeSqList.h"
#include "01_SequenceList.h"

/***
 * 调用顺序表函数进行合并
 * @param La
 * @param Lb
 * @param Lc
 */
void MergeSqList_1(SqList La, SqList Lb, SqList *Lc){

    int La_len,Lb_len;
    int i,j,k;
    LElemtype_Sq  ai, bj;
    //初始化Lc顺序表
    i = j = 1;
    k = 0;

    InitList_Sq(Lc);

    //获取La、Lb的长度
    La_len = ListLength_Sq(La);
    Lb_len = ListLength_Sq(Lb);


    //对La、Lb的顺序表进行遍历，比较La、和Lb，谁小则赋值给Lc
    while (i <= La_len && j <= Lb_len) {
        GetElem_Sq(La, i, &ai);
        GetElem_Sq(Lb, j, &bj);

        if (ai < bj) {
            ListInsert_Sq(Lc, ++k, ai);
            i++;
        } else {
            ListInsert_Sq(Lc, ++k, bj);
            j++;
        }

    }

    //最后把剩下的赋值给Lc

    while (i <= La_len){    //表La还未扫描完

        GetElem_Sq(La, i++, &ai );
        ListInsert_Sq(Lc, ++k , ai);
    }

    while (j <= Lb_len){    //表Lb还未扫描完

        GetElem_Sq(Lb, j++, &bj );
        ListInsert_Sq(Lc, ++k , bj);
    }

}

/***
 * 使用指针的方式进行合并
 * @param La
 * @param Lb
 * @param Lc
 */
void MergeSqList_2(SqList La, SqList Lb, SqList *Lc){

    LElemtype_Sq *pa, *pb, *pc;
    LElemtype_Sq *pa_last, *pb_last;

    pa = La.elem;
    pb = Lb.elem;

    (*Lc).listSize = (*Lc).length = La.length + Lb.length;
    pc = (*Lc).elem = (LElemtype_Sq *)malloc((*Lc).listSize*sizeof(LElemtype_Sq));
    if(!pc){
        exit(OVERFLOW);
    }

    pa_last = La.elem + La.length - 1;  //指向La最后一个元素
    pb_last = Lb.elem + Lb.length - 1;  //指向Lb最后一个元素

    while (pa <= pa_last && pb <= pb_last){
        if(*pa < *pb){
            *pc++ = *pa++;
        } else{
            *pc++ = *pb++;
        }
    }

    while (pa <= pa_last){
         *pc++ = *pa++;
    }

    while (pb <= pb_last){
        *pc++ = *pb++;
    }

}

void testMergeSqList_1(){
    SqList La, Lb, Lc1, Lc2;
    LElemtype_Sq a[4] = {3, 5, 8, 11};
    LElemtype_Sq b[7] = {2, 6, 8, 9, 11, 15, 20};
    int i ;

    InitList_Sq(&La);
    for (int i = 1; i <= 4; ++i) {
        ListInsert_Sq(&La, i, a[i-1]);
    }

    InitList_Sq(&Lb);
    for (int j = 1; j <= 7; ++j) {
        ListInsert_Sq(&Lb, j, b[j-1]);
    }

    printf("La = ");
    ListTraverse_Sq(La, PrintElem);
    printf("\n");

    printf("Lb = ");
    ListTraverse_Sq(Lb, PrintElem);
    printf("\n\n");

    MergeSqList_1(La, Lb, &Lc1);
    printf("Lc1 = ");
    ListTraverse_Sq(Lc1, PrintElem);
    printf("\n\n");

}

void testMergeSqList_2(){
    SqList La, Lb, Lc2;
    LElemtype_Sq a[4] = {3, 5, 8, 11};
    LElemtype_Sq b[7] = {2, 6, 8, 9, 11, 15, 20};
    int i ;

    InitList_Sq(&La);
    for (int i = 1; i <= 4; ++i) {
        ListInsert_Sq(&La, i, a[i-1]);
    }

    InitList_Sq(&Lb);
    for (int j = 1; j <= 7; ++j) {
        ListInsert_Sq(&Lb, j, b[j-1]);
    }

    printf("La = ");
    ListTraverse_Sq(La, PrintElem);
    printf("\n");

    printf("Lb = ");
    ListTraverse_Sq(Lb, PrintElem);
    printf("\n\n");

    MergeSqList_2(La, Lb, &Lc2);
    printf("Lc1 = ");
    ListTraverse_Sq(Lc2, PrintElem);
    printf("\n\n");
}

void PrintElem(LElemtype_Sq e){
    printf("%d " ,e );
}

#endif