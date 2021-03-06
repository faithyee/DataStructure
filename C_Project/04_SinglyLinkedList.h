//
//  单链表相关操作列表
// Created by yewmf on 2017/11/6.
//

#ifndef C_PROJECT_04_SINGLYLINKEDLIST_H
#define C_PROJECT_04_SINGLYLINKEDLIST_H


#include "00_Status.h"
#include <stdlib.h>
#include <stdio.h>

/***
 * 单链表类型定义
 */
#ifndef BANKQUEUING_H
typedef int LElemType_L;

/***
 * 单链表结构体
 */
typedef struct LNode{
    LElemType_L data;
    struct LNode* next;
}LNode;
typedef LNode* LinkList;        //指向单链表节点的指针
#endif

/***
 * 单链表（带头结点）函数列表
 */

//初始化单链表L
Status InitList_L(LinkList *L);

//置空单链表L，头节点保留
Status ClearList_L(LinkList L);

//销毁单链表L，连同节点一起销毁
void DestroyList_L(LinkList *L);

//判断单链表L是否为空。
Status ListEmpty_L(LinkList L);

//返回单链表L元素个数
int ListLength_L(LinkList L);

//用e接收单链表L中第i个元素
Status GetElem_L(LinkList L, int i, LElemType_L *e);

//返回单链表L中第一个与e满足Compare关系的元素位序
int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L));

//用pre_e接收cur_e的前驱
Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e);

//用next_e接收cur_e的后继
Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e);

//在单链表L第i个位置之前插入e
Status ListInsert_L(LinkList L, int i, LElemType_L e);

//删除单链表L第i个位置的值，并用e接收
Status ListDelete_L(LinkList L, int i , LElemType_L *e);

//用Visit函数访问单链表L
Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L));

//头插法建立 单链表（逆序输入）
Status CreateList_HL(LinkList *L, int n);

//尾插法建立单链表L（顺序输入）
Status CreateList_TL(LinkList *L, int n);


//判断data是否大于e，若data大于e，返回TRUE
Status CmpGreater(LElemType_L e, LElemType_L data);

//测试函数，打印整型
void PrintElem(LElemType_L e);

//测试用例
void testSinglyLinkedList();

#endif //C_PROJECT_04_SINGLYLINKEDLIST_H
