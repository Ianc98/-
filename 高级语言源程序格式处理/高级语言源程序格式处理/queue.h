//
// queue.h
//
// Description
// ������һ�������С�

#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int QElemType;	//����Ԫ������
typedef int Status;
// - - - - - �������С������е���ʽ�洢�ṹ - - - - -
typedef struct QNode
{
	QElemType data;
	QNode * next;
}QNode, *QueuePtr;
typedef struct
{
	QueuePtr front;		//��ͷָ��
	QueuePtr rear;		//��βָ��
}LinkQueue;

Status InitQueue(LinkQueue & Q);
Status DestroyQueue(LinkQueue & Q);
Status ClearQueue(LinkQueue & Q);
int QueueLength(LinkQueue Q);
Status EnQueue(LinkQueue & Q, QElemType e);
Status DeQueue(LinkQueue & Q, QElemType & e);
Status QueueTraverse(LinkQueue Q, Status(*visit)(QElemType));

#endif // !_QUEUE_H
