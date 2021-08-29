#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

int length;
int key;
int num;
int mark[1500];
double ans;
int mycount;

bool oneturn;
int main()
{
	int loca;
	scanf("%d %d %d",&length,&key,&num);
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(mark[temp%length]==false)
		{
			mark[temp%length]=true;
		}
		else
		{
			mycount++;
			loca=temp%key;
			int start=loca;
			while(mark[loca]==true)
			{
				mycount++;
				loca++;
				if(loca>=length) 
				{
					loca=loca%length;	
				}
			}
			mark[loca]=true;
			mycount++;
		
		}
	}

	ans=1.0*mycount;
	printf("%.1lf",ans);
 } 
 /*
 #include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1e3 + 10;
int p[maxn];
int main()
{
    memset(p, -1, sizeof(p));
    int Tsize, M, N, x;
    cin >> Tsize >> M >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        for(int j = 0; j < Tsize; j++){
            int pos = (x % M + j) % Tsize;
            if(p[pos] == -1){
                p[pos] = x;
                break;
            }
        }
    }
    double sum = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j <= Tsize; j++){
            sum++;
            int pos = (i + j) % Tsize;
            if(p[pos] == -1){
                break;
            }
        }
    }
    printf("%.1f", sum / M);
    return 0;
}
*/
