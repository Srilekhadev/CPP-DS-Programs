# include <iostream.h>
# include <conio.h>
# include <string.h>
class NODE
{
	private:
	  char lastname[30];
	  float gpa;
	  NODE *next;
	  friend class LIST;
};

class LIST
{
	public:
	  NODE* createlist(char names[15][20],float gpa[15]);
	  NODE* createfinallist(NODE *ptr);
	  void printlist(NODE *start);
	  void sortlist(NODE *start);
	  void sortlistbynames(NODE *start);
	  NODE * deletenodes(NODE *start,float gpa);
	  NODE * deletenodes1(NODE *start,float gpa);
	  NODE * mergelists(NODE *first,NODE *second);
};



NODE* LIST::createlist(char names[15][20],float gpa[15])
{
	NODE *start=NULL,*end=NULL,*newnode=NULL;
	for(int i=0;i<10;i++)
	{
		newnode=new NODE;
		strcpy(newnode->lastname,names[i]);
		newnode->gpa=gpa[i];
		newnode->next=NULL;
		if(start==NULL)
		{
			start=end=newnode;
		}
		else
		{
			end->next=newnode;
			end=newnode;
		}
	 }
	 return start;
}


void LIST::printlist(NODE *start)
{
	NODE *ptr=NULL;
	ptr=start;
	while(ptr!=NULL)
	{
		cout<<"\nLastName =" <<ptr->lastname <<"  GPA="<<ptr->gpa;
		ptr=ptr->next;
	}

}
void LIST::sortlist(NODE *start)
{
	char name[15];
	float gpa;
	NODE *i,*j;

	if(start)
	{
		for(i=start;i;i=i->next)
		{
			for(j=i->next;j;j=j->next)
			{
				if(i->gpa>j->gpa)
				{
				 strcpy(name,i->lastname);
				 gpa=i->gpa;
				 strcpy(i->lastname,j->lastname);
				 i->gpa=j->gpa;
				 strcpy(j->lastname,name);
				 j->gpa=gpa;
				 }
			 }
		}
	}
	else
	{
		cout<<"\n List does not exit.";
	}
}

void LIST::sortlistbynames(NODE *start)
{
	char name[15];
	float gpa;
	NODE *i,*j;

	if(start)
	{
		for(i=start;i;i=i->next)
		{
			for(j=i->next;j;j=j->next)
			{
				if(strcmp(i->lastname,j->lastname)>0)
				{
				 strcpy(name,i->lastname);
				 gpa=i->gpa;
				 strcpy(i->lastname,j->lastname);
				 i->gpa=j->gpa;
				 strcpy(j->lastname,name);
				 j->gpa=gpa;
				 }
			 }
		}
	}
	else
	{
		cout<<"\n List does not exit.";
	}
}


NODE * LIST::deletenodes(NODE *start,float gpa)
{
	NODE *cur,*pre,*del,*ptr;
	if(start==NULL)
	{
		cout<<"\n List does not exist.";
	}
	else
	{
	  ptr=start;
	  while(ptr!=NULL)
	  {
			if(ptr->gpa<gpa)
			{
				del=ptr;
				ptr=ptr->next;
				delete del;

			}
			else
			  break;
	  }

	  if(start!=ptr)
		  start=ptr;


	  pre=start;
	  cur=start->next;
	  while(cur!=NULL)
	  {
			if(cur->gpa<gpa)
			{
				pre->next=cur->next;
				del=cur;
				cur=cur->next;
				delete del;
			}
			else
			{
			pre=pre->next;
			cur=cur->next;
			}
	  }
	}

	return (start);
}

NODE * LIST::deletenodes1(NODE *start,float gpa)
{
	NODE *cur,*pre,*del,*ptr;
	if(start==NULL)
	{
		cout<<"\n List does not exist.";
	}
	else
	{
	  ptr=start;
	  while(ptr!=NULL)
	  {
			if(ptr->gpa>gpa)
			{
				del=ptr;
				ptr=ptr->next;

			}
			else
			  break;
	  }

	  if(start!=ptr)
		  start=ptr;


	  pre=start;
	  cur=start->next;
	  while(cur!=NULL)
	  {
			if(cur->gpa>gpa)
			{
				pre->next=cur->next;
				del=cur;
				cur=cur->next;
				delete del;
			}
			else
			{
			pre=pre->next;
			cur=cur->next;
			}
	  }
	}
	return (start);
}


NODE* LIST::mergelists(NODE *first,NODE *second)
{
  NODE *lastnode=first;
  if(first==NULL)
	 first=second;
  else
  {

  while(lastnode->next != NULL)
  {
	lastnode=lastnode->next;

  }

  lastnode->next=second;
  }
  return first;
}

 NODE* LIST::createfinallist(NODE *ptr)
 {
	NODE *start=NULL,*end=NULL,*newnode=NULL;

		while(ptr!=NULL)
		{
		newnode=new NODE;
		strcpy(newnode->lastname,ptr->lastname);
		newnode->gpa=ptr->gpa;
		newnode->next=NULL;
		if(start==NULL)
		{
			start=end=newnode;
		}
		else
		{
			end->next=newnode;
			end=newnode;
		}
		ptr=ptr->next;
	 }
	 return start;

 }







void main()
{

	char names1[15][20]={"A","B","X","U","C","V","R","I","T","D"};
	char names2[15][20]={"E","O","L","J","B","S","Z","Y","M","Q"};
	float gpa1[10]={2.86,1.65,6.43,4.99,1.34,8.43,2.99,1.32,2.36,5.53};
	float gpa2[10]={4.66,2.62,4.3,4.9,2.54,8.23,4.79,3.32,7.44,6.23};
	clrscr();
	NODE *UNO=NULL;
	LIST obj;
	UNO=obj.createlist(names1,gpa1);
	cout<<"\n First List Data..";
	obj.sortlist(UNO);
	obj.printlist(UNO);

	NODE *DUO=obj.createlist(names2,gpa2);
	cout<<"\n Second List Data..";
		obj.sortlist(DUO);
	obj.printlist(DUO);

	UNO=obj.deletenodes(UNO,3.0);
	cout<<"\n FIRST List Data after deletion..";
	obj.printlist(UNO);

	DUO=obj.deletenodes1(DUO,3.5);
	cout<<"\n SECOND List Data after deletion..";
	obj.printlist(DUO);

	UNO=obj.mergelists(UNO,DUO);
	NODE *finallist=obj.createfinallist(UNO);

	obj.sortlistbynames(finallist);
	cout<<"\n After merging of lists..";
	obj.printlist(finallist);

	getch();
}



