
#include <stdio.h>
#include "SequenceList.h"

/* ���Ե��õĺ���ԭ�� */
Status CmpGreater(LElemtype_Sq e, LElemtype_Sq data); // ��data > e ������TRUE�����򷵻�


int main() {
    SqList L;
    LElemtype_Sq e;
    LElemtype_Sq pre_e;
    LElemtype_Sq next_e;

    InitList_Sq(&L);

    for (int i = 1; i <= 10; ++i) {
        ListInsert_Sq(&L, i, i + 2);
    }

    ListEmpty_Sq(L) == TRUE ? printf("Ϊ��\n") : printf("��Ϊ��\n");
//    ClearList_Sq(&L);
    ListEmpty_Sq(L) == TRUE ? printf("Ϊ��\n") : printf("��Ϊ��\n");

    printf("����compare�����ĵ�ǰ�����ڵ� %d ��λ��\n", LocateElem_Sq(L, 4, CmpGreater));

    GetElem_Sq(L, 4, &e);
    printf("��λ�õ�����Ϊ%d \n",e);
    PriorElem_Sq(L, 7, &pre_e);
    printf("��ǰλ��Ԫ�ص�ǰ��Ϊ %d \n", pre_e);

    NextElem_Sq(L, 7, &next_e);
    printf("��ǰλ��Ԫ�صĺ��Ϊ %d \n", next_e);
    return 0;
}

Status CmpGreater(LElemtype_Sq e, LElemtype_Sq data) {
    return data > e ? TRUE : FALSE;
}