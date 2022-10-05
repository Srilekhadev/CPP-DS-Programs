//single inheritance
#include<iostream.h>
#include<conio.h>
class A
{
int a;
public:
   void  geta()
   {
   a=10;
   cout<<"\na="<<a;
   }
};
 class B:public A
 {
  int b;
  public:
     void getb()
     {
     b=20;
     cout<<"\nb="<<b;
     }
  };
 void main()
 {
 clrscr();
 A a1;
 B b1;
 a1.geta();
 b1.getb();
 b1.geta();
 getch();
 }

