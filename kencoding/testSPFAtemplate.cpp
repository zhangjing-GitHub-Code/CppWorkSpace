#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define MXM 214514
#define MXN 114514
#define MXINF 0x3f3f3f3f
#define ri register int
struct YEE{
	int u,v,id,w;
};
YEE e[MXM];
vector <YEE> Gs[MXM],Ge[MXM];
queue <int> que;
long ds[MXN],de[MXN];
bool ved[MXN];
int flg[MXN];
int path[MXN];
int n,m,k;
long p,ans;
bool SPFA(vector<YEE> G[],long *dis,int x){
	int u,v;
	memset(flg,0,sizeof(flg));
	memset(ved,false,sizeof(ved));
	memset(path,-1,sizeof(path));
	fill(dis,dis+n+1,MXINF);
	dis[x]=0;
	que.push(x);
	while(!que.empty()){
		u=que.front();
		que.pop();
		ved[u]=false;
		for(ri i=G[u].size()-1;i>=0;--i){
			if(dis[G[u][i].v]>dis[u]+G[u][i].w){
				dis[G[u][i].v]=dis[u]+G[u][i].w;
				path[G[u][i].v]=G[u][i].u;
				if(!ved[G[u][i].v]){
					ved[G[u][i].v]=true;
					flg[G[u][i].v]++;
					if(flg[G[u][i].v]>=n)return false;
					que.push(G[u][i].v);
				}
			}
		}
	}
	return false;
}
int main(){
	int s,t;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (ri i=1;i<=m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		Gs[u].push_back((YEE){u,v,i,-w});
		e[i]=(YEE){u,v,i,w};
		Ge[v].push_back((YEE){v,u,i,-w});
	}
	SPFA(Gs,ds,s);
	SPFA(Ge,de,t);
	ans=0;
	for(ri i=1;i<=m;++i)ans=max(ans,-ds[t]+ds[e[i].u]+de[e[i].v]-e[i].w);
	printf("%ld\n",ans);
	return 0;
}
