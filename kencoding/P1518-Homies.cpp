#include<iostream>
#include<cstdio>
#define ri register int
using namespace std;
int set[114514];
void NEWSET(int x){
	set[x]=x;
}
int FINDSET(int x){
	if(set[x]==x)return x;
	return FINDSET(set[x]);
}
void MERGESET(int x,int y){
	int XR=FINDSET(x);
	int YR=FINDSET(y);
	if(XR==YR)return;
	set[XR]=YR;
}
int main(){
	int n,m,p;
	cin >> n >> m >> p;
	for(ri i=0;i<=n;++i)NEWSET(i);
	for(ri i=0;i<m;++i){
		int Mi,Mj;
		scanf("%d%d",&Mi,&Mj);
		MERGESET(Mi,Mj);
	}
	for(ri i=0;i<p;++i){
		int Qi,Qj;
		scanf("%d%d",&Qi,&Qj);
		if(FINDSET(Qi)==FINDSET(Qj))printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
