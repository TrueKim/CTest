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

	struct _node *link;	// ���� ���
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

void AddressManagement(); //�ּ� ��ü���� �ý���
void Insert(node*);		// ��� ���� �Լ�
void Delete(node*);		// ��� ���� �Լ�
void Display(node*);	// ��� ���� ��� �Լ�

void ScheduleManagement();
void insert_schedule(item_ptr * ptr);

int main(void) {

	int menuNum = 1;

	printf("<1>address , <2>schedule ���� : ");
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


		printf("contents(�����Է�) : "); 
		scanf("%s", &contents);		
		strcpy(temp->contents, contents);

		printf("year(��) : "); 
		scanf("%d", &year);
		temp->year = year;

		printf("month(��) : "); 
		scanf("%d", &month);
		temp->month = month;

		printf("day(��) : "); 
		scanf("%d", &day);
		temp->day = day;

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
	printf("1. ȸ������ ����\n");
	printf("2. �ּҷ�\n");
	printf("3. ���� ����\n");
	printf("4. �α׾ƿ�\n");
	printf("-----------------");
	printf(">>�޴��� �����ϼ���: ");
}
/*
void Login() {
	do{

	}while(loginnum != 3)
}*/