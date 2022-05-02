#include "sqlist.h"

int main()
{
	int e;
	SqList L;
	InitList_Sq(L);
	printf("ListEmpty(L): %d\n", ListEmpty(L));
	ListInsert(L, 1, 22);
	printf("ListInsert(L, 1, 22)\n");
	ListInsert(L, 2, 23);
	printf("ListInsert(L, 2, 23)\n");
	ListInsert(L, 3, 26);
	printf("ListInsert(L, 3, 26)\n");
	ListInsert(L, 4, 287);
	printf("ListInsert(L, 4, 287)\n");
	printf("ListEmpty(L): %d\n", ListEmpty(L));
	DislpList(L);
	printf("\nListLength(L): %d\n", ListLength(L));
	printf("LocateElement(L, 23): %d\n", LocateElement(L, 23));
	ListDelet(L, 4);
	ListDelet(L, 1);
	DislpList(L);
	printf("\nLocateElement(L, 23): %d\n", LocateElement(L, 23));
	GetElem(L, 1, e);
	printf("GetElem(L, 1, e): %d\n", e);
	return 0;
}