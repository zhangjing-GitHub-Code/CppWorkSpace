#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int dist[114],pth[514];
bool ved[1919];
struct edge {
	int u,v,w;
};
struct node {
	int x ,d;
	bool operator< (const node & a)const{return a.d<d;}
};
int mtx[114][514];
int xmap[114][514];
vector<edge> head[114];
priority_queue<node> q;
void DKT(int s ){
	memset(dist,0x3f,sizeof(dist));
	memset(ved,0,sizeof(ved));
	memset(pth,0xff,sizeof(pth));
	q.push((node){s,0});
	dist[s]=pth[s]=0;
	while(!q.empty()){
		int curr=q.top().x;
		q.pop();
		if (ved[curr])continue;
		ved[curr]=true;
		for (unsigned int i=0;i<head[curr].size();++i){
			int y=head[curr][i].v;
			if(ved[y])continue;
			if (dist[y]>dist[curr]+head[curr][i].w){
				dist[y]=dist[curr]+head[curr][i].w;
				pth[y]=curr;
				q.push((node){y,dist[y]});
			}
		}
	}
}
int main(){
	int n,m,s,u,v,i,j,w;
	memset(mtx,0xff,sizeof(mtx));
	memset(xmap,0,sizeof(xmap));
	cin>>n>>m;
	for (int i=1;i<=m;++i){
		cin >> u >> v >> w;
		mtx[u][v]=w;
		mtx[v][u]=w;
	}
	cin >>m;
	for (int i=1;i<=m;++i){
		cin >>u>>v;
		xmap[u][v]=xmap[v][u]=1;
	}
	for (i=2;i<=n;i++)
		for (j=1;j<i;++j)
			if (mtx[i][j]!=-1){
				if (xmap[i][j])w=mtx[i][j];
				else w=0;
				head[i].push_back((edge){i,j,w});
				head[j].push_back((edge){j,i,w});
			}
	cin>>s>>v;
	DKT(s);
	cout <<dist[v]<<endl;
	return 0;
}
