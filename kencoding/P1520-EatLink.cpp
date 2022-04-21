#include<iostream>
#include<cstdio>
#define ri register int
using namespace std;
int s[114514],eat[114514]={99999};
void NEWS(int x){
	s[x]=x;
}
int FINDR(int x){
	if(s[x]==x)return x;
	return FINDR(s[x]);
}
void MERGES(int x,int y){
	int xx=FINDR(x);
	int yy=FINDR(y);
	if(xx==yy)return;
	s[xx]=yy;
}
bool CKMD(){

}
int main(){
	int n,k,f=0;
	cin >> n >> k;
	for(ri i=1;i<=n;++i)NEWS(i);
	for(ri i=0;i<k;++i){
		int d,x,y;
		int xr,yr;
		xr=FINDR(x);
		yr=FINDR(y);
		scanf("%d%d%d",&d,&x,&y);
		if(d==2){
			if(xr==yr||x==y||x>n||y>n||eat[yr]==xr){
				f++;
				continue;
			}
			eat[xr]=yr;
		}
		if(d==1){
			if(eat[yr]==xr||eat[xr]==yr){
				f++;
				continue;
			}
			MERGES(x,y);
		}
	}
	printf("%d",f);
	return 0;
}
