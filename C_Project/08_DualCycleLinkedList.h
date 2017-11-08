//
// Created by yewmf on 2017/11/8.
// 双向循环链表相关操作列表
//

#ifndef C_PROJECT_DUALCYCLELINKEDLIST_H
#define C_PROJECT_DUALCYCLELINKEDLIST_H

#include <stdlib.h>
#include "00_Status.h"

/**
 * 双循环链表类型定义
 */
typedef int LElemType_DC;
typedef struct DuLNode{
    LElemType_DC data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode;
typedef DuLNode* DuLinkList;            //指向双循环链表结构的指针

/**
 * 双循环链表函数列表
 */

/**
 * 初始化双链表L
 */
Status InitList_DuL(DuLinkList *L);

/**
 * 置空L
 */
Status ClearList_DuL(DuLinkList L);

/**
 * 销毁L
 */
void DestroyList_DuL(DuLinkList *L);

/**
 * 判断L是否为空
 */
Status ListEmpty_DuL(DuLinkList L);

/**
 * 返回L元素个数
 */
int ListLength_DuL(DuLinkList L);

/**
 * 用e接收L中第i个结点的元素值
 */
Status GetElem_DuL(DuLinkList L,int i, LElemType_DC *e);

/**
 * 返回L中第一个与e满足Compare关系的元素位序
 */
int LocateElem_DuL(DuLinkList L, LElemType_DC e ,Status(Compare)(LElemType_DC, LElemType_DC));

/**
 * 用pre_e接收cur_e的前驱
 */
Status PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *pre_e);

/**
 * 用next_e接收cur_e的后继
 */
Status NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *next_e);

/**
 * 返回L中指向第i个结点的指针
 */
DuLinkList GetElemPtr_DuL(DuLinkList L, int i);

/**
 * 在L的第i个位置之前插入e
 */
Status ListInsert_Dul(DuLinkList L, int i, LElemType_DC e);

/**
 *  删除L的第i个位置的值，并用e接收
 */
Status ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e);

/**
 * 用Visit函数访问L
 */
void ListTraverse_DuL(DuLinkList L, void(Visit)(LElemType_DC));

/**
 * 测试用例
 */
void testDualCycleLinkedList();


#endif //C_PROJECT_DUALCYCLELINKEDLIST_H
