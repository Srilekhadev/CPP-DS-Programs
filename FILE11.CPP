// A program on modification of record
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
	 void modifyrecords();
};

void student::modifyrecords()
{
	fstream fout;
	fout.open("stud.dbf",ios::out | ios::in | ios::binary);

	if(fout.fail())
	{
		cerr<<"\nError : file unable to create.";
		return;
	 }

	 int n,found=0,recsize;
	 recsize=sizeof(student);
	 cout<<"\n enter rn to modify :";
	 cin>>n;

	while(fout.read((char *)this,sizeof(student)) )
	{
	  if(rn==n)
	  {
		cout<<"\nEnter name,rn,m1,m2 :";
		cin>>name>>rn>>m1>>m2;
		tot=m1+m2;
		avg=tot/2.0;
		if(m1>=35 && m2>=35)
		  strcpy(res,"pass");
		else
		  strcpy(res,"fail");

		  fout.seekp(-recsize,ios::cur);
		fout.write((char *)this,sizeof(student));
		found=1;
		break;
	  }
	}
	 fout.close();
  if(found==0)
	 cout<<"\n record not found.";
  else
	 cout<<"\n record modified.";

}

void main()
{
  student sobj;
  sobj.modifyrecords();
  getch();
}







