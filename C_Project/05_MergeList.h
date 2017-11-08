//
// Created by yewmf on 2017/11/8.
//

#ifndef C_PROJECT_05_MERGELIST_H
#define C_PROJECT_05_MERGELIST_H

#include "04_SinglyLinkedList.c"

/***
 * 单链表归并函数列表
 * C = A + B，且保持元素相对位置不变，
 * Lc利用La的头结点，Lb中结点均插入新链表Lc中
 */
void MergeList_L(LinkList La, LinkList *Lb, LinkList *Lc);

void testMergeList_L();

#endif //C_PROJECT_05_MERGELIST_H
