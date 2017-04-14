#include"account.h"
//以下是打开文件中的账号密码函数 
struct account_single *load_account(struct account_single *head_account)
{
	FILE *fp;
	struct account_single *p1, *p2;
	fp = fopen("通讯录账号密码","a+");
	if(fp == NULL){
		printf("文件打开错误，在struct account_single *load_account函数中。\n");
		return head_account;
	}
	p1 = (struct account_single *)malloc(LEN_ACCOUNT);
	fscanf(fp,"%s%s",&p1->account_number,&p1->account_password);
	if(feof(fp) != 0){
		printf("当前无注册用户。\n");
		fclose(fp);
		return(head_account); 
	}
	else{
		rewind(fp);
		p1 = (struct account_single *)malloc(LEN_ACCOUNT);
		p2 = p1;
		head_account = p1;
		while(feof(fp) == 0){
			fscanf(fp,"%s%s",&p1->account_number,&p1->account_password);
			if(feof(fp) != 0){
				break;
			}
			p2->next = p1;
			p2 = p1;
			p1 = (struct account_single *)malloc(LEN_ACCOUNT);
		}
		p2->next = NULL;
		printf("account_single账号文件打开完毕。\n");
		printf("按任意键进入程序\n");
		system("pause");
		fclose(fp);
	}
	return head_account;	
} 

//以下是账号密码的菜单 

void menu_account()
{
	int i=20;
	printf("=================================================================\n");
	printf("=======================通讯录账号注册============================\n\n\n\n");
	printf("==\t\t\t1.注册\t\t\t==\n");
	printf("==\t\t\t2.登录\t\t\t==\n");
	printf("=================================================================\n\n\n");
	printf("请选择选项：");	 
} 

//以下是用户注册函数 

struct account_single *enroll(struct account_single *head_account)
{
	struct account_single *p0, *p1, *p3;
	char account_numb[20]={0};
	char password1[20] = {0};
	char password2[20] = {0};
	char c;
	int i = 0;
	p1 = head_account;
	p3 = head_account;
	printf("请输入账号：\n");
	fflush(stdin);
	gets(account_numb);
	for(;p3 != NULL;p3 = p3->next){
		if(strcmp(account_numb,p3->account_number) == 0){
			printf("该账号已经被注册。\n");
			system("pause");
			return head_account;
		}
	}

		printf("该账号可以使用。\n");
		p0 = (struct account_single *)malloc(LEN_ACCOUNT);
		strcpy(p0->account_number,account_numb);
		while(1)
		{
			printf("请输入密码（15位以内的字符）：");
			fflush(stdin);
			while(1){
				c = getch();
				if(c == '\r'){
					break;
				}
				if(c == '\b'){
					if(i==0)
						continue;
					printf("\b \b");
					i--;
				}
				else{
					password1[i++] = c;
					printf("*"); 
				}
			}
			i = 0;
			printf("\n请再输输入密码（15位以内的字符）：");
			fflush(stdin);
			while(1){
				c = getch();
				if(c == '\r'){
					break;
				}
				if(c == '\b'){
					if(i==0)
						continue;
					printf("\b \b");
					i--;
				}
				else{
					password2[i++] = c;
					printf("*"); 
				}
			}
			if(strcmp(password1,password2) == 0){
				strcpy(p0->account_password,password1);
				printf("\n密码设置成功！\n");
				system("pause");
				break;
			}
			else
				printf("两次密码输入不相同，请重新输入密码。\n");	
		}

		if(head_account == NULL){
			head_account = p0;
			p0->next = NULL;
			return head_account;
		}
		else{
			for(;p1->next != NULL;){
				p1 = p1->next;
			}
			if(p1->next == NULL){
				p1->next = p0;
				p0->next = NULL;
				printf("注册成功成功。按任意键继续...\n");
			}
			return head_account;
		}
} 


//登录函数


