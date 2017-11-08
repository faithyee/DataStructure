//
// Created by yewmf on 2017/11/8.
//静态链表相关操作列表
//

#ifndef C_PROJECT_06_STATICLINKEDLIST_H
#define C_PROJECT_06_STATICLINKEDLIST_H

#include <stdlib.h>
#include "00_Status.h"

#define MAXSIZE 1000            //静态链表的最大长度

/***
 * 静态链表类型定义
 */
typedef int SLinkList;          //静态链表类型
typedef int LElemType_s;
typedef struct {
    LElemType_s data;
    int cur;                    //cur是游标，做指针用，区别与数组下标
}Component[MAXSIZE];

/***
 * 全局变量
 */
Component SPACE;                //静态链表空间

/**
 * 将一维数组SPACE中各分量链成一个大的备用空间。
 */
void InitSpace_SL();

/**
 * 为插入数据申请空间
 * @return
 */
int Malloc_SL();

/**
 * 将下标为k的空闲结点回收
 */
void Free_SL(int k);

/**
 * 初始化静态链表，建立头结点
 */
int InitList_SL(SLinkList *H);

/**
 * 置空
 */
Status ClearList_SL(SLinkList H);

/**
 * 销毁
 */
void DestroyList_SL(SLinkList *H);

/**
 * 判空
 */
Status  ListEmpty_SL(SLinkList H);

/**
 * 求长
 */
int ListLength_SL(SLinkList H);

/**
 * 取值
 */
Status GetElem_SL(SLinkList H, int i, LElemType_s *e);

/**
 * 返回元素e的位序
 */
int LocateElem_SL(SLinkList H, LElemType_s e);

/**
 * 前驱
 */
Status PriorElem_SL(SLinkList H, LElemType_s cur_e, LElemType_s *pre_e);

/**
 * 后继
 */
Status NextElem_SL(SLinkList H, LElemType_s cur_e, LElemType_s *next_e);

/**
 * 插入
 */
Status ListInsert_SL(SLinkList H, int i, LElemType_s e);

/**
 * 删除
 */
Status ListDelete_SL(SLinkList H, int i , LElemType_s *e);

/**
 * 访问
 */
Status ListTraverse_SL(SLinkList H, void(Visit)(LElemType_s));

/**
 * 测试用例
 */
void testStaticLinkedList();

#endif //C_PROJECT_06_STATICLINKEDLIST_H


