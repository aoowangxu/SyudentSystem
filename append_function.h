/*************************************************************************
	> File Name: append_function.h
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Fri 06 May 2016 10:49:51 PM EDT
 ************************************************************************/

#ifndef _APPEND_FUNCTION_H
#define _APPEND_FUNCTION_H
#define MAX_SIZE 10000
#include"w_system.h"
typedef struct
{
    Node r[MAX_SIZE + 1];
    int length;
}Sqlist;

void swap(Sqlist *L, int i, int j);
void heapadjust(Sqlist *L, int s, int m);
void heapsort(Sqlist *L);
#endif
