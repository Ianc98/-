#include"lexical.h"
int main(void)
{
	char filename[30]; FILE * fp;
	int status;
	printf("�����ļ�����");
	scanf_s("%s", filename, 30);
	if (fopen_s(&fp,filename,"r"))
	{
		printf("�ļ���ʧ�ܣ�\n");
		getchar(); return 0;
	}
	printf("\n");
	printf("	�������		����ֵ\n");
	while (!feof(fp))
	{
		status = gettoken(fp);
		if (status >= AUTO && status <= _THREAD_LOCAL)
			printf("	�ؼ���			%s\n", token_text);
		switch (status)
		{
		case IDENT:
			printf("	��ʶ��			%s\n", token_text);
			break;
		case INT_CONST:
			printf("	���ͳ���		%s\n", token_text);
			break;
		case FLOAT_CONST:
			printf("	�����ͳ���		%s\n", token_text);
			break;
		case EQ:
			printf("	�Ⱥ�			==\n");
			break;
		case ASSIGN:
			printf("	��ֵ��			=\n");
			break;
		case PLUS:
			printf("	�Ӻ�			+\n");
			break;
		case PLUSPLUS:
			printf("	������			++\n");
			break;
		case SEMI:
			printf("	�ֺ�			;\n");
			break;
		case ERROR_TOKEN:
			printf("\n");
			printf("��������������%d\n", num);
			printf("\n");
			printf("�����������...");
			getchar(); getchar();
			return 0;
		}
	}
	printf("\n");
	printf("�����������...");
	getchar(); getchar();
	return 1;
}