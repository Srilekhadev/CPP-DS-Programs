# include <fstream.h>
# include <conio.h>
void main()
{
	ofstream fout("sample.txt");
	if(!fout)
	{
		cerr<<"\nError: file unable to create.";
		return;
	}
	else
	{
		cout<<"\nfile successfully created.";
		fout.close();
	}


	getch();
}