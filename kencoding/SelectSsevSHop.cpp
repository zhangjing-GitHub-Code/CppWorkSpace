#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 0x1f1f1f
#define ri register int
using namespace std;
int MAP[600][600]={INF};
void floyd(int n){
	for(ri i=0;i<=n;++i){
		for(ri l=1;l<=n;++l){
			for(ri c=1;c<=n;++c){
				MAP[l][c]=min(MAP[l][c],MAP[i][c]+MAP[l][i]);
			}
		}
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	memset(MAP,INF,sizeof(MAP)+1);
	for(ri i=1;i<=n;++i)MAP[i][i]=0;
	for(ri i=1;i<=m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		MAP[u][v]=min(w,MAP[u][v]);
		MAP[v][u]=min(w,MAP[v][u]);
	}
	floyd(n);
	int NODEMIN=INF,MINNODE=INF;
	for(ri node=1;node<=n;++node){
		int nmax=-1;
		for(ri c=1;c<=n;++c){
			if(MAP[node][c]>nmax)nmax=MAP[node][c];
		}
		if(nmax<NODEMIN){
			NODEMIN=nmax;
			MINNODE=node;
		}
	}
	cout << MINNODE;
	return 0;
}
