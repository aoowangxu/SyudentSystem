/*************************************************************************
	> File Name: insert.c
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Mar 2016 08:44:51 PM EST
 ************************************************************************/

#include<stdio.h>
#include"w_system.h"
#include"insert.h"

int middleinsert(Head *head, Head *p)
{
    Head pre = NULL;
    Head cru = *head;
    if(NULL == *head)
    {
        *head = *p;
        return 1;
    }
    while(NULL != cru && cru->num < (*p)->num)
    {
        pre = cru;
        cru = cru->next;
    }
    if(NULL == cru)
    {
        pre->next = (*p);
    }
    else if(cru == *head)
    {
        (*p)->next = *head;
        *head = *p;
    }
    else
    {
        (*p)->next = cru;
        pre->next = (*p);
    }
    return 1;
}
int tailinsert(Head *head, Head *p, Head *tail)
{
    if(NULL == *head)
    {
        *head = *p;
        *tail = *p;
        return 1;
    }
    if(NULL == *tail)
    {
        *tail = *head;
        while(NULL != (*tail)->next)
        {
            *tail = (*tail)->next;
        }
    }
    (*tail)->next = *p;
    *tail = *p;
    
}


int headinsert(Head *head, Head *p)
{
    if(NULL == *head)
    {
        *head = *p;
        return 1;
    }
    (*p)->next = *head;
    *head = *p;
    return 1;


}
