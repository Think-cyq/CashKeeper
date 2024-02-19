#define BANK_H_INCLUDED
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define upNum 2000

typedef struct account
{

    float iae;
    char aim;
    int year;
    int month;
    int day;
    double balance;

} Account;

int N;
Account acc1[upNum];
typedef Account expenseRecord[100];
char _name[10];
int _password;
int Record_count;

void menu();
void sigin();        // 登陆或注册
void login();        // 注册账号
void logon();        // 账号登陆
void save();         // 存款记录
void withdraw();     // 取款记录
void show_balance(); // 显示余额
void show_record();  // 显示所有账单
void find_Data();    // 查找某天的账单
void over();         // 退出系统
int inputPassword(); // 返回键盘输入的密码

void menu()
{
    do
    {
        char t;
        printf("          欢迎来到牙签记账软件           \n");
        printf("***************************************\n");
        printf("|              1.存款记录              |\n");
        printf("|              2.取款记录              |\n");
        printf("|              3.显示余额              |\n");
        printf("|              4.查看某天账单           |\n");
        printf("|              5 查看所有账单          |\n");
        printf("|              6.退出系统              |\n");
        printf("请选择：\n");
        t = getch(); // 利用不回显函数，输入t，可以不用手动按回车键
        switch (t)
        {
        case '1':
            save();
            break;
        case '2':
            withdraw();
            break;
        case '3':
            show_balance();
            break;
        case '4':
            find_Data();
            break;
        case '5':
            show_record();
            break;
        case '6':
            over();
            break;
        default:;
            break;
        }
    } while (1);
}

// 选择登陆还是注册
void signin()
{
    char t;
    printf("          欢迎来到牙签记账软件        \n");
    printf("************************************\n");
    printf("|              1.登陆               |\n");
    printf("|              2.注册               |\n");
    printf("************************************\n");
    while (1)
    {
        t = getch();
        switch (t)
        {
        case '1':
            logon();
            break;
        case '2':
            login();
            break;
        default:
            break;
        }
    }
}

// 登陆
void logon()
{
    char name[10];
    int Password;  // 业务员登录时输入的密码
    int right = 0; // 要返回的结果：0-不正确 1-正确
    printf("请输入账户的主人：");
    scanf("%s", name);
    if (strcmp(name, _name) != 0)
    {
        printf("休想偷偷看%s的理财机密\n", name);
        logon();
    }
    else
    {
        printf("该软件设置密码统一为6位数！\n");
        printf("请输入密码:");
        Password = inputPassword();
        if (Password == _password)
        {
            right = 1;
        }
        else
        {
            printf("对不起，密码错误\n");
        }
        if (right == 1)
            menu();
        else
            return;
    }
}

// 用户注册
void login()
{
    // 下面正常办理开户业务
    printf("正在开户\n");
    printf("户主姓名：");
    scanf("%s", _name);
    int iPass1, iPass2;
    printf("密码：");
    iPass1 = inputPassword(); // 输入密码1
    printf("确认密码：");
    iPass2 = inputPassword(); // 输入密码2
    if (iPass1 == iPass2)
    {
        _password = iPass1;
        printf("拥有的本金：");
        scanf("%lf", &acc1[Record_count].balance);
        acc1[Record_count].aim = 'i';
        
        Record_count++;
        printf("独一份的记账生成成功，开始你的记账之旅吧！\n");
        menu();
    }
    else
    {
        printf("两次密码不一致，未成功开户！\n");
    }
}

void save()
{
    do
    {
        char t;
        printf("哇！收获第一桶金\n");
        printf("记录下这个光荣的进账日期：");
        scanf("%d%d%d", &acc1[Record_count].year, &acc1[Record_count].month, &acc1[Record_count].day);
        printf("请输入金额：");
        scanf("%f", &acc1[Record_count].iae);
        getchar();
        printf("请输入收入来源或支出目的：");
        scanf("%c", &acc1[Record_count].aim);
        getchar();
        printf("%f\n", acc1[Record_count - 1].balance);
        acc1[Record_count].balance = acc1[Record_count - 1].balance + acc1[Record_count].iae;
        printf("存款后，还有%.2f元\n", acc1[Record_count].balance);
        Record_count++;
        printf("|  保存成功！是否继续？  |\n");
        printf("| 1.是             2.否 |\n");
        printf("|                       |\n");
        printf("-------------------------\n");
        while (1)
        {
            t = getch(); // 输入t
            if (t == '1')
            {
                break;
            }
            else if (t == '2') // 如果输入t为2，进入菜单
            {
                menu();
                break;
            }
        }
    } while (1); // 永远为真
}

