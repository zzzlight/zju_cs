#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<map>
using namespace std;

struct List
{
//	int data;
	vector<int> next;
}list[100005];
struct Node 
{
	int weight;
	int name;
}node[100005];
bool cmp(Node a,Node b)
{
	if(a.weight!=b.weight) return (a.weight>b.weight);
	else return a.name<b.name;
}
int main()
{
	int potnum;
	int edgenum;
	scanf("%d %d",&potnum,&edgenum);
	for(int i=0;i<edgenum;i++)
	{
		int id1,id2;
		scanf("%d %d",&id1,&id2);
		//list[id1].data=id1;
		list[id1].next.push_back(id2);
		list[id2].next.push_back(id1);
	}
	int start;
	scanf("%d",&start);
	while(1)
	{
		memset(node,0,100005);
		if(start==0) break;
		vector<int> seq;
		bool mark[100005];
		memset(mark,0,100005);
		for(int i=0;i<start;i++)
		{
			int n;
			scanf("%d",&n);
			seq.push_back(n);
			node[n].weight=1;
			node[n].name=n;
			mark[n]=true;
		}
		for(int i=0;i<seq.size();i++)
		{
		//	mark[seq[i]]=false;
				for(int t=0;t<list[seq[i]].next.size();t++)
				{
					if(mark[list[seq[i]].next[t]]==true)
					{
						node[seq[i]].weight++;
						node[seq[i]].name=seq[i];	
					}
				}
		//	mark[seq[i]]=true;
		}
		
		sort(node,node+100005,cmp);
		for(int t=0;t<3;t++)
		{
			printf("%d",node[t].name);
			if(t!=2) printf(" ");
		}
		if(start!=0) printf("\n");
		scanf("%d",&start);
		
	}
}
