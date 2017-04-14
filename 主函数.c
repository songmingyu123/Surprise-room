#include"account.h"
int main()
{
	int pass = 0;	//判断登录是否成功 
	char c; 
	int i;
	char *accountnum = NULL;	//存放账号用户名的地址
	char *accountnumb = NULL;	//存放账号用户名的地址,用于修改密码用的，应为再load函数中用户名字符变成XXX.txt,无法使用了 
	struct address_list *head = NULL;      //通讯录链表的头 
	struct address_list *search_easy_point = NULL;//查找到的联系人的地址 
	struct account_single *head_account = NULL; //账户密码的结构体的链表的头 
	head_account = load_account(head_account);		//读取账号密码的文件，把头地址返回给head_account 
	
	while(1){		
		if(pass == 1)
			break;
		system("cls");
		menu_account();
		fflush(stdin);
		c = getchar();
		if(c<'1'||c>'2'){
			printf("输入错误，请重新输入。\n");
			system("pause");
			continue;
		}
		i = c-'0';

		switch(i)
		{
			case 1:
				head_account = enroll(head_account);  //注册函数注册用户，返回链表头 
				save_enroll(head_account);		//保存用户名信息 
				break;
			case 2:
				accountnum = login(head_account);		//登录函数，返回用户名的字符串的首地址给accountnum
				accountnumb = accountnum;//给accountnumb赋值字符，给修改密码函数用 alter_password函数 
				if(accountnum != NULL){		 	//if  accountnum 不为 NULL，就是login 返回了有效的用户名 
					pass = 1;			//pass用来判断是否退出循环 
				}
				break;
			default:
				break;
		}
	}
	head = load(head,accountnum);//把head = NULL和accountnum（文件名）传给load函数，用来打开所登录用户的文件中的通讯录信息 
	if(head == NULL){
		printf("本账户的通讯录中没有联系人。\n");
	}
	while(1){
		system("cls");
		printf("=================================================================\n");
		printf("====			1.添加联系人			  ====\n");
		printf("====       		2.删除联系人       		  ====\n");
		printf("====       		3.查找联系人      		  ====\n");
		printf("====       		4.显示所有联系人   		  ====\n");
		printf("====       		5.修改联系人       		  ====\n");
		printf("====			6.保存（退出程序前，务必要保存）  ====\n");
		printf("====       		7.导出数据到Excel  		  ====\n");
		printf("====			8.退出程序			  ====\n");
		printf("====			9.修改当前用户的密码			  ====\n");
		printf("=================================================================\n");
		printf("请输入选项：");
		fflush(stdin); 

		c = getchar();
		if(c<'1'||c>'9'){
			printf("输入错误，请重新输入。\n");
			system("pause");
			continue;
		}
		i = c-'0'; 
		switch(i)
		{
			case 1:
				{
					fflush(stdin);
					head = insert(head);  //进入添加函数
				}
				break;
			case 2:
				{
					fflush(stdin);
					search(head);
					if(head == NULL){   //如果通讯录中为没有联系人。 
						break;
					}
				 	search_easy_point = search_easy(head);
				 	if(search_easy_point == NULL){
	 					break;
	 				}
					head = delete_single(head,search_easy_point);
				}
				break;
			case 3:
				{
					fflush(stdin);
					search(head);			
				}
				break;
			case 4:
				{
					fflush(stdin);
					head = paixu(head);
					print(head);
				}
				break;
			case 5:
				{
					fflush(stdin);
					search(head);
					search_easy_point = search_easy(head);
		 			if(search_easy_point == NULL){
 						break;
	 				}
					head = alter(head,search_easy_point);
				}
				break;
			case 6:
				{
					fflush(stdin);
					save(head,accountnum);
				} 
				break;
			case 7:
				{
					fflush(stdin);
					save_excel(head,accountnum);
				}
				break;
			case 8:
				{
					fflush(stdin);
					head = shifang(head);
					exit(0);
				}
				break;
			case 9:
				{
					fflush(stdin);
					alter_password(head_account,accountnumb);
					save_enroll(head_account);
				}
				break;
			default:
				printf("操作错误，此项不存在！\n");
				break;
		}
	}
	return 0;	
}

 