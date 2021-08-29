#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int vnum;
int edgenum;
int G[255][255];
vector<int> result;
bool visit[250];
vector<int> seqnum;


int main()
{

	scanf("%d",&vnum);
	scanf("%d",&edgenum);
	for(int i=0;i<edgenum;i++)
	{
		int id1;
		int id2;
		scanf("%d",&id1);
		scanf("%d",&id2);
		G[id1][id2]=true;
		G[id2][id1]=true;
	
	}

	int testnum;
	scanf("%d",&testnum);
	for(int i=0;i<testnum;i++)
	{
		seqnum.clear();
		int flag=0;
		int edgenum;
		scanf("%d",&edgenum);
		for(int j=0;j<edgenum;j++)
		{
			int temp;
			scanf("%d",&temp);
			seqnum.push_back(temp);
		}
			for(int x=0;x<seqnum.size();x++)
			{
				for(int y=x+1;y<seqnum.size();y++)
				{
					if(G[seqnum[x]][seqnum[y]]==false) flag=1;
				}
			}			
		if(flag==0)
		{
			int seq[255];
			fill(seq,seq+255,0);
			for(int x=0;x<seqnum.size();x++)
			{
				for(int y=1;y<=vnum;y++)
				{
					if(G[y][seqnum[x]]==true) seq[y]++;
				}
			}
		
			for(int x=1;x<=vnum;x++)
			{
				if(seq[x]==seqnum.size()) flag=-1;
			}
		
		}

		result.push_back(flag);
	}
	for(int i=0;i<result.size();i++)
	{
		if(result[i]==1)
		{
			printf("Not a Clique");
		}
		else if(result[i]==-1)
		{
			printf("Not Maximal");
		}
		else
		{
			printf("Yes");
		}
		if(i!=result.size()-1) printf("\n");
	}
}
