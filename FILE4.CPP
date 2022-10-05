# include <fstream.h>
# include <conio.h>
void main()
{
	char ch;
	ifstream fin("dev.txt");
	if(!fin)
	{
		cerr<<"\nError: file unable to open.";
		return;
	}

	ofstream fout("dup.txt");
	if(!fout)
	{
		cerr<<"\nError: file unable to created.";
		return;
	}

	while(fin)
	{
	  fin.get(ch);
	  fout.put(ch);
	}
	fin.close();
	fout.close();
	cout<<"\n 1 file copied.";
	getch();
}






















