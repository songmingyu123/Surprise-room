#include"account.h"
int main()
{
	int pass = 0;	//�жϵ�¼�Ƿ�ɹ� 
	char c; 
	int i;
	char *accountnum = NULL;	//����˺��û����ĵ�ַ
	char *accountnumb = NULL;	//����˺��û����ĵ�ַ,�����޸������õģ�ӦΪ��load�������û����ַ����XXX.txt,�޷�ʹ���� 
	struct address_list *head = NULL;      //ͨѶ¼�����ͷ 
	struct address_list *search_easy_point = NULL;//���ҵ�����ϵ�˵ĵ�ַ 
	struct account_single *head_account = NULL; //�˻�����Ľṹ��������ͷ 
	head_account = load_account(head_account);		//��ȡ�˺�������ļ�����ͷ��ַ���ظ�head_account 
	
	while(1){		
		if(pass == 1)
			break;
		system("cls");
		menu_account();
		fflush(stdin);
		c = getchar();
		if(c<'1'||c>'2'){
			printf("����������������롣\n");
			system("pause");
			continue;
		}
		i = c-'0';

		switch(i)
		{
			case 1:
				head_account = enroll(head_account);  //ע�ắ��ע���û�����������ͷ 
				save_enroll(head_account);		//�����û�����Ϣ 
				break;
			case 2:
				accountnum = login(head_account);		//��¼�����������û������ַ������׵�ַ��accountnum
				accountnumb = accountnum;//��accountnumb��ֵ�ַ������޸����뺯���� alter_password���� 
				if(accountnum != NULL){		 	//if  accountnum ��Ϊ NULL������login ��������Ч���û��� 
					pass = 1;			//pass�����ж��Ƿ��˳�ѭ�� 
				}
				break;
			default:
				break;
		}
	}
	head = load(head,accountnum);//��head = NULL��accountnum���ļ���������load����������������¼�û����ļ��е�ͨѶ¼��Ϣ 
	if(head == NULL){
		printf("���˻���ͨѶ¼��û����ϵ�ˡ�\n");
	}
	while(1){
		system("cls");
		printf("=================================================================\n");
		printf("====			1.�����ϵ��			  ====\n");
		printf("====       		2.ɾ����ϵ��       		  ====\n");
		printf("====       		3.������ϵ��      		  ====\n");
		printf("====       		4.��ʾ������ϵ��   		  ====\n");
		printf("====       		5.�޸���ϵ��       		  ====\n");
		printf("====			6.���棨�˳�����ǰ�����Ҫ���棩  ====\n");
		printf("====       		7.�������ݵ�Excel  		  ====\n");
		printf("====			8.�˳�����			  ====\n");
		printf("====			9.�޸ĵ�ǰ�û�������			  ====\n");
		printf("=================================================================\n");
		printf("������ѡ�");
		fflush(stdin); 

		c = getchar();
		if(c<'1'||c>'9'){
			printf("����������������롣\n");
			system("pause");
			continue;
		}
		i = c-'0'; 
		switch(i)
		{
			case 1:
				{
					fflush(stdin);
					head = insert(head);  //������Ӻ���
				}
				break;
			case 2:
				{
					fflush(stdin);
					search(head);
					if(head == NULL){   //���ͨѶ¼��Ϊû����ϵ�ˡ� 
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
				printf("�������󣬴�����ڣ�\n");
				break;
		}
	}
	return 0;	
}

 