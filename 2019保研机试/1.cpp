#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
bool record[10010];
int loopnum;
bool flag=0;
int flagnum;

int main()
{
	int num;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		flag=0;
		fill(record,record+10010,0);
		loopnum=0;
		string temp;
		cin>>temp;
		int tempnum=stoi(temp);
		record[tempnum]=true;   //第一个输入的也要计入 
		int sum=0;
		while(1)
		{
			if(temp.size()==1&&temp[0]=='1') break;
			int n=0;
			for(int j=0;j<temp.size();j++)
			{
				n=temp[j]-'0';	
				sum+=n*n;
			}	

			if(record[sum]==false)
			{
				record[sum]=true;				
			}
			else 
			{
				flag=1;
				flagnum=sum;
				break;
			}
			temp=to_string(sum);
		//	cout<<temp<<endl;
			sum=0;
			loopnum++;
			
		}
		if(flag==1)
		{
			cout<<flagnum;
		}
		else
		{
			cout<<loopnum;
			
		} 
		 if(i!=num-1) cout<<endl;
		

	}
 } 
