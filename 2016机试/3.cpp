#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> record;
vector<int> out;
bool flag[10001];
struct Person
{
	int id;
	int father=-1;
	int mother=-1;
	vector<int> son;
	int area;
	int sets;
	int sumsets;
	int sumarea;
	int personnum;
	double aveset;
	double avearea;
}person[10005];
vector<Person> result;
int father[10005];
bool mark[10005];
int findfather(int a)
{
	if(father[a]==a) return a;
	else 
	{
		int F=findfather(father[a]);
		father[a]=F;
		return F;
	}
}
void Unit(int faA,int faB)
{
	int a=findfather(faA);
	int b=findfather(faB);
	if(a!=b) father[max(a,b)]=min(a,b);  //总选最小的当父亲 
}
bool cmp(Person a,Person b)
{
	if(a.avearea!=b.avearea) return a.avearea>b.avearea;
	else return a.id<b.id;
}
int main()
{
	for(int i=0;i<10005;i++)
	{
		father[i]=i;
	}
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int tempid;
		int fatherid;
		int motherid;
		char temp1[5];
		char temp2[5];
		char temp3[5];
		cin>>temp1>>temp2>>temp3;
		sscanf(temp1,"%d",&tempid);
		sscanf(temp2,"%d",&fatherid);
		sscanf(temp3,"%d",&motherid);
		person[tempid].mother=motherid;
		person[tempid].father=fatherid;
		int sonnum;
		scanf("%d",&sonnum);
		for(int i=0;i<sonnum;i++)
		{
			char temp4[5];
			int tempson;
			cin>>temp4;
			sscanf(temp4,"%d",&tempson);
			person[tempid].son.push_back(tempson);
		}
		int tempset;
		int temparea;
		scanf("%d",&tempset);
		scanf("%d",&temparea);
		person[tempid].sets=tempset;
		person[tempid].area=temparea;
		
		if(fatherid!=-1)
		{
			Unit(fatherid,tempid);
			if(motherid!=-1) Unit(fatherid,motherid);
			for(int j=0;j<person[tempid].son.size();j++)
			{
				Unit(fatherid,person[tempid].son[j]);
			}
			
		}
		else
		{
			if(motherid!=-1) Unit(tempid,motherid);
			for(int i=0;i<person[tempid].son.size();i++)
			{
				Unit(tempid,person[tempid].son[i]);
			}
		}
		record.push_back(tempid);
		if(fatherid!=-1) record.push_back(fatherid);
		if(motherid!=-1) record.push_back(motherid);
		for(int j=0;j<sonnum;j++)
		{
			record.push_back(person[tempid].son[j]);
		}
	}

		
	int n=0;
	for(int i=0;i<record.size();i++)
	{
		int comfa=findfather(record[i]);
		
		if(flag[record[i]]==false) 
		{
			person[comfa].sumsets+=person[record[i]].sets;
			person[comfa].sumarea+=person[record[i]].area;
			person[comfa].personnum++;	
		}
		flag[record[i]]=true;
		if(mark[comfa]==false)
		{
			mark[comfa]=true;
			n++;
			out.push_back(comfa);
		}
		
	}
	printf("%d",n);
	for(int i=0;i<out.size();i++)
	{
		person[out[i]].aveset=1.0*person[out[i]].sumsets/(1.0*person[out[i]].personnum);
		person[out[i]].avearea=1.0*person[out[i]].sumarea/person[out[i]].personnum;
		person[out[i]].id=out[i];
		result.push_back(person[out[i]]);
	}
	sort(result.begin(),result.end(),cmp);
	for(int i=0;i<result.size();i++)
	{
		printf("\n%04d %d %0.3lf %0.3lf",result[i].id,result[i].personnum,result[i].aveset,result[i].avearea);
	}

}

