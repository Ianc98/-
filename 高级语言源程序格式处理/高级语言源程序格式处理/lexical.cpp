#include "lexical.h"

char * token_text;

int gettoken(FILE * fp)
{
	token_text = NULL;
	while ((c = fgetc(fp)) == ' ');	//���˵��հ׷��ţ�������Ǳ���λ�ã��Իس���Ҫ����
									//����ÿ�λس�������һ��������������1
	if ((c >= 'A'&&c <= "Z") || (c >= 'a'&&c <= 'z'))
	{

	}
	return 0;
}
