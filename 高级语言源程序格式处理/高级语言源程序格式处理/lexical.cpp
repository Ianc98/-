#include "lexical.h"

int num = 1;
char token_text[MAXLEN];
keyword HashKey[25][11] = 
{
	{{"_Alignas",_ALIGNAS},{"_Alignof",_ALIGNOF},{"_Atomic",_ATOMIC},{"_Bool",_BOOL},
	{"_Complex",_COMPLEX},{"_Generic",_GENERIC},{"_Imaginary",_IMAGINARY},{"_Noreturn",_NORETURN},
	{"_Static_assert",_STATIC_ASSERT},{"_Thread_local",_THREAD_LOCAL},{"",IDENT}},
	{{"",IDENT}},
	{{"auto",AUTO},{"",IDENT}},
	{{"break",BREAK},{"",IDENT}},
	{{"case",CASE},{"char",CHAR},{"const",CONST},{"continue",CONTINUE},{"",IDENT}},
	{{"default",DEFAULT},{"do",DO},{"double",DOUBLE},{"",IDENT}},
	{{"else",ELSE},{"enum",ENUM},{"extern",EXTERN},{"",IDENT}},
	{{"float",FLOAT},{"for",FOR},{"",IDENT}},
	{{"goto",GOTO},{"",IDENT}},
	{{"",IDENT}},
	{{"if",IF},{"inline",INLINE},{"int",INT},{"",IDENT}},
	{{"",IDENT}},
	{{"",IDENT}},
	{{"long",LONG},{"",IDENT}},
	{{"",IDENT}},
	{{"",IDENT}},
	{{"",IDENT}},
	{{"",IDENT}},
	{{"",IDENT}},
	{{"register",REGISTER},{"restrict",RESTRICT},{"return",RETURN},{"",IDENT}},
	{{"short",SHORT},{"signed",SIGNED},{"sizeof",SIZEOF},{"static",STATIC},
	{"struct",STRUCT},{"switch",SWITCH},{"",IDENT}},
	{{"typedef",TYPEDEF},{"",IDENT}},
	{{"union",UNION},{"unsigned",UNSIGNED},{"",IDENT}},
	{{"void",VOID},{"volatile",VOLATILE},{"",IDENT}},
	{{"while",WHILE},{"",IDENT}}
};
//������һ��������ĸ��ŵ�Hash������ÿһ��ĩβ����һ�������ڣ���ʶ��ΪIDENT

int gettoken(FILE * fp)
{
	char c;							//���ڶ�ȡ�ַ�
	int i = 0; int j = 0;
	while ((c = fgetc(fp)) == ' ' || c == '\n')		//���˵��հ׷���
		if (c == '\n') num++;						//�����ȡ���س�����������������1
	if ((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z') || c == '_')
	{
		do
		{
			token_text[i] = c;		//��c��ֵ���η����ʶ����	
			i++;
		} while (((c = fgetc(fp)) >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z') ||
			(c >= '0'&&c <= '9') || c == '_');
		//���c����ĸ������
		token_text[i] = 0;				//��β���������
		ungetc(c, fp);					//�˻ض�����ַ����ļ����뻺����
		//��ʶ�������ǹؼ��֣���Ҫ�ж������ض�Ӧ������
		//���Ŵ���token_text�У���˲���token_text�洢���ַ����Ƿ���Hash����
		//�����ʶ����ĳ���ؼ������ʱ�����عؼ��ֵ�������룬���򷵻�IDENT
		c = token_text[0];
		if (c != '_' && (c<'a' || c>'w')) return IDENT;
		//�����ʶ��������ĸ��Ϊ'_'����'a'-'w'����ôһ��ʱ��ʶ����ֱ�ӷ���IDENT
		i = c - '_';					//������Ӧ����ĸ���ڵ���
		while (strcmp(token_text, HashKey[i][j].key) && *HashKey[i][j].key)
			j++;
		return HashKey[i][j].c;
	}
	if (c >= '0'&&c <= '9')
	{	//�������ĸ�����֣����ʿ��������ͳ������߸����ͳ���
		do
		{
			token_text[i] = c;		//��c��ֵ���η����ʶ����	
			i++;
		} while ((c = fgetc(fp)) >= '0'&&c <= '9');		//ƴ���ִ�
		if (c == '.')
		{
			do
			{
				token_text[i] = c;		//��c��ֵ���η����ʶ����	
				i++;
			} while ((c = fgetc(fp)) >= '0'&&c <= '9');		//ƴ���ִ�(С������)
			token_text[i] = 0;
			ungetc(c, fp);
			return FLOAT_CONST;
		}
		token_text[i] = 0;
		ungetc(c, fp);
		return INT_CONST;
	}
	switch (c)
	{
	case '.':
		do
		{
			token_text[i] = c;		//��c��ֵ���η����ʶ����	
			i++;
		} while ((c = fgetc(fp)) >= '0'&&c <= '9');		//ƴ���ִ�(С������)
		if (i > 1)					//С���������������1������
		{
			token_text[i] = 0;
			ungetc(c, fp);
			return FLOAT_CONST;
		}
		else
		{
			ungetc(c, fp);
			return ERROR_TOKEN;
		}
	case '\'':
	case '"':
		do
		{
			if (c == '\n')
				if (token_text[i - 1] == '\\')
					num++;
				else return ERROR_TOKEN;
			token_text[i] = c;
			i++;
		} while ((c=fgetc(fp))!='"');
		token_text[i++] = c;
		token_text[i] = 0;
		return STRING_CONST;
	case '=':
		c = fgetc(fp);
		if (c == '=') return EQ;
		ungetc(c, fp);
		return ASSIGN;
	case '+':
		c = fgetc(fp);
		if (c == '+') return PLUSPLUS;
		ungetc(c, fp);
		return PLUS;
	case ';':
		return SEMI;
	default:
		if (feof(fp)) return EOF;
		else return ERROR_TOKEN;		//�����������
	}
}
