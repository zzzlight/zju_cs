#include<stdio.h>
#include<vector>
#include<algorithm>
                //注意这题 直接用建树的insert方法居然能除一个小测试点其他都过  26分 见后面 
using namespace std;
 struct Node
 {
 	int data;
 	Node* leftchild;
 	Node* rightchild;
 	
 };
bool flag;
vector<int> inorder;
vector<int> preorder;

Node* create(int prel,int prer,int inl,int inr)
{
	if(prel>prer) return NULL;
	Node* node=new Node;
	node->data=preorder[prel];
	node->leftchild=NULL;
	node->rightchild=NULL;
	int i;
	for(i=inl;i<inr;i++)
	{
		if(preorder[prel]==inorder[i]) break;
	}
	int numl=i-inl;
	node->leftchild=create(prel+1,prel+numl,inl,i-1);
	node->rightchild=create(prel+numl+1,prer,i+1,inr);
	return node;
 } 
void dfs(Node* root,int data,vector<int> &seq)
{
	if(root==NULL) 
	{
		flag=false;
		return ;
	}
	if(root->data==data) 
	{
		seq.push_back(root->data);
		flag=true;
		return ;
	}
	seq.push_back(root->data);
	if(root->data<=data) dfs(root->rightchild,data,seq);
	if(root->data>data) dfs(root->leftchild,data,seq);
	
 }

 void insert(Node* (&root),int data) 
 {
 	if(root==NULL)
 	{
 		root=new Node;
 		root->data=data;
 		root->leftchild=NULL;
 		root->rightchild=NULL;
 		return ;
	 }
	 if(root->data<=data) insert(root->rightchild,data);
	 if(root->data>data) insert(root->leftchild,data);
	 return ;
 }

 int main()
 {
	Node* root=NULL;
 	int testnum;
 	int nodenum;
 	scanf("%d %d",&testnum,&nodenum);
	for(int i=0;i<nodenum;i++)
	{
		int temp;
		scanf("%d",&temp);
		preorder.push_back(temp);
		inorder.push_back(temp);
	}
	sort(inorder.begin(),inorder.end());
	root=create(0,nodenum-1,0,nodenum-1);
	for(int i=0;i<testnum;i++)
	{
		int node1;
		int node2;
		scanf("%d",&node1);
		scanf("%d",&node2);
		vector<int> seq1;
 		vector<int> seq2; 
 		bool flag1;
 		bool flag2;
		dfs(root,node1,seq1);
		flag1=flag;
		dfs(root,node2,seq2);
		flag2=flag;
		if(flag1==false&&flag2==false)
		{
			printf("ERROR: %d and %d are not found.",node1,node2);
		}
		else if(flag1==false)
		{
			printf("ERROR: %d is not found.",node1);
		}
		else if(flag2==false)
		{
			printf("ERROR: %d is not found.",node2);
		}
		else
		{
			int min=9999999;
			if(seq1.size()<seq2.size()) min=seq1.size();
			else min=seq2.size();
			int x;
			for(x=0;x<min;x++)
			{
				if(seq1[x]!=seq2[x]) break;
			}
			if(x<min) printf("LCA of %d and %d is %d.",node1,node2,seq1[--x]);
			else if(x==min)
			{
				if(min==seq1.size())
				{
				 printf("%d is an ancestor of %d.",node1,node2);	
				}
				else if(min==seq2.size())
				{
				printf("%d is an ancestor of %d.",node2,node1);
				}	
			}			
		}
	if(i!=testnum-1) printf("\n");

	}
  } 
  /*
  #include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
 struct Node
 {
 	int data;
 	Node* leftchild;
 	Node* rightchild;
 	
 };
bool flag;
void dfs(Node* root,int data,vector<int> &seq)
{
	if(root==NULL) 
	{
		flag=false;
		return ;
	}
	if(root->data==data) 
	{
		seq.push_back(root->data);
		flag=true;
		return ;
	}
	seq.push_back(root->data);
	if(root->data<=data) dfs(root->rightchild,data,seq);
	if(root->data>data) dfs(root->leftchild,data,seq);
	
 }

 void insert(Node* (&root),int data) 
 {
 	if(root==NULL)
 	{
 		root=new Node;
 		root->data=data;
 		root->leftchild=NULL;
 		root->rightchild=NULL;
 		return ;
	 }
	 if(root->data<=data) insert(root->rightchild,data);
	 if(root->data>data) insert(root->leftchild,data);
	 return ;
 }

 int main()
 {
	Node* root=NULL;
 	int testnum;
 	int nodenum;
 	scanf("%d %d",&testnum,&nodenum);
 	for(int i=0;i<nodenum;i++)
 	{
 		int temp;
 		scanf("%d",&temp);
 		insert(root,temp);
 		
	}
	for(int i=0;i<testnum;i++)
	{
		int node1;
		int node2;
		scanf("%d",&node1);
		scanf("%d",&node2);
		vector<int> seq1;
 		vector<int> seq2; 
 		bool flag1;
 		bool flag2;
		dfs(root,node1,seq1);
		flag1=flag;
		dfs(root,node2,seq2);
		flag2=flag;
		if(flag1==false&&flag2==false)
		{
			printf("ERROR: %d and %d are not found.",node1,node2);
		}
		else if(flag1==false)
		{
			printf("ERROR: %d is not found.",node1);
		}
		else if(flag2==false)
		{
			printf("ERROR: %d is not found.",node2);
		}
		else
		{
			int min=9999999;
			if(seq1.size()<seq2.size()) min=seq1.size();
			else min=seq2.size();
			int x;
			for(x=0;x<min;x++)
			{
				if(seq1[x]!=seq2[x]) break;
			}
			if(x<min) printf("LCA of %d and %d is %d.",node1,node2,seq1[--x]);
			else if(x==min)
			{
				if(min==seq1.size())
				{
				 printf("%d is an ancestor of %d.",node1,node2);	
				}
				else if(min==seq2.size())
				{
				printf("%d is an ancestor of %d.",node2,node1);
				}	
			}			
		}
	if(i!=testnum-1) printf("\n");

	}
  } 
  */
