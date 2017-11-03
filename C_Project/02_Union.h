//
// Created by yewmf on 2017/11/3.
//

/**
 * 求并集相关操作列表
 * */

#ifndef INC_1_SEQUENCELIST_UNION_H
#define INC_1_SEQUENCELIST_UNION_H

#include "01_SequenceList.c"

/* 并集函数列表 */
void Union(SqList *La, SqList Lb);

Status equal(LElemtype_Sq e1, LElemtype_Sq e2);

void testUnion();

#endif

