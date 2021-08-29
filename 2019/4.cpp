#include<bits/stdc++.h>
#define inf 0x3ffffff

using namespace std;

int gloabstart;
int gloabfinal;
int potnum;
int ambnum;
int amseq[15];
int sum;
int G[1050][1050];
vector<int> tempseq;
vector<int> seq; 
vector<int> finalseq;
int maxcar=0;
int minstreet=99999;
bool visit[1500];
int d[1500];
vector<int> pre[1500]; 
void dijkstra(int start)
{
	fill(d,d+1500,inf);
	d[start]=0;
	fill(visit,visit+1500,0);
	for(int i=1;i<1050;i++)
	{
		int u=-1;
		int min=inf;
		for(int j=1;j<1050;j++)
		{
			if(visit[j]==false&&d[j]<min)
			{
				u=j;
				min=d[j];
			}
		}
		if(u==-1) return ;
		visit[u]=true;
		for(int v=1;v<1050;v++)
		{
			if(G[u][v]!=inf&&visit[v]==false)
			{
				if(d[u]+G[u][v]<d[v])
				{
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(d[u]+G[u][v]==d[v])
				{
					pre[v].push_back(u);
				}
								
			}

		}
	}
}
void dfs(int final)
{

	if(final==gloabstart)
	{
		tempseq.push_back(final);
		if(amseq[final-1000]>0&&amseq[final-1000]>maxcar)
		{
			maxcar=amseq[final-1000];
			minstreet=seq.size();
			seq=tempseq;
		}
		else if(amseq[gloabfinal-1000]>0&&tempseq.size()<minstreet)
		{
			minstreet=tempseq.size();
			seq=tempseq;
		}
		tempseq.pop_back();
		return ;
	}
	tempseq.push_back(final);
	for(int i=0;i<pre[final].size();i++)
	{
			dfs(pre[final][i]);		
	}
	tempseq.pop_back();
	return ;
}
int main()
{
	fill(G[0],G[0]+1050*1050,inf);
	scanf("%d %d",&potnum,&ambnum);
	for(int i=1;i<=ambnum;i++)
	{
		int temp;
		scanf("%d",&temp);
		amseq[i]=temp;
		sum+=temp;
	}
	int roadnum;
	scanf("%d",&roadnum);
	for(int i=0;i<roadnum;i++)
	{
		int distemp;
		int id1=0;
		int id2=0;
		char road1[10];
		char road2[10];
		scanf("%s",&road1);
		scanf("%s",&road2);
		scanf("%d",&distemp);
		if(road1[0]!='A') id1=stoi(road1);
		else
		{
			sscanf(road1,"A-%d",&id1);
			 id1=id1+1000;
		}
		if(road2[0]!='A') id2=stoi(road2);
		else
		{
			sscanf(road2,"A-%d",&id2);
			 id2=id2+1000;
		}
		G[id1][id2]=distemp;
		G[id2][id1]=distemp;
	}
	int callnum;
	scanf("%d",&callnum);
	for(int i=1;i<=callnum;i++)
	{
		int callid;
		scanf("%d",&callid);
		if(sum<=0) printf("All Busy");
		else
		{
			gloabstart=callid;
			dijkstra(callid);
			int mindis=999999;
			int thismaxcar=-1;
			int thisminstreet=999999;
			for(int tt=1001;tt<=1000+ambnum;tt++)
			{
				gloabfinal=tt;
				maxcar=0;
				minstreet=99999; 
				dfs(tt);
				int tempdis=d[tt];
				if(amseq[tt-1000]>0&&tempdis<mindis) 
				{
					mindis=tempdis;	
					thismaxcar= amseq[tt-1000];
					thisminstreet=seq.size();
					finalseq=seq;	
				}
				else if(amseq[tt-1000]>0&&tempdis==mindis&&amseq[tt-1000]>thismaxcar)
				{
					thismaxcar=amseq[tt-1000];
				 	thisminstreet=seq.size();
					finalseq=seq;
				
				}
				else if(amseq[tt-1000]>0&&tempdis==mindis&&amseq[tt-1000]==thismaxcar&&seq.size()<thisminstreet)
				{
					thisminstreet=seq.size();
					finalseq=seq;
					
				}
			

			}
			if(finalseq[0]>1000) 
			{
				int t=finalseq[0]-1000;
				amseq[t]--;	
			}
			for(int x=0;x<finalseq.size();x++)
			{
				if(finalseq[x]>1000) printf("A-%d",finalseq[x]-1000);
				else printf("%d",finalseq[x]);
				if(x!=finalseq.size()-1) printf(" ");
			}
			printf("\n%d",mindis);
			
			finalseq.clear();
		}	
		sum--;
		if(i<callnum) printf("\n");
		
	}
}
