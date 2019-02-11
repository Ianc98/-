#include"lexer.h"
#include"queue.h"

int i = 1;						//��Ǵ������

//�Զ������õ�visit()�������ж���
Status PrintElement(QElemType e)
{
	printf("	%d		%d\n", i++, e);
	return OK;
}

int main(void)
{
	char filename[30]; FILE * fp;
	int status; int ch = 1;
	LinkQueue Q;				//����һ�����У����ڴ�Ŵ�����
	InitQueue(Q);
ChooseFilename:
	system("cls");
	printf("�����ļ�����");
	scanf_s("%s", filename, 30);
	while (ch)
	{
		system("cls");
		printf("�ļ�����%s\n\n", filename);
		printf("�߼�����Դ�����ʽ����˵�\n");
		printf("1. �ʷ�����\n");
		printf("2. �﷨����\n");
		printf("3. ����ѡ���ļ�\n");
		printf("0. �˳�����\n");
		printf("\n");
		printf("�����ѡ��");
		scanf("%d", &ch);
		system("cls");
		if (fopen_s(&fp, filename, "r"))
		{
			printf("�ļ���ʧ�ܣ�\n");
			printf("�����������...");
			getchar(); getchar();
			goto ChooseFilename;
		}
		switch (ch)
		{
		case 1:
			printf("\n");
			printf("	�������				����ֵ\n");
			while (!feof(fp))
			{
				status = gettoken(fp);
				if (status >= AUTO && status <= _THREAD_LOCAL)
					printf("	�ؼ���					%s\n", token_text);
				switch (status)
				{
				case IDENT:
					printf("	��ʶ��					%s\n", token_text);
					break;
				case INT_CONST:
					printf("	���ͳ���				%s\n", token_text);
					break;
				case UNSIGNED_CONST:
					printf("	�޷������ͳ���			%s\n", token_text);
					break;
				case LONG_CONST:
					printf("	�����ͳ���				%s\n", token_text);
					break;
				case UNSIGNED_LONG_CONST:
					printf("	�޷��ų����ͳ���		%s\n", token_text);
					break;
				case DOUBLE_CONST:
					printf("	˫���ȸ����ͳ���		%s\n", token_text);
					break;
				case FLOAT_CONST:
					printf("	�����ͳ���				%s\n", token_text);
					break;
				case LONG_DOUBLE_CONST:
					printf("	��˫���ȸ����ͳ���		%s\n", token_text);
					break;
				case CHAR_CONST:
					printf("	�ַ��ͳ���				%s\n", token_text);
					break;
				case STRING_CONST:
					printf("	�ַ�������				%s\n", token_text);
					break;
				case ASSIGN:
					printf("	��ֵ�����				=\n");
					break;
				case PLUS:
					printf("	�ӷ������				+\n");
					break;
				case PLUSPLUS:
					printf("	���������				++\n");
					break;
				case MINUS:
					printf("	���������				-\n");
					break;
				case MINUSMINUS:
					printf("	�Լ������				--\n");
					break;
				case MULTIPLY:
					printf("	�˷������				*\n");
					break;
				case DIVIDE:
					printf("	���������				/\n");
					break;
				case MOD:
					printf("	ȡģ�����				/\n");
					break;
				case COMPARISON:
					printf("	��ϵ�����				%s\n", token_text);
					break;
				case AND:
					printf("	�߼���					&&\n");
					break;
				case OR:
					printf("	�߼���					||\n");
					break;
				case LP:
					printf("	��С����				(\n");
					break;
				case RP:
					printf("	��С����				)\n");
					break;
				case LBT:
					printf("	��������				[\n");
					break;
				case RBT:
					printf("	��������				]\n");
					break;
				case LBS:
					printf("	�������				{\n");
					break;
				case RBS:
					printf("	�Ҵ�����				}\n");
					break;
				case SEMI:
					printf("	�ֺ�					;\n");
					break;
				case COMMA:
					printf("	����					,\n");
					break;
				case ERROR_TOKEN:
					EnQueue(Q, num);
					break;
				}
			}
			printf("\n");
			printf("�����б� %d\n", QueueLength(Q));
			if (QueueLength(Q))
			{
				printf("\n");
				printf("	���		��\n");
				QueueTraverse(Q, PrintElement);
			}
			fclose(fp);
			printf("\n�����������...");
			getchar(); getchar();
			break;
		case 3:
			goto ChooseFilename;
		default:
			return 0;
		}
	}
	return 1;
}