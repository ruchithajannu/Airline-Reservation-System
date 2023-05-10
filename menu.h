#include<string.h>
void norm()
{
  textcolor(15);
  textbackground(0);
}
void rev()
{
  textcolor(0);
  textbackground(15);
}
int pmenu(char st[][20],int n,int r,int c,int cc)
{
   int r1,c1,count,i,l=0;
   char ch;
   count=cc;
   for(i=0;i<n;i++)
   {
      if(l<strlen(st[i]))
       l=strlen(st[i]);
    }
   do
    {

       r1=r;
       c1=c;
       for(i=0;i<n;i++)
       {
	 gotoxy(c1,r1);
	 if(count==i)
	   rev();
	 else
	   norm();
	 cprintf("%-*s",l,st[i]);
	 r1++;
       }
     ch=getch();
     if(ch==0)
     ch=getch();
     if(ch==72)
     {
       count--;
       if(count<0)
	count=n-1;
      }
     if(ch==80)
     {
       count++;
       if(count>n-1)
	count=0;
      }
     if(ch==13)
       return count+1;
     if(ch==27)
      return -1;
     if(ch==75||ch==77)
       return ch;
   }while(1);
 }
int hmenu(char st[][20],int n,int r,int c,int cc,int ck)
{
   int r1,c1,count,i;
   char ch;
   count=cc;
   do
    {

       r1=r;
       c1=c;
       for(i=0;i<n;i++)
       {
	 gotoxy(c1,r1);
	 if(count==i)
	   rev();
	 else
	   norm();
	 cprintf("%s",st[i]);
	 c1=c1+strlen(st[i])+5;
       }
     if(ck==1)
      return 0;
    else
    {
     ch=getch();
     if(ch==0)
     ch=getch();
    }
     if(ch==75)
     {
       count--;
       if(count<0)
	count=n-1;
      }
     if(ch==77)
     {
       count++;
       if(count>n-1)
	count=0;
      }
     if(ch==13)
     return count+1;
   }while(1);
 }
