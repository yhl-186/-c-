#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#define LIST_MAX_SIZE  100//˳�����󳤶�
void lmain();//��½����
void land();//�����˻�����ĵ�¼����
void toxy(int x, int y)      //������ƶ���X,Y���괦
{
    COORD pos = { x , y };
    HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(Out, pos);
}
int match(int m, char a[20]);//�˶��˺�����
int tj3();//ͳ���˺��������
int tj2;//ͳ�������������
#define LEN2 sizeof(struct land)
struct land//��¼��Ϣ
{
    int zhanghao;
    char password[20];
    struct land *next;
};
int tj3()//ͳ���˺������ı�����
{
    FILE* fp;
    int zhao = 0, n;
    char mm[20] = { '\0' };
    fp = fopen("data3.txt", "r");//���ļ�
    for (n = 0; !feof(fp); n++)//������ļ�
        fscanf(fp, "%d %s", &zhao, mm);
    n--;
    fclose(fp);//�ر��ļ�
    return (n);//���ظ���
}
void lmain()//��¼���ܺ���
{
    char choose;
    toxy(48, 8);
    printf("*****��ӭʹ����ҵ������Ϣ����ϵͳ*****");
    toxy(48, 10);
    printf("                ���¼                ");
    toxy(48, 12);
    printf("                1.��¼				  ");
    toxy(48, 14);
    printf("                2.�˳�				  ");
    toxy(48, 16);
    scanf(" %c", &choose);
    switch (choose)//���ܺ���
    {
    case'1':
        land();
        break;
    case'2':
        system("cls");
        getch();
        exit(0);//�޴����˳��������� 
        break;
    }
}


int match(int m, char a[20])//ƥ�����ݿ��е��˺�����

{
    FILE* fp;
    int n = 0, i = 0;
    int zhanghao;
    char password[20];
    if ((fp = fopen("data3.txt", "r")) == NULL)//�������ļ�
    {
        system("cls");
        printf("\n �˺Ų�����,�����������");
        getch();
        system("cls");
        land();
    }
    for (; !feof(fp);)
    {
        fscanf(fp, "%d%s", &zhanghao, password);
        if (m == zhanghao)
        {
            if (strcmp(a, password) == 0)
                {
                    return 1;
                }
            else
            {
                return -1;
            }
        }
    }
    return 0;
}
typedef struct //��������ڱ�ʾԱ����Ϣ
{
	char num[8];//Ա����
	char name[20];//����
	char sex[10];//�Ա�
	char department[20];//����
	char date[20];//����
	char phone[20];//�绰
	char work[20];//ְ�� 
	char chuqin[20];//�������
	char age[30];//����
}Staff;

typedef struct
{
	 Staff data[LIST_MAX_SIZE];//������
	int length;//��
}SqList;