void withdraw()
{
    do
    {
        char t;
        printf("哇！败家玩意！\n");
        printf("记录下这个光荣的出账日期：");
        scanf("%d%d%d", &acc1[Record_count].year, &acc1[Record_count].month, &acc1[Record_count].day);
        printf("请输入金额：\n");
        scanf("%f", &acc1[Record_count].iae);

        getchar();
        printf("请输入收入来源或支出目的：\n");
        scanf("%c", &acc1[Record_count].aim);
        
        getchar();
        if (acc1[Record_count].iae > acc1[Record_count - 1].balance)
        {
            printf("%d\n", Record_count);
            printf("%f\n", acc1[Record_count].balance);
            printf("这点钱还花，根本不够！");
        }
        else
        {
            acc1[Record_count].balance = acc1[Record_count - 1].balance - acc1[Record_count].iae;
            printf("存款后，还有%.2f元\n", acc1[Record_count].balance);
            Record_count++;
            printf("| 保存成功！是否继续？  |\n");
            printf("| 1.是             2.否|\n");
            printf("|                       |\n");
            printf("-------------------------\n");
        }
        while (1)
        {
            t = getch(); // 输入t
            if (t == '1')
            {
                break;
            }
            else if (t == '2') // 如果输入t为2，进入菜单
            {
                menu();
                break;
            }
        }
    } while (1); // 永远为真
}

void show_balance()
{
    char name[10];
    int id;
    printf("用户：");
    scanf("%s", &name);
    if (strcmp(name, _name) != 0) // 说明id账户不存在
    {
        printf("你不是本人嘞！\n");
    }
    else
    {
        printf("用户姓名：%s\n", name);
        {
            printf("余额：%.2f元. \n", acc1[Record_count].balance);
        }
    }
    return;
}

void show_record()
{
    printf("以下为全部账单，请注意查收：\n");
    for (int i = 0; i < Record_count; i++)
    {
        printf("%s %d-%d-%d %d %f %c %f\n", _name, acc1[i].year, acc1[i].month, acc1[i].day, _password, acc1[i].iae, acc1[i].aim, acc1[i].balance);
    }
}

void find_Data()
{
    int Target_year, Target_month, Target_day;
    printf("小伙，砸你得告诉我你要查哪一天：\n");
    scanf("%d %d %d", &Target_year, &Target_month, &Target_day);
    for (int i = 1; i <= Record_count; i++)
    {
        printf("%d\n", acc1[i].year);
        if (acc1[i].year == Target_year && acc1[i].month == Target_month && acc1[i].day == Target_day)
        {
            printf("%s %d %d %d %d %f %s %lf", _name, acc1[i].year, acc1[i].month, acc1[i].day, _password, acc1[i].iae, acc1[i].aim, acc1[Record_count].balance);
        }
    }
}

void readData()
{
    FILE *fp; // 用于文件操作
    int i = 0;
    // 从文件中取出余额
    if ((fp = fopen("account1.txt", "a+")) == NULL)
    {
        printf("data file cannot open!");
        exit(0);
    }
    while (fscanf(fp, "%s %d-%d-%d %d %f %c %lf", _name, &acc1[i].year, &acc1[i].month, &acc1[i].day, &_password, &acc1[i].iae, &acc1[i].aim, &acc1[i].balance) != EOF)
    {
        i++;
    }
    Record_count = i;
    
    fclose(fp);
    return;
}

// 将数据保存到文件中
void writeData()
{
    FILE *fp; // 用于文件操作
    // 保存余额
    if ((fp = fopen("account1.txt", "w")) == NULL)
    {
        printf("data file cannot open!");
        exit(0);
    }
    for (int i = 0; i < Record_count; i++)
    {
        fprintf(fp, "%s %d-%d-%d %d %.2f %c %.2f\n", _name, acc1[i].year, acc1[i].month, acc1[i].day, _password, acc1[i].iae, acc1[i].aim, acc1[i].balance);
    }
    fclose(fp);
}

int inputPassword()
{
    char ch;       // 接收字符形式密码
    int iPass = 0; // 要转换为数字
    int i;
    while (1)
    {
        for (i = 0; i < 6; i++)
        {
            ch = getch(); // 输入但不显示
            putchar('*'); // 输出*
            if (isdigit(ch))
                iPass = iPass * 10 + (ch - '0');
            else
            {
                iPass = 0;
                break; // 退出for循环后，再次接受
            }
        }
        fflush(stdin); // 清除键盘缓存区中已经有的输入
        printf("\n");
        if (iPass == 0) // 此条件成立可能由两种情况引起：输入了非数字字符被直接重置为0，或6位全0后正常退出for循环
        {
            printf("密码要求全为数字，且不全为0！\n");
            printf("请重新输入密码: ");
        }
        else
            break;
    }
    return iPass;
}

// 退出系统
void over()
{
    char t;
    printf("-----------------------------\n");
    printf("|         你确定要退出吗？     \n");
    printf("|      1.确定        2.取消    \n");
    printf("------------------------------\n");
    while (1)
    {
        t = getch();
        switch (t)
        {
        case '1':
            printf("已安全退出软件！\n");
            printf("欢迎您下次使用牙签软件！\n");
            printf("bye,bye了您嘞");
            writeData();
            exit(0);
            break;
        case '2':
            menu();
            break;
        default:
            break;
        }
    }
}

int main()
{
    system("title 管理系统");
    readData();
    signin();
    writeData();
    printf("%c", acc1[Record_count].aim);

    return 0;
}
