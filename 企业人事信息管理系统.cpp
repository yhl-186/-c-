#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#define LIST_MAX_SIZE  100//顺序表最大长度
void lmain();//登陆函数
void land();//输入账户密码的登录函数
void toxy(int x, int y)      //将光标移动到X,Y坐标处
{
    COORD pos = { x , y };
    HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(Out, pos);
}
int match(int m, char a[20]);//核对账号密码
int tj3();//统计账号密码个数
int tj2;//统计输入密码次数
#define LEN2 sizeof(struct land)
struct land//登录信息
{
    int zhanghao;
    char password[20];
    struct land *next;
};
int tj3()//统计账号密码文本个数
{
    FILE* fp;
    int zhao = 0, n;
    char mm[20] = { '\0' };
    fp = fopen("data3.txt", "r");//打开文件
    for (n = 0; !feof(fp); n++)//逐个读文件
        fscanf(fp, "%d %s", &zhao, mm);
    n--;
    fclose(fp);//关闭文件
    return (n);//返回个数
}
void lmain()//登录功能函数
{
    char choose;
    toxy(48, 8);
    printf("*****欢迎使用企业人事信息管理系统*****");
    toxy(48, 10);
    printf("                请登录                ");
    toxy(48, 12);
    printf("                1.登录				  ");
    toxy(48, 14);
    printf("                2.退出				  ");
    toxy(48, 16);
    scanf(" %c", &choose);
    switch (choose)//功能函数
    {
    case'1':
        land();
        break;
    case'2':
        system("cls");
        getch();
        exit(0);//无错误退出整个进程 
        break;
    }
}


int match(int m, char a[20])//匹配数据库中的账号密码

{
    FILE* fp;
    int n = 0, i = 0;
    int zhanghao;
    char password[20];
    if ((fp = fopen("data3.txt", "r")) == NULL)//不存在文件
    {
        system("cls");
        printf("\n 账号不存在,按任意键继续");
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
typedef struct //定义的用于表示员工信息
{
	char num[8];//员工号
	char name[20];//姓名
	char sex[10];//性别
	char department[20];//部门
	char date[20];//日期
	char phone[20];//电话
	char work[20];//职务 
	char chuqin[20];//出勤情况
	char age[30];//年龄
}Staff;

typedef struct
{
	 Staff data[LIST_MAX_SIZE];//数据域
	int length;//表长
}SqList;

//功能设计
void add(SqList *L1);//添加员工考勤信息
void ran(SqList *L1);//出勤信息排序
void select_num(SqList *L1);//按员工姓名查询
void select_name(SqList *L1);//按员工名查询
void select_all(SqList *L1);//查询所有员工
void delete_staff(SqList *L1);//删除员工考勤信息
void change(SqList *L1);//修改员工考勤信息
void read(SqList *L1);//文件读员工考勤信息
void write(SqList *L1);//文件写员工考勤信息
void menu();//菜单
void xz();//选择菜单 
void menu()//主菜单
{
    system("cls");
    toxy(40, 4);
    printf("**企业人事信息管理系统**");
    toxy(40, 6);
    printf("1.员工信息录入");
    toxy(40, 8);
    printf("2.员工信息浏览");
    toxy(40, 10);
    printf("3.按员工号查询");
    toxy(40, 12);
    printf("4.按照姓名查询");
    toxy(40, 14);
    printf("5.修改员工信息");
    toxy(40, 16);
    printf("6.删除员工信息");
    toxy(40, 18);
    printf("7.按员工号排序");
    toxy(40, 20);
    printf("0.退出系统");
    toxy(40, 22);
    printf("请按键选择，回车确定");
    toxy(40, 24);
    printf("************************");
    toxy(40,26);
    return;
}
void land()//输入账户密码的登录函数
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
            printf("请仔细按照要求登录，登陆三次仍未成功系统将自动退出！");
        }
        toxy(44,8);
        printf("请输入账号:");
        scanf("%d", &zhanghao);
        system("cls");
        toxy(44,10);
        printf("确认输入请按回车，重新输入请按Esc");
        hit = getch();
        for (; hit != 13 && hit != 27;)
        {
            hit = getch();
        }
    } while (hit == 27);
    system("cls");
    toxy(44,12);
    printf("请输入密码:");
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
        printf("登陆成功!按任意键继续");
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
            printf("输入三次错误，系统将强制退出!");
            Sleep(1000);
            exit(0);
        }
        if (i == -1&&tj2!=3)
        {
            system("cls");
            toxy(44,10);
            printf("登录失败!请检查密码！按任意键重新登录");
            getch();
            land();
        }
        if (i == 0&&tj2!=3)
            {
                system("cls");
                toxy(44,10);
                printf("不存在此用户!按任意键继续");
            }
        getch();
        system("cls");
        lmain();
    }
}