//�������
void add(SqList *L1);//���Ա��������Ϣ
void ran(SqList *L1);//������Ϣ����
void select_num(SqList *L1);//��Ա��������ѯ
void select_name(SqList *L1);//��Ա������ѯ
void select_all(SqList *L1);//��ѯ����Ա��
void delete_staff(SqList *L1);//ɾ��Ա��������Ϣ
void change(SqList *L1);//�޸�Ա��������Ϣ
void read(SqList *L1);//�ļ���Ա��������Ϣ
void write(SqList *L1);//�ļ�дԱ��������Ϣ
void menu();//�˵�
void xz();//ѡ��˵� 
void menu()//���˵�
{
    system("cls");
    toxy(40, 4);
    printf("**��ҵ������Ϣ����ϵͳ**");
    toxy(40, 6);
    printf("1.Ա����Ϣ¼��");
    toxy(40, 8);
    printf("2.Ա����Ϣ���");
    toxy(40, 10);
    printf("3.��Ա���Ų�ѯ");
    toxy(40, 12);
    printf("4.����������ѯ");
    toxy(40, 14);
    printf("5.�޸�Ա����Ϣ");
    toxy(40, 16);
    printf("6.ɾ��Ա����Ϣ");
    toxy(40, 18);
    printf("7.��Ա��������");
    toxy(40, 20);
    printf("0.�˳�ϵͳ");
    toxy(40, 22);
    printf("�밴��ѡ�񣬻س�ȷ��");
    toxy(40, 24);
    printf("************************");
    toxy(40,26);
    return;
}
void land()//�����˻�����ĵ�¼����
{
    int zhanghao;
    char password[20];
    int i = 2, j, k, n;
    char hit = 0;
    system("cls");
    do
    {
        system("cls");
        if(tj2==0)
        {
            toxy(44,6);
            printf("����ϸ����Ҫ���¼����½������δ�ɹ�ϵͳ���Զ��˳���");
        }
        toxy(44,8);
        printf("�������˺�:");
        scanf("%d", &zhanghao);
        system("cls");
        toxy(44,10);
        printf("ȷ�������밴�س������������밴Esc");
        hit = getch();
        for (; hit != 13 && hit != 27;)
        {
            hit = getch();
        }
    } while (hit == 27);
    system("cls");
    toxy(44,12);
    printf("����������:");
    {  
        int p;
        for(p=0;p<20;p++)
        {
            password[p]=getch();
            if(password[p]=='\b'&&p>0)
                {
                    p--;
                    p--;
                    printf("\b \b");
                }
        else
          {
            if(password[p]==13)
             {
                break;
             }
            printf("*");
         }
       }
        password[p]='\0';
    }
    i = match(zhanghao, password);
    if (i == 1)
    {
        system("cls");
        toxy(44,10);
        printf("��½�ɹ�!�����������");
        getch();
        xz();
    }
    else
    {
        tj2++;
        if(tj2==3)
        {
            system("cls");
            toxy(44,10);
            printf("�������δ���ϵͳ��ǿ���˳�!");
            Sleep(1000);
            exit(0);
        }
        if (i == -1&&tj2!=3)
        {
            system("cls");
            toxy(44,10);
            printf("��¼ʧ��!�������룡����������µ�¼");
            getch();
            land();
        }
        if (i == 0&&tj2!=3)
            {
                system("cls");
                toxy(44,10);
                printf("�����ڴ��û�!�����������");
            }
        getch();
        system("cls");
        lmain();
    }
}


void xz()//ѡ��˵� 
{
	char x;
	SqList *L1;
	L1 = (SqList*)malloc(sizeof(SqList));
	L1->length = 0;
	read(L1);//�ļ���

	while (1)
	{
		menu();//����ѡ�� 
		printf("���������ѡ��");
		scanf("%c", &x);
		switch (x)
		{
		case '1':
			add(L1);//Ա����Ϣ¼��
			write(L1);//�ļ�д��Ա����Ϣ
			break;
		case '2':
			select_all(L1);//Ա����Ϣ���
			break;
		case '3':
			select_num(L1);//����Ա���Ų�ѯ
			break;
		case '4':
			select_name(L1);//����������ѯ
			break;
		case '5':
			change(L1);//�޸�Ա����Ϣ
			write(L1);//�ļ�д��Ա����Ϣ
			break;
		case '6':
			delete_staff(L1);//ɾ��Ա����Ϣ
			write(L1);//�ļ�д��Ա����Ϣ
			break;
		case '7':
			ran(L1);//����Ա���Ž�������
			break;
		case '0':
			system("cls");
        	getch();
        	exit(0);
        	break;
		default:
			printf("��������������ѡ��!\n");
			break;
		}

	}
}
void delete_staff(SqList *L1)//ɾ��Ա��
{
	int i,j;
	char no[20];
	system("cls");
	printf("����Ҫɾ����Ա����:");
	scanf("%s",no);
	for(i=0;i<L1->length;i++)//�������
	{
		if(!strcmp(no,L1->data[i].num))//���Ա����һ��
		{
			break;
		}
	}
	if(i==L1->length)//��ѯ����β��û������ѭ��
	{
		printf("ɾ��ʧ��!\n");
		return;
	}
	for(j=i;j<L1->length-1;j++)
	{
		L1->data[j]=L1->data[j+1];//�ú�һ������ǰ��һ�� �ﵽɾ����Ч��
	}
	L1->length--;//����-1
	printf("ɾ���ɹ�!\n");
}

