#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    while(1)
    {
        Welcome();

        //从键盘接受字符指令
        //getch接受一个字符，不用按回车
        char ch = getch();

        switch(ch)
        {
        case'1'://录入学生信息
            InputStudent();
            break;
        case'2'://打印学生信息
            PrintStudent();
            break;
        case'3'://保存学生信息
            SaveStudent();
            break;
        case'4'://读取学生信息
            ReadStudent();
            break;
        case'5'://统计学生信息
            printf("学生总人数为：%d\n",CountStudent());
            system("pause");   //暂停
            system("cls");     //清屏
            break;
        case'6'://查找学生信息
            FindStudent();
            system("pause");   //暂停
            system("cls");     //清屏
            break;
        case'7'://修改学生信息
            ModifyStudent();
            break;
        case'8'://删除学生信息
            DeleteStudent();
            break;
        case'0'://退出
            printf("再见\n");
            return 0;
        default:
            printf("请重新输入\n");

        }
    }


    return 0;
}


//定义学生
typedef struct _Student
{
    char name[20]; //姓名
    int age;       //年龄
    int stuNum;    //学号
    int score;     //成绩
}Student;



//节点
typedef struct _Node
{
    Student stu;  //学生
    struct _Node* pNext;  //指向下一个节点


}Node;


//定义一个头结点
Node* g_pHead = NULL;


//欢迎
void Welcome()
{
        printf("*********************************************\n");
        printf("\t欢迎使用学生成绩管理系统\t\n");
        printf("*********************************************\n");
        printf("\t\t  选择功能\t\t\t\n");
        printf("*********************************************\n");
        printf("\t\t1.录入学生信息\t\t\t\n");
        printf("\t\t2.打印学生信息\t\t\t\n");
        printf("\t\t3.保存学生信息\t\t\t\n");
        printf("\t\t4.读取学生信息\t\t\t\n");
        printf("\t\t5.统计所有学生人数\t\t\t\n");
        printf("\t\t6.查找学生信息\t\t\t\n");
        printf("\t\t7.修改学生信息\t\t\t\n");
        printf("\t\t8.删除学生信息\t\t\t\n");
        printf("\t\t0.退出系统\t\t\t\n");
        printf("*********************************************\n");
}

//录入
void InputStudent()
{
    //创建一个节点

    Node* pNewNode = (Node*)malloc(sizeof(Node));
    pNewNode->pNext = NULL;


    //头插法
    if(g_pHead == NULL)
    {
        g_pHead = pNewNode;
    }
    else
    {
        pNewNode->pNext = g_pHead;
        g_pHead = pNewNode;
    }

    printf("请输入学生姓名：\n");
    scanf("%s",pNewNode->stu.name);  //键盘接受
    printf("请输入学生年龄：\n");
    scanf("%d",&pNewNode->stu.age);   //&整数，要加取地址运算符
    printf("请输入学生的学号：\n");
    scanf("%d",&pNewNode->stu.stuNum);
    printf("请输入学生的成绩：\n");
    scanf("%d",&pNewNode->stu.score);
    printf("学生成绩录入成功。\n");
    system("pause");   //暂停
    system("cls");     //清屏



}


//打印
void PrintStudent()
{
        printf("*********************************************\n");
        printf("\t欢迎使用学生成绩管理系统\t\n");
        printf("*********************************************\n");
        printf("\t学号\t姓名\t年龄\t成绩\n");
        printf("*********************************************\n");


        //遍历链表
        Node* p = g_pHead;
        while(p != NULL)
        {
            printf("\t%d\t%s\t%d\t%d\n",
                   p->stu.stuNum,
                   p->stu.name,
                   p->stu.age,
                   p->stu.score);

            p = p->pNext;
        }

        printf("*********************************************\n");
        system("pause");   //暂停
        system("cls");     //清屏
}


//保存
void SaveStudent()
{
    //打开文件
    FILE* fp = fopen("F:\\student.dat","w");

    if(fp == NULL)
    {
        printf("打开文件失败。\n");
        return;
    }

    //遍历链表
    Node* p = g_pHead;
        while(p != NULL)
        {
            fwrite(&p->stu,1,sizeof(Student),fp);
            p = p->pNext;
        }

    //关闭文件
    fclose(fp);
    printf("保存成功。\n");
    system("pause");   //暂停
    system("cls");     //清屏

}


//读取
void ReadStudent()
{
    //打开文件
    FILE* fp = fopen("F:\\student.dat","r");

    if(fp == NULL)
    {
        printf("打开文件失败。\n");
        return;
    }
    //读取
    Student stu;
    while(fread(&stu,1,sizeof(Student),fp))
    {
        //创建一个新节点
        Node* pNewNode = (Node*)malloc(sizeof(Node));

        pNewNode->pNext = NULL;

        memcpy(pNewNode,&stu,sizeof(Student));
        //头插法
        if(g_pHead == NULL)
        {
            g_pHead = pNewNode;
        }
        else
        {
            pNewNode->pNext = g_pHead;
            g_pHead = pNewNode;
        }
    }



    //关闭文件
    fclose(fp);
    printf("加载数据成功。\n");
    system("pause");   //暂停
    system("cls");     //清屏

}


//统计人数
int CountStudent()
{
    int nCount = 0; //总数

    //遍历链表
    Node* p = g_pHead;
    while(p != NULL)
    {
        nCount++;
        p = p->pNext;
    }
    return nCount;
}


//查找学生
void FindStudent(Node* FindStudent())
{
    int nStuNum;
    printf("请输入要查找的学号\n");
    scanf("%d",&nStuNum);

    Node* p = g_pHead;
    while(p != NULL)
    {
        if(p->stu.stuNum == nStuNum)
        {
            printf("\t学号:%d\t姓名:%s\t年龄:%d\t成绩:%d\n",p->stu.stuNum,p->stu.name,p->stu.age,p->stu.score);
            return p;

        }
        p = p->pNext;


    }

    printf("没有找到\n");
    return NULL;

}


//修改
void ModifyStudent()
{
    int nStuNum;
    printf("请输入要修改的学号：\n");
    scanf("%d",&nStuNum);

    Node* p = g_pHead;
    while(p != NULL)
    {

        if(p->stu.stuNum == nStuNum )
        {
            printf("请输入要修改的学生姓名、年龄、成绩：\n");
            scanf("%s %d %d",p->stu.name,&p->stu.age,&p->stu.score);
            printf("修改成功\n");
            break;
        }
        p = p->pNext;
    }

    if(p == NULL)
    {
        printf("没有找到该学生。\n");
    }
    system("pause");   //暂停
    system("cls");     //清屏
}

//删除
void DeleteStudent()
{
    int nStuNum;
    printf("请输入要删除的学号\n");

    scanf("%d",&nStuNum);

    Node* p1;

    //头结点判断
    if(g_pHead->stu.stuNum == nStuNum)
    {
        p1 = g_pHead;
        g_pHead = g_pHead->pNext;
        free(p1);
        system("pause");   //暂停
        system("cls");     //清屏
        return;
    }
    //不是头
    Node* p = g_pHead;
    Node* p2;
    while(p->pNext != NULL)
    {
        if(p->pNext->stu.stuNum == nStuNum)
        {
            p2 = p->pNext;
            p->pNext = p->pNext->pNext;
            free(p2);
            return;
        }
        p = p->pNext;
        if(p->pNext == NULL)
        {
            break;
        }
    }
    if(p->pNext == NULL)
        {
           printf("没有找到该学生\n");
        }
        //printf("删除成功\n");

}
