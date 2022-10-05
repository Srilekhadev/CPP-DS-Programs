# include <fstream.h>
# include <conio.h>
# include <process.h>
void main()
{
	char ch;
	ofstream fout("dev.txt");
	//if(!fout)
	if(fout.fail())
	{
		cerr<<"\nError: file unable to create.";
		exit(1);
	}

	cout<<"\nType text...[Ctrl+Z to terminate.] \n";
	while(cin)  //terminates when ctrl+z is typed on kb
	{
	  cin.get(ch);
	  fout.put(ch);
	}
	fout.close();
	cout<<"\n1 file created.";
	getch();
}






















