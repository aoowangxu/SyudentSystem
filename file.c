/*************************************************************************
	> File Name: file.c
	> Author: 
	> Mail: 
	> Created Time: Wed 30 Mar 2016 04:00:12 AM EDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"insert.h"
int save(Head head, char stu[10][9])
{
    FILE *fp;
    if((fp = fopen(*stu, "w")) == NULL)
    {
        printf("can't open this file\n");
        exit(0);
    }
    while(NULL != head)
    {
        fprintf(fp, "%d %d %d %s %d\n", head->num, head->age, head->grade, head->name, head->english4);
        head = head->next;
    }
    fclose(fp);
    printf("save success!\n");
    return 0;
    
}

int sort(Head head, Head h[])
{
    Head p = NULL;
    int tmp = 0;
    while(NULL != head)
    {
        p = head;
        head = head->next;
        p->next = NULL;
        tmp = head->num % 10;
        headinsert(h+tmp, &p);
    }
}

int read(Head *head, char stu[][9])
{
    FILE *fp;
    if((fp = fopen(stu[1],"r")) == NULL)
    {
        printf("can't open this file!\n");
        exit(0);
    }
    while(!feof(fp))
    {
        Node *p = (Node *)malloc(sizeof(Node));
        fscanf(fp, "%d %d %d %s", &p->num, &p->age, &p->grade, p->name);
        headinsert(head, &p);
    }
    fclose(fp);
    return 0;
}
