/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Mar 2016 07:05:30 PM EST
 ************************************************************************/

#include<stdio.h>
#include"w_system.h"
#include"file.h"
#include"bit_field.h"

Bit_num arr[MAX_SIZE_BIT];

char stu[10][9] = { {"stu0.dat"},{"stu1.dat"},\
                    {"stu2.dat"},{"stu3.dat"},\
                    {"stu4.dat"},{"stu5.dat"},\
                    {"stu6.dat"},{"stu7.dat"},\
                    {"stu8.dat"},{"stu9.dat"}};


int main()
{
    Head h[10] = {NULL};
    Head head = NULL;

    clear_all_bit(arr);
    create_data(h, stu);
    
    sys_circle(h, head, stu);   
    return 0;
}
