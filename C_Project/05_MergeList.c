//
// Created by yewmf on 2017/11/8.
//

#ifndef C_PROJECT_05_MERGELIST_C
#define C_PROJECT_05_MERGELIST_C

#include "04_SinglyLinkedList.c"

/***
 * 单链表归并函数列表
 * C = A + B，且保持元素相对位置不变，
 * Lc利用La的头结点，Lb中结点均插入新链表Lc中
 */
void MergeList_L(LinkList La, LinkList *Lb, LinkList *Lc){

    LinkList  pa, pb, pc;

    pa = La->next;
    pb = (*Lb)->next;
    pc = *Lc = La;

    while (pa && pb){
        if(pa->data <= pb->data){
            pc->next = pa;//pc的结点也跟随这第三行代码，一直后移，不用管其中值的意义
            pc = pa;   //把La当前结点pa给pc（Lc），
            pa = pa->next;//pa结点后移一位
        } else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }

    pc->next = pa? pa : pb;

    free(*Lb);          //释放Lb的头结点
    *Lb = NULL;


}


void testMergeList_L(){

    LinkList  La, Lb, Lc;
    int  m;
    m = 5;

    printf("as a example , the length of La is %d, Lb is %d  \n", m, m);

    printf("put La : \n");
    CreateList_HL(&La, m);

    printf("put Lb : \n");
    CreateList_TL(&Lb, m);

    printf("La = ");
    ListTraverse_L(La, PrintElem);
    printf("\n");

    printf("Lb = ");
    ListTraverse_L(Lb, PrintElem);
    printf("\n");
    PressEnter;

    MergeList_L(La, &Lb, &Lc);
    printf("La + Lb = Lc : ");
    ListTraverse_L(Lc, PrintElem);
    printf("\n");
    PressEnter;
}

#endif //C_PROJECT_05_MERGELIST_C

