//
// tree.h
//
// Description
// ���պ��ӱ�ʾ��������һ������

#pragma once

#ifndef _TREE_H
#define _TREE_H

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MAX_TREE_SIZE 100
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char * TElemType;
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
}CTree, *CTreePtr;

Status InitTree(CTreePtr & T);
Status InsertChild(CTreePtr & T, int p, int i, CTreePtr c);

#endif // !_TREE_H

