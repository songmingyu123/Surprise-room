#include"account.h"

/*读取文件中的通讯录信息*/ 
struct address_list *load(struct address_list *head,char *filep)   
{
	FILE *fp;
	struct address_list *p1, *p2;
	fp = fopen(filep,"ab+");
	if(fp == NULL){
		printf("文件打开错误，在struct address_list *load函数中。\n");
		return head;
	}
	p1 = (struct address_list *)malloc(LEN);
	fread(p1,LEN,1,fp);
	if(feof(fp) != 0){
		printf("当前您的通讯录中没有联系人。\n");
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
		printf("打开完毕。\n");
		fclose(fp);
	}
	return head;
}
/*向通讯录中添加联系人*/
struct address_list *insert(struct address_list *head)  // 添加信息
{
	struct address_list *p0, *p1, *p3;
	char name[20]={0};
	char a;
	p1 = head;
	p3 = head; 
	printf("请输入要保存的联系人信息：\n");
	printf("请输入联系人名字：\n");
	gets(name);
	for(;p3 != NULL;p3 = p3->next){
		if(strcmp(name,p3->name) == 0){
			printf("该联系人已经保存在通讯录中。\n");
			print_single(p3);
			printf("\n\n是否确定继续添加该联系人？（y/n）\n");
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
		printf("请输入性别：");
		fflush(stdin);
		gets(p0->sex);
		printf("请输入工作：");
		gets(p0->job);
		printf("请输入电话：");
		gets(p0->handset);
		printf("请输入地址：");
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
				printf("添加成功。按任意键继续...\n");
			}
			return head;
		}
} 
/*展示通讯录中所有联系人的信息*/
void print(struct address_list *head)  //输出通讯录信息函数 
{
	struct address_list *p;
	if(head != NULL){
		p = head;
		printf("共有%d位联系人（按姓名排序）：\n",n);
		printf("---姓名--------------性别------------工作-----------电话--------------地址\n\n\n");
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
		printf("通讯录为空。\n");
	}
	system("pause");
} 
/*将通讯录中的联系人按名字的拼音进行排序*/
struct address_list *paixu(struct address_list *head)  //排序函数
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
		printf("通讯录为空，无法排序。\n");
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
/*将通讯录中的联系人保存到文件中*/ 
void save(struct address_list *head,char *filep)		//保存函数
{
	FILE *fp;
	char account_num[20]={0};
	struct address_list *p1;
	strcpy(account_num,filep);
	fp = fopen(account_num,"wb");  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!没有写 
	if(fp == NULL){
		printf("保存文件时打开文件失败，在save文件中。\n");
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
//显示单个联系人的信息
void print_single(struct address_list *single)	 
{
	printf("\n---编号----------姓名--------------性别------------工作-----------电话--------------地址\n");
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
/*通过名字模糊查询联系人信息，并展示该联系人信息*/
struct address_list *search(struct address_list *head)		 //查找函数
{
	char name[20];  	//要查找的名字的字符，或者部分字符（可模糊查询）   
	char name1[20]; 	//通讯录中已经有的名字，用来和要查找的名字进行比较判断是否存在 
	int i=0,j=0,flag=0,k=0;
	int find_number=0;
	struct address_list *p1, *p2; 
	if(head == NULL){
		printf("该账户通讯中没有联系人。\n");
		system("pause");
		return head;   //当前head为NULL 
	}
	p1 = head;
	printf("**************************************\n");
	printf("请输入要查找的姓名（支持模糊查询，输入名字的一部分即可）：\n");
	printf("**************************************\n");
	printf("请输入：");
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
		printf("未找到联系人。\n");
		system("pause");
	}
}
//退出函数
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
//修改通讯录中的联系人的信息函数 
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
	printf("请输入要保存的联系人信息：\n");
	printf("请输入联系人名字：\n");
	fflush(stdin);
	gets(address.name);
	for(;p3 != NULL;p3 = p3->next){
		if(strcmp(address.name,p3->name) == 0){
			printf("该联系人已经保存在通讯录中。\n");
			print_single(p3);
			printf("\n\n是否继续修改该联系人？（y/n）\n");
			fflush(stdin);
			a = getchar();
			if(a=='y') break;
			else return head;
		}
	}
		strcpy(alter_pointer->name,address.name);
		fflush(stdin); 
		printf("请输入性别：");
		gets(address.sex);
		strcpy(alter_pointer->sex,address.sex);
		printf("请输入工作：");
		gets(address.job);
		strcpy(alter_pointer->job,address.job);
		printf("请输入电话：");
		gets(address.handset);
		strcpy(alter_pointer->handset,address.handset);
		printf("请输入地址：");
		gets(address.address);
		strcpy(alter_pointer->address,address.address);
		return head;
} 

//只能查找联系人并返回该联系人地址的函数 
struct address_list *search_easy(struct address_list *head)
{
	struct address_list *p = NULL; //查找联系人时用p这个链表。
	struct address_list *p_bianhao = NULL; //查找编号，确定联系人时用p_bianhao这个链表 
	char name[20];
	int i = 0;
	int bianhao = -1;
	if(head == NULL){
		printf("您的通讯中没有联系人。\n");
		system("pause"); 
		return head;
	}
	p_bianhao = head;
	printf("请再次确认您是否要对该联系人进行操作，并输入用户的完整姓名：");
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
		printf("未找到该联系人。\n");
		system("pause");
		return p;
	}
	printf("\n请输入您想要操作的联系人的编号：");
	scanf("%d",&bianhao);
	for(;p_bianhao != NULL;){
		if(p_bianhao->bianhao_address_list == bianhao){
			return p_bianhao;
		}
		p_bianhao = p_bianhao->next;
	}
	
}
//删除某个联系人的函数
struct address_list *delete_single(struct address_list *head,struct address_list *delet)
{
	struct address_list *p, *q;
	if(head->bianhao_address_list == delet->bianhao_address_list){
		head = head->next;
		printf("删除成功!\n");
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
				printf("删除成功!\n");
				n = n-1;
				return head; 
			}
			q = q->next;
			p = p->next;
		}
	}
}

//以下将数据导出到excel 
void save_excel(struct address_list *head,char *filep)
{
	FILE *fp;
	struct address_list *p1 = NULL;
	char account_num[20]={0};
	strcpy(account_num,filep);
	fp = fopen(strcat(account_num,".csv"),"w");
	if(fp == NULL){
		printf("保存文件时打开文件失败，在save_excel文件中。\n");
		exit(0);
	}
	p1 = head;
	fprintf(fp,"姓名,性别,工作,电话,地址\n");
	while(p1 != NULL){
		fprintf(fp,"%s,%s,%s,%s,%s\n",p1->name,p1->sex,p1->job,p1->handset,p1->address);
		p1 = p1->next;
	}
	printf("导出成功。\n");
	system("pause"); 
	fclose(fp);	
} 
