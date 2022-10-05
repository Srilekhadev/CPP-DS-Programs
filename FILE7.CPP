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
	 void writerecords();
};

void student::writerecords()
{
	char ans;
	ofstream fout;
	fout.open("stud.dbf",ios::out | ios::binary);

	if(fout.fail())
	{
		cerr<<"\nError : file unable to create.";
		return;
	 }

	 do
	 {
		cout<<"\nEnter name,rn,m1,m2 :";
		cin>>name>>rn>>m1>>m2;
		tot=m1+m2;
		avg=tot/2.0;
		if(m1>=35 && m2>=35)
		  strcpy(res,"pass");
		else
		  strcpy(res,"fail");

		fout.write((char *)this,sizeof(student));

		cout<<"\n Want to add more records [y/n] :";
		cin>>ans;
	 }while(ans=='y' || ans=='Y');
	 fout.close();
}

void main()
{
  student sobj;
  sobj.writerecords();
  getch();
}







