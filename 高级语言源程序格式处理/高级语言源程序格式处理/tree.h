//
// tree.h
//
// Description
// ���պ��ӱ�ʾ��������һ������

#pragma once

#ifndef _TREE_H
#define _TREE_H

#include<stdio.h>

#define MAX_TREE_SIZE 100
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int TElemType;
// - - - - - ���ĺ�������洢��ʾ - - - - -
typedef struct CTNode		//���ӽ��
{
	int child;
	CTNode * next;
}*ChildPtr;
typedef struct
{
	TElemType data;
	ChildPtr firstchild;	//��������ͷ���
}CTBox;
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;				//������͸���λ��
}CTree;

Status InitTree(CTree & T);
Status CreateTree(CTree & T, TElemType);

#endif // !_TREE_H

