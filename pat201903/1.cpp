#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

bool judgeprime(int num)
{
	if(num<=1) return false;
	for(int i=2;i<=int(sqrt(1.0*num));i++)
	{
		if(num%i==0) return false;
	}
	return true;
}

int main()
{
	int num;
	scanf("%d",&num);
	int num1=num-6;
	int num2=num+6;
	
	if(num1>0&&judgeprime(num)&&judgeprime(num1))
	{
		printf("Yes\n");
		printf("%d",num1);	
	}
	else if(num2>0&&judgeprime(num)&&judgeprime(num2))
	{
		printf("Yes\n");
		printf("%d",num2);		
	}
	else
	{
		printf("No\n");
		int j;
		int out=-1;
		for(j=num+1;j<200000000;j++)
		{
			if(judgeprime(j)&&judgeprime(j-6))
			{
				if(j-6>num)	out=j-6;
				else out=j;
				break;
			 } 
			 else if(judgeprime(j)&&judgeprime(j+6))
			 {
			 	out=j;
			 	break;   // «’“nextseyprime 
			}
		}
	
		printf("%d",out);
	}
	

		

}
 
