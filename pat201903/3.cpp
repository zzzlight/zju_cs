#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
int k;
int potnum;
int edgenum;
int father[1001];
int G[1005][1005];
vector<int> realsus;

int findfather(int a)
{
	if(father[a]==a) return a;
	else findfather(father[a]); 
}
void Union(int a,int  b)
{
	int faA=findfather(a);
	int faB=findfather(b);
	if(faA!=faB)
	{
		
		father[faA]=min(faA,faB);
		father[faB]=min(faA,faB);
	}
}
int main()
{
	scanf("%d %d %d",&k,&potnum,&edgenum);
	for(int i=0;i<edgenum;i++)
	{
		int calltemp;
		int rectemp;
		int durtemp;
		scanf("%d %d %d",&calltemp,&rectemp,&durtemp);
		G[calltemp][rectemp]+=durtemp;
	}
	
 	for(int i = 1; i <= potnum; ++i)   //直接用全部点去遍历 由于n2在10w 是可以接受的 
	{
   		 int sum = 0, rsum = 0;
    	for(int j = 1; j <= potnum; ++j)  //用j循环计算全部图中的打出数 以及打回数 
		{
    	    if(G[i][j] > 0 &&G[i][j] <= 5) 
			{
     	         ++sum; //打出去短电话数 
     	         if(G[j][i] > 0) ++rsum;//  回电话人数
     	   }
  		}
  		if(sum > k ) //若 
		{
    	    realsus.push_back(i);
    	    if(sum > 0 && 1.0 * rsum / sum > 0.2) realsus.pop_back();//去除回电话数大于20%的嫌疑人
   		}
    }

	if(realsus.size()==0) printf("None");
	else
	{
		vector<int> ans[1001];
		sort(realsus.begin(),realsus.end());
		for(int i=0;i<1001;i++)
		{
			father[i]=i;
		}
		for(int j=0;j<realsus.size();j++)
		{
			for(int x=j+1;x<realsus.size();x++)
			{
				if(G[realsus[j]][realsus[x]]>0&&G[realsus[x]][realsus[j]]>0)
				{
					Union(realsus[j],realsus[x]);
				}
			}
		}
		map<int,int> mp;
		set<int> myset1;
		int mycount=0;
		for(int j=0;j<realsus.size();j++)
		{
			ans[findfather(realsus[j])].push_back(realsus[j]);
		}
		for(int j=0;j<realsus.size();j++)
		{
			if(ans[findfather(realsus[j])].size()!=0)
			{
				if(myset1.find(findfather(realsus[j]))==myset1.end())
				{
					mp[mycount]=findfather(realsus[j]);
					mycount++;
					myset1.insert(findfather(realsus[j]));
				}
				sort(ans[findfather(realsus[j])].begin(),ans[findfather(realsus[j])].end());
			 } 
		}
		for(int t=0;t<mycount;t++)
		{
			for(int x=0;x<ans[mp[t]].size();x++)
			{
				printf("%d",ans[mp[t]][x]);
				if(x!=ans[mp[t]].size()-1) printf(" ");
			}
			if(t!=mycount-1) printf("\n");
		}
	}
}
