/*************************************************************************
	> File Name: append_function.c
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Fri 06 May 2016 10:14:41 PM EDT
 ************************************************************************/

#include<stdio.h>
#include"append_function.h"

void swap(Sqlist *L, int i, int j)
{
    Node temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}
void heapadjust(Sqlist *L, int s, int m)
{
    Node temp = L->r[s];
    int j = 0;
    for (j = 2*s; j <= m; j *= 2)
    {
        if (j  < m && L->r[j].grade > L->r[j+1].grade)
        {
            ++j;
        }
        if (temp.grade <= L->r[j].grade)
        {
            break;
        }

        L->r[s]= L->r[j];
        s = j;
    }
    L->r[s] = temp;
}

void heapsort(Sqlist *L)
{
    int i = 0;
    for (i = L->length/2; i > 0; --i)
    {
        heapadjust(L, i, L->length);
    }

    for (i = L->length; i > 1; --i)
    {
        swap(L, 1, i);
        heapadjust(L, 1, i-1);
    }
}
