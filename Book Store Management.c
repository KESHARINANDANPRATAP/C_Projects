// Submited By-KESHARI NANDAN PRATAP
/*        Password to run this program is 1234*/
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip.h>
#include<dos.h>

class group
{
    protected:
    struct books
    {
     char flag;
     char bname[50];
     char aname[50];
     char pubname[50];
     int price;
     int noofbooks;
    }b;
     fstream file;
    public:
    group();
    void insert();
    void display();
    void update();
    void search();
    void deletion();
    void exit();
};

void main()
{
    int choice;
    char pass[20]; 
    clrscr(); 
    group g; 
y:      clrscr(); 
    gotoxy(12,12); 
    cout<<"ENTER THE PASSWORD  :"; 
    cin>>pass; 
    if(strcmp(pass,"1234")==0) 
    goto z; 
    else 
    { 
        gotoxy(12,12); 
        cout<<"INCORRECT PASSWORD"; 
        sound(1000); 
        delay(1000); 
        nosound(); 
        clrscr(); 
        goto y; 
    } 
    //group g; 
z:      do 
    { 
      clrscr(); 
      gotoxy(30,4); 
      cout<<"*********************"; 
      gotoxy(30,5); 
      cout<<"BOOK STORE MANAGEMENT"; 
      gotoxy(30,6); 
      cout<<"*********************"; 
      gotoxy(30,10); 
      cout<<"1.insert record"; 
      gotoxy(30,11); 
      cout<<"2.display"; 
      gotoxy(30,12); 
      cout<<"3.update"; 
      gotoxy(30,13); 
      cout<<"4.search"; 
      gotoxy(30,14); 
      cout<<"5.delete"; 
      gotoxy(30,15); 
      cout<<"6.exit"; 
      gotoxy(30,20); 
      cout<<"enter your choice  :"; 
      cin>>choice; 
      clrscr(); 
      switch(choice) 
      { 
        case 1: 
             g.insert(); 
             break; 
        case 2: 
             g.display(); 
             break; 
        case 3: 
             g.update(); 
             break; 
        case 4: 
             g.search(); 
             break; 
        case 5: 
             g.deletion(); 
             break; 
        case 6: 
             g.exit(); 
             exit(1); 
    } 
      }while(choice != 0); 
} 

void group::group() //zero argument constructor 
{ 
 file.open("books.dat",ios::binary|ios::in|ios::out); 
 if(!file) 
    { 
      cout<<endl<<"unable to open the file"; 
       exit(); 
    } 
} 


//adds record to the file void group::insert() 
{ 
    char ch; 
    file.seekp(0L,ios::end); 
    do 
    { 
     cout<<endl<<"enter book name :"; 
     gets(b.bname); 
     cout<<endl<<"enter author's name :"; 
     gets(b.aname); 
     cout<<endl<<"enter publisher's name :"; 
     gets(b.pubname); 
     cout<<endl<<"enter the book's price :"; 
     cin>>b.price; 
     cout<<endl<<"enter the no of books  :"; 
     cin>>b.noofbooks; 
     b.flag=' '; 
     file.write((char*)&b,sizeof(b)); 
     cout<<endl<<endl<<"add another record?(y/n)"; 
     cin>>ch; 
    }while(ch=='y' || ch=='Y'); 
} 

//displays all the books void group::display() 
{ 
int j=1; 
file.seekg(0L,ios::beg); 

while (file.read((char*)&b,sizeof(b))) 
{ 
if(b.flag != '*') 
{ 
    cout<<endl<<"RECORD NO :"<<j++<<endl<<"*************"<<endl<<"BOOK NAME   :"<<b.bname<<endl<<"AUTHOR NAME :"<<b.aname 
        <<endl<<"PUBLISHER   :"<<b.pubname<<endl<<"PRICE       :"<<b.price 
        <<endl<<"COPIES      :"<<b.noofbooks<<endl<<endl<<endl; 
    getch(); 
} 
} 
file.clear(); 
a:cout<<endl<<endl<<endl<<"press any key ...."; 
getch(); 
} 

