#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void login()
{
	int x = 0, i = 0;
	char Uname[10], ch = ' ';
	char PassWord[10];
	char code[10];
	char user[10] = "name";
	char pass[10] = "pass";
	while(x <= 3)
	{
		printf("\n  *Login*  \n");
		printf("Enter username:");
		scanf("%s", Uname);
		printf("\n Enter password:");
		while(i < 10)
		{
			PassWord[i] = getch();
			ch = PassWord[i];
			if(ch == 13) 
			break;
			else
			printf("*");
			i++;
		}
		PassWord[i] = '\0';
		i = 0;
		if(strcmp(Uname,"name") == 0 && strcmp(PassWord, "pass") == 0)
		{
			printf("\n Welcome Login is successful");
			printf("\n Press any key to continue");
			getch();
			break;
		}
		else
		{
			printf("\n Sorry Login is unsuccessful");
			x++;
			getch();
		}
	}
	if(x > 3)
	{
		printf("\n You have entered the wrong username and password for times");
		getch();
	}
	system("cls");
}
struct book{
	char code[20];
	char name[20];
	char date[20];
	int cost;
}a;
void insert();
void viewAll();
void find();
void book_ticket();

main()
{
	login();
	int c;
	do
	{
		printf("\nEnter 1 to insert movie");
		printf("\nEnter 2 to book tickets");
		printf("\nEnter 3 to view all movie");
		printf("\nEnter 4 to find movie");
		printf("\nEnter 0 to exit");
		printf("\nEnter your choice:");
		scanf("%d", &c);
		system("cls");
		switch(c)
		{
			case 1:
				insert();
			break;
			case 2:
				book_ticket();
			break;
			case 3:
				viewAll();
			break;
			case 4:
				find();
			break;
			case 0:
				exit(0);
			break;
			default:
				printf("Wrong choice");
			break;	
		}
		}while(c != 0);
}
void insert()
{
	FILE *p;
	struct book a;
	printf("Enter movie code: ");
	scanf("%s", a.code);
	printf("Enter name: ");
	scanf("%s", a.name);
	printf("Enter date: ");
	scanf("%s", a.date);
	printf("Enter ticket price: ");
	scanf("%d", &a.cost);
	p = fopen("D:\\data.txt", "a");
	if(p == NULL)
	{
		printf("can not open the file.\n");
	}
	else
	{
		fprintf(p,"%s %s %s %d \n", a.code, a.name, a.date, a.cost);
		printf("Recorded successfully");
	}
	printf("\n");
	fclose(p);
	system("cls");
}
void find()
{
	struct book a;
	FILE *p;
	char ch[20];
	printf("Enter movie code:");
	scanf("%s", ch);
	p = fopen("D:\\data.txt", "r");
	if(p == NULL)
	{
		printf("can not open the file");
		exit(1);
	}
	else
	{
		while(getc(p) != EOF)
		{
			fscanf(p, "%s %s %s %d", a.code, a.name, a.date, a.cost);
			if(strcmp(a.code, ch) == 0)
			{
				printf("\n Record found\n");
				printf("\n code : %s", a.code);
				printf("\n movie name: %s", a.name);
				printf("\n movie date: %s", a.date);
				printf("\n price of ticket: %d", a.cost);
			}
		}
	}
	fclose(p);
	system("cls");
}
void viewAll()
{
	char c;
	FILE *p;
	p = fopen("D:\\data.txt", "r");
	if(p == NULL)
	{
		printf("can not open the file.");
		exit(1);
	}
	else
	{
		system("cls");
		while((c = fgetc(p)) != EOF)
		printf("%c", c);
	}
	fclose(p);
}
void book_ticket()
{
	struct book a;
	FILE *p;
	FILE *pf;
	int Tseat, phonenumber, Tamount;
	char name[20];
	char c;
	char moviecode[20];
	p = fopen("D:\\data.txt", "r");
	if(p == NULL)
	{
		printf("can not open the file.");
		exit(1);
	}
	else
	{
		system("cls");
		while((c = fgetc(p)) != EOF)
		printf("%c", c);
	}
	fclose(p);
	printf("\n for book ticket choice movie (Enter movie code first latter of movie)\n");
	printf("\n Enter movie code:");
	scanf("%s", moviecode);
	p = fopen("D:\\data.txt", "r");
	if(p == NULL)
	{
		printf("can not open the file.");
		exit(1);
	}
	else
	{
		while(getc(p) != EOF)
		{
			fscanf(p,"%s %s %s %d",a.code, a.name, a.date, &a.cost);
			if(strcmp(a.code , moviecode) == 0)
			{
				printf("\n Record found\n");
				printf("\n code : %s", a.code);
				printf("\n movie name: %s", a.name);
				printf("\n date name: %s", a.date);
				printf("\n price of ticket: %d", a.cost);
			}
		}
	}
	printf("\n *Fill details*");
	printf("\n Enter your name:");
	scanf("%s", name);
	printf("\n Phone number:");
	scanf("%d", &phonenumber);
	printf("\n total number of tickets:");
	scanf("%d", &Tseat);
	
	Tamount = a.cost * Tseat;
	
	printf("\n Enjoy movie\n");
	printf("\n name: %s", name);
	printf("\n phone number: %d", phonenumber);
	printf("\n movie name : %s", a.name);
	printf("\n Total seats: %d", Tseat);
	printf("\n cost per ticket: %d", a.cost);
	printf("\n Total amount: %d", Tamount);
	
	pf = fopen("D:\\oldTransection.txt", "a");
	if(pf == NULL)
	{
		printf("can not open the file.");
	}
	else
	{
		fprintf(pf,"%s %d %d %d %s %d \n", name, phonenumber, Tseat, Tamount, a.name, a.cost);
		printf("\n Record insert successful.");
	}
	printf("\n");
	fclose(pf);
	fclose(p);
}
