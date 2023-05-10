#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include"booking.h"

void admenu();
void menu();

void box()
{
 int i,j;
 for(i=1;i<=24;i++)
 {
   for(j=1;j<=80;j++)
   {
     textcolor(LIGHTCYAN);
     cprintf("%c",219);
   }
 }
}
void cbody(int x, int y)
{
  gotoxy(x,y);
  textcolor(LIGHTGREEN);
  textbackground(LIGHTBLUE);
}

void ccare()
{
printf("                               SRM-AP, Amaravathi.   ");
printf("\n\nFeel free to contact us anytime\n");
printf("\n---TEAM---");
printf("\nSection : C");
printf("\nGroup   : 4");
printf("\nMentor  : Vidya V");
printf("\n\nTeam members:");
printf("\nRuchitha Jannu (AP21110010140)");
printf("\nSubodh Amru Kiliveti (AP21110010141)");
printf("\nRitika Khande (AP21110010142)");
printf("\n\nObjective / Aim:");
printf("\nThe purpose of the project is to build an application program to reduce");
printf("\nthe manual work for managing the booking counter and customer care.");
printf("\n\nTicket Fares: ");
printf("\n   Age 1 to 4   : Rs.0");
printf("\n   Age 5 to 18  : Rs.250");
printf("\n   Age 19 to 99 : Rs.500");
}

void main()
{
  int opt,i;
  char pass[10];

  while(1)
  {
  clrscr();
  box();

  cbody(20,9);
  cprintf("%c                                          %c\n",219,219);
  cbody(20,10);
  cprintf("%c          AIRLINE BOOKING SYSTEM          %c\n",219,219);
  cbody(20,11);
  cprintf("%c                                          %c\n",219,219);
  cbody(20,12);
  cprintf("%c      1. ADMIN                            %c\n",219,219);
  cbody(20,13);
  cprintf("%c      2. COUSTMER                         %c\n",219,219);
  cbody(20,14);
  cprintf("%c      3. EXIT                             %c\n",219,219);
  cbody(20,15);
  cprintf("%c                                          %c\n",219,219);

  gotoxy(20,25);
  printf("Enter Your Choice:");
  scanf("%d",&opt);

  clrscr();
  switch(opt)
    {

    case 1:
		admenu();
		break;

    case 2:
		menu();
		break;

    case 3:
		exit(0);
		break;

   default:

		printf("Invalid Input");
		break;
   }

getch();
  }
}

void menu()
{
  int opt,i;
  clrscr();

  while(1)
   {
    clrscr();
    box();

  cbody(20,9);
  cprintf("%c                                        %c\n",219,219);
  cbody(20,10);
  cprintf("%c      1. Booking                        %c\n",219,219);
  cbody(20,11);
  cprintf("%c      2. Customer Care                  %c\n",219,219);
  cbody(20,12);
  cprintf("%c      3. Exit Menu                      %c\n",219,219);
  cbody(20,13);
  cprintf("%c                                        %c\n",219,219);

 gotoxy(20,25);
  printf("Enter Your Choice:");
  scanf("%d",&opt);

  clrscr();
  switch(opt)
    {

    case 1:
		openacc(ret_seatno());
		break;
  
     
    case 2:
		ccare();
		break;

    case 3:
		main();
		break;
   default:

		printf("Invalid Input");
		break;
   }
  getch();
 }
}
//************************************************//

void admenu()
{
  int opt,i;
  clrscr();

  while(1)
   {
    clrscr();
    box();

  cbody(20,9);
  cprintf("%c                                        %c\n",219,219);
  cbody(20,10);
  /*cprintf("%c    1. Flight update                  %c\n",219,219);
  cbody(20,11);*/
  cprintf("%c      1. Display Rec                    %c\n",219,219);
  cbody(20,11);
  cprintf("%c      2. Search Rec                     %c\n",219,219);
  cbody(20,12);
  cprintf("%c      3. Exit Menu                      %c\n",219,219);
  cbody(20,13);
  cprintf("%c                                        %c\n",219,219);

 gotoxy(20,25);
  printf("Enter Your Choice:");
  scanf("%d",&opt);

  clrscr();
  switch(opt)
    {

    case 1:
		dispall();
		break;

    case 2:
		searchacc();
		break;
    case 3:
		main();
		break;
   default:

		printf("Invalid Input");
		break;
   }
  getch();
 }
}