void change(SqList *L1)//�ı�Ա����Ϣ
{
	int i;
	char no[20];
	system("cls");
	printf("����Ա����:");
	scanf("%s",no);
	for(i=0;i<L1->length;i++)//�������
	{
		if(!strcmp(no,L1->data[i].num))//���Ա����һ��
		{
			break;
		}
	}
	if(i==L1->length)//��ѯ����β��û������ѭ��
	{
		printf("�޸�ʧ��!\n");
		return;
	}
	printf("����������:");
	scanf("%s",L1->data[i].name);
	printf("�������Ա�:");
	scanf("%s",L1->data[i].sex);
	printf("����������:");
	scanf("%s",L1->data[i].age);
	printf("������绰:");
	scanf("%s",L1->data[i].phone);
	printf("�����벿��:");
	scanf("%s",L1->data[i].department);
	printf("������ְ��:");
	scanf("%s",L1->data[i].work);
	printf("�����뿼������(xxxx-xx-xx):");
	scanf("%s",L1->data[i].date);
	printf("������������:");
	scanf("%s",L1->data[i].chuqin);
	printf("�޸ĳɹ�!\n");
}

void ran(SqList *L1)//��Ա��������
{
	int i,j;
	Staff temp;
	system("cls");
	for(i=0;i<L1->length;i++)
	{
		for(j=i+1;j<L1->length;j++)//ѡ������ ÿ��ѭ���ź�һ��data[i]
		{
			if(strcmp(L1->data[i].num,L1->data[j].num)>0)//�����Ҫ���� 
			{
				temp=L1->data[i];
				L1->data[i]=L1->data[j];
				L1->data[j]=temp;
			}
		}
	}
	printf("�������Ա���������Ľ��:\n");
	select_all(L1);//��������ʾ
	getch();
    xz();//������һ��
}
void select_num(SqList *L1)//��Ա���Ų�ѯ
{
	int i,flag=0;
	char no[20];
	system("cls");
	printf("����Ա����:");
	scanf("%s",no);
	for(i=0;i<L1->length;i++)//��������
	{
		if(!strcmp(no,L1->data[i].num))//����������Ա����һ��
		{
			flag=1;
			printf("%-10s%-10s%-10s%-10s%-20s%-10s%-20s%-20s%-20s\n","Ա����","����","�Ա�","����","�绰","����","ְ��","��������","�������");
			printf("%-10s%-10s%-10s",L1->data[i].num,L1->data[i].name,L1->data[i].sex);
			printf("%-10s%-20s%-10s",L1->data[i].age,L1->data[i].phone,L1->data[i].department);
			printf("%-20s%-20s%-20s\n",L1->data[i].work,L1->data[i].date,L1->data[i].chuqin);	
		}
	}
	if(flag==0)//��ѯ����β��û������ѭ��
	{
		printf("�޸�Ա����Ϣ!\n");
	}
	getch();
    xz();//������һ��
}

void select_name(SqList *L1)//��������ѯ
{
	int i,flag=0;
	char name[20];
	system("cls");
	printf("����Ա������:");
	scanf("%s",name);
	for(i=0;i<L1->length;i++)//��������
	{
		if(!strcmp(name,L1->data[i].name))//�������һ�� 
		{
			printf("%-10s%-10s%-10s%-10s%-20s%-10s%-20s%-20s%-20s\n","Ա����","����","�Ա�","����","�绰","����","ְ��","��������","�������");
			printf("%-10s%-10s%-10s",L1->data[i].num,L1->data[i].name,L1->data[i].sex);
			printf("%-10s%-20s%-10s",L1->data[i].age,L1->data[i].phone,L1->data[i].department);
			printf("%-20s%-20s%-20s\n",L1->data[i].work,L1->data[i].date,L1->data[i].chuqin);	
			flag=1;//���ñ�־ ��ʾ��ѯ����  ���ﲻ���� ����Ϊ �������ܻ��ظ� ��Ҫ���ظ�����Ҳ��ʾ
		}
	}
	if(flag==0)//��ѯ����β��û������ѭ��
	{
		printf("�޸�������Ϣ!\n");
	}
	getch();
    xz();//������һ��
}

