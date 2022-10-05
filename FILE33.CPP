#include<fstream.h>
#include <conio.h>
# include <process.h>
void main()
{
	char ch;
	clrscr();
	ifstream fin("dev.txt");
	if(!fin)
	{
		cerr<<"\nError: file uable to open.";
		exit(1);

	 }
	 ofstream fout("dup.txt");
	 if(!fout)
	 {
		cerr<<"\nError: file uable to create.";
		exit(1);
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



