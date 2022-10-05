# include<fstream.h>
# include<conio.h>
void main(int argc,char *argv[])
{
	char ch;
	if(argc!=2)
	{
		cerr<<"\n Error : Invalid no. of args";
		return;
	}

	ifstream fin(argv[1]);
	if(!fin)
	{
		cerr<<"\n Error : File unable to open.";
		return;
	}

	while(fin)
	{
		fin.get(ch);
		cout.put(ch);
	}
	fin.close();
 }



