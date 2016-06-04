/*************************************************************************
	> File Name: bit_field.c
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Sat 07 May 2016 05:24:13 AM EDT
 ************************************************************************/

#include<string.h>
#include<stdio.h>
#include<assert.h>
#include"bit_field.h"

int set_bit(Bit_ptr arr, int n)
{
    assert(n >= 0 && n < MAX_SIZE_BIT && arr != NULL);
    arr[n].a = 1;
    return 0;
}

int delete_bit(Bit_ptr arr, int n)
{
    assert(n >= 0 && n < MAX_SIZE_BIT && arr != NULL);
    arr[n].a = 0;
    return 0;
}

int clear_all_bit(Bit_ptr arr)
{
    assert(arr != NULL);
    bzero(arr, sizeof(arr));
    return 0;
}

