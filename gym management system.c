#include <windows.h>

#include <stdio.h>

#include <conio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include <dos.h>

#include <time.h>

#define RETURNTIME 15

char catagories[][15] = {"New Member", "Coach", "Staff"};

void returnfunc(void);

void mainmenu(void);

void addstaff(void);

void deletestaff(void);

void editstaff(void);

void searchstaff(void);

void viewstaff(void);

void closeapplication(void);

int getdata();

int checkid(int);

int t(void);

void Password();

void issuerecord();

void loaderanim();

FILE *fp, *ft, *fs;

COORD coord = {0, 0};

int s;

char findstaff;

char password[10] = {"pass"};

void gotoxy(int x, int y)

{

	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct meroDate

{

	int mm, dd, yy;
};

struct staff

{

	int id;

	char stname[20];

	char name[20];

	char Address[20];

	char membersince[10];

	int contact;

	int count;

	char *cat;

	struct meroDate issued;

	struct meroDate duedate;
};

struct staff a;

int main()

{

	Password();

	getch();

	return 0;
}

void mainmenu()

{

	system("cls");

	int i;

	gotoxy(0, 1);

	printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("   \xcd\xcd\xcd\xcd\xcd\xcd GYM MANAGEMENT SYSTEM \xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\n   MAIN MENU");

	gotoxy(3, 7);

	printf("[1] Add Members   ");

	gotoxy(3, 9);

	printf("[2] Remove Members");

	gotoxy(3, 11);

	printf("[3] Search Members");

	gotoxy(3, 13);

	printf("[4] View Member's list");

	gotoxy(3, 15);

	printf("[5] Edit Members Record");

	gotoxy(3, 17);

	printf("[6] Close Application");

	gotoxy(3, 19);

	t();

	gotoxy(3, 21);

	printf("Enter your choice:");

	switch (getch())

	{

	case '1':

		addstaff();

		break;

	case '2':

		deletestaff();

		break;

	case '3':

		searchstaff();

		break;

	case '4':

		viewstaff();

		break;

	case '5':

		editstaff();

		break;

	case '6':

	{

		system("cls");

		gotoxy(3, 3);

		printf("Gym Management System");

		gotoxy(3, 5);

		printf("Project in C");

		gotoxy(3, 7);

		exit(0);
	}

	default:

	{

		gotoxy(10, 25);

		printf("\aWrong Entry!!Please re-entered correct option");

		if (getch())

			mainmenu();
	}
	}
}

void addstaff(void)

{

	system("cls");

	int i;

	gotoxy(0, 1);

	printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("   \xcd\xcd\xcd\xcd\xcd\xcd GYM MANAGEMENT SYSTEM \xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\n   SELECT CATEGORIES");

	gotoxy(3, 7);

	printf("[1] New Member");

	gotoxy(3, 9);

	printf("[2] Coach");

	gotoxy(3, 11);

	printf("[3] Staff");

	gotoxy(3, 13);

	printf("[4] Back to main menu");
	printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");

	gotoxy(3, 15);

	printf("Enter your choice:");

	scanf("%d", &s);

	if (s == 4)

		mainmenu();

	system("cls");

	fp = fopen("stf.dat", "ab+");

	if (getdata() == 1)

	{

		a.cat = catagories[s - 1];

		fseek(fp, 0, SEEK_END);

		fwrite(&a, sizeof(a), 1, fp);

		fclose(fp);

		gotoxy(3, 16);

		printf("The record is sucessfully saved");

		gotoxy(3, 17);

		printf("Save any more?(Y / N):");

		if (getch() == 'n')

			mainmenu();

		else

			system("cls");

		addstaff();
	}
}

void deletestaff()

{

	system("cls");

	int d;

	char another = 'y';

	while (another == 'y')

	{

		system("cls");

		gotoxy(3, 2);

		printf("Enter the ID to remove: ");

		scanf("%d", &d);

		fp = fopen("stf.dat", "rb+");

		rewind(fp);

		while (fread(&a, sizeof(a), 1, fp) == 1)

		{

			if (a.id == d)

			{

				gotoxy(3, 4);

				printf("The record is available");

				gotoxy(3, 5);

				printf("Name is %s", a.name);

				gotoxy(3, 7);

				findstaff = 't';
			}
		}

		if (findstaff != 't')

		{

			gotoxy(3, 4);

			printf("No record is found modify the search");

			if (getch())

				mainmenu();
		}

		if (findstaff == 't')

		{

			gotoxy(3, 7);

			printf("Do you want to delete it?(Y/N):");

			if (getch() == 'y')

			{

				ft = fopen("test.dat", "wb+");

				rewind(fp);

				while (fread(&a, sizeof(a), 1, fp) == 1)

				{

					if (a.id != d)

					{

						fseek(ft, 0, SEEK_CUR);

						fwrite(&a, sizeof(a), 1, ft);
					}
				}

				fclose(ft);

				fclose(fp);

				remove("stf.dat");

				rename("test.dat", "stf.dat");

				fp = fopen("stf.dat", "rb+");

				if (findstaff == 't')

				{

					gotoxy(3, 9);

					printf("The record is sucessfully deleted");

					gotoxy(3, 10);

					printf("Delete another record?(Y/N)");
				}
			}

			else

				mainmenu();

			fflush(stdin);

			another = getch();
		}
	}

	gotoxy(10, 15);

	mainmenu();
}

void searchstaff()

{

	system("cls");

	int d;

	printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd SEARCH MEMBER \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");

	gotoxy(3, 5);

	printf("1. Search By ID");

	gotoxy(3, 7);

	printf("2. Search By Name");

	gotoxy(3, 9);

	printf("Enter Your Choice: ");

	fp = fopen("stf.dat", "rb+");

	rewind(fp);

	switch (getch())

	{

	case '1':

	{

		system("cls");

		gotoxy(3, 3);

		printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd SEARCH BY ID \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");

		gotoxy(3, 5);

		printf("Enter the id: ");

		scanf("%d", &d);

		gotoxy(3, 7);

		while (fread(&a, sizeof(a), 1, fp) == 1)

		{

			if (a.id == d)

			{

				Sleep(2);

				gotoxy(3, 5);

				printf("The Record is available");

				gotoxy(3, 8);

				printf("ID:%d", a.id);

				gotoxy(3, 9);

				printf("Category:%s", a.cat);

				gotoxy(3, 10);

				printf("Name:%s", a.name);

				gotoxy(3, 11);

				printf("Address:%s ", a.Address);

				gotoxy(3, 12);

				printf("Contact:%i ", a.contact);

				gotoxy(3, 13);

				printf("Member Since:%s", a.membersince);

				findstaff = 't';
			}
		}

		if (findstaff != 't')

		{

			printf("\aNo Record Found");
		}

		gotoxy(3, 15);

		printf("Try another search?(Y/N)");

		if (getch() == 'y')

			searchstaff();

		else

			mainmenu();

		break;
	}

	case '2':

	{

		char s[15];

		system("cls");

		gotoxy(3, 3);

		printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd SEARCH BY NAME \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");

		gotoxy(3, 5);

		printf("Enter the Name:");

		scanf("%s", s);

		int d = 0;

		while (fread(&a, sizeof(a), 1, fp) == 1)

		{

			if (strcmp(a.name, (s)) == 0)

			{

				gotoxy(3, d + 7);

				// printf("The Staff is available");

				gotoxy(3, d + 8);

				printf("ID:%d", a.id);

				gotoxy(3, d + 9);

				printf("Name:%s", a.name);

				gotoxy(3, d + 10);

				printf("Address:%s", a.Address);

				gotoxy(3, d + 11);

				printf("Contact:%i", a.contact);

				gotoxy(3, d + 12);

				printf("Member Since:%s", a.membersince);

				gotoxy(3, d + 13);

				getch();

				d += 6;
			}
		}

		if (d == 0)

			printf("\aNo Record Found");

		gotoxy(3, d + 8);

		printf("Try another search?(Y/N)");

		if (getch() == 'y')

			searchstaff();

		else

			mainmenu();

		break;
	}

	default:

		getch();

		searchstaff();
	}

	fclose(fp);
}

void viewstaff(void)

{

	int i = 0, j;

	system("cls");

	gotoxy(1, 1);

	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd MEMBER LIST \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");

	gotoxy(2, 2);

	printf("\n CATEGORY === ID ==== NAME ======== ADDRESS ===== CONTACT ===== MEMBER SINCE ");

	j = 4;

	fp = fopen("stf.dat", "rb");

	while (fread(&a, sizeof(a), 1, fp) == 1)

	{

		gotoxy(1, j);

		printf("%s", a.cat);

		gotoxy(14, j);

		printf("%d", a.id);

		gotoxy(22, j);

		printf("%s", a.name);

		gotoxy(36, j);

		printf("%s", a.Address);

		gotoxy(50, j);

		printf("%i", a.contact);

		gotoxy(67, j);

		printf("%s", a.membersince);

		gotoxy(68, j);

		printf("\n\n");

		j++;
	}

	fclose(fp);

	gotoxy(35, 25);

	returnfunc();
}

void editstaff(void)

{

	system("cls");

	int c = 0;

	int d, e;

	gotoxy(20, 4);

	printf("\xdb\xdb\xdb\xdb\xdb\xdbEdit Member's Record \xdb\xdb\xdb\xdb\xdb\xdb");

	char another = 'y';

	while (another == 'y')

	{

		system("cls");

		gotoxy(15, 6);

		printf("Enter Id to be edited:");

		scanf("%d", &d);

		fp = fopen("stf.dat", "rb+");

		while (fread(&a, sizeof(a), 1, fp) == 1)

		{

			if (checkid(d) == 0)

			{

				gotoxy(15, 7);

				printf("This Member is available");

				gotoxy(15, 8);

				printf("The ID:%d", a.id);

				gotoxy(15, 9);

				printf("Enter new name:");

				scanf("%s", a.name);

				gotoxy(15, 10);

				printf("Enter new Address:");

				scanf("%s", a.Address);

				gotoxy(15, 11);

				printf("Enter new Contact:");

				scanf("%i", &a.contact);

				gotoxy(15, 12);

				printf("Enter New Membership date:");

				scanf("%s", &a.membersince);

				gotoxy(15, 13);

				printf("The record is modified");

				fseek(fp, ftell(fp) - sizeof(a), 0);

				fwrite(&a, sizeof(a), 1, fp);

				fclose(fp);

				c = 1;
			}

			if (c == 0)

			{

				gotoxy(15, 9);

				printf("No record found");
			}
		}

		gotoxy(15, 16);

		printf("Modify another Record?(Y/N)");

		fflush(stdin);

		another = getch();
	}

	returnfunc();
}

void returnfunc(void)

{

	{

		gotoxy(15, 20);

		printf("Press ENTER to return to main menu");
	}

a:

	if (getch() == 13)

		mainmenu();

	else

		goto a;
}

int getdata()

{

	int t;

	gotoxy(3, 2);

	printf("Enter the Information Below");

	gotoxy(3, 4);

	printf("%s", catagories[s - 1]);

	gotoxy(3, 6);

	printf("ID:");

	gotoxy(7, 6);

	scanf("%d", &t);

	if (checkid(t) == 0)

	{

		gotoxy(3, 10);

		printf("\aThe id already exists\a");

		getch();

		mainmenu();

		return 0;
	}

	a.id = t;

	gotoxy(3, 8);

	printf("Name:");

	gotoxy(9, 8);

	scanf("%s", a.name);

	gotoxy(3, 10);

	printf("Address:");

	gotoxy(12, 10);

	scanf("%s", a.Address);

	gotoxy(3, 12);

	printf("Contact:");

	gotoxy(12, 12);

	scanf("%i", &a.contact);

	gotoxy(3, 14);

	printf("Member Since:");

	gotoxy(17, 14);

	scanf("%s", &a.membersince);

	gotoxy(3, 16);

	return 1;
}

int checkid(int t)

{

	rewind(fp);

	while (fread(&a, sizeof(a), 1, fp) == 1)

		if (a.id == t)

			return 0;

	return 1;
}

int t(void)

{

	time_t t;

	time(&t);

	printf("Date and time:%s\n", ctime(&t));

	return 0;
}

void Password(void)

{

	system("cls");

	char d[25] = "Password Protected";

	char ch, pass[10];

	int i = 0, j;

	printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("   \xcd\xcd\xcd\xcd\xcd\xcd GYM MANAGEMENT SYSTEM \xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");

	printf("\n\n   Enter Password:");

	while (ch != 13)

	{

		ch = getch();

		if (ch != 13 && ch != 8)
		{

			putch('*');

			pass[i] = ch;

			i++;
		}
	}

	pass[i] = '\0';

	if (strcmp(pass, password) == 0)

	{

		printf("\n\n\n   Password matched!!");

		printf("\n   Press any key to countinue.....");

		getch();

		mainmenu();
	}

	else

	{

		printf("\n\n   Warning!! \n   Incorrect Password");

		getch();

		Password();
	}
}
