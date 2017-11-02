//
// Created by yewmf on 2017/11/2.
//
/**
 *  ���ݣ�˳�����ز����б�
 */

#ifndef INC_1_SEQUENCELIST_SEQUENCELIST_H
#define INC_1_SEQUENCELIST_SEQUENCELIST_H



#include <stdio.h>
#include <stdlib.h> //�ṩmalloc��realloc��free��exitԭ��
#include "../0_Status/Status.h" //��������

/*�궨��*/
#define LIST_INIT_SIZE  100         //˳���洢�ռ�ĳ�ʼ������
#define LISTINCREMENT   10          //˳���洢�ռ�ķ�������

/*˳������Ͷ���*/
#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int LElemtype_Sq;
#endif

typedef struct{
    LElemtype_Sq *elem;             //�洢�ռ��ַ��ָ���һ������ָ�룩
    int length;                     //��˳�����
    int listSize;                   //��ǰ����Ĵ洢����
}SqList;                            //˳���0�ŵ�Ԫ����ʹ��

/***
 * ˳������б�
 */

//��ʼ����˳���
Status InitList_Sq(SqList *L);

//���˳���L
void ClearList_Sq(SqList *L);

//����˳���L
void DestroyList_Sq(SqList *L);

//�ж�˳���L�Ƿ�Ϊ��
Status ListEmpty_Sq(SqList L);

//����˳���L��Ԫ�ظ���
int ListLength_Sq(SqList L);

//��e����˳���L�еĵ�i��Ԫ��
Status GetElem_Sq(SqList L, int i, LElemtype_Sq *e);

//����˳���L���׸���e����Compare��ϵ��Ԫ��λ��
int LocateElem_Sq(SqList L, LElemtype_Sq e, Status(Compare)(LElemtype_Sq, LElemtype_Sq));

//��pre_e����cur_e��ǰ��
Status PriorElem_Sq(SqList L, LElemtype_Sq cur_e, LElemtype_Sq *pre_e);

//��next_e����cur_e�ĺ��
Status NextElem_Sq(SqList L, LElemtype_Sq cur_e, LElemtype_Sq *next_e);

//��˳���L�ĵ�i��λ���ϲ���e
Status ListInsert_Sq(SqList *L, int i, LElemtype_Sq e);

//ɾ��˳���L�ϵ�i��λ�õ�Ԫ�أ�����e����
Status ListDelete_Sq(SqList *L, int i, LElemtype_Sq *e);

//��visit��������˳���L
Status ListTraverse_Sq(SqList L, void(Visit)(LElemtype_Sq));

#endif //INC_1_SEQUENCELIST_SEQUENCELIST_H