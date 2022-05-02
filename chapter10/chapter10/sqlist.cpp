#include "sqlist.h"

status InitList_Sq(SqList& L) //����һ���ձ�
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));//�����ڴ�
	if (!L.elem) exit(ERROR);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

status ListInsert(SqList& L, int i, ElemType e) //���� һ�� Ԫ��
{
	int* q, * p;
	if (i<1 || i>(L.length + 1))return ERROR;//�ɲ����λ����length+1��
	if (L.length >= L.listsize)//�ڴ治�����˾�����LISTINCREMENT���ڴ�
	{
		L.elem = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!L.elem)exit(ERROR);
		L.listsize += LISTINCREMENT;
	}
	q = &(L.elem[i - 1]);
	for (p = &(L.elem[L.length]); p >= q; p--)
	{
		*(p + 1) = *p;
	}
	*q = e;
	L.length += 1;
	return OK;
}
status ListDelet(SqList& L, int i)
{
	int* q, * p, e;
	if (i<1 || i>L.length)return ERROR;//����
	e = L.elem[i - 1];  //����Ҫɾ����Ԫ��
	q = L.elem + L.length - 1 - 1;//ɾ�����β��   L.elem + L.length - 1��ɾ��ǰ���һ��Ԫ�ص��±꣬�ڼ�һ��ɾ��������һ��Ԫ���±�
	for (p = &L.elem[i - 1]; p <= q; p++)
	{
		*p = *(p + 1);
	}
	L.length -= 1;
	return OK;
}

int LocateElement(SqList L, ElemType e)//��λ����Ԫ��
{
	int i = 1;
	while (i <= L.length)
	{
		if (L.elem[i - 1] == e)return i;
		i++;
	}
	return 0;
}

int ListLength(SqList L)//��ȡ����
{
	return L.length;
}
status DislpList(SqList L)//��ʾ��
{
	int i = 0;
	for (i = 0; i < L.length; i++)
	{
		printf("%d  ", L.elem[i]);
	}
	return OK;
}
bool ListEmpty(SqList L)//�Ƿ�Ϊ��
{
	if (L.length == 0)
		return true;
	else
		return false;
}

status GetElem(SqList L, int i, ElemType& e)//ָ��λ��Ԫ��
{
	e = L.elem[i - 1];
	return OK;
}