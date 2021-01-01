#include<stdio.h>
#include<conio.h>

void about();
void disclamier();

void main()
{
int i,ch=0;
char cha;

while(ch!=4)
 {
  textcolor(10);
  clrscr();
  gotoxy(20,1);
  printf("-:CMOS PASSWORD BREAKER(version1.0):-");
  printf("\nEnter your choice");
  printf("\n[1]Break cmos password");
  printf("\n[2]About");
  printf("\n[3]Disclamier");
  printf("\n[4]Exit");
  printf("\n Your choice[ ]");
  gotoxy(62,22);
  printf("By:-");
  gotoxy(62,23);
  printf("Syntax-Example");
  while(1)
  {
  gotoxy(14,7);
  fflush(stdin);
  scanf("%d",&ch);
  if (ch==1|ch==2|ch==3|ch==4)
  break;
  else
  gotoxy(14,7);
  printf(" ");
  gotoxy(15,8);
  printf("You must enter a valid number beetween 1-4");
    }

  switch(ch)
    {
    case 1: clrscr();
        printf("Are You Sure(y/n)???");
        fflush(stdin);
        scanf("%c",&cha);
        if(cha=='y'|cha=='Y')
        {
        clrscr();
        printf("Breaking Cmos Password,Please Wait....");
        for(i=0;i<256;i++)
         {
         //outp(0x70,i);//outp(0x71,i);
         }
        delay(5600);
        clrscr();
        printf("\nCmos Password Breaked!!!");
        getch();
        clrscr();
        gotoxy(20,1);
        printf("-:CMOS PASSWORD BREAKER(version1.0):-");
        about();
        gotoxy(26,16);
        printf("Thanks For Using This.");
        gotoxy(40,18);
        printf("Press any key to Exit....");
        getch();
        exit(1);
        }
        else
         {
        clrscr();
        gotoxy(20,4);
        printf("-:CMOS PASSWORD BREAKER(version1.0):-");
        about();
        gotoxy(34,16);
        printf("Press any key.......");
        }
        getch();
        break;
     case 2:clrscr();
        gotoxy(20,1);
        textcolor(11);
        cprintf("-:Cmos Password Breaker(version1.0):-");
        gotoxy(3,4);
        cprintf("This is a helpfull utility for those person who forgot cmos password.This " );
        gotoxy(3,5);
        cprintf("programm can break all the cmos password stored in cmos battery.");
        gotoxy(10,6);
        cprintf("(SUPERVISOR Password and USER Password)");
        textcolor(13);
        gotoxy(8,8);
        cprintf("NOTE:-When you break cmos password by using this then");
        gotoxy(10,9);
        cprintf("    next time when you boot your computer then at startup");
        gotoxy(10,10);
        cprintf("    cmos shows checksum error and restore defaults.");
        gotoxy(25,12);
        cprintf("      IT IS NORMAL.");
        gotoxy(26,17);
        printf("*************************************");
        gotoxy(26,24);
        printf("*************************************");
        for(i=17;i<25;i++)
         {
          gotoxy(26,i);
          printf("%c",178);
        }
        for(i=17;i<25;i++)
          {
          gotoxy(62,i);
          printf("%c",178);}
          textcolor(14);
          gotoxy(31,18);
          cprintf("Cmos Password Breaker By:- ");
          gotoxy(38,19);
          cprintf("Syntax-Example");
          gotoxy(31,20);
          cprintf("E-mail:-");
          gotoxy(30,21);
          cprintf("admin@syntax-example.com");
          gotoxy(42,22);
          getch();
          break;

     case 3:disclamier();
        break;
     case 4:exit(1);
        }
       }
     }

   void about()
      {
       int i;
     gotoxy(20,7);
     printf("*************************************");
     gotoxy(20,14);
     printf("*************************************");
     for(i=7;i<15;i++)
       {
       gotoxy(20,i);
       printf("%c",178);
          }
     for(i=7;i<15;i++)
     {
       gotoxy(57,i);
       printf("%c",178);}
       textcolor(7);
       gotoxy(26,8);
       cprintf("Cmos Password Breaker By:- ");
       gotoxy(32,9);
       cprintf("Syntax-Example");
       gotoxy(25,10);
       cprintf("E-mail:-");
       gotoxy(25,11);
       cprintf("admin@syntax-example.com");
    }

   void disclamier()
   {
   clrscr();
   gotoxy(20,2);
   printf("-:Cmos Password Breaker(version1.0):-");
   gotoxy(2,3);
   printf("Disclamier:-");
   gotoxy(1,5);
   printf("This software is provided on \"AS-IS\"  basis.I am not responsible for any damage");
   gotoxy(1,6);
   printf("caused to you or your computer's hardware or software by using this software.");
   gotoxy(6,7);
   printf("This software is freeware you can distribute this software to any one who ");
   gotoxy(1,8);
   printf("wish to use it.You can use this as you wish.");
   gotoxy(6,9);
   printf("If you found any bug or wish to give any suggestion for improvment of");
   gotoxy(1,10);
   printf("this programme then please contact me at my E-mail adrress:-");
   gotoxy(20,12);
   printf("admin@syntax-example.com");
   getch();
    }
