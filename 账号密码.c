#include"account.h"
//�����Ǵ��ļ��е��˺����뺯�� 
struct account_single *load_account(struct account_single *head_account)
{
	FILE *fp;
	struct account_single *p1, *p2;
	fp = fopen("ͨѶ¼�˺�����","a+");
	if(fp == NULL){
		printf("�ļ��򿪴�����struct account_single *load_account�����С�\n");
		return head_account;
	}
	p1 = (struct account_single *)malloc(LEN_ACCOUNT);
	fscanf(fp,"%s%s",&p1->account_number,&p1->account_password);
	if(feof(fp) != 0){
		printf("��ǰ��ע���û���\n");
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
		printf("account_single�˺��ļ�����ϡ�\n");
		printf("��������������\n");
		system("pause");
		fclose(fp);
	}
	return head_account;	
} 

//�������˺�����Ĳ˵� 

void menu_account()
{
	int i=20;
	printf("=================================================================\n");
	printf("=======================ͨѶ¼�˺�ע��============================\n\n\n\n");
	printf("==\t\t\t1.ע��\t\t\t==\n");
	printf("==\t\t\t2.��¼\t\t\t==\n");
	printf("=================================================================\n\n\n");
	printf("��ѡ��ѡ�");	 
} 

//�������û�ע�ắ�� 

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
	printf("�������˺ţ�\n");
	fflush(stdin);
	gets(account_numb);
	for(;p3 != NULL;p3 = p3->next){
		if(strcmp(account_numb,p3->account_number) == 0){
			printf("���˺��Ѿ���ע�ᡣ\n");
			system("pause");
			return head_account;
		}
	}

		printf("���˺ſ���ʹ�á�\n");
		p0 = (struct account_single *)malloc(LEN_ACCOUNT);
		strcpy(p0->account_number,account_numb);
		while(1)
		{
			printf("���������루15λ���ڵ��ַ�����");
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
			printf("\n�������������루15λ���ڵ��ַ�����");
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
				printf("\n�������óɹ���\n");
				system("pause");
				break;
			}
			else
				printf("�����������벻��ͬ���������������롣\n");	
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
				printf("ע��ɹ��ɹ��������������...\n");
			}
			return head_account;
		}
} 


//��¼����


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
		printf("��ǰû���Ѿ�ע����û���\n");
		system("pause");
		return p3; 
	}
	printf("�������˺ţ�15λ�ַ����ڣ���");
	fflush(stdin);
	gets(account_numb);
	for(;p3 != NULL;p3 = p3->next){
		if(strcmp(account_numb,p3->account_number) == 0){
			break;
		}
	}

	if(p3 == NULL){
		printf("���˻���û��ע�ᡣ\n");
		system("pause");
		return p3;
	}	
	printf("���������루15λ���ڵ��ַ�����");
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
		printf("\n������ȷ���ڵ�¼\n");
		for(t=0;t<8;t++){
			Sleep(100);
			printf(".");
		}
		return p3->account_number;
	} 
	else{
		printf("\n�������,�������������롣\n");
		printf("���������루15λ���ڵ��ַ�����");
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
			printf("\n������ȷ���ڵ�¼\n");
			for(t=0;t<8;t++){
				Sleep(100);
				printf(".");
			}
			return p3->account_number;
		}
		else{
			printf("\n����������󡣳��򼴽��˳�\n");
			system("pause");
			exit(0); 
		}
	}
}

void save_enroll(struct account_single *head_account)
{
	FILE *fp;
	struct account_single *p1;
	fp = fopen("ͨѶ¼�˺�����","w");  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!û��д 
	if(fp == NULL){
		printf("�����ļ�ʱ���ļ�ʧ�ܣ���save_enroll�ļ��С�\n");
		exit(0);
	}
	p1 = head_account;
	while(p1 != NULL){
		fprintf(fp,"%s       %s        ",p1->account_number,p1->account_password);
		p1 = p1->next;
	}
	fclose(fp);
} 
//�޸����뺯�� 
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
		printf("��������Ҫ�޸ĵ����루15λ���ڵ��ַ�����");
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
		printf("\n�������������루15λ���ڵ��ַ�����");
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
			printf("\n�������óɹ���\n");
			system("pause");
			break;
		}
		else
			printf("�����������벻��ͬ���������������롣\n");	
	}
	
}