//
// Created by yewmf on 2017/11/6.
//

#ifndef SINGLEYLINKEDLIST_C
#define SINGLEYLINKEDLIST_C

#include "04_SinglyLinkedList.h"

//初始化单链表L
Status InitList_L(LinkList *L){

    (*L) = (LinkList)malloc(sizeof(LNode));
    if(!(*L)){
        exit(OVERFLOW);
    }
    (*L)->next = NULL;

    return OK;

}

//置空单链表L，头节点保留
Status ClearList_L(LinkList L){

    LinkList pre, p;

    if(!L){
        return  ERROR;
    }

    pre = L->next;

    while (pre){
        p = pre->next;
        free(pre);
        pre = p;
    }

    L->next = NULL;

    return OK;
}

//销毁单链表L，连同节点一起销毁
void DestroyList_L(LinkList *L){

    LinkList p = *L;

    while (p){
        p = (*L)->next;
        free(*L);
        (*L) = p;
    }

}

//判断单链表L是否为空。
Status ListEmpty_L(LinkList L){

    if(L!= NULL && L->next == NULL){    //链表存在且只有头结点
        return TRUE;
    } else{
        return FALSE;
    }

}

//返回单链表L元素个数
int ListLength_L(LinkList L){

    LinkList p;
    int i;

    if(L){

        i = 0;
        p = L->next;

        while (p){
            i++;
            p = p->next;
        }
    }

    return i;

}

//用e接收单链表L中第i个元素
Status GetElem_L(LinkList L, int i, LElemType_L *e){

    int j;
    LinkList p;

    j = 1;
    p = L->next;

    while (p && j < i){
        //p不为空且还未到达i处

        j++;
        p = p->next;
    }

    if(!p || j > i){
        //第i个元素不存在
        return ERROR;
    }

    *e = p->data;

    return OK;

}

//返回单链表L中第一个与e满足Compare关系的元素位序
int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L)){

    int i;
    LinkList p;

    i = -1;             //L不存在时返回-1
    if(L){
        i = 0;
        p = L->next;

        while (p){
            i++;
            if(!Compare(e, p->data)){
                p = p->next;
            }else{
                break;
            };
        }
    }

    return i;

}

//用pre_e接收cur_e的前驱
Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e){

    LinkList p, suc;

    if(L){
        p = L->next;

        //第一个结点无前驱
        if(p->data!=cur_e){

            //若p结点有后继
            while (p->next){
                //suc指向p的后继
                suc = p->next;
                if(suc->data==cur_e){
                    *pre_e = p->data;
                    return OK;
                }
                p == suc;

            }

        }
    }

    return ERROR;

}

//用next_e接收cur_e的后继
Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e){

    LinkList p, suc;

    if(L){
        p = L->next;

        while (p && p->next){
            suc = p->next;

            if(suc && p->data == cur_e){
                *next_e = suc->data;
                return OK;
            }

            if(suc){
                p = suc;
            } else{
                break;
            }
        }
    }

    return ERROR;

}

//在单链表L第i个位置之前插入e
Status ListInsert_L(LinkList L, int i, LElemType_L e){

    LinkList p,s;
    int j;

    p = L;
    j = 0;

    while(p && j< i-1){
        //寻找第i-1个结点
        p = p->next;
        ++j;
    }

    if(!p || j< i-1){
        return ERROR;
    }

    s = (LinkList)malloc(sizeof(LNode));
    if(!s){
        exit(OVERFLOW);
    }

    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;

}

//删除单链表L第i个位置的值，并用e接收
Status ListDelete_L(LinkList L, int i , LElemType_L *e){

    LinkList pre,p;
    int j;

    pre = L;
    j = 1;
    while (pre->next && j < i){
        //寻找第i个结点，并令pre指向其前驱
        pre = pre->next;
        ++j;
    }

    if(!pre->next || j > i){
        //删除位置不合理
        return ERROR;
    }

    p = pre->next;
    pre->next = p->next;
    *e = p->data;
    free(p);

    return OK;

}

//用Visit函数访问单链表L
Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L)){

    LinkList p;
    if(!L){
        return ERROR;
    } else{
        p = L->next;
    }

    while (p){
        Visit(p->data);
        p = p->next;
    }

    return OK;

}

//头插法建立 单链表（逆序输入）
Status CreateList_HL(FILE *fp, LinkList *L, int n){

    int i;
    LinkList p;
    LElemType_L tmp;

    //建立头结点
    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L)){
        exit(OVERFLOW);
    }
    (*L)->next = NULL;

    for (int i = 1; i < n; ++i) {

//        if(scanf(fp, "%d", &tmp)== 1){
//            p = (LinkList)malloc(sizeof(LNode));
//            if(!p){
//                exit(OVERFLOW);
//            }
//
//            p->data = tmp;
//            p->next = (*L)->next;
//            (*L)->next = p;
//        } else{
//            return ERROR;
//        }
    }

    return OK;
}


//尾插法建立单链表L（顺序输入）
Status CreateList_TL(FILE *fp , LinkList *L, int n){

    int i;
    LinkList p, q;
    LElemType_L tmp;

    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L)){
        exit(OVERFLOW);
    }
    (*L)->next = NULL;

    for(i = 1, q = *L; i <= n; ++i){
//        if(scanf(fp, "%d", &tmp)== 1){
//            p = (LinkList)malloc(sizeof(LNode));
//            if(!p){
//                exit(OVERFLOW);
//            }
//            p->data = tmp;
//            q->next = p;
//            q = q->next;
//        } else{
//            return ERROR;
//        }
    }

    q->next = NULL;

    return OK;
}


//判断data是否大于e，若data大于e，返回TRUE
Status CmpGreater(LElemType_L e, LElemType_L data){

    return data>e? TRUE: FALSE;

}

//测试函数，打印整型
void PrintElem(LElemType_L e){

    printf("%d ", e);

}

void testSinglyLinkedList(){
    LinkList L;
    int i ;
    LElemType_L e;

    printf("1.InitList_L fun test....");
    {
        printf("initList L ...");
        InitList_L(&L);
        printf("\n");
    }
    PressEnter;

    printf("4. ListEmpty_L fun test..");
    {
        ListEmpty_L(L)? printf("L is Empty!\n"): printf("L not empty!\n");
        printf("\n");
    }
    PressEnter;

    printf("10. ListInsert_L fun test...\n");
    {
        for (int i = 1; i <= 6; i++) {
            printf("Insert %d in the %d position of the L\n", 2*i, i);
            ListInsert_L(L, i, i * 2);
        }
    }
    PressEnter;

    ListTraverse_L(L, PrintElem);


}

#endif