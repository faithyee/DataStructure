//
// Created by yewmf on 2017/11/6.
//

#ifndef C_PROJECT_03_MERGESQLIST_H
#define C_PROJECT_03_MERGESQLIST_H

#include "01_SequenceList.c"

/* 顺序表归并函数列表 */
void MergeSqList_1(SqList La, SqList Lb, SqList *Lc);
/* C = A + B. A,B,C均为非递减序列 */

void MergeSqList_2(SqList La, SqList Lb, SqList *Lc);
/* C = A + B. A,B,C均为非递减序列 */

void testMergeSqList_1();

void testMergeSqList_2();

void PrintElem(LElemtype_Sq e);

#endif //C_PROJECT_03_MERGESQLIST_H
