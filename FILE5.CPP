# include <fstream.h>
# include <conio.h>
# include <string.h>
void main()
{
	char name[15],res[6];
	int rn,m1,m2,tot;
	float avg;
	char ans;
	ofstream fout("stud.txt");
	if(fout.fail() )  // fail() returns 1 on fail to create file 
			//	otherwise return 0
	{
		cerr<<"\nError : file unable to create.";
		return;
	}

	do
	{
		cout<<"\n Enter name :";
		cin>>name;
	  //	flush(cin);
	  //cin.getline(name,15,'\n');
		cout<<"\nEnter rn,m1,m2 :";
		cin>>rn>>m1>>m2;
		tot=m1+m2;
		avg=tot/2.0;
		if(m1>=35 && m2>=35)
		  strcpy(res,"pass");
		else
		  strcpy(res,"fail");

fout<<name<<endl<<rn<<endl<<m1<<endl<<m2<<endl<<tot<<endl<<
avg<<endl<<res<<endl;

		cout<<"\nWant to continue [y/n] :";
		cin>>ans;
	}while(ans=='y' || ans=='Y');

	fout.close();
}
























