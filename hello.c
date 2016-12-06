#include <stdio.h>

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