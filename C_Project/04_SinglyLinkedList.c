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
                p = suc;
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
/**
 * 插入逻辑，即通过指针定位，定位到要插入的位置的前一个结点，通过前一个结点
 * 来把要插入的第i个结点接到（找到的i-1）结点的后面。
 */
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

    //结点插入逻辑,在i-1的后面插入新结点s
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

    p = pre->next;//定位到pre的后一个结点
    pre->next = p->next;//删除pre后的结点
    *e = p->data;//返回pre后的结点的值
    free(p);//清空删除的结点

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
        Visit(p->data);//打印结构里的值
        p = p->next;//链表遍历
    }

    return OK;

}

//头插法建立 单链表（逆序输入）
Status CreateList_HL(LinkList *L, int n){

    int i;
    LinkList p;
    LElemType_L tmp;

    //建立头结点
    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L)){
        exit(OVERFLOW);
    }
    (*L)->next = NULL;

    for (int i = 1; i <= n; ++i) {

        scanf("%d", &tmp);
        if(tmp != 1){

            p = (LinkList)malloc(sizeof(LNode));
            if(!p){
                exit(OVERFLOW);
            }

            p->data = tmp;
            p->next = (*L)->next;
            (*L)->next = p;
        } else{
            return ERROR;
        }
    }

    return OK;
}


//尾插法建立单链表L（顺序输入）
Status CreateList_TL(LinkList *L, int n){

    int i;
    LinkList p, q;
    LElemType_L tmp;

    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L)){
        exit(OVERFLOW);
    }
    (*L)->next = NULL;

    for(i = 1, q = *L; i <= n; ++i){
        scanf("%d", &tmp);
        if(tmp != 1){
            p = (LinkList)malloc(sizeof(LNode));
            if(!p){
                exit(OVERFLOW);
            }
            p->data = tmp;
            q->next = p;
            q = q->next;
        } else{
            return ERROR;
        }
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


    printf("12. ListTraverse_L fun test...\n");
    {
        printf("L List is : ");
        ListTraverse_L(L, PrintElem);
        printf("\n");
    }
    PressEnter;

    printf("5. ListLength_L fun test...\n");
    {
        printf("the length of L is : %d \n", ListLength_L(L));
        printf("\n");
    }
    PressEnter;

    printf("11. ListDelete_L fun test...\n");
    {
        ListDelete_L(L, 6, &e);
        printf("the %d th of the element %d is deleted on L \n", 6, e);
        printf("The new L List is : ");
        ListTraverse_L(L, PrintElem);
        printf("\n");
    }
    PressEnter;

    printf("6. GetElem_L fun test...\n");
    {
        GetElem_L(L, 4, &e);
        printf("the %d th element is %d on L \n", 4, e);
        printf("\n");
    }
    PressEnter;

    printf("7. LocateElem_L fun test...\n");
    {
        i = LocateElem_L(L, 7, CmpGreater);
        printf("the element of the first bigger than 7 is in %dth place \n", i);
        printf("\n");
    }
    PressEnter;

    printf("8. PriorElem_L fun test...\n");
    {
        PriorElem_L(L, 6, &e);
        printf("the prior element of the element 6 is %d \n", e);
        printf("\n");
    }
    PressEnter;

    printf("9. NextElem_L fun test...\n");
    {
        NextElem_L(L, 6, &e);
        printf("the next element of the element 6 is %d \n", e);
        printf("\n");
    }
    PressEnter;

    printf("2. ClearList_L fun test...\n");
    {
        printf("L List before clear : \n");
        ListEmpty_L(L)? printf("L is Empty!\n"): printf("L is not empty!\n");
        ClearList_L(L);
        printf("L List after clear : \n");
        ListEmpty_L(L)? printf("L is Empty!\n"): printf("L is not empty!\n");
        printf("\n");
    }
    PressEnter;

    printf("3. DestroyList_L fun test...\n");
    {
        printf("L List before destroy : \n");
        L? printf("L is exist!\n"): printf("L is not exist!\n");
        DestroyList_L(&L);
        printf("L List after destroy : \n");
        L? printf("L is exist!\n"): printf("L is not exist!\n");
        printf("\n");
    }
    PressEnter;

    printf("13. CreateList_HL fun test...\n");
    {
        LinkList HL;
        printf("Building L list by head-inserting method : \n");
        CreateList_HL(&HL, 5);
        printf("the created HL List is : \n");
        ListTraverse_L(HL, PrintElem);
        printf("\n");
    }
    PressEnter;

    printf("14. CreateList_TL fun test...\n");
    {
        LinkList TL;
        printf("Building L list by tail-inserting method : \n");
        CreateList_TL(&TL, 5);
        printf("the created TL List is : \n");
        ListTraverse_L(TL, PrintElem);
        printf("\n");
    }
    PressEnter;


}

#endif