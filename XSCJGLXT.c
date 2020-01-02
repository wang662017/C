#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    while(1)
    {
        Welcome();

        //�Ӽ��̽����ַ�ָ��
        //getch����һ���ַ������ð��س�
        char ch = getch();

        switch(ch)
        {
        case'1'://¼��ѧ����Ϣ
            InputStudent();
            break;
        case'2'://��ӡѧ����Ϣ
            PrintStudent();
            break;
        case'3'://����ѧ����Ϣ
            SaveStudent();
            break;
        case'4'://��ȡѧ����Ϣ
            ReadStudent();
            break;
        case'5'://ͳ��ѧ����Ϣ
            printf("ѧ��������Ϊ��%d\n",CountStudent());
            system("pause");   //��ͣ
            system("cls");     //����
            break;
        case'6'://����ѧ����Ϣ
            FindStudent();
            system("pause");   //��ͣ
            system("cls");     //����
            break;
        case'7'://�޸�ѧ����Ϣ
            ModifyStudent();
            break;
        case'8'://ɾ��ѧ����Ϣ
            DeleteStudent();
            break;
        case'0'://�˳�
            printf("�ټ�\n");
            return 0;
        default:
            printf("����������\n");

        }
    }


    return 0;
}


//����ѧ��
typedef struct _Student
{
    char name[20]; //����
    int age;       //����
    int stuNum;    //ѧ��
    int score;     //�ɼ�
}Student;



//�ڵ�
typedef struct _Node
{
    Student stu;  //ѧ��
    struct _Node* pNext;  //ָ����һ���ڵ�


}Node;


//����һ��ͷ���
Node* g_pHead = NULL;


//��ӭ
void Welcome()
{
        printf("*********************************************\n");
        printf("\t��ӭʹ��ѧ���ɼ�����ϵͳ\t\n");
        printf("*********************************************\n");
        printf("\t\t  ѡ����\t\t\t\n");
        printf("*********************************************\n");
        printf("\t\t1.¼��ѧ����Ϣ\t\t\t\n");
        printf("\t\t2.��ӡѧ����Ϣ\t\t\t\n");
        printf("\t\t3.����ѧ����Ϣ\t\t\t\n");
        printf("\t\t4.��ȡѧ����Ϣ\t\t\t\n");
        printf("\t\t5.ͳ������ѧ������\t\t\t\n");
        printf("\t\t6.����ѧ����Ϣ\t\t\t\n");
        printf("\t\t7.�޸�ѧ����Ϣ\t\t\t\n");
        printf("\t\t8.ɾ��ѧ����Ϣ\t\t\t\n");
        printf("\t\t0.�˳�ϵͳ\t\t\t\n");
        printf("*********************************************\n");
}

//¼��
void InputStudent()
{
    //����һ���ڵ�

    Node* pNewNode = (Node*)malloc(sizeof(Node));
    pNewNode->pNext = NULL;


    //ͷ�巨
    if(g_pHead == NULL)
    {
        g_pHead = pNewNode;
    }
    else
    {
        pNewNode->pNext = g_pHead;
        g_pHead = pNewNode;
    }

    printf("������ѧ��������\n");
    scanf("%s",pNewNode->stu.name);  //���̽���
    printf("������ѧ�����䣺\n");
    scanf("%d",&pNewNode->stu.age);   //&������Ҫ��ȡ��ַ�����
    printf("������ѧ����ѧ�ţ�\n");
    scanf("%d",&pNewNode->stu.stuNum);
    printf("������ѧ���ĳɼ���\n");
    scanf("%d",&pNewNode->stu.score);
    printf("ѧ���ɼ�¼��ɹ���\n");
    system("pause");   //��ͣ
    system("cls");     //����



}


//��ӡ
void PrintStudent()
{
        printf("*********************************************\n");
        printf("\t��ӭʹ��ѧ���ɼ�����ϵͳ\t\n");
        printf("*********************************************\n");
        printf("\tѧ��\t����\t����\t�ɼ�\n");
        printf("*********************************************\n");


        //��������
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
        system("pause");   //��ͣ
        system("cls");     //����
}


//����
void SaveStudent()
{
    //���ļ�
    FILE* fp = fopen("F:\\student.dat","w");

    if(fp == NULL)
    {
        printf("���ļ�ʧ�ܡ�\n");
        return;
    }

    //��������
    Node* p = g_pHead;
        while(p != NULL)
        {
            fwrite(&p->stu,1,sizeof(Student),fp);
            p = p->pNext;
        }

    //�ر��ļ�
    fclose(fp);
    printf("����ɹ���\n");
    system("pause");   //��ͣ
    system("cls");     //����

}


//��ȡ
void ReadStudent()
{
    //���ļ�
    FILE* fp = fopen("F:\\student.dat","r");

    if(fp == NULL)
    {
        printf("���ļ�ʧ�ܡ�\n");
        return;
    }
    //��ȡ
    Student stu;
    while(fread(&stu,1,sizeof(Student),fp))
    {
        //����һ���½ڵ�
        Node* pNewNode = (Node*)malloc(sizeof(Node));

        pNewNode->pNext = NULL;

        memcpy(pNewNode,&stu,sizeof(Student));
        //ͷ�巨
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



    //�ر��ļ�
    fclose(fp);
    printf("�������ݳɹ���\n");
    system("pause");   //��ͣ
    system("cls");     //����

}


//ͳ������
int CountStudent()
{
    int nCount = 0; //����

    //��������
    Node* p = g_pHead;
    while(p != NULL)
    {
        nCount++;
        p = p->pNext;
    }
    return nCount;
}


//����ѧ��
void FindStudent(Node* FindStudent())
{
    int nStuNum;
    printf("������Ҫ���ҵ�ѧ��\n");
    scanf("%d",&nStuNum);

    Node* p = g_pHead;
    while(p != NULL)
    {
        if(p->stu.stuNum == nStuNum)
        {
            printf("\tѧ��:%d\t����:%s\t����:%d\t�ɼ�:%d\n",p->stu.stuNum,p->stu.name,p->stu.age,p->stu.score);
            return p;

        }
        p = p->pNext;


    }

    printf("û���ҵ�\n");
    return NULL;

}


//�޸�
void ModifyStudent()
{
    int nStuNum;
    printf("������Ҫ�޸ĵ�ѧ�ţ�\n");
    scanf("%d",&nStuNum);

    Node* p = g_pHead;
    while(p != NULL)
    {

        if(p->stu.stuNum == nStuNum )
        {
            printf("������Ҫ�޸ĵ�ѧ�����������䡢�ɼ���\n");
            scanf("%s %d %d",p->stu.name,&p->stu.age,&p->stu.score);
            printf("�޸ĳɹ�\n");
            break;
        }
        p = p->pNext;
    }

    if(p == NULL)
    {
        printf("û���ҵ���ѧ����\n");
    }
    system("pause");   //��ͣ
    system("cls");     //����
}

//ɾ��
void DeleteStudent()
{
    int nStuNum;
    printf("������Ҫɾ����ѧ��\n");

    scanf("%d",&nStuNum);

    Node* p1;

    //ͷ����ж�
    if(g_pHead->stu.stuNum == nStuNum)
    {
        p1 = g_pHead;
        g_pHead = g_pHead->pNext;
        free(p1);
        system("pause");   //��ͣ
        system("cls");     //����
        return;
    }
    //����ͷ
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
           printf("û���ҵ���ѧ��\n");
        }
        //printf("ɾ���ɹ�\n");

}
