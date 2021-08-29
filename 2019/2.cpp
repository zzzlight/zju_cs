#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Node
{
	int id=-1;
	int data;
	int rank;
	int next;
}seq1[100000];
vector<Node> seq;
vector<Node> seqn;
vector<Node> seqk;
vector<Node> ans;
vector<Node> useless;
bool mark[100000];
bool cmp(Node a,Node b)
{
	return a.rank>b.rank;
}
int main()
{
	string startid;
	int start;
	cin>>startid;
	start=stoi(startid);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		string stringid;
		string tempnext;
		int data;
		cin>>stringid;
		cin>>data;
		cin>>tempnext;
		int tempnextid=stoi(tempnext);
		int tempid=stoi(stringid);
		Node tempnode;
		tempnode.id=tempid;
		tempnode.data=data;
		tempnode.next=tempnextid;
		seq1[tempid]=tempnode;
	}
	int nextid=start;
	int  r=1; 
	while(nextid!=-1) 
	{
		seq1[nextid].rank=r;
		r++;
		seq.push_back(seq1[nextid]);
		 mark[nextid]=true;
		nextid=seq1[nextid].next;
	}
	if(seq.size()<n)
	{
		for(int i=0;i<100000;i++)
		{
			if(seq1[i].id!=-1)
			{
				if(mark[seq1[i].id]==false) useless.push_back(seq1[i]); 
			}
			
		}
	}
	sort(seq.begin(),seq.end(),cmp);
	int markk=0;
	int markn=0;
	for(int i=0;i<seq.size();i++)
	{
		if(seq[i].rank==k) markk=k;
		if(seq[i].rank==n) markn=n;
	}
	for(int i=0;i<seq.size();i++)
	{
		Node temp=seq[i];
		if(seq[i].rank<=markn&&seq[i].rank>markk) seqn.push_back(temp);
		if(seq[i].rank<=markk) seqk.push_back(temp);
	}
	int x=0;
	int y=0;
	while(x<seqk.size()&&y<seqn.size()&&seqn[y].rank>k&&seqk[x].rank>0)
	{
		Node temp1=seqk[x];
		Node temp2=seqn[y];
		ans.push_back(temp1);
		ans.push_back(temp2);
		x++;
		y++;
	}

	if(y==seqn.size())
	{
		while(x<seqk.size())
		{
			ans.push_back(seqk[x]);
			x++;
		}
	}
	else if(x==seqk.size())
	{
		while(y<seqn.size())
		{ 
			ans.push_back(seqn[y]);
			y++;
		}
	}
	if(useless.size()==0)
	{
		for(int i=0;i<ans.size();i++)
		{
			if(i!=ans.size()-1) printf("%05d %d %05d\n",ans[i].id,ans[i].data,ans[i+1].id);
			else printf("%05d %d -1",ans[i].id,ans[i].data);
		}
	}
	else
	{
		for(int i=0;i<ans.size();i++)
		{
			if(i!=ans.size()-1) printf("%05d %d %05d\n",ans[i].id,ans[i].data,ans[i+1].id);
			else printf("%05d %d -1\n",ans[i].id,ans[i].data);
		}
		for(int i=0;i<useless.size();i++)
		{
			printf("%05d %d %05d",useless[i].id,useless[i].data,useless[i].next);
			if(i!=useless.size()-1) printf("\n");
		}
	 } 
}
