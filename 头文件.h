//���¶�����ͷ�ļ��� 
#ifndef _ACCOUNT_H_ 
#define _ACCOUNT_H_

#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>
#include<windows.h>

//���½����˺궨�� 

#define NAME 20
#define SEX 5
#define JOB 30
#define HANDSET 20
#define ADDRESS 40
#define ACCOUNT_NUM 20  //account_single�ṹ�����˻��ṹ���Ա�ĳ���
#define ACCOUNT_PASSWORD 20
//���¶���ͨѶ¼�˻��ṹ��

struct account_single{
	char account_number[ACCOUNT_NUM];
	char account_password[ACCOUNT_PASSWORD];
	struct account_single *next;
}account_single;
#define LEN_ACCOUNT sizeof(account_single)
//���¶���ͨѶ¼�ṹ��
struct address_list{
	char name[NAME];
	char sex[SEX];
	char job[JOB];
	char handset[HANDSET];
	char address[ADDRESS];
	struct address_list *next;
}address_list;
//���½����˽ṹ�峤�ȵĺ궨�� 
#define LEN sizeof(address_list)
int n;  	//��ǰͨѶ¼�е����� 

//��������������
void print(struct address_list *head);  //���ͨѶ¼��Ϣ���� 
void print_single(struct address_list *single);//��ʾ������ϵ�˵���Ϣ 
struct address_list *paixu(struct address_list *head);  //������
struct address_list *search(struct address_list *head); //���Һ���
struct address_list *insert(struct address_list *head);  // �����Ϣ
void save(struct address_list *head,char *filep);//���溯�� 
struct address_list *load(struct address_list *head,char *filep);   //��ͨѶ¼���� 
struct address_list *delete_single(struct address_list *head,struct address_list *delet); //ɾ������
struct address_list *shifang(struct address_list *head);  //�˳�����
struct address_list *alter(struct address_list *head,struct address_list *alter_pointer);//�޸ĺ���
struct address_list *search_easy(struct address_list *head);//ֻ�ܲ�����ϵ�˲����ظ���ϵ�˵�ַ�ĺ��� 
struct account_single *load_account(struct account_single *head_account);//���ļ��е��˺����뺯��
void menu_account();//�˺�����Ĳ˵� 
char *login(struct account_single *head_account);//��¼����
struct account_single *enroll(struct account_single *head_account);//ע���û�
void save_enroll(struct account_single *head_account);//����ע���û����˺�����
void save_excel(struct address_list *head,char *filep);//�����ݵ�����excel 
void alter_password(struct account_single *head_account,char *account_word);//�޸����뺯�� 

#endif
