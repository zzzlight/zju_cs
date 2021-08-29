#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Node
{
	string data;
	int leftchild=-1;
	int rightchild=-1;
}node[50];
int root;
void inorder(int r)
{
	if(r==-1) 
	{
		return ;
	}
	if(root!=r&&(node[r].leftchild!=-1||node[r].rightchild!=-1)) cout<<"(";
	inorder(node[r].leftchild);
	cout<<node[r].data;
	inorder(node[r].rightchild);
	if(root!=r&&(node[r].leftchild!=-1||node[r].rightchild!=-1)) cout<<")";
	return ;
}
bool mark[50];
int main()
{
	int num;
	cin>>num;
	for(int i=1;i<=num;i++)
	{
		string temp;
		cin>>temp;
		int rtemp;
		int ltemp;
		cin>>ltemp>>rtemp;
		node[i].leftchild=ltemp;
		node[i].rightchild=rtemp;
		node[i].data=temp;
		if(ltemp!=-1) mark[ltemp]=true;
		if(rtemp!=-1) mark[rtemp]=true;
	}

	for(int i=1;i<=num;i++)
	{
		if(mark[i]==false) root=i;
	}
	inorder(root);
}
