#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#define nenhenghengAAAAAAAAAAAA 11451419
using namespace std;
/*int bst=0,bstn=0,wst=114514,wstn=114514,ved[114514]={0},bkved[114514]={0},cantoved[114514]={0};
struct node{
	vector<int> in,to;
	int price;
};
node *Nodes=new node [nenhenghengAAAAAAAAAAAA];
bool CANTOSTART(int n){
	cantoved[n]=1;
	if(n==1)return true;
	for(int i=0;i<Nodes[n].in.size();++i){
		if(!cantoved[Nodes[n].in[i]]){
			if(CANTOSTART(Nodes[n].in[i]))return true;
		}
	}
	return false;
}
int HIGH_DFS(int n){
	ved[n]=1;
	if(Nodes[n].price>=bst){
		bst=Nodes[n].price;
		bstn=n;
	}
	for(int i=0;i<Nodes[n].to.size();++i){
		if(!ved[Nodes[n].to[i]])HIGH_DFS(Nodes[n].to[i]);
	}
}
int BACKWD_DFS(int n){
	bkved[n]=1;
	memset(cantoved,0,114514);
	if(Nodes[n].price<wst&&CANTOSTART(n)){
		wst=Nodes[n].price;
		wstn=n;
	}
	for(int i=0;i<Nodes[n].in.size();++i){
		if(!bkved[Nodes[n].in[i]])BACKWD_DFS(Nodes[n].in[i]);
	}
}
int main(){
	int n,m;
	cin >> n>>m;
	for(int i=0;i<n;++i){
		cin>>Nodes[i+1].price;
	}
	for(int i=0;i<m;++i){
		int u,v,type;
		scanf("%d%d%d",&u,&v,&type);
		if(type==1){
			Nodes[v].in.push_back(u);
			Nodes[u].to.push_back(v);
		}else{
			Nodes[v].in.push_back(u);
			Nodes[u].to.push_back(v);
			Nodes[u].in.push_back(v);
			Nodes[v].to.push_back(u);
		}
	}
	HIGH_DFS(1);
	BACKWD_DFS(bstn);
	cout << bst-wst;
}*/
#define INF 0x1f1f1f1f
#define ri register int
#define MAXN 100050
#define usi unsigned int
struct edge{int u,v,id;};
vector<edge> g[MAXN];
int f[MAXN],c[MAXN],p[MAXN],n,m;
void DFS(int x,int minc,int par){
	bool stat=true;
	minc=min(p[x],minc);
	if(minc>=c[x])stat=false;
	else c[x]=minc;
	f[x]=max(max(f[par],p[x]-c[x]),f[x]);
	if(!stat)return;
	for (usi i=0;i<g[x].size();++i)
		DFS(g[x][i].v,minc,x);
}
int main(){
	int u,v,dir;
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",p+i);
	for(ri i=1;i<=m;++i){
		scanf("%d %d %d",&u,&v,&dir);
		g[u].push_back((edge){u,v,i});
		if(dir==2)g[v].push_back((edge){v,u,i});
	}
	memset(c,0x1F,sizeof(c));
	memset(f,0,sizeof(f));
	DFS(1,INF,0);
	cout << f[n];
	return 0;
}
