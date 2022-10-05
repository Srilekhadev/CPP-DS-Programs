// A program to search record
# include <fstream.h>
# include <conio.h>
# include <string.h>
class student
{
  private:
	 char name[15];
	 int rn,m1,m2,tot;
	 float avg;
	 char res[6];
  public:
	 void searchrecords();
};

void student::searchrecords()
{
	ifstream fin;
	fin.open("stud.dbf",ios::in || ios::binary);
	if(fin.fail())
	{
		cerr<<"\nError : file unable to open.";
		return;
	 }
	 int n,found=0;
	 cout<<"\n enter rn to search :";
	 cin>>n;

	cout<<"\n\t\t\t Student Details\n";
	cout<<"\nName\tRn  M1  M2  Tot  Avg   Result";
	cout<<"\n-----------------------------------------------";
	cout.precision(2);
	cout.setf(ios::left,ios::adjustfield);
	while(fin.read((char *)this,sizeof(student)) )
	{
		if (rn==n)
		{
		cout<<"\n";
		cout.width(12); cout<<name;  		cout.width(4); cout<<rn;
		cout.width(4); cout<<m1;
		cout.width(4); cout<<m2;     		cout.width(4); cout<<tot;
		cout.width(6); cout<<avg;    		cout.width(6); cout<<res;
		found=1;
			break;
		}
	}

	if(found==0)
	  cout<<"\n record not found.";



	 fin.close();
}

void main()
{
  student sobj;
  sobj.searchrecords();
  getch();
}







