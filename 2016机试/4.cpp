#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int maxlevel=0;
struct Node
{
	int data;
	Node* leftchild=NULL;
	Node* rightchild=NULL;
	int level=0;
};
int count1;
int count2;
vector<int> nodes;
void dfs(Node* root,int level)
{
	if(root==NULL) return;
	root->level=level;
	if(root->level>maxlevel) maxlevel=root->level;
	if(root->rightchild!=NULL) dfs(root->rightchild,level+1);
	if(root->leftchild!=NULL) dfs(root->leftchild,level+1);
	
}
void dfs1(Node* root)
{
	if(root==NULL) return;
	if(root->level==maxlevel) count2++;
	if(root->level==maxlevel-1) count1++;
	if(root->rightchild!=NULL) dfs1(root->rightchild);
	if(root->leftchild!=NULL) dfs1(root->leftchild);
	
}
void create(int data,Node* &n)
{
	if(n==NULL) 
	{
		n=new Node;
	//	n->rightchild=n->leftchild=NULL;
		n->data=data;
		return ;   //×¢Òâreturn 
	}
	
	if(n->data>=data) create(data,n->leftchild);
	if(n->data<data) create(data,n->rightchild);
	return ;
 } 
int main()
{
	int num;
	scanf("%d",&num);
	Node* root=NULL;
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		nodes.push_back(temp);
	}
	for(int i=0;i<num;i++)
	{
		create(nodes[i],root);
	}
	dfs(root,0);
	dfs1(root);
	int sum=count1+count2;
	printf("%d + %d = %d",count2,count1,sum);
}
