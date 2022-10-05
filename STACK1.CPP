#include<iostream.h>
#include<conio.h>
#define SIZE 5
 template <class T>
 class STACK
  {
    private:

	  T stack[SIZE];
	  int top;

    public:

	   STACK()
	   {
	     top=-1;
	    }
	   void push(T item);
	   T pop();
	   void display();

    };

  template <class T>
  void STACK<T>::push(T item)
   {
      if(top==SIZE-1)
       {
	 cout<<"\n stack is full";
	}
      else
	{
	  top++;
	  stack[top]=item;
	  cout<<"\n 1 item addeed";
	 }
    }

  template <class T>
  T STACK<T>::pop()
   {
     T item=-555;
     if(top==-1)
	{
	  cout<<"\n stack is empty";
	 }
      else
	 {
	   item=stack[top];
	   top--;
	  }
      return item;
    }

  template<class T>
  void STACK<T>::display()
    {
      int i;
      if(top==-1)
	{
	   cout<<"\n stack is empty";
	 }
       else
	 {
	    cout<<"\n items in stack are:::::";
	      for(i=0;i<=top;i++)
		{
		   cout<<"\t"<<stack[i];
		 }
	   }
      }

void main()
 {
   STACK <int>sobj;
   int item,choice;
   clrscr;
   do
     {
	cout<<"\n\t\t stack using array";
	cout<<"\n\t 1.push";
	cout<<"\n\t 2.pop";
	cout<<"\n\t 3.display";
	cout<<"\n\t 4.exit";
	cout<<"\n\t ENTER CHOICE:::::";
	cin>>choice;

	switch (choice)
	    {
		case 1:
			cout<<"\n enter data:";
			cin>>item;
			sobj.push(item);
			break;
		case 2:
			item=sobj.pop();
			if(item!=-555)
				cout<<"\n item deleted"<<item;
			break;
		case 3:
			sobj.display();
			break;
		case 4:
			return;
		default:
			cout<<"\n invalid choice";

	      }
	  getch();
      }while(1);
  }