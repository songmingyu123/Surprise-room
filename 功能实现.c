#include"account.h"

/*��ȡ�ļ��е�ͨѶ¼��Ϣ*/ 
struct address_list *load(struct address_list *head,char *filep)   
{
	FILE *fp;
	struct address_list *p1, *p2;
	fp = fopen(filep,"ab+");
	if(fp == NULL){
		printf("�ļ��򿪴�����struct address_list *load�����С�\n");
		return head;
	}
	p1 = (struct address_list *)malloc(LEN);
	fread(p1,LEN,1,fp);
	if(feof(fp) != 0){
		printf("��ǰ����ͨѶ¼��û����ϵ�ˡ�\n");
		n = 0;
	 	m = 0;
		fclose(fp);
		return(head); 
	}
	else{
		rewind(fp);
		p1 = (struct address_list *)malloc(LEN);
		p2 = p1;
		head = p1;
		n = 0;
		while(feof(fp) == 0){
			fread(p1,LEN,1,fp);
			if(feof(fp) != 0){
				break;
			}
			p1 = (struct address_list *)malloc(LEN);
			p2->next = p1;
			p2 = p1;
			//p1 = (struct address_list *)malloc(LEN);      
			n = n+1;
			m = m+1;
		}
		p1->next = NULL;
		p2->next = NULL;
		printf("����ϡ�\n");
		fclose(fp);
	}
	return head;
}
/*��ͨѶ¼�������ϵ��*/
struct address_list *insert(struct address_list *head)  // �����Ϣ
{
	struct address_list *p0, *p1, *p3;
	char name[20]={0};
	char a;
	p1 = head;
	p3 = head; 
	printf("������Ҫ�������ϵ����Ϣ��\n");
	printf("��������ϵ�����֣�\n");
	gets(name);
	for(;p3 != NULL;p3 = p3->next){
		if(strcmp(name,p3->name) == 0){
			printf("����ϵ���Ѿ�������ͨѶ¼�С�\n");
			print_single(p3);
			printf("\n\n�Ƿ�ȷ��������Ӹ���ϵ�ˣ���y/n��\n");
			fflush(stdin);
			a = getchar();
			if(a=='y') break;
			else return head;
			
		}
	}
		p0 = (struct address_list *)malloc(LEN);
		n++;
		m++;
		p0->bianhao_address_list = m;
		strcpy(p0->name,name);
		printf("�������Ա�");
		fflush(stdin);
		gets(p0->sex);
		printf("�����빤����");
		gets(p0->job);
		printf("������绰��");
		gets(p0->handset);
		printf("�������ַ��");
		gets(p0->address);
		if(head == NULL){
			head = p0;
			p0->next = NULL;
			return head;
		}
		else{
			for(;p1->next != NULL;){
				p1 = p1->next;
			}
			if(p1->next == NULL){
				p1->next = p0;
				p0->next = NULL;
				printf("��ӳɹ��������������...\n");
			}
			return head;
		}
} 
/*չʾͨѶ¼��������ϵ�˵���Ϣ*/
void print(struct address_list *head)  //���ͨѶ¼��Ϣ���� 
{
	struct address_list *p;
	if(head != NULL){
		p = head;
		printf("����%dλ��ϵ�ˣ����������򣩣�\n",n);
		printf("---����--------------�Ա�------------����-----------�绰--------------��ַ\n\n\n");
		do{
			printf("%s",p->name);
			printf("		");	
			printf("%s",p->sex);
			printf("		");	
			printf("%s",p->job);
			printf("		");	
			printf("%s",p->handset);
			printf("		");	
			printf("%s",p->address);
			printf("		\n");
			p = p->next;
		}while(p != NULL);
		printf("\n=========================================================================\n");
	}
	else{
		printf("ͨѶ¼Ϊ�ա�\n");
	}
	system("pause");
} 
/*��ͨѶ¼�е���ϵ�˰����ֵ�ƴ����������*/
struct address_list *paixu(struct address_list *head)  //������
{
	struct address_list *p1, *p2;
	int i,j,k;
	struct address_list1{
		int bianhao_address_list;
		char name[NAME];
		char sex[SEX];
		char job[JOB];
		char handset[HANDSET];
		char address[ADDRESS];
	};
	struct address_list1 px[200];
	struct address_list1 temp;
	if(head == NULL){
		printf("ͨѶ¼Ϊ�գ��޷�����\n");
		return head; 
	}
	p1 = head;
	for(i=0;i<n;i++){
		px[i].bianhao_address_list = p1->bianhao_address_list;
		strcpy(px[i].name,p1->name);
		strcpy(px[i].sex,p1->sex);
		strcpy(px[i].job,p1->job);
		strcpy(px[i].handset,p1->handset);
		strcpy(px[i].address,p1->address);
		p2 = p1;
		p1 = p1->next;
	}
	head = shifang(head);
     // zhangsan    chenggong     wanger
	for(j=0;j<n-1;j++){
		for(i=j+1;i<n;i++){
			if(strcmp(px[i].name,px[j].name)<0){
				temp = px[j];
				px[j] = px[i];
				px[i] = temp;				
			}
		}
	}
	p1 = (struct address_list *)malloc(LEN);
	p2 = p1;
	p1->bianhao_address_list = px[0].bianhao_address_list;
	strcpy(p1->name,px[0].name);
	strcpy(p1->sex,px[0].sex);
	strcpy(p1->job,px[0].job);
	strcpy(p1->handset,px[0].handset);
	strcpy(p1->address,px[0].address);
	head = p1;
	for(i=1;i<n;i++){
		p1 = (struct address_list *)malloc(LEN);
		p1->bianhao_address_list = px[i].bianhao_address_list;
		strcpy(p1->name,px[i].name);
		strcpy(p1->sex,px[i].sex);
		strcpy(p1->job,px[i].job);
		strcpy(p1->handset,px[i].handset);
		strcpy(p1->address,px[i].address);
		p2->next = p1;
		p2 = p1;
	}
	p2->next = NULL;
	return head; 
}
/*��ͨѶ¼�е���ϵ�˱��浽�ļ���*/ 
void save(struct address_list *head,char *filep)		//���溯��
{
	FILE *fp;
	char account_num[20]={0};
	struct address_list *p1;
	strcpy(account_num,filep);
	fp = fopen(account_num,"wb");  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!û��д 
	if(fp == NULL){
		printf("�����ļ�ʱ���ļ�ʧ�ܣ���save�ļ��С�\n");
		fclose(fp);
		exit(0);
	}
	p1 = head;
	while(p1 != NULL){
		fwrite(p1,LEN,1,fp);
		p1 = p1->next;
	}
	fclose(fp);
}
//��ʾ������ϵ�˵���Ϣ
void print_single(struct address_list *single)	 
{
	printf("\n---���----------����--------------�Ա�------------����-----------�绰--------------��ַ\n");
	printf("%d",single->bianhao_address_list); 
	printf("		");	
	printf("%s",single->name);
	printf("		");	
	printf("%s",single->sex);
	printf("		");	
	printf("%s",single->job);
	printf("		");	
	printf("%s",single->handset);
	printf("		");	
	printf("%s\n",single->address);
	printf("========================================================================\n\n\n");	
}
/*ͨ������ģ����ѯ��ϵ����Ϣ����չʾ����ϵ����Ϣ*/
struct address_list *search(struct address_list *head)		 //���Һ���
{
	char name[20];  	//Ҫ���ҵ����ֵ��ַ������߲����ַ�����ģ����ѯ��   
	char name1[20]; 	//ͨѶ¼���Ѿ��е����֣�������Ҫ���ҵ����ֽ��бȽ��ж��Ƿ���� 
	int i=0,j=0,flag=0,k=0;
	int find_number=0;
	struct address_list *p1, *p2; 
	if(head == NULL){
		printf("���˻�ͨѶ��û����ϵ�ˡ�\n");
		system("pause");
		return head;   //��ǰheadΪNULL 
	}
	p1 = head;
	printf("**************************************\n");
	printf("������Ҫ���ҵ�������֧��ģ����ѯ���������ֵ�һ���ּ��ɣ���\n");
	printf("**************************************\n");
	printf("�����룺");
	gets(name);
	while(p1 != NULL){
		strcpy(name1,p1->name);
		i = strlen(name1);
		j = strlen(name);
		flag = 0;
		for(k=0;k<i;k++){
			if(name1[k] == name[flag])
				flag++;
		}
		if(flag == j){
			find_number++;
			print_single(p1); 
		}
		p1 = p1->next;
	}
	system("pause");
	if(find_number == 0){
		printf("δ�ҵ���ϵ�ˡ�\n");
		system("pause");
	}
}
//�˳�����
struct address_list *shifang(struct address_list *head)
{
	struct address_list *p1;
	while(head != NULL){
		p1 = head;
		head = head->next;
		free(p1);
	}
	return head;
}
//�޸�ͨѶ¼�е���ϵ�˵���Ϣ���� 
struct address_list *alter(struct address_list *head,struct address_list *alter_pointer)
{
	struct address_list1{
		int b;
		char name[NAME];
		char sex[SEX];
		char job[JOB];
		char handset[HANDSET];
		char address[ADDRESS];
	}address;
	char a; 
	struct address_list *p3;
	p3 = head;
	printf("������Ҫ�������ϵ����Ϣ��\n");
	printf("��������ϵ�����֣�\n");
	fflush(stdin);
	gets(address.name);
	for(;p3 != NULL;p3 = p3->next){
		if(strcmp(address.name,p3->name) == 0){
			printf("����ϵ���Ѿ�������ͨѶ¼�С�\n");
			print_single(p3);
			printf("\n\n�Ƿ�����޸ĸ���ϵ�ˣ���y/n��\n");
			fflush(stdin);
			a = getchar();
			if(a=='y') break;
			else return head;
		}
	}
		strcpy(alter_pointer->name,address.name);
		fflush(stdin); 
		printf("�������Ա�");
		gets(address.sex);
		strcpy(alter_pointer->sex,address.sex);
		printf("�����빤����");
		gets(address.job);
		strcpy(alter_pointer->job,address.job);
		printf("������绰��");
		gets(address.handset);
		strcpy(alter_pointer->handset,address.handset);
		printf("�������ַ��");
		gets(address.address);
		strcpy(alter_pointer->address,address.address);
		return head;
} 

