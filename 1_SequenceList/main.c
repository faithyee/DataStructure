
#include <stdio.h>
#include "SequenceList.h"

/* 测试调用的函数原型 */
Status CmpGreater(LElemtype_Sq e, LElemtype_Sq data); // 若data > e ，返回TRUE，否则返回


int main() {
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