#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
void auth(int);
void content();
void menu(void);
void menu2(void);
void add_student();
void show_student();
void add_teacher();
void srch_teacher();
void search_stu(int);
void srch_student();
void srch_stud(int);
void srch_tcr();
void del_admin();
void show_teacher();
void change_pass();
void about_me();
void make_admin();
void thank_you();
struct adminmain
{
  char unm[50],pass[50],name[50],address[50],email[50],phno[20];
}admin;
struct student
{
  char name[100],email[50],address[60],phno[20];
  int cls,roll,adno;
 // long phno;
 // struct student *next;
}s;
struct teacher
{
  char name[100],email[50],address[60],phno[20];
  int cls,tid;
 // long phno;
 // struct teacher *next;
}t;
void frame()
{
  int i;
  for(i=0;i<=24;i++)
  {
    gotoxy(1,i);
    printf("| ");
    gotoxy(77,i);
    printf("| ");
  }
  for(i=0;i<=38;i++)
  {
    gotoxy(2*i,1);
    printf("* ");
    gotoxy(2*i,25);
    printf("* ");
  }
}
void welcome()
{
  frame();
  gotoxy(50,20);
  printf("created by: Palak");

  while(!kbhit())
  {
  gotoxy(25,24);
  printf("   <Welcome>   ");
  delay(400);
  gotoxy(25,24);
  printf("  <<Welcome>>  ");
  gotoxy(25,24);
  delay(400);
  printf(" <<<Welcome>>> ");
  delay(400);
  }
}
void input(char *txt)
{
while(!kbhit())
  {
  gotoxy(25,24);
  printf("   <%s>   ",txt);
  delay(400);
  gotoxy(25,24);
  printf("  <<%s>>  ",txt);
  gotoxy(25,24);
  delay(400);
  printf(" <<<%s>>> ",txt);
  delay(400);
  }
}
void login()
{
clrscr();
  frame();
  int i;
  FILE *fa;
  fa=fopen("admindb.dat","rb");
  if(fa==NULL)
  {
  gotoxy(25,10);
  printf("No admin present");
  fclose(fa);
  getche();
  make_admin();
  }
  gotoxy(28,8);
  printf("L O G I N");
  for(i=1;i<=12;i++)
  {
    gotoxy(22,i+10);
    printf("|");
    gotoxy(44,i+10);
    printf("|");
  }
  for(i=1;i<=12;i++)
  {
    gotoxy(2*(i+10),22);
    printf("*");
    gotoxy(2*(i+10),10);
    printf("*");
  }
  char unm[50],pass[50],ch;
  gotoxy(24,12);
  printf("Username:");
  gotoxy(24,16);
  printf("Password:");
  gotoxy(24,13);
  gets(unm);
  int j=0;
  while(1)
  {
    ch=getch();
    if(ch==13)
    {
      //pass[j]=='\0';
      break;
    }
    else if(ch==8)
    {
    if(j>0)
    {
      gotoxy(24+j,17);
      printf("\b \b");
      j--;
      pass[j]='\0';
      }
    }
    else
    {
      pass[j]=ch;
      gotoxy(24+j,17);
      printf("*");
      j++;
    }
  }
  pass[j]='\0';
  //printf("%s",pass);
  fread(&admin,sizeof(admin),1,fa);
  if((strcmp(unm,admin.unm)==0)&&(strcmp(pass,admin.pass)==0))
  {

  auth(1);
  //printf("%s %s %d",unm,pass,j);
  }
  else
  {
  auth(0);
  //printf("%s %s %d",unm,pass,j);
  }
}
void make_admin()
{
 clrscr();
 printf("1. Enter name");
 gets(admin.name);
 printf("2. Enter phno");
 gets(admin.phno);
 printf("3. Enter email");
 gets(admin.email);
 printf("4. Enter address");
 gets(admin.address);
 printf("5. Enter username");
 gets(admin.unm);
 printf("6. Enter password");
 gets(admin.pass);
 FILE *fd;
 fd=fopen("admindb.dat","wb");
 if(fd!=NULL)
 {
   fwrite(&admin,sizeof(admin),1,fd);
   fclose(fd);
   printf("Admin made successfully");
   getch();
   login();
 }
}
void auth(int k)
{

 clrscr();
 //char ch;
 frame();
 if(k==1)//successfull
 {
 gotoxy(20,10);
  printf(" S U C C E S S F U L");
  input("Press Any Key");
  getch();
   clrscr();
   content();
  }
  else

  {
  gotoxy(20,10);
  printf(" U N S U C C E S S F U L");
  getch();
 // login();
  }

  //getch();

}
void content()
{
char ct;
clrscr();
frame();
gotoxy(60,3);
printf("TIME %s",__TIME__);
gotoxy(20,3);
printf("DATE %s",__DATE__);
gotoxy(25,8);
printf("1.STUDENT");
gotoxy(25,9);
printf("2.TEACHER");
gotoxy(25,10);
printf("3.ABOUT ME");
gotoxy(25,11);
printf("4.CHANGE PASSWORD");
gotoxy(25,12);
printf("5.DELETE ADMIN");
gotoxy(25,13);
printf("PRESS <0> TO EXIT\n");
gotoxy(25,14);
printf("ENTER YOUR CHOICE:");
gotoxy(45,17);
ct=getche();
switch(ct)
{
  case '1':
    menu();
    break;
  case '2':
    menu2();
    break;
  case '3':
    about_me();
    break;
  case '4':
    change_pass();
    break;
  case '5':
    del_admin();
    break;
  case '0':
    thank_you();
    break;
  default:
    gotoxy(25,19);
    printf("INVALID INPUT");
    getch();
    content();
    break;
}
}
void change_pass()
{
clrscr();
  FILE *ft;
  ft=fopen("admindb.dat","rb");
  if(ft!=NULL)
  {
     printf("Are you sure to change the password (Y for yes and N for no)");
     fread(&admin,sizeof(admin),1,ft);
     char ch;
     ch=getch();
     if(ch=='y'||ch=='Y')
     {
       printf("\nEnter old password:");
       char arr[20];
       gets(arr);
       if(strcmp(arr,admin.pass)==0)
       {
	printf("Enter new password:");
	char newpass[20];
	gets(newpass);
	struct adminmain abc;
	strcpy(abc.pass,newpass);
	strcpy(abc.name,admin.name);
	strcpy(abc.email,admin.email);
	strcpy(abc.phno,admin.phno);
	strcpy(abc.address,admin.address);
	strcpy(abc.unm,admin.unm);
	fclose(ft);
	FILE *fa;
	fa=fopen("admindb.dat","wb");
	fwrite(&abc,sizeof(abc),1,fa);
	fclose(fa);
	printf("Password changed successfully!!! Please wait for 5 sec");
	delay(5000);
	login();
       }
       else
       {
	printf("Wrong password");
	getch();
	login();
       }
     }
  }
}
void del_admin()
{
clrscr();
  FILE *ft;
  ft=fopen("admindb.dat","rb");
  if(ft!=NULL)
  {
     printf("Are you sure to delete admin (Y for yes and N for no)");
     fread(&admin,sizeof(admin),1,ft);
     char ch;
     ch=getch();
     if(ch=='y'||ch=='Y')
     {
       printf("Enter password:");
       char arr[20];
       gets(arr);
       if(strcmp(arr,admin.pass)==0)
       {
	printf("Removing Admin...Wait 5 sec.");
	remove("admindb.dat");
	delay(5000);
	login();
       }
       else
       {
	printf("Wrong password");
	getch();
	login();
       }
     }
  }
}
void menu()
{
//getch();
char ch;
clrscr();
frame();
gotoxy(60,3);
printf("TIME %s",__TIME__);
gotoxy(20,3);
printf("DATE %s",__DATE__);
gotoxy(25,8);
printf("1. ADD STUDENT");
gotoxy(25,9);
printf("2. SHOW STUDENT");
gotoxy(25,10);
printf("3. SEARCH STUDENT");
gotoxy(25,11);
printf("4. ABOUT ME");
gotoxy(25,12);
printf("5. BACK TO CONTENTS");
gotoxy(25,14);
printf("ENTER YOUR CHOICE:");
gotoxy(45,17);
//scanf("%c",&ch);

ch=getche();

switch(ch)
{
  case '1':
    add_student();
   break;
  case '2':
    show_student();
   break;
   case '3':
    srch_stud(12);
    break;
   case '4':
    about_me();
    break;
   case '5':
    clrscr();
    content();
    break;
   case '0':
    break;
   default:
    gotoxy(25,19);
    printf("INVALID INPUT");
    getch();
    menu();
    break;

}
//getch();
}
void menu2()
{
char ch2;
clrscr();
frame();
gotoxy(60,3);
printf("TIME %s",__TIME__);
gotoxy(20,3);
printf("DATE %s",__DATE__);
gotoxy(25,8);
printf("1. ADD TEACHER");
gotoxy(25,9);
printf("2. SHOW TEACHER");
gotoxy(25,10);
printf("3. SEARCH TEACHER");
gotoxy(25,11);
printf("4. ABOUT ME");
gotoxy(25,12);
printf("5. BACK TO CONTENTS");
gotoxy(25,14);
printf("ENTER YOUR CHOICE:");
gotoxy(45,17);
//scanf("%c",&ch);

ch2=getche();

switch(ch2)
{
  case '1':
    add_teacher();
   break;
  case '2':
    show_teacher();
   break;
   case '3':
    srch_teacher();
    break;
   case '4':
    about_me();
    break;
   case '5':
    clrscr();
    content();
    break;
   default:
    gotoxy(25,19);
    printf("INVALID INPUT");
    getch();
    menu2();
    break;

}
//getch();
}
void add_student()
{
clrscr();
/*  char name[100],email[50],address[60];
  int cls,roll,adno;
  long phno;  */
//email add phno cls
 printf("Enter the name of student ");
 gets(s.name);
 printf("Enter student email ");
 gets(s.email);
 printf("Enter student home address ");
 gets(s.address);
 printf("Enter student phone number ");
 gets(s.phno);
  printf("Enter student class ");
 scanf("%d",&s.cls);
 printf("Enter student addmission number ");
 scanf("%d",&s.adno);
 printf("Enter student roll number ");
 scanf("%d",&s.roll);

 //printf("%s %s %s %s %d %d %d",s.name,s.email,s.address,s.phno,s.adno,s.cls,s.roll);
  FILE *fs;
  fs = fopen("studentdb.dat","ab");
  fwrite(&s,sizeof(s),1,fs);
  fclose(fs);
  menu();
}
void search_stu(int adno)
{
   student s,s1;
FILE *fs;
int flag=0;
fs = fopen("studentdb.dat","rb");
if(fs==NULL)
{
 printf("Error in file loading...");
 }
 else
 {
 int i;
 fseek(fs,0,SEEK_END);
 long n = ftell(fs)/sizeof(s);
 fseek(fs,0,SEEK_SET);
  for( i= 1;i<=n;i++)
  {

   fread(&s1,sizeof(s),1,fs);
   if(s1.adno==adno)
   {
    s=s1;
    flag=1;
    break;
   }
   //
   }
     if(flag==1)
    {
    printf("\n%s %s %s %s %d %d %d",s.name,s.email,s.address,s.phno,s.adno,s.cls,s.roll);

    }
    else
    {
    printf("No such student exist!! ");
    }
 }
 fclose(fs);
 getch();
 menu();
}
void srch_stud(int cls)
{
clrscr();
 student s,s1;
 FILE *fs;
 int flag=0;
 fs=fopen("studentdb.dat","rb");
 if(fs==NULL)
 {
 printf("Error in loading file...");
 }
 else
 {
   int i;
   fseek(fs,0,SEEK_END);
   long n = ftell(fs)/sizeof(s);
   fseek(fs,0,SEEK_SET);
   for( i= 1;i<=n;i++)
   {
    fread(&s1,sizeof(s),1,fs);
   if(s1.cls==cls)
   {
    printf("\n%s %d %d %s %s %s %d",s1.name,s1.adno,s1.cls,s1.address,s1.phno,s1.email,s1.roll);
   }
   }
}
getch();
menu();
}
void show_student()
{
clrscr();
student s;
FILE *fs;
fs = fopen("studentdb.dat","rb");
if(fs==NULL)
{
 printf("Error in file loading...");
 }
 else
 {
 int i;
 fseek(fs,0,SEEK_END);
 long n = ftell(fs)/sizeof(s);
 fseek(fs,0,SEEK_SET);
  for( i= 1;i<=n;i++)
  {
   fread(&s,sizeof(s),1,fs);
   printf("\n%s %s %s %s %d %d %d",s.name,s.email,s.address,s.phno,s.adno,s.cls,s.roll);

  }
 }
 fclose(fs);
 getch();
 menu();
}
void add_teacher()
{
clrscr();
  char name[100],email[50],address[60];
  int cls,tid;
  long phno;
//email add phno cls
 printf("Enter the name of teacher ");
 gets(t.name);
 printf("Enter teacher email ");
 gets(t.email);
 printf("Enter teacher home address ");
 gets(t.address);
 printf("Enter teacher phone number ");
 gets(t.phno);
  printf("Enter teacher class ");
 scanf("%d",&t.cls);
 printf("Enter teacher id ");
 scanf("%d",&t.tid);

 //printf("%s %s %s %s %d %d %d",s.name,s.email,s.address,s.phno,s.adno,s.cls,s.roll);
  FILE *ft;
  ft = fopen("teacherdb.dat","ab");
  fwrite(&t,sizeof(t),1,ft);
  fclose(ft);
    menu2();
}
void show_teacher()
{
clrscr();
teacher t;
FILE *ft;
ft = fopen("teacherdb.dat","rb");
if(ft==NULL)
{
 printf("Error in file loading...");
 }
 else
 {
 int i;
 fseek(ft,0,SEEK_END);
 long n = ftell(ft)/sizeof(t);
 fseek(ft,0,SEEK_SET);
  for( i= 1;i<=n;i++)
  {
   fread(&t,sizeof(t),1,ft);
   printf("\n%s %s %s %s %d",t.name,t.email,t.address,t.phno,t.cls);

  }
 }
 fclose(ft);
 getch();
  menu2();
}
void srch_teacher()
{
clrscr();
//frame();
teacher t;
FILE *ft;
ft=fopen("teacherdb.dat","rb");
if (ft==NULL)
{
 printf("Error in loading file...");
}
else
{
 int i;
 fseek(ft,0,SEEK_END);
 long n=ftell(ft)/sizeof(t);
 printf("%d",n);
 fseek(ft,0,SEEK_SET);
 for(i=1;i<=n;i++)
 {
  fread(&t,sizeof(t),1,ft);
  printf("\n%s %s %s %s %d %d",t.name,t.address,t.email,t.phno,t.cls,t.tid);
  }
 fclose(ft);
 getch();
 menu2();
}
//getch();
}
void about_me()
{
clrscr();
  frame();
  FILE *fs;
  fs=fopen("admindb.dat","rb");
  fread(&admin,sizeof(admin),1,fs);
  gotoxy(4,5);
  printf(" About\n ");

  gotoxy(8,10);
  printf("Admin name %s\n",admin.name);
  gotoxy(8,11);
  printf("Admin email %s\n",admin.email);
  gotoxy(8,12);
  printf("Admin phno %s\n",admin.phno);
  gotoxy(8,13);
  printf("Admin address %s\n",admin.address);
  gotoxy(8,14);
  printf("Admin username %s\n",admin.unm);
  gotoxy(8,15);
  //printf("Admin password %s\n",admin.pass);
  fclose(fs);
  getch();
  content();
}
void thank_you()
{
  clrscr();
  frame();
  int i;
  gotoxy(28,8);
  printf("T H A N K   Y O U");
  getch();
  exit(0);
}
void main()
{
  int i;
  clrscr();
  welcome();
  getch();
  clrscr();
  login();
  //getch();
  //clrscr();
  //content();
  //search_stu(1234);
  //srch_teacher();
  }

