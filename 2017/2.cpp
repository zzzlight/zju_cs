#include<stdio.h>
#include<algorithm>
#include<set>

using namespace std;

struct Inf
{
	int frequent;
	int id;
	Inf (int a,int b)   //���Զ����캯���� ����д�����浱Ĭ��ʱ�Ĺ��캯�� 
	{                     //������û��a��b����Ĭ�ϳ�ʼ�����޷����� 
		frequent=a;
		id=b;
	}
	Inf():id(0),frequent(0){}
	bool operator<(const Inf& n)const   //������ʵ��cmp������ 
	{
		if(n.frequent!=frequent)
		{
			return frequent>n.frequent;
		}
		else return id<n.id;
	}
};
int mark[50005];
set<Inf> line;

int main()
{
	int num;
	scanf("%d",&num);
	int capacity;
	scanf("%d",&capacity);
	for(int i=0;i<num;i++)
	{
		int temp1;
		scanf("%d",&temp1);
		if(i==0)
		{
			Inf temp2;
			temp2.id=temp1;
			mark[temp1]++;
			temp2.frequent=mark[temp1];
			line.insert(temp2);
		}
		else
		{
			printf("%d:",temp1);
			int max;
			if(line.size()<capacity)
			{
				max=line.size();
			}
			else
			{
				max=capacity;
			}
			int count=0;
			for(auto it=line.begin();it!=line.end()&&count<max;count++,it++)
			{
				printf(" %d",it->id);
			}
			if(i!=num-1) printf("\n");
			mark[temp1]++;
			Inf temp2;
			temp2.frequent=mark[temp1];
			temp2.id=temp1;
			
			auto it=line.find(Inf(mark[temp1]-1,temp1));
			
			if(it==line.end()) line.insert(temp2);
			else 
			{
				line.erase(it);
				line.insert(temp2);
			}
			
		}
	}
}
