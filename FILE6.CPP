# include <fstream.h>
# include <conio.h>
# include <string.h>
void main()
{
	char name[15],res[6];
	int rn,m1,m2,tot;
	float avg;
	ifstream fin("stud.txt");
	if(fin.fail() )
	{
		cerr<<"\nError : file unable to open.";
		return;
	}

	cout<<"\n\t\tStudent Details\n";
	cout<<"\nName\t    Rn  M1  M2  Tot  Avg   Result";
	cout<<"\n==============================================";
	cout.precision(2);
	cout.setf(ios::left,ios::adjustfield);
	while(1)
	{
		fin>>name>>rn>>m1>>m2>>tot>>avg>>res;
		if(fin.eof())  // eof() return 1 if fin object deos not read values form file otherwise 0
		  break;

		cout<<"\n";
		cout.width(12); cout<<name;
		cout.width(4); cout<<rn;
		cout.width(4); cout<<m1;
		cout.width(4); cout<<m2;
		cout.width(4); cout<<tot;
		cout.width(6); cout<<avg;
		cout.width(6); cout<<res;
	}

	fin.close();
	getch();
}
























