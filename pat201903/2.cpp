#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>

using namespace std;

map<string,int> stringtoint;
map<int,string> inttostring;
bool cmp(string a,string b)
{
	string a1=a.substr(6,8);
	string b1=b.substr(6,8);
	return a1<b1;
}

int mycount=0;
vector<string> guestlist;
string oldname;
vector<string> guestold;
int main()
{
	int listnum;
	cin>>listnum;
	for(int i=0;i<listnum;i++)
	{
		string temp;
		cin>>temp;
		stringtoint[temp]=i;
		inttostring[i]=temp;
	}
	int guestnum;
	cin>>guestnum;
	for(int i=0;i<guestnum;i++)
	{
		string name;
		cin>>name;
		guestlist.push_back(name);
		if(stringtoint.find(name)!=stringtoint.end()) 
		{
			mycount++;
			guestold.push_back(name);
		}
	}
	cout<<mycount<<endl;
	if(mycount!=0)
	{
		sort(guestold.begin(),guestold.end(),cmp);
		cout<<guestold[0];
	}
	else
	{
		sort(guestlist.begin(),guestlist.end(),cmp);
		cout<<guestlist[0];
	}
}
