#include"lexer.h"
#include "parser.h"
#include "tree.h"

token_kind w;

/**********************************************
*�������ƣ�program
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ����
*���������Դ�ļ�ָ��fp
*����ֵ��������
**********************************************/
Status program(FILE * fp)
{
	CTree T;
	InitTree(T);
	w = gettoken(fp);
	if (ExtDefList(fp))
	{
		
	}
	return Status();
}
