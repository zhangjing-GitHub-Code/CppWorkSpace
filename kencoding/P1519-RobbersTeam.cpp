#include<iostream>
#include<cstdio>
#define ri register int
#define SZ 114514
using namespace std;
int us[SZ];
void NEWSET(int x){
	us[x]=x;
}
int FINDSET(int x){
	if(us[x]==x)return x;
	return FINDSET(us[x]);
}
void MERGESET(int x,int y){
	int XR=FINDSET(x);
	int YR=FINDSET(y);
	if(XR==YR)return;
	us[XR]=YR;
}
void MERGEENER(int x,int y){
	if(FINDSET(x)!=FINDSET(y))MERGESET(x,y);
	return;
}
int main(){
	int n,m;
	cin >> n >> m;
	for(ri i=1;i<=n;++i)NEWSET(i);
	for(ri i=0;i<m;++i){
		int p,x,y;
		scanf("%d%d%d",&p,&x,&y);
		if(p==0)MERGESET(x,y);
		if(p==1)MERGEENER(x,y);
	}
	int cnt=1,vi[114514]={0};
	for(ri i=1;i<=n;++i){
		int FR=FINDSET(i);
		if(!vi[FR]){
			vi[FR]=1;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
