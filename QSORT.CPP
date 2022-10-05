# include <iostream.h>
# include <conio.h>
class sorting
{
	public:
		void readvalues (int x[],int n);
		void printvalues (int x[],int n);
		void qsort (int x[],int left,int right);
};

void sorting::readvalues(int x[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cin>>x[i];
	}
}

void sorting::printvalues(int x[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
	  cout<<"\t"<<x[i];
	}
}

void sorting::qsort(int x[], int left, int right)
{
	int l, r, pivot, t ;
	if(left<right) //more than one element
	{
	pivot=x[left];
	l=left+1;
	r=right;
	do
	{
		while (x[l]<pivot && l<=right)
		l++;
		while(x[r] > pivot && r>=left)
		r--;
		if(l<r) // not crossed
		{
			t=x[l];
			x[l]=x[r];
			x[r]=t;
		}
	}while(l<r); // not crossed

	if(r<l) // crossed
	{
		t=x[left];
		x[left]=x[r];
		x[r]=t;
	}
	if(left +1<r)
	qsort(x, left, r-1);
	if(right-1>r)
	qsort(x,r+1,right);
  }
}
void main()
{
	class sorting obj;
	int a[30],n;
	cout<<"\n Enter n :";
	cin>>n;
	cout<<"Enter numbers :";
	obj.readvalues(a,n);
	obj.qsort(a,0,n-1);
	cout<<"\n after quick sort....";
	obj.printvalues(a,n);
	getch();
}	