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
	printf("1. 계정 추가\n");
	printf("2. 로그인\n");
	printf("-----------------");
	printf("메뉴를 선택하세요: \n");
}

void HomeMenuSystem(){
	int num;
	ShowHomeMenu();
	do{
		do{
			printf("메뉴를 선택하세요: \n");
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
	printf("1. 회원정보 변경\n");
	printf("2. 주소록\n");
	printf("3. 일정 관리\n");
	printf("4. 로그아웃\n");
	printf("-----------------");
	printf(">>메뉴를 선택하세요: ");
}