#include<stdio.h>
#include<conio.h>
FILE *f,*f1;
struct bank
{
  int accno;
  char acname[20];
  float bal;
}b;
int ret_accno()
{
  f=fopen("bank.dat","r");
  while(fread(&b,sizeof(b),1,f)==1);
  fclose(f);
  if(b.accno==0)
     return 1000;
 else
    return b.accno+1;
}
void openacc(int n)
{
 f=fopen("bank.dat","a");
 printf("A/C Number :%d\n",n);
 b.accno=n;
 printf("Enter Name :");
 fflush(stdin);
 gets(b.acname);
 b.bal=500;
 printf("Opening balance :%.2f",b.bal);
 fwrite(&b,sizeof(b),1,f);
 fclose(f);
}
void header()
{
  printf("%-10s%-15s%s","A/C.NO","A/C.NAME","BALANCE");
  printf("\n-------------------------------------");
  }
void dispall()
{
  int c=0;
  f=fopen("bank.dat","r");
  header();
  while(fread(&b,sizeof(b),1,f)==1)
  {
    printf("\n%-10d%-15s%.2f",b.accno,b.acname,b.bal);
    c++;
    if(c%20==0)
    {
     printf("\nPress any key to continue..........");
     getch();
//     clrscr();
     header();
   }
}
 fclose(f);
}
void searchacc()
{
  int ck=0,taccno;
  f=fopen("bank.dat","r");
  printf("Enter A/c .No to search :");
  scanf("%d",&taccno);
  while(fread(&b,sizeof(b),1,f)==1)
  {
     if(b.accno==taccno)
     {
       ck=1;
       printf("Account Holder Name :%s",b.acname);
       printf("\nBalance Amount     :%.2f",b.bal);
       break;
      }
  }
  if(ck==0)
  {
    gotoxy(35,22);
    printf("Account number not found");
  }
 fclose(f);
}
void deposit()
{
  int ck=0,taccno;
  float amt;
  f=fopen("bank.dat","r");
  f1=fopen("temp.dat","w");
  printf("Enter Accno to  deposit :");
  scanf("%d",&taccno);
  while(fread(&b,sizeof(b),1,f)==1)
  {
     if(b.accno==taccno)
     {
       ck=1;
       printf("Enter deposit Amount :");
       scanf("%f",&amt);
       b.bal=b.bal+amt;
      }
    fwrite(&b,sizeof(b),1,f1);
  }
  fcloseall();
  remove("bank.dat");
  rename("temp.dat","bank.dat");
   gotoxy(35,22);
  if(ck==0)
   printf("Account number not found");
  else
    printf("Rs %.2f is Deposited",amt);
 }
 void withdrawal()
 {
  int ck=0,taccno,flag=0;
  float amt;
  f=fopen("bank.dat","r");
  f1=fopen("temp.dat","w");
  printf("Enter Accno to  withdrawal :");
  scanf("%d",&taccno);
    while(fread(&b,sizeof(b),1,f)==1)
  {
     if(b.accno==taccno)
     {
       ck=1;
       if(b.bal>200)
	{
	    printf("Enter withdrawal Amount :");
	    scanf("%f",&amt);
	    if(b.bal-amt>=200)
	       b.bal=b.bal-amt;
	     else
	       flag=1;
	  }
	else
	  flag=1;
      }
    fwrite(&b,sizeof(b),1,f1);
  }
  fcloseall();
  remove("bank.dat");
  rename("temp.dat","bank.dat");
   gotoxy(35,22);
  if(ck==0)
  {
    printf("Account number not found");
     return;
   }
   if(flag==0)
     printf("Rs %.2f is withdrawn",amt);
    else
      printf("Withdrawal is not possible");
  }
 void closeacc()
 {
  int ck=0,taccno;
  f=fopen("bank.dat","r");
  f1=fopen("temp.dat","w");
  printf("Enter Accno to  close :");
  scanf("%d",&taccno);
  while(fread(&b,sizeof(b),1,f)==1)
  {
     if(b.accno!=taccno)
       fwrite(&b,sizeof(b),1,f1);
     else
       ck=1;
  }
  fcloseall();
  remove("bank.dat");
  rename("temp.dat","bank.dat");
   gotoxy(35,22);
  if(ck==0)
    printf("Account number not found");
  else
     printf("%d Account is closed",taccno);
  }

