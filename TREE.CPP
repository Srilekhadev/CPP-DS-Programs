# include <iostream.h>
# include <conio.h>

class NODE
{
	private:
	 int data;
	 NODE *left,*right;
	 friend class TREE;
};

class TREE
{
	public :
		NODE * createtree(int data[],int len);
		void inorder(NODE *root);
		void preorder(NODE *root);
		void postorder(NODE *root);
		int level;
		int getNleafnodes(NODE *root);
		int getNrightchilds(NODE *root);
		int getnodeswithtwochilds(NODE *root);
		int levelnos[100],nl;

		void getleaflevels(NODE *root);
		void getmaxleaflevels(NODE *root);
		void isbalancedtree(NODE *root);
		TREE()
		{
		 level=0;
		 nl=0;
		}


};


NODE* TREE::createtree(int data[],int len)
{
	NODE *root=NULL,*newnode=NULL,*ptr=NULL;
	for(int i=0;i<len;i++)
	{
		newnode=new NODE;
		newnode->data=data[i];
		newnode->left=newnode->right=NULL;

		if(root==NULL)
		  root=newnode;
		else
		{
		  ptr=root;
		  while(1)
		  {
			 if(newnode->data<ptr->data)
			 {
				if(ptr->left==NULL)
				{
					ptr->left=newnode;
					break;
				}
				else
					ptr=ptr->left;
			 }
			 else if(newnode->data>ptr->data)
			 {
				if(ptr->right==NULL)
				{
					ptr->right=newnode;
					break;
				}
				else
				 ptr=ptr->right;

			 }
			 else
				break;

		  }
	  }

	}
	return root;
}

void TREE::inorder(NODE *root)
{
	if(root!=NULL)
	{
		int n=level++;
		inorder(root->left);

		cout<<"\n "<<root->data<<" (level-"<<n<<")";
		level=n+1;
		inorder(root->right);

	}

}

void TREE::preorder(NODE *root)
{
	if(root!=NULL)
	{
		int n=level++;
		cout<<"\n "<<root->data<<" (level-"<<n<<")";
		preorder(root->left);
		level=n+1;

		preorder(root->right);

	}

}

void TREE::postorder(NODE *root)
{
	if(root!=NULL)
	{
		int n=level++;
		postorder(root->left);
		 level=n+1;
		postorder(root->right);

		cout<<"\n"<<root->data<<" (level-"<<n<<")";

	}

}

int TREE::getNleafnodes(NODE *root)
{
  if(root==NULL)
	 return 0;
  if(root->left==NULL && root->right==NULL)
	 return 1;
  else
	 return getNleafnodes(root->left)+getNleafnodes(root->right);
}

int TREE::getNrightchilds(NODE *root)
{
  if(root==NULL)
	 return 0;
  else if(root->left==NULL && root->right==NULL)
  return 0;
  else if(root->left==NULL && root->right!=NULL)
	 return 1;
  else
	 return getNrightchilds(root->left)+getNrightchilds(root->right);
}
int TREE::getnodeswithtwochilds(NODE *root)
{
  if(root==NULL)
	 return 0;
  else if(root->left==NULL && root->right==NULL)
  return 0;
  else if(root->left!=NULL && root->right!=NULL)
	 return 1;
  else
	 return getnodeswithtwochilds(root->left)+getnodeswithtwochilds(root->right);
}

void TREE::getleaflevels(NODE *root)
{


	if(root!=NULL)
	{
		int n=level++;
		getleaflevels(root->left);

	  //	cout<<"\n "<<root->data<<" (level-"<<n<<")";
	  if(root->left==NULL && root->right==NULL)
	  {
		levelnos[nl]=n-1;
		nl++;
	  }
		level=n+1;
		getleaflevels(root->right);

	}


}
void TREE::getmaxleaflevels(NODE *root)
{
	 nl=0;
	 getleaflevels(root);
	 int max=levelnos[0];
	 int min=max;
	 for(int i=1;i<nl;i++)
	 {
		if(levelnos[i]>max)
		  max=levelnos[i];

		if(levelnos[i]<min)
		  min=levelnos[i];


	 }

	 cout<<"\n Maximum leaf levels of tree is :"<<max;
	 cout<<"\n Minimum leaf levels of tree is :"<<min;
	 cout<<"\n The height of the tree is :"<<max;

}


void TREE::isbalancedtree(NODE *root)
{
	 nl=0;
	 int equal=1;
	 getleaflevels(root);
	 int l=levelnos[0];
	 for(int i=1;i<nl;i++)
	 {
		if(l!=levelnos[i])
		{
			equal=0;
			break;
		}
	 }
	 if(equal==1)
		cout<<"\n Tree is Balanced";
	 else
		cout<<"\n Tree is not Balanced";





}







void main()
{
		int data[15],len=15,i;
		clrscr();
		cout<<"\nEnter 15 integers :";
		for(i=0;i<len;i++)
		{
		  cin>>data[i];

		}

		TREE tobj;
		NODE *root=NULL;
		root=tobj.createtree(data,len);
		cout<<"\n\tInOrder Traversal..";
		tobj.level=0;
		tobj.inorder(root);

		cout<<"\n\tPreOrder Traversal..";
				tobj.level=0;
		tobj.preorder(root);

		cout<<"\n\tPostOrder Traversal..";
		tobj.level=0;
		tobj.postorder(root);
		cout<<"\n Number of leaf nodes in the tree : "<<tobj.getNleafnodes(root);
		cout<<"\n Number of nodes with only right child and no left child :"<<tobj.getNrightchilds(root);
		cout<<"\n Number ofnodes that have two childs : "<<tobj.getnodeswithtwochilds(root);
		tobj.getmaxleaflevels(root);
		tobj.isbalancedtree(root);

		getch();
}





