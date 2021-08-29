#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int start;
int final;
int countmax=9999999;
struct Station
{
	int line;
	int id;
}station[10005];
vector<Station> seq[10005];
vector<Station> result;
vector<Station> stops; 
bool flag[10005];
int submin;

void dfs(int s,int count)
{
	if(s==final)
	{
		int sub=0;
		if(countmax>count)
		{
			result=stops;   //���Ƽ�¼Ϊ���ս�� 
			countmax=count;
			for(int i=1;i<stops.size();i++)
			{
				if(stops[i].line!=stops[i-1].line)
				{
					sub++;     //������ô˴λ��˴��� 
				}
			}
			submin=sub;  //��¼��С���˴��� 
			
		}
		if(countmax==count)
		{
			for(int i=1;i<stops.size();i++)
			{
				if(stops[i].line!=stops[i-1].line)
				{
					sub++;
				}
			}
			if(sub<submin)
			{
				result=stops;  //���� 
				submin=sub;
			}
		}
		return;
	}    //�߽����� 
	for(int i=0;i<seq[s].size();i++)
	{
		if(flag[seq[s][i].id]==false)
		{
			flag[seq[s][i].id]=true;
			stops.push_back(seq[s][i]);      //�ڽӱ��dfs���� 
			dfs(seq[s][i].id,count+1);
			stops.pop_back();       //��Ϊ��ʱ��¼ ��ʱpop��ʹÿ��dfs��պ���� 
			flag[seq[s][i].id]=false;
		}
	}
}
int main()
{
	int linenum;
	scanf("%d",&linenum);
	for(int i=1;i<=linenum;i++)
	{
		int potnum;
		scanf("%d",&potnum);
		for(int j=0;j<potnum;j++)
		{
			int temp;
			scanf("%d",&temp); 
			station[j].id=temp;
			station[j].line=i;
			if(j!=0)
			{
				seq[station[j].id].push_back(station[j-1]);
				seq[station[j-1].id].push_back(station[j]);  //�ڽӱ��¼ͼ 
			}
			
		}
	}
	int cxnum;
	scanf("%d",&cxnum);
	for(int i=0;i<cxnum;i++)
	{
		scanf("%d %d",&start,&final);
		countmax=9999999;
		dfs(start,0);
		printf("%d\n",countmax);
		int lineout=result[0].line;
		int id=start;
		for(int i=0;i<result.size();i++)
		{
			if(lineout!=result[i].line)
			{
				printf("Take Line#%d from %04d to %04d.\n",lineout,id,result[i-1].id);
				lineout=result[i].line;  //���»��˵����� 
				id=result[i-1].id;   //������� �����ϴε��յ㣩 
			}

		}
		printf("Take Line#%d from %04d to %04d.\n",lineout,id,final);
		
	}
	
}
