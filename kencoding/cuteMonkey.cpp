#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
struct edge{
	int u,v,id;
};
using namespace std;
int s[414514],rank1[414514],rank2[414514];
int g[414514],t[414514],monkey[414514][2],edges[414514][2];
inline void make_set(int *s,int *rk,int x){
	s[x]=x;
	rk[x]=0;
}
int find_set(int *s,int x){
	if(s[x]!=x)return find_set(s,s[x]);
	return x;
}
void merge_set(int *s,int *rk,int x,int y){
	if((x<0)||(y<0))return;
	x=find_set(s,x);
	y=find_set(s,y);
	if(x==y)return;
	if(rk[x]<rk[y])s[x]=y;
	else{
		s[y]=x;
		if(rk[x]==rk[y])rk[x]++;
	}
}
/*void DFS(long long u){
	visited[u]=true;
	falltime[u]=-1;
	for(int i=0;i<4;++i){
		if(!visited[monkey[u][i].v])DFS(monkey[u][i].v);
	}
}*/
int main(){
	memset(t,0xff,sizeof(t));
	int n,m,x,y;
	cin >> n >> m;
	for(int i=1;i<=n;++i)make_set(s,rank1,i);
	for(int i=1;i<=n;++i)scanf("%d%d",&monkey[i][0],&monkey[i][1]);
	for(int i=0;i<m;++i){
		int id,h;
		cin >> edges[i][0] >> edges[i][1];
		int p=monkey[edges[i][0]][edges[i][1]-1];
		monkey[edges[i][0]][edges[i][1]-1]=-1;
		edges[i][1]=p;
	}
	for(int i=1;i<=n;++i){
		merge_set(s,rank1,i,monkey[i][0]);
		merge_set(s,rank1,i,monkey[i][1]);
	}
	for(int i=1;i<=n;++i){g[i]=s[i];rank2[i]=rank1[i];}
	for(int i=m-1;i>=0;--i){
		int tmp=find_set(s,1);
		x=find_set(s,edges[i][0]);
		y=find_set(s,edges[i][1]);
		if(x==y)continue;
		if((x==tmp)||(y==tmp)){
			int ttmp;
			if(x==tmp)ttmp=y;
			else ttmp=x;
			t[ttmp]=i;
			merge_set(s,rank1,tmp,ttmp);
		}else{
			merge_set(s,rank1,x,y);
			merge_set(g,rank2,x,y);
		}
	}
	for(int i=1;i<=n;++i)printf("%d\n",t[find_set(g,i)]);
	/*
		for(int j=0;j<monkey[id].size();++j){
			if(monkey[id][j].id==h){
				monkey[id].erase(monkey[id].begin()+j);
				break;
			}
		}
		for(long long j=1;j<=n;++j)if(falltime[j]==-1)falltime[j]=i;
		DFS(1);
	}*/
	return 0;
}