void xz()//选择菜单 
{
	char x;
	SqList *L1;
	L1 = (SqList*)malloc(sizeof(SqList));
	L1->length = 0;
	read(L1);//文件读

	while (1)
	{
		menu();//界面选择 
		printf("请输入你的选择：");
		scanf("%c", &x);
		switch (x)
		{
		case '1':
			add(L1);//员工信息录入
			write(L1);//文件写入员工信息
			break;
		case '2':
			select_all(L1);//员工信息浏览
			break;
		case '3':
			select_num(L1);//按照员工号查询
			break;
		case '4':
			select_name(L1);//按照姓名查询
			break;
		case '5':
			change(L1);//修改员工信息
			write(L1);//文件写入员工信息
			break;
		case '6':
			delete_staff(L1);//删除员工信息
			write(L1);//文件写入员工信息
			break;
		case '7':
			ran(L1);//按照员工号进行排序
			break;
		case '0':
			system("cls");
        	getch();
        	exit(0);
        	break;
		default:
			printf("输入有误，请重新选择!\n");
			break;
		}

	}
}
void delete_staff(SqList *L1)//删除员工
{
	int i,j;
	char no[20];
	system("cls");
	printf("输入要删除的员工号:");
	scanf("%s",no);
	for(i=0;i<L1->length;i++)//遍历输出
	{
		if(!strcmp(no,L1->data[i].num))//如果员工号一样
		{
			break;
		}
	}
	if(i==L1->length)//查询到表尾都没有跳出循环
	{
		printf("删除失败!\n");
		return;
	}
	for(j=i;j<L1->length-1;j++)
	{
		L1->data[j]=L1->data[j+1];//用后一个覆盖前面一个 达到删除的效果
	}
	L1->length--;//人数-1
	printf("删除成功!\n");
}

void change(SqList *L1)//改变员工信息
{
	int i;
	char no[20];
	system("cls");
	printf("输入员工号:");
	scanf("%s",no);
	for(i=0;i<L1->length;i++)//遍历输出
	{
		if(!strcmp(no,L1->data[i].num))//如果员工号一样
		{
			break;
		}
	}
	if(i==L1->length)//查询到表尾都没有跳出循环
	{
		printf("修改失败!\n");
		return;
	}
	printf("请输入姓名:");
	scanf("%s",L1->data[i].name);
	printf("请输入性别:");
	scanf("%s",L1->data[i].sex);
	printf("请输入年龄:");
	scanf("%s",L1->data[i].age);
	printf("请输入电话:");
	scanf("%s",L1->data[i].phone);
	printf("请输入部门:");
	scanf("%s",L1->data[i].department);
	printf("请输入职务:");
	scanf("%s",L1->data[i].work);
	printf("请输入考勤日期(xxxx-xx-xx):");
	scanf("%s",L1->data[i].date);
	printf("请输入出勤情况:");
	scanf("%s",L1->data[i].chuqin);
	printf("修改成功!\n");
}

void ran(SqList *L1)//按员工号排序
{
	int i,j;
	Staff temp;
	system("cls");
	for(i=0;i<L1->length;i++)
	{
		for(j=i+1;j<L1->length;j++)//选择排序 每次循环排好一个data[i]
		{
			if(strcmp(L1->data[i].num,L1->data[j].num)>0)//如果需要交换 
			{
				temp=L1->data[i];
				L1->data[i]=L1->data[j];
				L1->data[j]=temp;
			}
		}
	}
	printf("输出根据员工号排序后的结果:\n");
	select_all(L1);//排序完显示
	getch();
    xz();//返回上一层
}
void select_num(SqList *L1)//按员工号查询
{
	int i,flag=0;
	char no[20];
	system("cls");
	printf("输入员工号:");
	scanf("%s",no);
	for(i=0;i<L1->length;i++)//遍历查找
	{
		if(!strcmp(no,L1->data[i].num))//如果和输入的员工号一样
		{
			flag=1;
			printf("%-10s%-10s%-10s%-10s%-20s%-10s%-20s%-20s%-20s\n","员工号","姓名","性别","年龄","电话","部门","职务","考勤日期","出勤情况");
			printf("%-10s%-10s%-10s",L1->data[i].num,L1->data[i].name,L1->data[i].sex);
			printf("%-10s%-20s%-10s",L1->data[i].age,L1->data[i].phone,L1->data[i].department);
			printf("%-20s%-20s%-20s\n",L1->data[i].work,L1->data[i].date,L1->data[i].chuqin);	
		}
	}
	if(flag==0)//查询到表尾都没有跳出循环
	{
		printf("无该员工信息!\n");
	}
	getch();
    xz();//返回上一层
}

