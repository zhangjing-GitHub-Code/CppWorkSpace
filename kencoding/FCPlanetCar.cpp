#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define ri register int
using namespace std;
int set[1145],rks[1145];
struct edge{
	int u,v,w;
}G[1145];
bool ccmp(edge l,edge r){
	return l.w>r.w;
}
inline void NEWSET(int x){
	set[x]=x;
	rks[x]=0;
}
int FINDSET(int x){
	/*if(set[x]==x)return x;
	return FINDSET(set[x]);*/
	if(set[x]!=x)set[x]=FINDSET(set[x]);
	return set[x];
}
void MERGESET(int x,int y){
	x=FINDSET(x);
	y=FINDSET(y);
	if(x==y)return;
	if(rks[x]<rks[y])set[x]=y;
	else{
		set[y]=x;
		if(rks[x]==rks[y])rks[x]++;
	}
}
int main(){
	int n,m,s,t,q,j,ans;
	scanf("%d%d",&n,&m);
	for(ri i=0;i<m;++i){
		scanf("%d%d%d",&G[i].u,&G[i].v,&G[i].w);
	}
	sort(G,G+m,ccmp);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&s,&t);
		ans=0x3fffff;
		for(ri i=0;i<m;++i){
			for(j=1;j<=n;++j)NEWSET(j);
			for(j=i;j<m;++j){
				MERGESET(G[j].u,G[j].v);
				if(FINDSET(s)==FINDSET(t)){
					ans=min(ans,G[i].w-G[j].w);
					break;
				}
			}
		}
		if(ans<0x3fffff)printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}

