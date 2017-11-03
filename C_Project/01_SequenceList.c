//
// Created by yewmf on 2017/11/2.
//

#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "01_SequenceList.h"

/* ���Ե��õĺ���ԭ�� */
Status CmpGreater(LElemtype_Sq e, LElemtype_Sq data); // ��data > e ������TRUE�����򷵻�

//��ʼ����˳���
Status InitList_Sq(SqList *L){

    (*L).elem = (LElemtype_Sq*)malloc(LIST_INIT_SIZE* sizeof(LElemtype_Sq));
    if(!(*L).elem){
        printf("��ʼ������Lʧ��\n");
        exit(OVERFLOW);
    }

    (*L).length = 0;
    (*L).listSize = LIST_INIT_SIZE;
    printf("��ʼ������L�ɹ�\n");
    return OK;
}

//ɾ��˳���L�ϵ�i��λ�õ�Ԫ�أ�����e����
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

//��visit��������˳���L
Status ListTraverse_Sq(SqList L, void(Visit)(LElemtype_Sq)){

    int i;

    for(int i = 0; i< L.length; i++){
        Visit(L.elem[i]);
    }

    return OK;
}

//��˳���L�ĵ�i��λ���ϲ���e
Status ListInsert_Sq(SqList *L, int i, LElemtype_Sq e){
    //���� �µ����Ա�Ŀռ䣬���ڿ����µ����Ա������ռ�
    LElemtype_Sq *newBase;

    //���� �������������ָ��������ƶ�λ�õ�ָ��
    LElemtype_Sq *q, *p;

    //�ж������i�Ƿ�����߼�
    if(i < 1 || i > (*L).length+1){
        printf("������±겻�����߼�\n");
        return ERROR;

    }

    //�ж�˳���Ĵ洢�ռ��Ƿ��Ѿ����ˣ�����Ҫ�����¿ռ�
    if((*L).length >= (*L).listSize){
        newBase = (LElemtype_Sq*)realloc((*L).elem, ((*L).listSize+LISTINCREMENT)*sizeof(LElemtype_Sq));
        if(!newBase){
            printf("����ռ�ʧ��\n");
            exit(OVERFLOW);
        }

        (*L).elem = newBase;
        (*L).listSize += LISTINCREMENT;
        printf("����ռ�ɹ�\n");
    }


    //ָ�붨λ�������λ��
    q = &(*L).elem[i - 1];

    //ָ�뿪ʼ�Ӻ���ǰ�ƶ�Ԫ��(ǰһ��Ԫ�ظ���һ��Ԫ�ظ�ֵ)
    for(p = &(*L).elem[(*L).length - 1]; p >= q ; --p){
        *(p + 1) = *p;
    }

    //����Ԫ��
    *q = e;
    printf("�ɹ����� %d \n", *q);

    //����1
    (*L).length++;
    printf("��ǰ�� %d \n", (*L).length);

    return OK;
}

//���˳���L
void ClearList_Sq(SqList *L){
    (*L).length = 0;
    printf("����ɹ�\n");
}

//����˳���L
void DestroyList_Sq(SqList *L){

    free((*L).elem);

    (*L).elem = NULL;
    (*L).length = 0;
    (*L).listSize = 0;

}

//�ж�˳���L�Ƿ�Ϊ��
Status ListEmpty_Sq(SqList L){
    return L.length == 0? TRUE : FALSE;
}

//����˳���L��Ԫ�ظ���
int ListLength_Sq(SqList L){
    return L.length;
}

//����˳���L���׸���e����Compare��ϵ��Ԫ��λ��
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

//��e����˳���L�еĵ�i��Ԫ��
Status GetElem_Sq(SqList L, int i, LElemtype_Sq *e){
    if(i < 1 || i > L.length){
        return ERROR;
    } else{
        *e = L.elem[i - 1];
        printf("ȡ��%d��Ԫ�أ�",i);
        return TRUE;
    }
}


//��pre_e����cur_e��ǰ��
Status PriorElem_Sq(SqList L, LElemtype_Sq cur_e, LElemtype_Sq *pre_e){

    int i = 1;
    LElemtype_Sq  e;

    if(L.elem[0] != cur_e){     //��һ���ڵ���ǰ��

        //����
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

//��next_e����cur_e�ĺ��
Status NextElem_Sq(SqList L, LElemtype_Sq cur_e, LElemtype_Sq *next_e){

    int i = 1 ;

    while (i < L.length && L.elem[i] != cur_e){
        ++i;
    }

    if(i < L.length -1){        //���һ���ڵ��޺��
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

#endif