void select_name(SqList *L1)//按姓名查询
{
	int i,flag=0;
	char name[20];
	system("cls");
	printf("输入员工姓名:");
	scanf("%s",name);
	for(i=0;i<L1->length;i++)//遍历查找
	{
		if(!strcmp(name,L1->data[i].name))//如果姓名一样 
		{
			printf("%-10s%-10s%-10s%-10s%-20s%-10s%-20s%-20s%-20s\n","员工号","姓名","性别","年龄","电话","部门","职务","考勤日期","出勤情况");
			printf("%-10s%-10s%-10s",L1->data[i].num,L1->data[i].name,L1->data[i].sex);
			printf("%-10s%-20s%-10s",L1->data[i].age,L1->data[i].phone,L1->data[i].department);
			printf("%-20s%-20s%-20s\n",L1->data[i].work,L1->data[i].date,L1->data[i].chuqin);	
			flag=1;//设置标志 表示查询到了  这里不跳出 是因为 姓名可能会重复 需要把重复的人也显示
		}
	}
	if(flag==0)//查询到表尾都没有跳出循环
	{
		printf("无该姓名信息!\n");
	}
	getch();
    xz();//返回上一层
}

void add(SqList *L1)//添加 
{
	system("cls");
	if(L1->length>=LIST_MAX_SIZE)//如果达到了最大长度
	{
		printf("顺序表满，无法添加!\n");
		return ;
	}
	printf("请输入员工号:");
	scanf("%s",L1->data[L1->length].num);//信息存入表尾 L1->length 是顺序表当前长度 第L1->length个元素并未被使用 所以直接存在里面
	printf("请输入姓名:");
	scanf("%s",L1->data[L1->length].name);
	printf("请输入性别:");
	scanf("%s",L1->data[L1->length].sex);
	printf("请输入年龄:");
	scanf("%s",L1->data[L1->length].age);
	printf("请输入电话:");
	scanf("%s",L1->data[L1->length].phone);
	printf("请输入部门:");
	scanf("%s",L1->data[L1->length].department);
	printf("请输入职务:");
	scanf("%s",L1->data[L1->length].work);
	printf("请输入出勤日期（xxxx-xx-xx）:");
	scanf("%s",L1->data[L1->length].date);
	printf("请输入出勤情况:");
	scanf("%s",L1->data[L1->length].chuqin);
	L1->length++;//表长+1 使得刚刚存的数据有效
}

void select_all(SqList *L1)//显示所有的员工信息
{
	int i;
	system("cls");
	if(L1->length==0)//顺序表长度为0
	{
		printf("无员工信息!\n");
		return;
	}
	printf("%-10s%-10s%-10s%-10s%-20s%-10s%-20s%-20s%-20s\n","员工号","姓名","性别","年龄","电话","部门","职务","考勤日期","出勤情况");
	for(i=0;i<L1->length;i++)//遍历输出
	{
		printf("%-10s%-10s%-10s",L1->data[i].num,L1->data[i].name,L1->data[i].sex);
		printf("%-10s%-20s%-10s",L1->data[i].age,L1->data[i].phone,L1->data[i].department);
		printf("%-20s%-20s%-20s\n",L1->data[i].work,L1->data[i].date,L1->data[i].chuqin);
	}
	getch();
    xz();//返回上一层
}

void read(SqList *L1)//文件读
{
	FILE *fp;
	int a = 0;//a,用来识别到底有没有删除数据.t,用来接收fsacnf函数的返回值(为-1是说明无数据)
	if ((fp = fopen("Staff.txt", "r+")) == NULL)//‘r’允许读
	{
		printf("文件打开失败!\n");
		return;
	}
	else
	{
		while (!feof(fp))
		{
			a = 1;
			fread(&L1->data[L1->length++],sizeof(Staff),1,fp);
		}
		fclose(fp);		//关闭文件
		if (a == 0)
		{
			printf("文本无数据,员工考勤信息读取失败\n");
		}
		else
		{
			L1->length--;
		}
	}
}

void write(SqList *L1)//文件写
{
	FILE *fp;
	int t = 0;
	int i;
	if ((fp = fopen("Staff.txt", "w+")) == NULL)
	{
		printf("文件打开失败!\n");
		return;
	}
	else
	{
		for (i = 0; i < L1->length; i++)
		{
			t=1;
			fwrite(&L1->data[i],sizeof(Staff),1,fp);
		}
		fclose(fp);	//关闭文件
		if(L1->length==0)
		{
			t=1;
		}
		if (t == 1)
		{
			printf("员工信息写入完成\n");
		}
		else
		{
			printf("员工考勤信息写入失败\n");
		}
	}
}
int main()

{
    system("color F");
    
    lmain();
    return 0;
}
