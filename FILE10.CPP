// A program to delete record
# include <fstream.h>
# include <conio.h>
# include <string.h>
# include <stdio.h>
class student
{
  private:
	 char name[15];
	 int rn,m1,m2,tot;
	 float avg;
	 char res[6];
  public:
	 void deleterecords();
};

void student::deleterecords()
{
	ifstream fin;
	fin.open("stud.dbf",ios::in | ios::binary);
	if(fin.fail())
	{
		cerr<<"\nError : file unable to open.";
		return;
	 }

	 ofstream fout;
	 fout.open("temp.dbf",ios::out | ios::binary);
	 if(fout.fail())
	 {
		cerr<<"\nError :  file unable to create.";
		return;
	 }

	 int n,found=0;
	 cout<<"\n enter rn to delete :";
	 cin>>n;

	while(fin.read((char *)this,sizeof(student)) )
	{

		if (rn==n)
			found=1;
		else
		  fout.write( (char *)this,sizeof(student));

	}


	fout.close();
	fin.close();
	remove("stud.dbf");
	rename("temp.dbf","stud.dbf");


	if(found==0)
	  cout<<"\n record not found.";
	else
	  cout<<"\n record deleted.";

}

void main()
{
  student sobj;
  sobj.deleterecords();
  getch();
}