void add(SqList *L1)//��� 
{
	system("cls");
	if(L1->length>=LIST_MAX_SIZE)//����ﵽ����󳤶�
	{
		printf("˳��������޷����!\n");
		return ;
	}
	printf("������Ա����:");
	scanf("%s",L1->data[L1->length].num);//��Ϣ�����β L1->length ��˳���ǰ���� ��L1->length��Ԫ�ز�δ��ʹ�� ����ֱ�Ӵ�������
	printf("����������:");
	scanf("%s",L1->data[L1->length].name);
	printf("�������Ա�:");
	scanf("%s",L1->data[L1->length].sex);
	printf("����������:");
	scanf("%s",L1->data[L1->length].age);
	printf("������绰:");
	scanf("%s",L1->data[L1->length].phone);
	printf("�����벿��:");
	scanf("%s",L1->data[L1->length].department);
	printf("������ְ��:");
	scanf("%s",L1->data[L1->length].work);
	printf("������������ڣ�xxxx-xx-xx��:");
	scanf("%s",L1->data[L1->length].date);
	printf("������������:");
	scanf("%s",L1->data[L1->length].chuqin);
	L1->length++;//��+1 ʹ�øոմ��������Ч
}

void select_all(SqList *L1)//��ʾ���е�Ա����Ϣ
{
	int i;
	system("cls");
	if(L1->length==0)//˳�����Ϊ0
	{
		printf("��Ա����Ϣ!\n");
		return;
	}
	printf("%-10s%-10s%-10s%-10s%-20s%-10s%-20s%-20s%-20s\n","Ա����","����","�Ա�","����","�绰","����","ְ��","��������","�������");
	for(i=0;i<L1->length;i++)//�������
	{
		printf("%-10s%-10s%-10s",L1->data[i].num,L1->data[i].name,L1->data[i].sex);
		printf("%-10s%-20s%-10s",L1->data[i].age,L1->data[i].phone,L1->data[i].department);
		printf("%-20s%-20s%-20s\n",L1->data[i].work,L1->data[i].date,L1->data[i].chuqin);
	}
	getch();
    xz();//������һ��
}

void read(SqList *L1)//�ļ���
{
	FILE *fp;
	int a = 0;//a,����ʶ�𵽵���û��ɾ������.t,��������fsacnf�����ķ���ֵ(Ϊ-1��˵��������)
	if ((fp = fopen("Staff.txt", "r+")) == NULL)//��r�������
	{
		printf("�ļ���ʧ��!\n");
		return;
	}
	else
	{
		while (!feof(fp))
		{
			a = 1;
			fread(&L1->data[L1->length++],sizeof(Staff),1,fp);
		}
		fclose(fp);		//�ر��ļ�
		if (a == 0)
		{
			printf("�ı�������,Ա��������Ϣ��ȡʧ��\n");
		}
		else
		{
			L1->length--;
		}
	}
}

void write(SqList *L1)//�ļ�д
{
	FILE *fp;
	int t = 0;
	int i;
	if ((fp = fopen("Staff.txt", "w+")) == NULL)
	{
		printf("�ļ���ʧ��!\n");
		return;
	}
	else
	{
		for (i = 0; i < L1->length; i++)
		{
			t=1;
			fwrite(&L1->data[i],sizeof(Staff),1,fp);
		}
		fclose(fp);	//�ر��ļ�
		if(L1->length==0)
		{
			t=1;
		}
		if (t == 1)
		{
			printf("Ա����Ϣд�����\n");
		}
		else
		{
			printf("Ա��������Ϣд��ʧ��\n");
		}
	}
}
int main()

{
    system("color F");
    
    lmain();
    return 0;
}
