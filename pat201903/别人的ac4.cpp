#include<bits/stdc++.h>
using namespace std;
const int INF=1000000000;
int weight[15],G[1015][1015],d[15][1015];
vector<int> pre[15][1015],temp,path;
bool inq[1015];
int ns,na,m,k;
void dijkstra(int index){
	 fill(inq,inq+1015,false);
	 fill(d[index],d[index]+1015,INF);
	 d[index][1000+index]=0;
	 for(int i=1;i<=1000+na;i++){
		 int u=-1,MIN=INF;
		 for(int j=1;j<=1000+na;j++){
			 if(inq[j]==false&&d[index][j]<MIN){
				 MIN=d[index][j];
				 u=j;
			 }
		 }
		 if(u==-1) return;
		 inq[u]=true;
		 for(int v=1;v<=1000+na;v++){
			 if(inq[v]==false&&G[u][v]!=INF){
				 if(d[index][u]+G[u][v]<d[index][v]){
					 pre[index][v].clear();
					 pre[index][v].push_back(u);
					 d[index][v]=d[index][u]+G[u][v];
				 }else if(d[index][u]+G[u][v]==d[index][v]) pre[index][v].push_back(u);
			 }
		 }
	 }
}
void dfs(int s,int ed){
	temp.push_back(s);
	if(s==ed+1000){
		if(path.size()==0) path=temp;
		else {
			if(temp.size()<=path.size()) path=temp;
		}
		temp.pop_back();
		return;
	}
	for(int i=0;i<pre[ed][s].size();i++){
		dfs(pre[ed][s][i],ed);
	}
	temp.pop_back();
}

int main(){

	
	scanf("%d%d",&ns,&na);
	for(int i=1;i<=na;i++) scanf("%d",&weight[i]);
	scanf("%d",&m);
	fill(G[0],G[0]+1015*1015,INF);
	for(int i=0;i<m;i++){
		char str[10];
		int u,v;
		scanf("%s",str);
		if(str[0]=='A'){
			sscanf(str,"A-%d",&u);
			u+=1000;
		}else u=stoi(str);
		scanf("%s",str);
		if(str[0]=='A'){
			sscanf(str,"A-%d",&v);
			v+=1000;
		}else v=stoi(str);
		scanf("%d",&G[u][v]);
		G[v][u]=G[u][v];
	}
	for(int i=1;i<=na;i++){
		dijkstra(i);
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int aim,mindis=INF,maxleft=-1,index;
		vector<int> res;
		scanf("%d",&aim);
		for(int j=1;j<=na;j++){
			if(weight[j]>0){
				if(d[j][aim]<mindis){
					mindis=d[j][aim];
					maxleft=weight[j];
					dfs(aim,j);
					res=path;
					path.clear();
					index=j;
				}else if(d[j][aim]==mindis&&weight[j]>weight[index]){
					dfs(aim,j);
					maxleft=weight[j];
					res=path;
					path.clear();
					index=j;
				}else if(d[j][aim]==mindis&&weight[j]==weight[index]){
					dfs(aim,j);
					if(path.size()<res.size()) res=path,index=j;
					path.clear();
				}
			}
		}
		if(maxleft==-1) printf("All Busy\n");
		else {
			weight[index]--;
			for(int j=res.size()-1;j>=0;j--){
				if(res[j]>1000) printf("A-%d",res[j]-1000);
				else printf("%d",res[j]);
				if(j) printf(" ");
				else printf("\n");
			}
			printf("%d\n",d[index][aim]);
		}
	}
}
