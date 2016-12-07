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
#include <memory.h>

struct _node {
	char name[10];	
	char phone[14];

	struct _node *link;	// 다음 노드
};

typedef struct _node node;

typedef struct userSchedule * item_ptr;
typedef struct userSchedule {
	char contents[40];
	int year; 
	int month;
	int day;
	item_ptr link;
};

item_ptr schedule;

void ShowHomeMenu();
void HomeMenuSystem();
void AddAccount();
void Login();

void AddressManagement(); //주소 전체관리 시스템
void Insert(node*);		// 노드 삽입 함수
void Delete(node*);		// 노드 삭제 함수
void Display(node*);	// 노드 정보 출력 함수

void ScheduleManagement();
void insert_schedule(item_ptr * ptr);

int main(void) {

	int menuNum = 1;

	printf("<1>address , <2>schedule 선택 : ");
	scanf("%d", &menuNum);

	if(menuNum == 1)
		AddressManagement();
	else if(menuNum == 2)
		ScheduleManagement();

}

void AddressManagement(){
	 	node *ptr;
	int choice;

	/*
		첫번째 노드 생성
		동적할당을 통해 공간을 생성하여 노드를 만든다.
		다음 노드 위치는 NULL로 초기화한다
	*/
	ptr = (node *)malloc(sizeof(node));
	ptr->link = NULL;

	/*
		do-while을 이용한 반복
		4. 종료를 선택할 때까지 반복한다.
	*/
	do {
		// 메뉴 출력
		printf("=====주소 관리 프로그램=====\n");
		printf("1. 등    록\n");
		printf("2. 출    력\n");
		printf("3. 삭    제\n");
		printf("4. 종    료\n");
		printf("============================\n");
		printf(">>명령어를 선택하시오: ");
		
		// 1문자를 입력받아 숫자로 변환
		choice = getchar() - '0';
		
		// 입력 버퍼 초기화
		fflush(stdin);

		/* 
			입력받은 숫자에 따라 분기
			1 : 등록 -> Insert
			2 : 출력 -> Display
			3 : 삭제 -> Delete
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

void ScheduleManagement(){
	item_ptr temp;	
	int ans =1;

	printf("\n");
    printf("1. Insert a new subject \n");
	printf("2. Delete a subject \n");
	printf("3. Print all subject list\n");
	printf("4. Exit\n");

	printf("make your choice (1 ~ 4)\n");

	scanf("%d", &ans);
	
	while (ans >=1 && ans <=4)
	{
		if (ans >=1 && ans <=4)
		{
			switch(ans)
			{
			case 1: insert_schedule(&schedule);
				break;
			//case 2: delete_schedule(&schedule);
			//	break;
			//case 3: viewAll_schedule(schedule);
			//	break;
			//case 4:  exit(1);
			}
		}
		printf("1. Insert a new subject \n");
		printf("2. Delete a subject \n");
		printf("3. Print all subject list\n");
		printf("4. Exit\n");

		printf("make your choice (1 ~ 4)\n");

		scanf("%d", &ans);	

	}
}


void Insert(node *ptr) {
	while (ptr->link != NULL)
		ptr = ptr->link;

	ptr->link = (node*)malloc(sizeof(node));
	ptr = ptr->link;


	printf("\n");
	printf("이름을 입력하시오: ");
	gets(ptr->name);
	printf("전화번호 입력하시오: ");
	gets(ptr->phone);

	ptr->link = NULL;
	printf("\n");
}

void Delete(node *ptr)  {
	node *prev;
	char _phone[14];

	printf("삭제할 전화번호를 선택하시오: ");
	gets(_phone);

	while (ptr->link != NULL)  {
		prev = ptr;
		ptr = ptr->link;

		/* 저장되어 있는 데이터중에서 전화번호를 기준으로 데이터를 삭제 */
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
		printf("%6s", "이  름 : ") ;
		printf("%6s", ptr->name);
		printf("%14s", "전화번호 : ");
		printf("%14s", ptr->phone);
		
		ptr = ptr->link;
		printf("\n");
	}
	printf("\n");
}

void insert_schedule(item_ptr *ptr)
{
			
		item_ptr rear, temp;

		char contents[40];
		int year;
		int month;
		int day;	

		temp = (item_ptr) malloc(sizeof(struct userSchedule));

		temp->link = NULL;

		if(*ptr){
			for(rear=*ptr;rear->link;rear=rear->link){
				;
			}
			rear->link = temp;
		}
		else
			*ptr = temp;


		printf("contents(내용입력) : "); 
		scanf("%s", &contents);		
		strcpy(temp->contents, contents);

		printf("year(년) : "); 
		scanf("%d", &year);
		temp->year = year;

		printf("month(월) : "); 
		scanf("%d", &month);
		temp->month = month;

		printf("day(일) : "); 
		scanf("%d", &day);
		temp->day = day;

}

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
	//case 2:
	//	Login();
	//	break;
	}
   }while(num != 3);
}

void AddAccount(){
	//IS_FULL();
	//FindID();
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
/*
void Login() {
	do{

	}while(loginnum != 3)
}*/