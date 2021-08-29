#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<math.h>
using namespace std;


struct School
{
	string name;
	double score;
	int rank;
	int totalnum;
}schoolseq[100001];
string tran(string name)
{
	string newschool;
	int distance='A'-'a';
	for(int i=0;i<name.size();i++)
	{
		if(name[i]>='A'&&name[i]<='Z')
		{
			char temp=name[i]-distance;
			newschool.push_back(temp);
		}else
		{
			newschool.push_back(name[i]);
		}
	}
	return newschool;
}
set<string> schoolcount;
map<string,int> mymap1;
bool cmp(School a,School b)
{
	if(a.score!=b.score) return a.score>b.score;
	else if(a.totalnum!=b.totalnum) return a.totalnum<b.totalnum;
	else return a.name<b.name; 
}
int main()
{
	int num;
	cin>>num;
	int schoolnum=0;
	for(int i=0;i<num;i++)
	{
		string temp,tempschool;
		cin>>temp;
		char mark=temp[0];
		double tempscore;
		double finalscore;
		cin>>tempscore;
		cin>>tempschool;
		string school=tran(tempschool);
		if(mark=='T')
		{
			finalscore=tempscore*1.5;
		}
		else if(mark=='B')
		{
			finalscore=tempscore/1.5;
		}
		else
		{
			 finalscore=tempscore;
		}
		if(schoolcount.find(school)==schoolcount.end())
		{
			schoolcount.insert(school);
			mymap1[school]=schoolnum;
			schoolseq[schoolnum].name=school;
			schoolseq[schoolnum].totalnum++;
			schoolseq[schoolnum].score+=finalscore;
			schoolnum++;
		}
		else
		{
			int tempid=mymap1[school];
			schoolseq[tempid].totalnum++;
			schoolseq[tempid].score+=finalscore;
		}
	}
	for(int i=0;i<schoolnum;i++)
	{
		schoolseq[i].score=floor(schoolseq[i].score);
	}
	sort(schoolseq,schoolseq+schoolnum,cmp);
	int ranknow=1;
	schoolseq[0].rank=1;
	for(int i=1;i<schoolnum;i++)
	{
		if(schoolseq[i].score==schoolseq[i-1].score)
		{
			schoolseq[i].rank=ranknow;
		}
		else
		{
			ranknow=i+1;
			schoolseq[i].rank=ranknow;
		}
	}
	printf("%d\n",schoolnum);
	for(int i=0;i<schoolnum;i++)
	{
		printf("%d ",schoolseq[i].rank);
		cout<<schoolseq[i].name;
		printf(" ");
		printf("%.0f %d",floor(schoolseq[i].score),schoolseq[i].totalnum);
		if(i!=schoolnum-1) printf("\n");
	}
}