//ֻ�ܲ�����ϵ�˲����ظ���ϵ�˵�ַ�ĺ��� 
struct address_list *search_easy(struct address_list *head)
{
	struct address_list *p = NULL; //������ϵ��ʱ��p�������
	struct address_list *p_bianhao = NULL; //���ұ�ţ�ȷ����ϵ��ʱ��p_bianhao������� 
	char name[20];
	int i = 0;
	int bianhao = -1;
	if(head == NULL){
		printf("����ͨѶ��û����ϵ�ˡ�\n");
		system("pause"); 
		return head;
	}
	p_bianhao = head;
	printf("���ٴ�ȷ�����Ƿ�Ҫ�Ը���ϵ�˽��в������������û�������������");
	gets(name);
	p = head;
	system("cls");
	for(;p != NULL;){
		if(strcmp(name,p->name) == 0){
			i++;
			print_single(p);
		}
		p = p->next;
	}
	if(i == 0){
		printf("δ�ҵ�����ϵ�ˡ�\n");
		system("pause");
		return p;
	}
	printf("\n����������Ҫ��������ϵ�˵ı�ţ�");
	scanf("%d",&bianhao);
	for(;p_bianhao != NULL;){
		if(p_bianhao->bianhao_address_list == bianhao){
			return p_bianhao;
		}
		p_bianhao = p_bianhao->next;
	}
	
}
//ɾ��ĳ����ϵ�˵ĺ���
struct address_list *delete_single(struct address_list *head,struct address_list *delet)
{
	struct address_list *p, *q;
	if(head->bianhao_address_list == delet->bianhao_address_list){
		head = head->next;
		printf("ɾ���ɹ�!\n");
		n = n-1;
		system("pause");
		return head;
	}
	else{
		q = head;
		p = head->next;
		while(p != NULL){
			if(p->bianhao_address_list == delet->bianhao_address_list){
				q->next = p->next;
				free(p);
				printf("ɾ���ɹ�!\n");
				n = n-1;
				return head; 
			}
			q = q->next;
			p = p->next;
		}
	}
}

//���½����ݵ�����excel 
void save_excel(struct address_list *head,char *filep)
{
	FILE *fp;
	struct address_list *p1 = NULL;
	char account_num[20]={0};
	strcpy(account_num,filep);
	fp = fopen(strcat(account_num,".csv"),"w");
	if(fp == NULL){
		printf("�����ļ�ʱ���ļ�ʧ�ܣ���save_excel�ļ��С�\n");
		exit(0);
	}
	p1 = head;
	fprintf(fp,"����,�Ա�,����,�绰,��ַ\n");
	while(p1 != NULL){
		fprintf(fp,"%s,%s,%s,%s,%s\n",p1->name,p1->sex,p1->job,p1->handset,p1->address);
		p1 = p1->next;
	}
	printf("�����ɹ���\n");
	system("pause"); 
	fclose(fp);	
} 
