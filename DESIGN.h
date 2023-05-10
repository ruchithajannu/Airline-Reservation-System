#include<stdio.h>
#include<conio.h>
void hline(int r,int sc,int ec)
{
    int i;
   for(i=sc;i<=ec;i++)
   {
     gotoxy(i,r);
     printf("%c",196);
    }
 }
void vline(int c,int sr,int er)
{
   int i;
   for(i=sr;i<=er;i++)
   {
     gotoxy(c,i);
   printf("%c",179);
    }
 }
void box(int sc,int sr,int ec,int er)
{
  gotoxy(sc,sr);
 printf("%c",218);
   gotoxy(sc,er);
  printf("%c",192);
   gotoxy(ec,sr);
  printf("%c",191);
   gotoxy(ec,er);
  printf("%c",217);
   hline(sr,sc+1,ec-1);
   hline(er,sc+1,ec-1);
   vline(sc,sr+1,er-1);
   vline(ec,sr+1,er-1);
}