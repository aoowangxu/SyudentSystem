/*************************************************************************
	> File Name: bit_field.h
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Sat 07 May 2016 05:24:13 AM EDT
 ************************************************************************/

#ifndef _BIT_FIELD_H
#define _BIT_FIELD_H

#define MAX_SIZE_BIT 10000000
#pragma pack(1)

typedef struct sb
{
    int a:1;
}Bit_num,*Bit_ptr;

int set_bit(Bit_ptr arr, int n);
int delete_bit(Bit_ptr arr, int n);
int clear_all_bit(Bit_ptr arr);
#endif
