#include"lexer.h"
#include "parser.h"
#include "tree.h"

int w;

/***********************************************************
*�������ƣ�program
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ����
*���������Դ�ļ�ָ��fp
*����ֵ�������﷨��AST�����������﷨��������INFEASIBLE
***********************************************************/
CTreePtr program(FILE * fp)
{
	CTreePtr T;
	CTreePtr c;
	char string[] = "����";
	InitTree(T);
	w = gettoken(fp);
	if ((c = ExtDefList(fp)) && c->n)
	{
		T->n = 1; T->r = 0;
		T->nodes[0].data = string;		//����һ�������Ϊ�����ĸ�
		T->nodes[0].firstchild = NULL;
		if (!InsertChild(T, T->r, 1, c)) return NULL;
	}
	else return NULL;
	return T;
}

/***********************************************************
*�������ƣ�program
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ����
*���������Դ�ļ�ָ��fp
*����ֵ�������﷨��AST�����������﷨��������INFEASIBLE
***********************************************************/
CTreePtr ExtDefList(FILE * fp)
{
	CTreePtr T; CTreePtr c;
	char string[] = "�ⲿ��������";
	if (w == EOF) return NULL;
	InitTree(T);
	T->n = 1;  T->r = 0;
	T->nodes[0].data = string;
	T->nodes[0].firstchild = NULL;
	c = ExtDef(fp);
	InsertChild(T, T->r, 1, c);
	c = ExtDefList(fp);
	InsertChild(T, T->r, 2, c);
	return T;
}
