# include <fstream.h>
# include <conio.h>
void main()
{
	char ch;
	ifstream fin("dev.txt");
	//if(!fin)
	if(fin.fail())
	{
		cerr<<"\nError: file unable to open.";
		return;
	}

	while(fin)
	{
	 fin.get(ch);
	  cout<<ch;
	}
	fin.close();
	getch();
}






















