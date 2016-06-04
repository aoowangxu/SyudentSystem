/*************************************************************************
	> File Name: w_system.c
	> Author: 
	> Mail: 
	> Created Time: Fri 11 Mar 2016 07:35:22 PM EST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"w_system.h"
#include"insert.h"
#include"file.h"
#include<time.h>
#include"bit_field.h"
#include"append_function.h"
extern Bit_num arr[MAX_SIZE_BIT];
void Menu(void)
{
    system("clear");
    printf("***********************student_system***********************\n");
    printf("1.insert\t\t\t\t2.delete\n3.find\t\t\t\t\t4.undate\n\
5.save\t\t\t\t\t6.show\n7.destory\t\t\t\t8.exit\n\
9.inquire\t\t\t\t10.interval_sort\n");
    printf("***********************student_system***********************\n");
}

int create_data(Head *h, char stu[][9])
{
    int i = 0;
    for(i = 0; i < 10; ++i)
    {
       // int tmp = i*1000;
        printf("creating student information.....\n");
        Create(&h[i], i);
        printf("saving student information..... \n");
        save(h[i], stu+i);
    }
    return 0;
}


int Create(Head *head, int tmp)
{
    int i = 0;
    for (i = tmp; i < 1e7; i += 10)
    {
        Head p = (Head)malloc(sizeof(Node));
        if(NULL == p)
        {
            printf("malloc failed!\n");
            return 0;
        }
        p->num = i;
        p->age = rand()%10 + 20;
        p->grade = rand()%100;
        p->name[0] = rand()%32 + 65;
        p->next = NULL;
        p->english4 = rand()%700;
        int count = 0;
        int flag = 0;
        if (p->english4 >= 425)
        {
            set_bit(arr, i);
        }
        headinsert(head, &p);
    }
    return 1;
}


int Insert(Head *head, int n)
{
    Head p_tmp = NULL;
    Head p = (Head)malloc(sizeof(Node));
    if(NULL == p)
    {
        printf("malloc failed\n");
        return 0;
    }
    p->next = NULL;
    printf("please input a student information.\nnum\tage\tgrade\tname\tenglish4\n");
    scanf("%d %d %d %s %d", &p->num, &p->age, &p->grade, p->name, &p->english4);
    middleinsert(head, &p);
    if (p->english4 >= 425)
    {
        set_bit(arr, p->num);
    }
    printf("insert success!");
    getchar();
    return 1;
}

int Delete(Head *head, int num)
{
    delete_bit(arr, num);
    Head p = *head;
    while(NULL != *head && num != (*head)->num)
    {
        p = *head;
        *head = (*head)->next;
    }
    if(NULL == *head)
    {
        return 0;
    }
    p->next = (*head)->next;
    free(*head);

    printf("delete success\n");
    getchar();
    getchar();
    return 0;   
}

int Find(Head head, int num)
{
    while(NULL != head && num != head->num)
    {
        head = head->next;
    }
    if(NULL == head)
    {
        printf("no fiand");
        return 0;
    }
    printf("%d %d %d %s %d", head->num, head->age, head->grade, head->name, head->english4);
    getchar();
    return 1;

}

int Update(Head head, int num)
{
    while(NULL != head && num != head->num)
    {
        head = head->next;  
    }
    if(head == NULL)
    {
        printf("no this student.\n");
        return 0;
    }
    printf("please input student information.\nnum\tage\tgrade\tname\tenglish4\n");
    scanf("%d %d %d %s %d",&head->num, &head->age, &head->grade, head->name, &head->english4);
    if (head->english4 >= 425)
    {
        set_bit(arr, head->num);
    }
    printf("Update success\n");
    getchar();
    getchar();
    return 1;
}

void Show(Head head)
{
    printf("num\tage\tgrade\tname\n");
    while(NULL != head)
    {
        printf("%d %d %d %s\n", head->num, head->age, head->grade, head->name);
        head= head->next;
    }
    getchar();
}

int Destory(Head *head)
{
    Head p = *head;
    while(NULL != *head)
    {
        *head = (*head)->next;
        free(p);
        p = *head;
    }    
    *head = NULL;
    clear_all_bit(arr);
    printf("Destory success\n");
    return 1;
}

int inquire_english4()
{
    int num = 0;
    printf("pleasea input inquire num：");
    scanf("%d", &num);
    if (1 == arr[num].a)
    {
        printf("english4 is passed\n");
    }
    else
    {
        printf("english4 isn't passed\n");
    }
    getchar();
    getchar();
    return 0;
}
  
int sys_circle(Head *h, Head head, char stu[][9])   
{
    int i = 0;
    int j = 0;
    int n = 0;;
    int sit = 0;

    while(1)
    {
        Menu();
        printf("please input your operate:\n");
        scanf("%d",&n);
        switch(n)
        {
            case(1):
            {
                printf("please input num:\n");
                scanf("%d", &sit);
                Insert(h+sit%10, sit);
                break;
            }
            case(2):
            {
                printf("please input num:\n");
                scanf("%d", &sit);
                Delete(h+sit%10, sit);
                break;
            }
            case(3):
            {
                printf("please input num:\n");
                scanf("%d", &sit);
                Find(h[sit %10], sit);
                getchar();
                break;
            }
            case(4):
            {
                printf("please input num:\n");
                scanf("%d", &sit);
                Update(h[sit %10], sit);
                break;
            }
            case(5):
            {
                for(i = 0; i < 10; ++i)
                {
                    save(h[i],stu+i);
                }
                break;
            }
            case(6):
            {
                for(i = 0; i < 10; ++i)
                {
                    Show(h[i]);              
                }
                break;
            }
            case(7):
            {
                for(i = 0; i < 10; ++i)
                {
                    Destory(h+i);
                }
                Destory(&head);
                break;
            }
            case(8):
            {
                return 0;
            }
            case(9):
            {
                inquire_english4();
                break;
                
            }
            case(10):
            {
                interval_sort(h[1]);
                break;
            }
            default:
            {
                printf("no your choise.\n");
                break;
            }
        }
    }
    return 0;
}

int interval_sort(Head head)
{
    int start = 0;
    int end = 0;
    int i = 0;
    while(1)
    {
        printf("please input end and start:");
        scanf("%d %d", &start, &end);
        if (start >= 0 && end < MAX_SIZE_BIT && start < end)
        {
            break;
        }
    }

    Sqlist L;
    L.length = (end - start)/10;

    while(NULL != head && end <= head->num)
    {
        head = head->next;
    }
    if(NULL == head)
    {
        printf("no fiand");
        return 0;
    }
    while(head != NULL && head->num >= start)
    {
        L.r[i++] = *head;
        head = head->next;
    }

    heapsort(&L);
    printf("please input N of in the outrunner.\n");
    scanf("%d", &end);
    printf("num age grade name english4\n");
    for (i = 1; i <= end; ++i)
    {
        printf("%d %d %d %s %d\n", L.r[i].num, L.r[i].age, L.r[i].grade, L.r[i].name, L.r[i].english4);
    }
    getchar();
    getchar();
    return 0;
}
