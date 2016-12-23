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
	struct _addressNode *link;   // ���� ���
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
void AddressManagement(); //�ּ� ��ü���� �ý���
void AddressInsert(addressNode*);      // ��� ���� �Լ�
void AddressDelete(addressNode*);      // ��� ���� �Լ�
void AddressDisplay(addressNode*);   // ��� ���� ��� �Լ�

void ScheduleManagement();
void insert_schedule(schedule_ptr * ptr);
int checkDate(int year, int month, int day); 
void viewAll_schedule(schedule_ptr ptr);
void delete_schedule(schedule_ptr * ptr);

void ShowHomeMenu(){

	printf("===== Home Menu =====\n");
	printf("1. ���� �߰�\n");
	printf("2. �α���\n");
	printf("=====================\n");

}

void HomeMenuSystem() {

	int num;

	ShowHomeMenu();

	do{
		do{
			printf("�޴��� �����ϼ���: ");
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
	printf("1. ȸ������ ����\n");
	printf("2. �ּҷ�\n");
	printf("3. ���� ����\n");
	printf("4. �α׾ƿ�\n");
	printf("======================\n");

}

void AddAccount() {

	char yesNo[2] = "n"; 
	do {
		printf( "���̵� �Է� : " ); 
		scanf( "%s", &user[usernum].id ); 
		printf( "�н����� �Է� : " ); 
		scanf( "%s", &user[usernum].password ); 
		printf( "�Է¿Ϸ��߳���? (y/n) : " ); 
		scanf( "%s", &yesNo );
	}while( strcmp( yesNo, "y" ) != 0 ); 

	usernum++; 
	printf( "\n" );

} 

void Login() {

	int menunum;
	const char *id;
	const char *pw;

	printf("���̵� �Է� : ");
	scanf("%s", &id);
	printf("�н����� �Է� : ");
	scanf("%s", &pw);

	do {
		do {
			ShowLoginMenu();
			printf("�޴��� �����ϼ���: ");
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
	printf("���̵� �Է� : ");
	scanf("%s", &new_ID);

	printf("������ �н����� : ");
	scanf("%s", &new_password);

}


void AddressManagement(){
	addressNode *addressPtr;
	int choice = 0;
	addressPtr = (addressNode *)malloc(sizeof(addressNode));
	addressPtr->link = NULL;

	do {
		printf("\n");
		printf("=====�ּ� ���� ���α׷�=====\n");
		printf("1. ��    ��\n");
		printf("2. ��    ��\n");
		printf("3. ��    ��\n");
		printf("4. ��    ��\n");
		printf("============================\n");
		printf(">>��ɾ �����Ͻÿ�: ");

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
	printf("====���ο� �ּ� ���====\n");
	printf("�̸� : ");
	gets(addressPtr->name);
	printf("��ȭ��ȣ : ");
	gets(addressPtr->phone);

	addressPtr->link = NULL;
	printf("\n");

}

void AddressDelete(addressNode *addressPtr)  {

	addressNode *prev;
	char _names[10];

	printf("\n");
	printf("====���� �ּ� ����====\n");
	printf("������ �̸��� �����ϼ���: ");
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
			printf("��ġ�ϴ� ������ �����ϴ�.\n");
	}
	printf("\n");

	return;

}

void AddressDisplay(addressNode *addressPtr)  {

	printf("\n");
	printf("====��ü �ּ� ���====\n");

	if(addressPtr == NULL)
		printf("����� ���� �����ϴ�.\n");


	while (addressPtr != NULL) {
		printf("%6s", "��  �� : ") ;
		printf("%6s", addressPtr->name);
		printf("%14s", "��ȭ��ȣ : ");
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
		printf("��¥(��/��/��)�� �Է��Ͻÿ�\n");

		printf("year(��) : "); 
		scanf("%d", &year);
		temp->year = year;

		printf("month(��) : "); 
		scanf("%d", &month);
		temp->month = month;

		printf("day(��) : "); 
		scanf("%d", &day);
		temp->day = day;

	}while(checkDate(year,month,day) == 0);

	printf("contents(�����Է�) : "); 
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

	printf("year/month/day/\t��������\n");
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
		printf("�׷� ������ �����ϴ�\n");
		return;
	}

	printf("������ ��¥�� �Է��ϼ��� \n");
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
		printf("�׷� ������ �����ϴ�.\n");
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