#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#define maxn  200000
using namespace std;

int primelist[maxn];
int numc=0;
bool isprime(int n)
{
	if(n<=1) return false;
	for(int i=2;i<(int)sqrt(1.0*n);i++)
	{
		if(n%i==0) return false;
	}
	return true;
	
}
bool isprimell(long long n)
{
	if(n<=1) return false;
	for(long long i=2;i<(long long)sqrt(1.0*n);i++)
	{
		if(n%i==0) return false;
	}
	return true;
	
}
void findprime()
{

	for(int i=1;i<=maxn;i++)
	{
		if(isprime(i)) primelist[numc++]=i;
	}
}
struct factor
{
	int count;
	int x;
}fac[10];
int main()
{
	string ans;
	findprime();
	int num;
	int facn=0;
	cin>>num;
	if(num==1) cout<<"1"<<endl<<"Yes";
else
{
	for(int i=0;i<numc&&primelist[i]<(int)sqrt(1.0*num);i++)
	{
		if(num%primelist[i]==0)
		{
			fac[facn].x=primelist[i];
			fac[facn].count=0;
			while(num%primelist[i]==0)
			{
				fac[facn].count++;
				num=num/primelist[i];
			}
			facn++;
		}
		if(num==1) break;
	}
	if(num!=1)
	{
		fac[facn].x=num;
		fac[facn++].count=1;
	}
	for(int i=0;i<facn;i++)
	{
		string temp1=to_string(fac[i].x);
		string temp2;
		ans+=temp1;
		if(fac[i].count>1)
		{
			temp2=to_string(fac[i].count);
			ans+=temp2;
		}
	}
	cout<<ans<<endl;
	if(ans.size()>=10) 
	{
		long long judgenum=stoll(ans);
		if(isprimell(judgenum)) cout<<"Yes";
		else cout<<"No";
	}
	else
	{
		int judgenum=stoi(ans);
		if(isprime(judgenum)) cout<<"Yes";
		else cout<<"No";		
	}
	
	
}

	
}