//update the books void group::update() 
{ 
    char code[20]; 
    int count=0; 
    longint pos; 
    cout<<endl<<"enter the book name :"; 
    gets(code); 

    file.seekg(0L,ios::beg); 

    while(file.read((char*)&b,sizeof(b))) 
    { 
      if(strcmp(b.bname,code)==0) 
       { 
        cout<<endl<<"enter the new book name :"; 
        gets(b.bname); 
        cout<<endl<<"enter author's name     :"; 
        gets(b.aname); 
        cout<<endl<<"enter publisher's name  :"; 
        gets(b.pubname); 
        cout<<endl<<"enter the price         :"; 
        cin>>b.price; 
        cout<<endl<<"enter the no of books   :"; 
        cin>>b.noofbooks; 
        b.flag=' '; 

        pos=count*sizeof(b); 
        file.seekp(pos,ios::beg); 
        file.write((char*)&b,sizeof(b)); 
        return; 
       } 
    count++; 
    } 
    cout<<endl<<"no book available with this name  :"<<code; 
    cout<<endl<<"press any key ...."; 
    getch(); 

    file.clear(); 
} 

//search for a given book void group::search() 
{ 
    char book[20],author[20]; 
    int opt; 
    cout<<endl<<"search by          :"; 
    cout<<endl<<endl<<"1.book name   "; 
    cout<<endl<<endl<<"2.author name "; 
    cout<<endl<<endl<<"enter your option  :"; 
    cin>>opt; 
    if(opt==1) 
    { 
        cout<<endl<<endl<<"enter book's name   :"; 
        gets(book); 
        file.seekg(0l,ios::beg); 
        while(file.read((char*)&b,sizeof(b))) 
        { 
            if(strcmp(b.bname,book)==0) 
            { 
                            cout<<endl<<setw(20)<<b.bname<<setw(20)<<b.aname<<setw(10)<<b.pubname<<setw(10)<<b.price<<setw(10)<<b.noofbooks; 
            } 
        } 
        file.clear(); 
    } 
    else 
    { 
        cout<<endl<<endl<<"enter author's name   :"; 
        gets(author); 
        file.seekg(0l,ios::beg); 
        while(file.read((char*)&b,sizeof(b))) 
        { 
            if(strcmp(b.aname,author)==0) 
            { 
              cout<<endl<<setw(20)<<b.bname<<setw(20)<<b.aname<<setw(10)<<b.pubname<<setw(10)<<b.price<<setw(10)<<b.noofbooks; 

            } 
        } 
        file.clear(); 
    } 
    cout<<endl<<"press any key ..."; 
    getch(); 
} 

//deletes the record void group::deletion() 
{ 
    char book[20],name[20],publ[20]; 
    longint pos; 
    int count=0; 
    cout<<endl<<"enter book's name :"; 
    gets(book); 
    cout<<endl<<"enter author's name :"; 
    gets(name); 
    cout<<endl<<"enter the publisher's name :"; 
    gets(publ); 
    file.seekg(0l,ios::beg); 
    while(file.read((char*)&b,sizeof(b))) 
    { 
        if(strcmp(b.bname,book)==0 && strcmp(b.aname,name)==0 && strcmp(b.pubname,publ)==0) 
        { 
            b.flag='*'; 
            pos=count*sizeof(b); 
            file.seekp(pos,ios::beg); 
            file.write((char*)&b,sizeof(b)); 
            cout<<endl<<"record deleted successfully"; 
            goto v; 
        } 
        count++; 
    } 
    cout<<endl<<"no book in file with name :"<<book<<" "<<"written by  "<<name<<" "<<"and published by  "<<publ; 
    v:cout<<endl<<"press any key....."; 
    getch(); 
    file.clear(); 
} 


void group::exit() 
{ 
    file.close(); 
} 
// Submited By-KESHARI NANDAN PRATAP
