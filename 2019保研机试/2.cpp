#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
vector<int> seq;
int hangnum;
int main()
{
	int num;
	int width;
	scanf("%d %d\n",&num,&width);
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		seq.push_back(temp);
	}
	sort(seq.begin(),seq.end());
	int count=0;
	int flag=1;
	int hang=ceil((seq.size()/width));
	while(count<seq.size())
	{
		int n=0;
		while(n<width)
		{
			if(flag==1)
			{
				if(count+n>=seq.size()) break;
				if(n==0) 	printf("%d",seq[count+n]);
				else printf(" %d",seq[count+n]);
			}
			else if(flag==-1)
			{
				if((count+width)>=seq.size())
				{
					for(int x=seq.size()-1;x>=count;x--)
					{
						printf("%d",seq[x]);
						if(x!=count) printf(" ");
					}
					break;
				}
				else 
				{
					if(n==0) printf("%d",seq[count+width-1+n*flag]);
					else printf(" %d",seq[count+width-1+n*flag]);
				}
			
			}
			
			n++;
		}
		if(hangnum<hang) printf("\n");
		count+=width;
		flag=flag*(-1);
		hangnum++;
			
	} 
}
