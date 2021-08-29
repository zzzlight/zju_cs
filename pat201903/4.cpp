#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<map>
using namespace std;

int inorder[100];
int postorder[100];
int n;


bool judge7;
struct Node 
{
	int data;
	Node* rightchild;
	Node* leftchild;
	Node* parents; 
	int level=0;
};
map<int,Node*> mymap; 
Node* create(int postl,int postr,int inl,int inr)
{
	if(postl>postr) return NULL;
	Node* node=new Node;
	node->leftchild=NULL;
	node->rightchild=NULL;
	node->data=postorder[postr];
	int k;
	for(k=inl;k<inr;k++)
	{
		if(postorder[postr]==inorder[k]) break;
	}
	int numl=k-inl;
	node->leftchild=create(postl,postl+numl-1,inl,k-1);
	node->rightchild=create(postl+numl,postr-1,k+1,inr);
	return node;
	
}

void dfs(Node* root,int level)
{
	if(root==NULL) return;
	if(root->leftchild!=NULL) root->leftchild->parents=root;
	if(root->rightchild!=NULL) root->rightchild->parents=root;
	mymap[root->data]=root;
	root->level=level;
	dfs(root->leftchild,level+1);
	dfs(root->rightchild,level+1);
	
}

void dfs6(Node* root)
{
	if(root==NULL) return;
	if(root->leftchild!=NULL||root->rightchild!=NULL)
	{
	if((root->leftchild==NULL&&root->rightchild!=NULL)||(root->leftchild!=NULL&&root->rightchild==NULL)) judge7=true; 	
	}

	dfs6(root->leftchild);
	dfs6(root->rightchild);
	
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&postorder[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&inorder[i]);
	}
	Node * root=NULL;
	root=create(0,n-1,0,n-1);
	int judgenum;
	scanf("%d",&judgenum);
	getchar();
	for(int i=0;i<judgenum;i++)
	{
		int id1=-1;
		int id2=-1;
		int mode=1;
		string a;
		getline(cin,a);
		if(a[0]>='0'&&a[0]<='9')
		{
			if(a.find("siblings") != string::npos)
			{
				mode=2;
				sscanf(a.c_str(),"%d and %d are siblings",&id1,&id2);
			}
			else if(a.find("root") != string::npos)
			{
				mode=1;
				sscanf(a.c_str(),"%d is the root",&id1);
			}
			else if(*(a.end()-1)=='l')
			{
				mode=6;
				sscanf(a.c_str(),"%d and %d are on the same level",&id1,&id2);
			}
			else if(a.find("parent") != string::npos) 
			{
				mode=3;
				sscanf(a.c_str(),"%d is the parent of %d",&id1,&id2);
			}
			else if(a.find("right child") != string::npos) 
			{
				sscanf(a.c_str(),"%d is the right child of %d",&id1,&id2);
				mode=5;
			}
			else if(a.find("left child") != string::npos) 
			{
				sscanf(a.c_str(),"%d is the left child of %d",&id1,&id2);
				mode=4;	
			}
				
			
		}
		else mode=7;
		dfs(root,0);
		if(mode==1)
		{
			if(id1==root->data) printf("Yes");
			else printf("No");
		 } 
		 else if(mode==2)
		 {
		 	Node* numid1=mymap[id1];
		 	Node* numid2=mymap[id2];
		 	if(numid1->parents==numid2->parents) printf("Yes");
		 	else printf("No");
		 }
		else if(mode==3)
		{
			Node* numid1=mymap[id1];
			Node* numid2=mymap[id2];
			if(numid2->parents==numid1) printf("Yes");
		 	else printf("No");
		}
		else if(mode==4)
		{
			Node* numid1=mymap[id1];
			Node* numid2=mymap[id2];
			if(numid2->leftchild==numid1) printf("Yes");
		 	else printf("No");
		}
		else if(mode==5)
		{
			Node* numid1=mymap[id1];
			Node* numid2=mymap[id2];
			if(numid2->rightchild==numid1) printf("Yes");
		 	else printf("No");
		}
		else if(mode==6)
		{
			Node* numid1=mymap[id1];
			Node* numid2=mymap[id2];
			if(numid1->level==numid2->level) printf("Yes");
		 	else printf("No");	
		 } 
		 else if(mode==7)
		 {
		 	dfs6(root);
			if(judge7==true) printf("No");
		 	else printf("Yes");
		 }
		if(i!=judgenum-1) printf("\n");
	}
}
