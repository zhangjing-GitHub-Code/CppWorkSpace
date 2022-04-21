#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define ri register int
using namespace std;
struct faq{int sid,dist,sum;}s[114514];
inline void MKST(int x){
	s[x].sid=x;
	s[x].sum=1;
	s[x].dist=0;
}
int FNST(int x){
	if(s[x].sid!=x){
	int tm=s[x].sid;
	s[x].sid=FNST(s[x].sid);
	s[x].dist+=s[tm].dist;
	}
	return s[x].sid;
}
void MGST(int x,int y){
	x=FNST(x);
	y=FNST(y);
	if(x==y)return;
	s[y].sid=x;
	s[y].dist+=s[x].sum;
	s[x].sum+=s[y].sum;
}
int main(){
	int T,n,x,y;
	char oprstr[10];
	scanf("%d",&T);
	n=30000;
	for(ri i=1;i<=n;++i)MKST(i);
	for(ri i=0;i<T;++i){
		scanf("%s%d%d",oprstr,&x,&y);
		if(oprstr[0]=='M')MGST(x,y);
		else if(FNST(x)!=FNST(y))printf("-1\n");
		else printf("%d\n",abs(s[x].dist-s[y].dist)-1);
	}
	return 0;
}
