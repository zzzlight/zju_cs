#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

string wrongw;
string out;
bool goodword[1000];
int wrongword[1000];
int wrongword2[1000];
//要注意几种：前面或者后面发现该键并没有卡住的此时要剔除  卡住的键重复出现时，若是第一个卡住键时录入该键，后续若是仍在连着重复此时每次保留整除时候的那一个其他过掉    
int main()
{
	int num;
	cin>>num;
	string seq;
	cin>>seq;
	for(int i=0;i<seq.size();i++) 
	{
		if(goodword[seq[i]]==false&&wrongword[seq[i]]==0) 
		{
			int j;
			int start=i;
			for(j=i;j<seq.size();j++)
			{
				if(seq[j]!=seq[i]) break;
			}
			if((j-start)%num==0)
			{
				wrongword[seq[i]]++;
				wrongw.push_back(seq[i]);
			}
			else
			{
				goodword[seq[i]]=true;
			}
		}
		else if(goodword[seq[i]]==true&&wrongword[seq[i]]==0)
		{
			goodword[seq[i]]=true;
		}
		else if(wrongword[seq[i]]!=0&&goodword[seq[i]]==false)
		{
			if(wrongword[seq[i]]%num==0)
			{
				int j;
				int start=i;
				for(j=i;j<seq.size();j++)
				{
					if(seq[j]!=seq[i]) break;
				}
				if((j-start)%num!=0)
				{
					goodword[seq[i]]=true;
					wrongword[seq[i]]=0;
					int pos=wrongw.find(seq[i]);
					wrongw.erase(pos,1);
				
				}
				else
				{
					wrongword[seq[i]]++;
				}
			}
			else
			{
				wrongword[seq[i]]++;
			}

	
			
		}
		
	}
	//要特判若是后面出现了证实不是卡住 虽然前面显示卡住了 应该去除掉此卡键  重新判定为正常键位 
	for(int i=0;i<seq.size();i++) 
	{
		if(goodword[seq[i]]==false&&wrongword2[seq[i]]==0) 
		{
			out.push_back(seq[i]);
			wrongword2[seq[i]]++;
		}
		else if(goodword[seq[i]]==true)
		{
			goodword[seq[i]]=true;
			out.push_back(seq[i]);
		}
		else if(wrongword2[seq[i]]!=0&&goodword[seq[i]]==false)
		{
			if(wrongword2[seq[i]]%num==0)
			{
			
					wrongword2[seq[i]]++;
					out.push_back(seq[i]);
			}
			else
			{
				wrongword2[seq[i]]++;
			}

	
			
		}
	}
	cout<<wrongw<<endl;
	cout<<out;

}
