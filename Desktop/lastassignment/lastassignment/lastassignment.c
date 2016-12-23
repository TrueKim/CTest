#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <malloc.h>
#include <memory.h>

#define MAX 15
#define MAX_USER 100

void HomeMenuSystem();
void ShowHomeMenu();
void AddAccount();
void ShowLoginMenu();
void Login();

typedef struct User {
	char id[15];
	char password[15];
};

struct User user[MAX_USER];

int usernum = 0;

struct _addressNode {
	char name[10];   
	char phone[14]; 
	struct _addressNode *link;   // 다음 노드
};


typedef struct _addressNode addressNode;

typedef struct userSchedule * schedule_ptr;
typedef struct userSchedule {
	char contents[40];
	int year;
	int month;
	int day;
	schedule_ptr link;
};

schedule_ptr schedule;
//**********************
void AddressManagement(); //주소 전체관리 시스템
void AddressInsert(addressNode*);      // 노드 삽입 함수
void AddressDelete(addressNode*);      // 노드 삭제 함수
void AddressDisplay(addressNode*);   // 노드 정보 출력 함수

void ScheduleManagement();
void insert_schedule(schedule_ptr * ptr);
int checkDate(int year, int month, int day); 
void viewAll_schedule(schedule_ptr ptr);
void delete_schedule(schedule_ptr * ptr);

void ShowHomeMenu(){

	printf("===== Home Menu =====\n");
	printf("1. 계정 추가\n");
	printf("2. 로그인\n");
	printf("=====================\n");

}

void HomeMenuSystem() {

	int num;

	ShowHomeMenu();

	do{
		do{
			printf("메뉴를 선택하세요: ");
			scanf("%d", &num);
		}while( num > 3 || num < 1 );

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

int main(){

	HomeMenuSystem();

}

void ShowLoginMenu(){

	printf("\n===== Login Menu =====\n");
	printf("1. 회원정보 변경\n");
	printf("2. 주소록\n");
	printf("3. 일정 관리\n");
	printf("4. 로그아웃\n");
	printf("======================\n");

}

void AddAccount() {

	char yesNo[2] = "n"; 
	do {
		printf( "아이디 입력 : " ); 
		scanf( "%s", &user[usernum].id ); 
		printf( "패스워드 입력 : " ); 
		scanf( "%s", &user[usernum].password ); 
		printf( "입력완료했나요? (y/n) : " ); 
		scanf( "%s", &yesNo );
	}while( strcmp( yesNo, "y" ) != 0 ); 

	usernum++; 
	printf( "\n" );

} 

void Login() {

	int menunum;
	const char *id;
	const char *pw;

	printf("아이디 입력 : ");
	scanf("%s", &id);
	printf("패스워드 입력 : ");
	scanf("%s", &pw);

	do {
		do {
			ShowLoginMenu();
			printf("메뉴를 선택하세요: ");
			scanf("%d", &menunum);
		}while( menunum >4 || menunum <1);

		switch (menunum) {
		case 1:
			//ChangeIDandPW();
			printf("1");
			break;
		case 2:
			AddressManagement();
			break;
		case 3:
			ScheduleManagement();
			break;
		case 4:
			exit(1);
		}
	}while(menunum != 4);

}

void ChangeIDandPW() {
	char new_ID;
	char new_password;
	printf("아이디 입력 : ");
	scanf("%s", &new_ID);

	printf("변경할 패스워드 : ");
	scanf("%s", &new_password);

}


void AddressManagement(){
	addressNode *addressPtr;
	int choice = 0;
	addressPtr = (addressNode *)malloc(sizeof(addressNode));
	addressPtr->link = NULL;

	do {
		printf("\n");
		printf("=====주소 관리 프로그램=====\n");
		printf("1. 등    록\n");
		printf("2. 출    력\n");
		printf("3. 삭    제\n");
		printf("4. 종    료\n");
		printf("============================\n");
		printf(">>명령어를 선택하시오: ");

		choice = getchar() - '0';
		fflush(stdin);

		switch(choice) {
		case 1 : 
			AddressInsert(addressPtr); 
			break;
		case 2 : 
			AddressDisplay(addressPtr->link);
			break;
		case 3 : 
			AddressDelete(addressPtr); 
			break;
		}
	}while(choice!=4);
}



void AddressInsert(addressNode *addressPtr) {

	while (addressPtr->link != NULL)
		addressPtr = addressPtr->link;
	addressPtr->link = (addressNode*)malloc(sizeof(addressNode));
	addressPtr = addressPtr->link;

	printf("\n");
	printf("====새로운 주소 등록====\n");
	printf("이름 : ");
	gets(addressPtr->name);
	printf("전화번호 : ");
	gets(addressPtr->phone);

	addressPtr->link = NULL;
	printf("\n");

}

void AddressDelete(addressNode *addressPtr)  {

	addressNode *prev;
	char _names[10];

	printf("\n");
	printf("====기존 주소 삭제====\n");
	printf("삭제할 이름를 선택하세요: ");
	gets(_names);

	while (addressPtr->link != NULL)  {
		prev = addressPtr;
		addressPtr = addressPtr->link;

		if (strcmp(_names, addressPtr->name) == 0) {
			prev->link = addressPtr->link;
			free(addressPtr);
			break;
		}
		else
			printf("일치하는 정보가 없습니다.\n");
	}
	printf("\n");

	return;

}

void AddressDisplay(addressNode *addressPtr)  {

	printf("\n");
	printf("====전체 주소 출력====\n");

	if(addressPtr == NULL)
		printf("저장된 값이 없습니다.\n");


	while (addressPtr != NULL) {
		printf("%6s", "이  름 : ") ;
		printf("%6s", addressPtr->name);
		printf("%14s", "전화번호 : ");
		printf("%14s", addressPtr->phone);
		addressPtr = addressPtr->link;
		printf("\n");
	}
	printf("\n");
}



void ScheduleManagement() {

	schedule_ptr temp;

	int ans =1;

	printf("\n");
	printf("1. Insert a new schedule \n");
	printf("2. View all schedule list \n");
	printf("3. Delete a schedule \n");
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
			case 2: viewAll_schedule(schedule);
				break;
			case 3: delete_schedule(&schedule);
				break;
			case 4:  exit(1);
			}
		}
		printf("1. Insert a new schedule \n");
		printf("2. View all schedule list \n");
		printf("3. Delete a schedule \n");
		printf("4. Exit\n");

		printf("make your choice (1 ~ 4)\n");

		scanf("%d", &ans);

	}

}

