//以下定义了头文件名 
#ifndef _ACCOUNT_H_ 
#define _ACCOUNT_H_

#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>
#include<windows.h>

//以下进行了宏定义 

#define NAME 20
#define SEX 5
#define JOB 30
#define HANDSET 20
#define ADDRESS 40
#define ACCOUNT_NUM 20  //account_single结构体中账户结构体成员的长度
#define ACCOUNT_PASSWORD 20
//以下定义通讯录账户结构体

struct account_single{
	char account_number[ACCOUNT_NUM];
	char account_password[ACCOUNT_PASSWORD];
	struct account_single *next;
}account_single;
#define LEN_ACCOUNT sizeof(account_single)
//以下定义通讯录结构体
struct address_list{
	char name[NAME];
	char sex[SEX];
	char job[JOB];
	char handset[HANDSET];
	char address[ADDRESS];
	struct address_list *next;
}address_list;
//以下进行了结构体长度的宏定义 
#define LEN sizeof(address_list)
int n;  	//当前通讯录中的人数 

//以下声明函数名
void print(struct address_list *head);  //输出通讯录信息函数 
void print_single(struct address_list *single);//显示单个联系人的信息 
struct address_list *paixu(struct address_list *head);  //排序函数
struct address_list *search(struct address_list *head); //查找函数
struct address_list *insert(struct address_list *head);  // 添加信息
void save(struct address_list *head,char *filep);//保存函数 
struct address_list *load(struct address_list *head,char *filep);   //打开通讯录函数 
struct address_list *delete_single(struct address_list *head,struct address_list *delet); //删除函数
struct address_list *shifang(struct address_list *head);  //退出函数
struct address_list *alter(struct address_list *head,struct address_list *alter_pointer);//修改函数
struct address_list *search_easy(struct address_list *head);//只能查找联系人并返回该联系人地址的函数 
struct account_single *load_account(struct account_single *head_account);//打开文件中的账号密码函数
void menu_account();//账号密码的菜单 
char *login(struct account_single *head_account);//登录函数
struct account_single *enroll(struct account_single *head_account);//注册用户
void save_enroll(struct account_single *head_account);//保存注册用户的账号密码
void save_excel(struct address_list *head,char *filep);//将数据导出到excel 
void alter_password(struct account_single *head_account,char *account_word);//修改密码函数 

#endif
