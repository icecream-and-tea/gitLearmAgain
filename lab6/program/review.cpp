#include <stdio.h>
#include <stdlib.h>

#define OK 1;
#define FALSE 0;
typedef int Status;

typedef struct {
    short r0;
    short r1;
    short r2;
    short r3;
    short r4;
    short r5;
    short r6;
    short r7;
}Register;

typedef struct{
    short num, ans;
    int lchild, rchild;
}BiTNode;

void Menu()
{
    printf("1.lab0l\n");
    printf("2.lab0p\n");
    printf("3.lab02\n");
    printf("4.lab03\n");
    printf("5.lab04_rec\n");
    printf("6.lab04_mod\n");
    printf("7.lab05\n");
}

short lab0l(short r0, short r1)
{
    short r7 = 0;
    for(; r1 != 0; r1--)
    {
        r7 += r0;
    }
    return r7;
}

short lab0p(short r0, short r1)
{
    short r2, r3, r7 = 0;
    for(r2 = 1; r2 != 0; r2 *= 2)
    {
        r3 = r2 & r1;
        if(r3)
        {
            r7 += r0;
        }
        r0 = r0 << 1;
    }
    return r7;
}

short lab02(short r0)
{
    short r1 = 2, r2 = 1, r3 = 1;
    short r7 = r1;
    r0 -= 2;
    if(r0 < 0)  
    {//判断是否为初始量
        r7 = 1;
        return r7;
    }
    for(; r0 != 0; r0 --)
    {
        r3 *= 2;
        r7 = r3 + r1;
        r3 = r2;
        r2 = r1;
        r1 = r7;  //更新状态
    }
    r7 = r7 % 1024;
    return r7;
}

short lab03(short r0)
{
    short r7;
    BiTNode temp;
    BiTNode *tree;
    tree = (BiTNode*)malloc(11 * sizeof(BiTNode));
    //0为废结点
    tree[1] = {24, 706 ,0, 0};
    tree[2] = {144, 642, 1, 3};
    tree[3] = {456, 66, 0, 0};
    tree[4] = {1088, 2, 2, 6};
    tree[5] = {1092, 290, 0, 0};
    tree[6] = {2096, 898, 5, 0};
    tree[7] = {4200, 322, 4, 9};
    tree[8] = {8192, 514, 0, 0};
    tree[9] = {12000, 258, 8, 10};
    tree[10] = {14000, 898, 0, 0};
    temp = tree[7];
    while(1)
    {
        if(r7 - temp.num == 0)
        {
            r7 = temp.ans;
            return r7;
        }
        else if(r7 - temp.num < 0)
        {
            if(temp.lchild)
            {
                temp = tree[temp.lchild];
            }
            else printf("cannot find!\n");
        }
        else 
        {
            if(temp.rchild)
            {
                temp = tree[temp.rchild];
            }
            else printf("cannot find!\n");
        }
    }
}

short lab04_rec( int addressnum )
{
    addressnum --;
    if(addressnum == 0)
        return 1;
    else return lab04_rec(addressnum) + 1;
}

short lab04_mod( short r0)
{
    short r1, r2;
    while(r0 > 7)
    {
        r1 = r0/7;
        r2 = r0 - r1*8;
        r0 = r1 + r2;  
    }
    if(r0 == 7)
        return 0;
    else return r0;
}

int lab05(short r0)
{
    int i = 2;
    short r1 = 1;
    while(i * i <= r0)
    {
        if(r0 % i == 0)
        {
            r1 = 0;
            break;
        }
        i++;
    }
    return r1;
}

int main()
{
    int opt;
    Register reg = {0};
    Menu();
    scanf("%d",&opt);
    switch(opt)
    {
        case 1: 
                printf("please enter the number\n");
                scanf("%hd,%hd",&reg.r0,&reg.r1);
                printf("result = %hd\n",lab0l(reg.r0, reg.r1)); 
                break;
        case 2: 
                printf("please enter the number\n");
                scanf("%hd,%hd",&reg.r0,&reg.r1);
                printf("result = %hd\n",lab0p(reg.r0, reg.r1)); 
                break;
        case 3: 
                printf("please enter the number\n");
                scanf("%hd",&reg.r0);
                printf("fib = %hd\n",lab02(reg.r0));
                break;
        case 4: 
                printf("please enter the number\n");
                scanf("%hd",&reg.r0);
                printf("fib = %hd\n",lab03(reg.r0));
                break;
        case 5: 
                printf("please enter the number\n");
                scanf("%hd",&reg.r0);
                printf("rec = %hd\n",lab04_rec(reg.r0));
                break;
        case 6: 
                printf("please enter the number\n");
                scanf("%hd",&reg.r0);
                printf("mod = %hd\n",lab04_mod(reg.r0));
                break;
        case 7: 
                printf("please enter the number\n");
                scanf("%hd",&reg.r0);
                if(lab05(reg.r0))
                {
                    printf("prime\n");
                }
                else printf("not prime\n");
                break;
    }
    system("pause");
}