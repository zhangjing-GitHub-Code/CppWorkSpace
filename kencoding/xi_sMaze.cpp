#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define ri register int
using namespace std;
/*struct edge{
	int u,v;
};
queue<int> vq;
vector<edge> G[114514];
bool ved[114514]={false};
//BFS but not search
bool BFSBNS(){
	int init=0;
	for(;init<114510;++init){
		if(G[init].size()!=0)break;
	}
	vq.push_back(init);
	while(!vq.empty()){
		int f=vq.front();
		if(ved[f])return false;
	}
}*/
int s[114514];
bool ved[100005];
void NEWSET(int x){
	s[x]=x;
}
int FINDSET(int x){
	if(s[x]==x)return x;
	return FINDSET(s[x]);
}
bool MERGESET(int x,int y){
	int XR=FINDSET(x);
	int YR=FINDSET(y);
	ved[x]=true;
	ved[y]=true;
	if(XR==YR)return false;
	s[XR]=YR;
	return true;
}
int main(){
	int l,r;
	while(1){
		bool yee=false;
		scanf("%d%d",&l,&r);
		if(r==-1&&l==-1)break;
		if(l==0&&r==0){
			printf("1 ");//Yes\n");
			continue;
		}
		memset(ved,false,sizeof(ved));
		for(ri i=0;i<100006;++i)NEWSET(i);
		ved[l]=true;
		ved[r]=true;
		while(1){
			//if(r==0&&l==0)break;
			if(!MERGESET(l,r)){
				//printf("No\n");
				yee=true;
				//break;
			}
			scanf("%d%d",&l,&r);
			if(r==0||l==0)break;
		}
		if(yee){
			printf("0 ");//No\n");
			continue;
		}
		int sc=0;
		for(ri i=0;i<=100005;++i){
			if(ved[i]&&s[i]==i)sc++;
		}
		if(sc==1)printf("1 ");//Yes\n");
		else printf("0 ");//No\n");
	}
	return 0;
}
