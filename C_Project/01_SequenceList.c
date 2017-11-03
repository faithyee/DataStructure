//
// Created by yewmf on 2017/11/2.
//

#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "01_SequenceList.h"

/* 测试调用的函数原型 */
Status CmpGreater(LElemtype_Sq e, LElemtype_Sq data); // 若data > e ，返回TRUE，否则返回

//初始化空顺序表
Status InitList_Sq(SqList *L){

    (*L).elem = (LElemtype_Sq*)malloc(LIST_INIT_SIZE* sizeof(LElemtype_Sq));
    if(!(*L).elem){
        printf("初始化链表L失败\n");
        exit(OVERFLOW);
    }

    (*L).length = 0;
    (*L).listSize = LIST_INIT_SIZE;
    printf("初始化链表L成功\n");
    return OK;
}

//删除顺序表L上第i个位置的元素，并用e返回
Status ListDelete_Sq(SqList *L, int i, LElemtype_Sq *e){

    LElemtype_Sq  *p, *q;

    if(i < 1 || i > (*L).length){
        return ERROR;
    }

    p = &(*L).elem[i - 1];
    *e = *p;
    q = (*L).elem + (*L).length-1;

    for(++p; p <= q; ++p){
        *(p-1) = *p;
    }

    (*L).length;

    return OK;

}

//用visit函数访问顺序表L
Status ListTraverse_Sq(SqList L, void(Visit)(LElemtype_Sq)){

    int i;

    for(int i = 0; i< L.length; i++){
        Visit(L.elem[i]);
    }

    return OK;
}

//在顺序表L的第i个位置上插入e
Status ListInsert_Sq(SqList *L, int i, LElemtype_Sq e){
    //定义 新的线性表的空间，用于开辟新的线性表容量空间
    LElemtype_Sq *newBase;

    //定义 用来插入输入的指针和用来移动位置的指针
    LElemtype_Sq *q, *p;

    //判断输入的i是否符合逻辑
    if(i < 1 || i > (*L).length+1){
        printf("输入的下标不符合逻辑\n");
        return ERROR;

    }

    //判断顺序表的存储空间是否已经满了，按需要开辟新空间
    if((*L).length >= (*L).listSize){
        newBase = (LElemtype_Sq*)realloc((*L).elem, ((*L).listSize+LISTINCREMENT)*sizeof(LElemtype_Sq));
        if(!newBase){
            printf("申请空间失败\n");
            exit(OVERFLOW);
        }

        (*L).elem = newBase;
        (*L).listSize += LISTINCREMENT;
        printf("申请空间成功\n");
    }


    //指针定位到插入的位置
    q = &(*L).elem[i - 1];

    //指针开始从后往前移动元素(前一个元素给后一个元素赋值)
    for(p = &(*L).elem[(*L).length - 1]; p >= q ; --p){
        *(p + 1) = *p;
    }

    //插入元素
    *q = e;
    printf("成功插入 %d \n", *q);

    //表长加1
    (*L).length++;
    printf("当前表长 %d \n", (*L).length);

    return OK;
}

//清空顺序表L
void ClearList_Sq(SqList *L){
    (*L).length = 0;
    printf("清除成功\n");
}

//销毁顺序表L
void DestroyList_Sq(SqList *L){

    free((*L).elem);

    (*L).elem = NULL;
    (*L).length = 0;
    (*L).listSize = 0;

}

//判断顺序表L是否为空
Status ListEmpty_Sq(SqList L){
    return L.length == 0? TRUE : FALSE;
}

//返回顺序表L中元素个数
int ListLength_Sq(SqList L){
    return L.length;
}

//返回顺序表L中首个与e满足Compare关系的元素位序
int LocateElem_Sq(SqList L, LElemtype_Sq e, Status(Compare)(LElemtype_Sq, LElemtype_Sq)){

    int i = 1;

    while( i <= L.length && !Compare(e, L.elem[i - 1])){
        ++i;
    }

    if(i <= L.length){
        return i;
    } else{
        return 0;
    }

}

//用e接收顺序表L中的第i个元素
Status GetElem_Sq(SqList L, int i, LElemtype_Sq *e){
    if(i < 1 || i > L.length){
        return ERROR;
    } else{
        *e = L.elem[i - 1];
        printf("取第%d个元素，",i);
        return TRUE;
    }
}


//用pre_e接收cur_e的前驱
Status PriorElem_Sq(SqList L, LElemtype_Sq cur_e, LElemtype_Sq *pre_e){

    int i = 1;
    LElemtype_Sq  e;

    if(L.elem[0] != cur_e){     //第一个节点无前驱

        //遍历
        while (i < L.length && L.elem[i] != cur_e){
            ++i;
        }

        if(i < L.length){
            *pre_e = L.elem[i - 1];
            return OK;
        }

    }

    return ERROR;

}

//用next_e接收cur_e的后继
Status NextElem_Sq(SqList L, LElemtype_Sq cur_e, LElemtype_Sq *next_e){

    int i = 1 ;

    while (i < L.length && L.elem[i] != cur_e){
        ++i;
    }

    if(i < L.length -1){        //最后一个节点无后继
        *next_e = L.elem[i + 1];
        return OK;
    }

    return ERROR;

}

void testSequenceList(){
    SqList L;
    LElemtype_Sq e;
    LElemtype_Sq pre_e;
    LElemtype_Sq next_e;

    InitList_Sq(&L);

    for (int i = 1; i <= 10; ++i) {
        ListInsert_Sq(&L, i, i + 2);
    }

    ListEmpty_Sq(L) == TRUE ? printf("为空\n") : printf("不为空\n");
//    ClearList_Sq(&L);
    ListEmpty_Sq(L) == TRUE ? printf("为空\n") : printf("不为空\n");

    printf("满足compare条件的当前数据在第 %d 个位置\n", LocateElem_Sq(L, 4, CmpGreater));

    GetElem_Sq(L, 4, &e);
    printf("该位置的数据为%d \n",e);
    PriorElem_Sq(L, 7, &pre_e);
    printf("当前位置元素的前驱为 %d \n", pre_e);

    NextElem_Sq(L, 7, &next_e);
    printf("当前位置元素的后继为 %d \n", next_e);
    return 0;
}

Status CmpGreater(LElemtype_Sq e, LElemtype_Sq data) {
    return data > e ? TRUE : FALSE;
}

#endif
