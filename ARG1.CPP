# include <iostream.h>
# include <conio.h>
void  main(int argc,char *argv[])
{
	int i;
	cout<<"\n No. of arguments passed =" <<argc;
	cout<<"\n arguments values...\n";
	for(i=0;i<argc;i++)
	{
		cout<<"\n"<<argv[i];
	}
	getch();
}














