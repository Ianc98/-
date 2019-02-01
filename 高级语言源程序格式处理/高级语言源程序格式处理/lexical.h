//
// lexical.h
//

#pragma once

#ifndef _LEXICAL_H
#define _LEXICAL_H
//��ֹ�ظ�������ͷ�ļ�

#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define MAXLEN 100

struct keyword
{
	char key[15];
	enum token_kind c;
};
//Hash�������Ԫ��
enum token_kind
{
	ERROR_TOKEN, AUTO, BREAK, CASE, CHAR, CONST, CONTINUE, DEFAULT, DO, DOUBLE, ELSE, ENUM, EXTERN,
	FLOAT, FOR, GOTO, IF, INLINE, INT, LONG, REGISTER, RESTRICT, RETURN, SHORT, SIGNED, SIZEOF,
	STATIC, STRUCT, SWITCH, TYPEDEF, UNION, UNSIGNED, VOID, VOLATILE, WHILE, _ALIGNAS, _ALIGNOF,
	_ATOMIC, _BOOL, _COMPLEX, _GENERIC, _IMAGINARY, _NORETURN, _STATIC_ASSERT, _THREAD_LOCAL, IDENT,
	INT_CONST, FLOAT_CONST, EQ, ASSIGN, PLUS, PLUSPLUS, SEMI
};
//����ö�����ͣ�ʹ��ͬ���͵ĵ��ʵõ�Ψһ�ı�ʶ��

extern int num;						//��������������¼��ǰ�ѷ�����Դ����ĵڼ���
extern char token_text[MAXLEN];		//��ŵ���ֵ���ַ���
extern keyword HashKey[25][11];		//��Źؼ��ּ����ʶ���Hash��

/**********************************************
*�������ƣ�gettoken
*�������ܣ���Դ������дʷ�����
*���������Դ�����ļ�ָ��fp
*����ֵ�����ʱ�ʶ��
**********************************************/
int gettoken(FILE * fp);

#endif // !_LEXICAL_H