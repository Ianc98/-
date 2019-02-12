#include "tree.h"

/**********************************************
*�������ƣ�InitTree
*�������ܣ��������г�ʼ��
*�����������CTreePtr T
*����ֵ������ִ��״̬��ִ�гɹ�����OK��
**********************************************/
Status InitTree(CTreePtr & T)
{
	if (!T) T = (CTreePtr)malloc(sizeof(CTree));
	if (!T) exit(OVERFLOW);
	T->n = 0; T->r = -1;		//������λ����Ϊ-1��˵����ǰ��û�и�
	return OK;
}

/**********************************************
*�������ƣ�InsertChild
*�������ܣ�ΪT��ĳ��������һ������
*�����������CTreePtr T��int pָ��ĳ����㣬int i
��ʾ��i��������CTreePtr c��Ҫ���������
*����ֵ������ִ��״̬��ִ�гɹ�����OK�����򷵻�
ERROR
**********************************************/
Status InsertChild(CTreePtr & T, int p, int i, CTreePtr c)
{
	if (!T) return ERROR;
	if (p < 0 || p >= T->n) return ERROR;			//p��ָ��T��ĳ�����
	if (!c || !c->n) return ERROR;					//Ҫ����������ǿ���
	int k = 0, j = T->n;
	ChildPtr prior = T->nodes[p].firstchild;			//�������ҵ�i������ǰһ�����
	ChildPtr cur = prior;							//�������ҵ�i�����
	ChildPtr t = (ChildPtr)malloc(sizeof(CTNode));
	if (!t) exit(OVERFLOW);
	while (k < c->n)
		T->nodes[j++] = c->nodes[k++];
	t->child = T->n + c->r;							//��������λ��
	T->n += c->n;
	if (i == 1)
	{
		if (prior)
		{
			t->next = prior;
			prior = t;
		}
		else prior = t;
	}
	else if (i < 1) return ERROR;					//���i����Ƿ�������ERROR
	else
	{
		k = 1;											//k��ʾ��ǰ�ǵڼ�������
		while (k < i&&cur)
		{
			k++;
			prior = cur;
			cur = cur->next;
		}
		if (cur)
		{
			prior->next = t;
			t->next = cur;
		}
		else if (k == i)
		{
			prior->next = t;
			t->next = NULL;
		}
		else return ERROR;
	}
	return OK;
}
