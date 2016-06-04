/*************************************************************************
	> File Name: w_system.h
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Mar 2016 07:22:23 PM EST
 ************************************************************************/

#ifndef _W_SYSTEM_H
#define _W_SYSTEM_H
typedef struct node
{
    int num;
    int age;
    int grade;
    char name[20];
    struct node *next;
    int english4;
    int count;
    int flag;
}Node, *Head;

void Menu(void);
int Create(Head *head, int tmp);
int Insert(Head *head, int num);
int Delete(Head *head, int num);
int Find(Head head, int num);
int Update(Head head, int num);
void Show(Head head);
int Destory(Head *head);
int create_data(Head *h, char stu[][9]);
int sys_circle(Head *h, Head head, char stu[][9]);   
int inquire_english4();
int interval_sort(Head head);
#endif
