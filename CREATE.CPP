# include<fstream.h>
# include<conio.h>
void main( int argc,char *argv[])
{
	char ch;
	if(argc!=2)
	{
		cerr<<"\n Error : Invalid no. of args";
		return;
	}

	ofstream fout(argv[1]);
	if(!fout)
	{
		cerr<<"\n Error : File unable to create.";
		return;
	}

	while(cin)
	{
		cin.get(ch);
		fout.put(ch);
	}
	fout.close();
	cout<<"\n file created.";
 }









