#include"lexical.h"
int main(void)
{
	char filename[30]; FILE * fp;
	int status;
	printf("�����ļ�����");
	scanf("%s", &filename);
	if (!(fp = fopen(filename, "r")))
	{
		printf("�ļ���ʧ�ܣ�\n");
		getchar(); return 0;
	}
	printf("	�������		����ֵ\n");
	while (!feof(fp))
	{
		status = gettoken(fp);
		if (status >= AUTO && status <= _THREAD_LOCAL)
			printf("	�ؼ���");
	}
	return 1;
}