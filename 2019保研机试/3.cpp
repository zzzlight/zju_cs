#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> inorder;
vector<int> pre;
struct Node
{
	int data;
	Node* leftchild;
	Node* rightchild;
	
};
Node* create(int prel,int prer,int inl,int inr)
{
	if(prel>prer) return NULL;
	Node* node=new Node;
	
	node->data=pre[prel];
	int m=-1;
	for(int i=inl;i<=inr;i++)
	{
		if(pre[prel]==inorder[i]) 
		{
			m=i;
			break;
		}
	}
	int cut=m-inl;
	node->leftchild=create(prel+1,prel+cut,inl,inl+cut-1);
	node->rightchild=create(prel+cut+1,prer,inl+cut+1,inr);
	return node;
}

int getheight(Node* root)
{
	if(root==NULL) return 0;
	int right=getheight(root->rightchild)+1;
	int left=getheight(root->leftchild)+1;
	return right>left?right:left;
}
bool judge(Node* root)
{
	if(root==NULL) return true;
	int right=getheight(root->rightchild);
	int left=getheight(root->leftchild);
	return abs(right-left)<2&&judge(root->leftchild)&&judge(root->rightchild);
}
int main()
{
	int testnum;
	scanf("%d",&testnum);
	for(int i=0;i<testnum;i++)
	{
		int num;
		scanf("%d",&num);
		for(int j=0;j<num;j++)
		{
			int temp;
			scanf("%d",&temp);
			inorder.push_back(temp);
		}
		pre=inorder;
		sort(inorder.begin(),inorder.end());
		Node* root=create(0,num-1,0,num-1);
		bool flag=judge(root);
		if(flag==true) printf("Yes");
		else printf("No");
		if(i!=testnum-1) printf("\n");
		pre.clear();
		inorder.clear();
	}
}
