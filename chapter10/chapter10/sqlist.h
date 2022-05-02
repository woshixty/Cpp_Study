#pragma once
#ifndef _INC_SQLIST
#define _INC_SQLIST

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define LIST_INIT_SIZE 100  //��ʼ����ʱ��������
#define LISTINCREMENT 10  //��ʼ���������������ʱ�������
#define ERROR 0
#define OK 1

typedef int ElemType;
typedef int status;

typedef struct {
	ElemType* elem;//�洢�ռ����ַ
	int length;  //��ǰ���ȣ���Ԫ�ظ�����
	int listsize;//��ǰ����Ĵ洢����
}SqList;

status InitList_Sq(SqList& L);
status ListInsert(SqList& L, int i, ElemType e);
status ListDelet(SqList& L, int i);
int LocateElement(SqList L, ElemType e);
int ListLength(SqList L);//��ȡ����
status DislpList(SqList L);//��ʾ��
bool ListEmpty(SqList L);//�Ƿ�Ϊ��
status GetElem(SqList L, int i, ElemType& e);//ָ��λ��Ԫ��

#endif