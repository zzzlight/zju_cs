#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> line;
int num1[100001];
int num2[100001];
int out[100001];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		line.push_back(temp);	
	}
	sort(line.begin(),line.end(),cmp);
	line.push_back(0);
	int max=0;
	int min=99999999;
	int s1=0;
	int s2=0;
	for(int i=0;i<num;i++)
	{
		s1+=line[i];
		num1[i]=s1;
	}
	for(int i=num-1;i>=0;i--)
	{
		s2+=line[i+1];
		num2[i]=s2;
	}
	for(int i=0;i<num;i++)
	{
		out[i]=abs(num1[i]-num2[i]);
	}
	int n1num=-1;
	int n2num=-1;
	for(int i=0;i<num;i++)
	{
		n1num=i+1;
		n2num=num-n1num;
		int tempmin=abs(n1num-n2num);
		int tempmax=out[i];
		if(tempmin<min) 
		{
			min=tempmin;
			max=tempmax;
		}
		else if(tempmin==min)
		{
			if(max<tempmax)
			{
				max=tempmax;
			}
		}
	}
	
	
	printf("%d %d",min,max);
	
}