char *login(struct account_single *head_account)
{
	struct account_single *p0, *p3;
	char c;
	char account_numb[20]={0};
	char password1[20]={0};
	char password2[20]={0};
	int i=0;
	int t=0;
	p0 = head_account;
	p3 = head_account;
	if(head_account == NULL){
		printf("当前没有已经注册的用户。\n");
		system("pause");
		return p3; 
	}
	printf("请输入账号（15位字符以内）：");
	fflush(stdin);
	gets(account_numb);
	for(;p3 != NULL;p3 = p3->next){
		if(strcmp(account_numb,p3->account_number) == 0){
			break;
		}
	}

	if(p3 == NULL){
		printf("该账户还没有注册。\n");
		system("pause");
		return p3;
	}	
	printf("请输入密码（15位以内的字符）：");
	fflush(stdin);
	while(1){
		c = getch();
		if(c == '\r'){
			break;
		}
		if(c == '\b'){
			if(i==0)
				continue;
			printf("\b \b");
			i--;
		}
		else{
			password1[i++] = c;
			printf("*"); 
		}
	}
	if(strcmp(p3->account_password,password1) == 0){
		printf("\n密码正确正在登录\n");
		for(t=0;t<8;t++){
			Sleep(100);
			printf(".");
		}
		return p3->account_number;
	} 
	else{
		printf("\n密码错误,请重新输入密码。\n");
		printf("请输入密码（15位以内的字符）：");
		i=0;
		fflush(stdin);
		while(1){
			c = getch();
			if(c == '\r'){
				break;
			}
			if(c == '\b'){
				if(i==0)
					continue;
				printf("\b \b");
				i--;
			}
			else{
				password2[i++] = c;
				printf("*"); 
			}
		}
		if(strcmp(p3->account_password,password2) == 0){
			printf("\n密码正确正在登录\n");
			for(t=0;t<8;t++){
				Sleep(100);
				printf(".");
			}
			return p3->account_number;
		}
		else{
			printf("\n密码输入错误。程序即将退出\n");
			system("pause");
			exit(0); 
		}
	}
}

void save_enroll(struct account_single *head_account)
{
	FILE *fp;
	struct account_single *p1;
	fp = fopen("通讯录账号密码","w");  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!没有写 
	if(fp == NULL){
		printf("保存文件时打开文件失败，在save_enroll文件中。\n");
		exit(0);
	}
	p1 = head_account;
	while(p1 != NULL){
		fprintf(fp,"%s       %s        ",p1->account_number,p1->account_password);
		p1 = p1->next;
	}
	fclose(fp);
} 
//修改密码函数 
void alter_password(struct account_single *head_account,char *account_word)
{
	struct account_single *p3;
	char c;
	char password1[20] = {0};
	char password2[20] = {0};
	int i=0;
	int t=0;
	p3 = head_account;
	for(;p3 != NULL;p3 = p3->next){
		if(strcmp(account_word,p3->account_number) == 0){
			break;
		}
	}
	while(1)
	{
		printf("请输入您要修改的密码（15位以内的字符）：");
		fflush(stdin);
		while(1){
			c = getch();
			if(c == '\r'){
				break;
			}
			if(c == '\b'){
				if(i==0)
					continue;
				printf("\b \b");
				i--;
			}
			else{
				password1[i++] = c;
				printf("*"); 
			}
		}
		i = 0;
		printf("\n请再输输入密码（15位以内的字符）：");
		fflush(stdin);
		while(1){
			c = getch();
			if(c == '\r'){
				break;
			}
			if(c == '\b'){
				if(i==0)
					continue;
				printf("\b \b");
				i--;
			}
			else{
				password2[i++] = c;
				printf("*"); 
			}
		}
		if(strcmp(password1,password2) == 0){
			strcpy(p3->account_password,password1);
			printf("\n密码设置成功！\n");
			system("pause");
			break;
		}
		else
			printf("两次密码输入不相同，请重新输入密码。\n");	
	}
	
}