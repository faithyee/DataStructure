//
// Created by yewmf on 2017/11/8.
//

#ifndef STATICLINKEDLIST_C
#define STATICLINKEDLIST_C

#include "06_StaticLinkedList.h"

/**
 * 将一维数组SPACE中各分量链成一个大的备用空间。
 */
void InitSpace_SL();

/**
 * 为插入数据申请空间
 * @return
 */
int Malloc_SL(){
    //todo malloc_sl
}

/**
 * 将下标为k的空闲结点回收
 */
void Free_SL(int k){
    //todo free_sl
}

/**
 * 初始化静态链表，建立头结点
 */
int InitList_SL(SLinkList *H){
    //todo initList_sl
}

/**
 * 置空
 */
Status ClearList_SL(SLinkList H){
    //todo clearList_sl
}

/**
 * 销毁
 */
void DestroyList_SL(SLinkList *H){
    //todo destroylist_sl
}

/**
 * 判空
 */
Status  ListEmpty_SL(SLinkList H){
    //todo  listempty_sl
}

/**
 * 求长
 */
int ListLength_SL(SLinkList H){
    //todo listlength_sl
}

/**
 * 取值
 */
Status GetElem_SL(SLinkList H, int i, LElemType_s *e){
    //todo getelem_sl
}

/**
 * 返回元素e的位序
 */
int LocateElem_SL(SLinkList H, LElemType_s e){
    //todo locateElem_sl
}

/**
 * 前驱
 */
Status PriorElem_SL(SLinkList H, LElemType_s cur_e, LElemType_s *pre_e){
    //todo priorElem_sl
}

/**
 * 后继
 */
Status NextElem_SL(SLinkList H, LElemType_s cur_e, LElemType_s *next_e){
    //todo nextElem_sl
}

/**
 * 插入
 */
Status ListInsert_SL(SLinkList H, int i, LElemType_s e){
    //todo listinsert_sl
}

/**
 * 删除
 */
Status ListDelete_SL(SLinkList H, int i , LElemType_s *e){
    //todo listdelete_sl
}

/**
 * 访问
 */
Status ListTraverse_SL(SLinkList H, void(Visit)(LElemType_s)){
    //todo listTraverse_sl
}

/**
 * 测试用例
 */
void testStaticLinkedList(){
    //todo test
}

#endif//STATICLINKEDLIST_C



