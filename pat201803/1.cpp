#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> getnext(vector<int> a)
{
	vector<int> renum;
	int count=0;
	int sum=1;
	for(int i=0;i<a.size();)
	{
		
		if(i+1<a.size()&&a[i]==a[i+1])
		{
			i++;
			sum++;
		}
		else
		{
			renum.push_back(a[i]);
			renum.push_back(sum);
			sum=1;
			i++;
		}
	}

	return renum;
}
int main()
{
	int d;
	int times;
	scanf("%d %d",&d,&times);
	int count=0;
	vector<int> result;
	result.push_back(d);
	while(count<times-1)
	{
		result=getnext(result);
		count++;
	}
	for(int i=0;i<result.size();i++)
	{
		printf("%d",result[i]);
	}
 } 
