//
// Created by yewmf on 2017/11/8.
// 在一堆数组中建立集合(A-B)U(B-A)
//

#ifndef C_PROJECT_07_DIFFERENCE_H
#define C_PROJECT_07_DIFFERENCE_H

#include <stdio.h>
#include "00_Status.h"
#include "06_StaticLinkedList.c"

/**
 * 在一堆数组中建立集合(A-B)U(B-A)
 */
void difference(SLinkList *S, LElemType_s A[], int len_A, LElemType_s B[], int len_B);

void testDifference();

#endif //C_PROJECT_07_DIFFERENCE_H
