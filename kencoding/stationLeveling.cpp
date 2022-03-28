#include<iostream>
#include<cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
struct edge{
	int u,v;
};
vector<edge> g[1145];
int inCnt[1145],vnum,level,cnt;
int stations[1145];
bool mtx[1145][1145];
queue <int> que;
bool TLS(){
	int i,vx,v,k;
	for(i=1;i<=vnum;++i)if(!inCnt[i])que.push(i);
	level=cnt=0;
	vx=que.size();
	while(!que.empty()){
		v=que.front();
		que.pop();
		++cnt;
		for(i=0;i<g[v].size();++i){
			k=g[v][i].v;
			if(!(--inCnt[k]))que.push(k);
		}
		vx--;
		if(!vx){
			level++;
			vx=que.size();
		}
	}
	if(cnt<vnum) return false;
	else return true;
}
int main(){
	int i,j,n,m,t,x;
	memset(inCnt,0,sizeof(inCnt));
	memset(mtx,0,sizeof(mtx));
	cin>>vnum>>n;
	for(i=1;i<=n;i++){
		cin>>m;
		for(j=1; j<=m;j++)cin>>stations[j];
		if(m<2) continue;
		j=2;
		for(t=stations[1]+1;t<stations[m];++t){
			if(t!=stations[j])
				for(x=1;x<=m;++x){
					if(!mtx[t][stations[x]]){
						mtx[t][stations[x]]=true;
						inCnt[stations[x]]++;
						g[t].push_back((edge){t,stations[x]});
					}
				}
			else j++;
		}
	}
	if(TLS())
		cout<<level<<endl;
	else cout<<"Cycled\n";
	return 0;
}
