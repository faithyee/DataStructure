//
// Created by yewmf on 2017/11/2.
//
/**
 *  内容：顺序表相关操作列表
 */

#ifndef INC_1_SEQUENCELIST_SEQUENCELIST_H
#define INC_1_SEQUENCELIST_SEQUENCELIST_H



#include <stdio.h>
#include <stdlib.h> //提供malloc、realloc、free、exit原型
#include "../0_Status/Status.h" //绪论内容

/*宏定义*/
#define LIST_INIT_SIZE  100         //顺序表存储空间的初始分配量
#define LISTINCREMENT   10          //顺序表存储空间的分配增量

/*顺序表类型定义*/
#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int LElemtype_Sq;
#endif

typedef struct{
    LElemtype_Sq *elem;             //存储空间基址（指向第一个借点的指针）
    int length;                     //当顺序表长度
    int listSize;                   //当前分配的存储容量
}SqList;                            //顺序表0号单元正常使用

/***
 * 顺序表函数列表
 */

//初始化空顺序表
Status InitList_Sq(SqList *L);

//清空顺序表L
void ClearList_Sq(SqList *L);

//销毁顺序表L
void DestroyList_Sq(SqList *L);

//判断顺序表L是否为空
Status ListEmpty_Sq(SqList L);

//返回顺序表L中元素个数
int ListLength_Sq(SqList L);

//用e接收顺序表L中的第i个元素
Status GetElem_Sq(SqList L, int i, LElemtype_Sq *e);

//返回顺序表L中首个与e满足Compare关系的元素位序
int LocateElem_Sq(SqList L, LElemtype_Sq e, Status(Compare)(LElemtype_Sq, LElemtype_Sq));

//用pre_e接收cur_e的前驱
Status PriorElem_Sq(SqList L, LElemtype_Sq cur_e, LElemtype_Sq *pre_e);

//用next_e接收cur_e的后继
Status NextElem_Sq(SqList L, LElemtype_Sq cur_e, LElemtype_Sq *next_e);

//在顺序表L的第i个位置上插入e
Status ListInsert_Sq(SqList *L, int i, LElemtype_Sq e);

//删除顺序表L上第i个位置的元素，并用e返回
Status ListDelete_Sq(SqList *L, int i, LElemtype_Sq *e);

//用visit函数访问顺序表L
Status ListTraverse_Sq(SqList L, void(Visit)(LElemtype_Sq));

#endif //INC_1_SEQUENCELIST_SEQUENCELIST_H