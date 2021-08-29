#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
vector<bool> ans;
bool map1[1005];
bool map2[1002][1002];
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		
		fill(map1,map1+1005,0);
		fill(map2[0],map2[0]+1002*1002,false);
		int row;
		bool flag=false;
		scanf("%d",&row);
		for(int j=1;j<=row;j++)
		{
			int loca;
			scanf("%d",&loca);
			if(map1[loca]==false)
			{
				map1[loca]=true;
				int q=j-1;
				int line=loca-1;
				int up=loca+1;
				while((line>0&&q>0))
				{

					if(map2[q][line]==true)
					{
						flag=true;
						break;
					}
					else
					{
						line--;
						q--;
					}
				}
				q=j-1;
				while(q>0&&up<=row)
				{
					if(map2[q][up]==true)
					{
						flag=true;
						break;
					}
					else
					{
						up++;
						q--;
					 } 
				}
				map2[j][loca]=true;
				
			}
			else
			{
				flag=true;
			
			}
		
		}
		ans.push_back(flag);
		
	}
	for(int i=0;i<num;i++)
	{
		if(ans[i]!=true) printf("YES");
		else printf("NO");
		if(i!=num-1) printf("\n"); 
	}
 } 
