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
//Ҫע�⼸�֣�ǰ����ߺ��淢�ָü���û�п�ס�Ĵ�ʱҪ�޳�  ��ס�ļ��ظ�����ʱ�����ǵ�һ����ס��ʱ¼��ü��������������������ظ���ʱÿ�α�������ʱ�����һ����������    
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
	//Ҫ�������Ǻ��������֤ʵ���ǿ�ס ��Ȼǰ����ʾ��ס�� Ӧ��ȥ�����˿���  �����ж�Ϊ������λ 
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
