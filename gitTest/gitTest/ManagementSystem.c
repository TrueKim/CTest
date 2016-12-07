/*#include <stdio.h>

#define MAX 15

void ShowHomeMenu();
void HomeMenuSystem();
void AddAccount();
void Login();

typedef struct user[usernum]{
	char id[MAX];
	char password[MAX];
	char name[30];

}user;



}*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct _node {
	char name[10];	
	char phone[14];

	struct _node *link;	// ���� ���
};

typedef struct _node node;

void ShowHomeMenu();
void HomeMenuSystem();
void AddAccount();
void Login();

void AddressManagement(); //�ּ� ��ü���� �ý���
void Insert(node*);		// ��� ���� �Լ�
void Delete(node*);		// ��� ���� �Լ�
void Display(node*);	// ��� ���� ��� �Լ�

int main(void) {
	AddressManagement();


}

void AddressManagement(){
	 	node *ptr;
	int choice;

	/*
		ù��° ��� ����
		�����Ҵ��� ���� ������ �����Ͽ� ��带 �����.
		���� ��� ��ġ�� NULL�� �ʱ�ȭ�Ѵ�
	*/
	ptr = (node *)malloc(sizeof(node));
	ptr->link = NULL;

	/*
		do-while�� �̿��� �ݺ�
		4. ���Ḧ ������ ������ �ݺ��Ѵ�.
	*/
	do {
		// �޴� ���
		printf("=====�ּ� ���� ���α׷�=====\n");
		printf("1. ��    ��\n");
		printf("2. ��    ��\n");
		printf("3. ��    ��\n");
		printf("4. ��    ��\n");
		printf("============================\n");
		printf(">>��ɾ �����Ͻÿ�: ");
		
		// 1���ڸ� �Է¹޾� ���ڷ� ��ȯ
		choice = getchar() - '0';
		
		// �Է� ���� �ʱ�ȭ
		fflush(stdin);

		/* 
			�Է¹��� ���ڿ� ���� �б�
			1 : ��� -> Insert
			2 : ��� -> Display
			3 : ���� -> Delete
		*/
		switch(choice) {
			case 1 : 
				Insert(ptr); 
				break;
			case 2 : 
				Display(ptr->link);
				break;
			case 3 : 
				Delete(ptr); 
				break;
		}
	}while(choice!=4);


}


void Insert(node *ptr) {
	while (ptr->link != NULL)
		ptr = ptr->link;

	ptr->link = (node*)malloc(sizeof(node));
	ptr = ptr->link;


	printf("\n");
	printf("�̸��� �Է��Ͻÿ�: ");
	gets(ptr->name);
	printf("��ȭ��ȣ �Է��Ͻÿ�: ");
	gets(ptr->phone);

	ptr->link = NULL;
	printf("\n");
}

void Delete(node *ptr)  {
	node *prev;
	char _phone[14];

	printf("������ ��ȭ��ȣ�� �����Ͻÿ�: ");
	gets(_phone);

	while (ptr->link != NULL)  {
		prev = ptr;
		ptr = ptr->link;

		/* ����Ǿ� �ִ� �������߿��� ��ȭ��ȣ�� �������� �����͸� ���� */
		if (strcmp(_phone, ptr->phone) == 0) {
			prev->link = ptr->link;
			free(ptr);
			break;
		}
	}
	return;
}

void Display(node *ptr)  {

	while (ptr != NULL) {
		printf("%6s", "��  �� : ") ;
		printf("%6s", ptr->name);
		printf("%14s", "��ȭ��ȣ : ");
		printf("%14s", ptr->phone);
		
		ptr = ptr->link;
		printf("\n");
	}
	printf("\n");
}

void ShowHomeMenu(){
	printf("\tHome Menu\n");
	printf("-----------------");
	printf("1. ���� �߰�\n");
	printf("2. �α���\n");
	printf("-----------------");
	printf("�޴��� �����ϼ���: \n");
}

void HomeMenuSystem(){
	int num;
	ShowHomeMenu();
	do{
		do{
			printf("�޴��� �����ϼ���: \n");
			scanf("%d", &num);
		}while(num>3 || num <1);
		printf("\n");
	switch (num){
	case 1:
		AddAccount();
		break;
	case 2:
		Login();
		break;
	}
   }while(num != 3);
}

void AddAccount(){
	IS_FULL();
	FindID();
	ShowHomeMenu();
}

void ShowLoginMenu(){
	printf("\tLogin Menu\n");
	printf("-----------------");
	printf("1. ȸ������ ����\n");
	printf("2. �ּҷ�\n");
	printf("3. ���� ����\n");
	printf("4. �α׾ƿ�\n");
	printf("-----------------");
	printf(">>�޴��� �����ϼ���: ");
}

void Login() {
	do{

	}while(loginnum != 3)
}