void insert_schedule(schedule_ptr * ptr) {

	schedule_ptr rear, temp;

	char contents[40];
	int year;
	int month;
	int day;   

	temp = (schedule_ptr) malloc(sizeof(struct userSchedule));

	temp->link = NULL;

	if(*ptr){
		for(rear=*ptr;rear->link;rear=rear->link){
			;
		}
		rear->link = temp;
	}
	else
		*ptr = temp;


	do{
		printf("날짜(년/월/일)을 입력하시오\n");

		printf("year(년) : "); 
		scanf("%d", &year);
		temp->year = year;

		printf("month(월) : "); 
		scanf("%d", &month);
		temp->month = month;

		printf("day(일) : "); 
		scanf("%d", &day);
		temp->day = day;

	}while(checkDate(year,month,day) == 0);

	printf("contents(내용입력) : "); 
	scanf("%s", &contents);      
	strcpy(temp->contents, contents);

}

int checkDate(int year, int month, int day) {

	int yearValid = 0;
	int leapYear = 0;
	int monthValid = 0;
	int dayValid = 0;
	int daysInMonth = 0;

	if(year>=1000 && year<=2999){
		yearValid = 1;
		if((year%4 == 0 && year%100 != 0) || (year%400 == 0))
			leapYear = 1;
	}
	if(month>=1 && month<=12){
		monthValid = 1;

		switch(month){
		case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
			daysInMonth = 31;
			break;
		case 4 : case 6 : case 9 : case 11 :
			daysInMonth = 30;
			break;
		case 2 :
			if(leapYear == 1)
				daysInMonth = 29;
			else
				daysInMonth = 28;
		}
	}
	else
		daysInMonth = 0;

	if(day <= daysInMonth)
		dayValid = 1;

	if((yearValid == 1) && (monthValid == 1) && (dayValid == 1))
		return 1;

	else
		return 0;

}

void viewAll_schedule(schedule_ptr ptr) {

	schedule_ptr temp = ptr;

	printf("year/month/day/\t일정내용\n");
	printf("=============================================\n");

	for( ;temp;temp=temp->link){

		printf("%d /", temp->year);
		printf("%d /", temp->month);
		printf("%d \t", temp->day);
		printf("%10s", temp->contents);
		printf("\n");

	}

	printf("=============================================\n");

}

void delete_schedule(schedule_ptr * ptr) {

	schedule_ptr prev, temp;
	int count = 0;
	int number = 0;

	int year;
	int month;
	int day;

	if (*ptr==NULL) 
	{
		printf("그런 일정은 없습니다\n");
		return;
	}

	printf("삭제할 날짜를 입력하세요 \n");
	scanf("%d", &year);
	scanf("%d", &month);
	scanf("%d", &day);

	temp = *ptr;
	prev = NULL;

	while(temp){
		if((temp->year == year)&&(temp->month == month)&&(temp->day == day)){
			temp = NULL;
		}
		else{
			prev = temp;
			temp = temp->link;
			count++;
		}
	}

	if(count == 0){
		temp = *ptr;
	}
	else{
		temp = prev->link;
	}

	if(temp == NULL){
		printf("그런 일정은 없습니다.\n");
		return;
	}

	if (prev == NULL)
	{
		*ptr = (*ptr)->link;
	}
	else 
	{
		prev->link = temp->link;
	}

	free(temp);

	viewAll_schedule(*ptr);
}