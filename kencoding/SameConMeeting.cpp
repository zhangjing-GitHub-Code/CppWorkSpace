#include<iostream>
#include<cstdio>
#include<cstring>
#define ri register int
using namespace std;
int CSET[114514];
bool ved[114514]={false};
int FIND_ROOT(int x){
	//ved[x]=true;
	if(CSET[x]==x)return x;
	else return FIND_ROOT(CSET[x]);
}
int NEW_SET(int x){
	CSET[x]=x;
	return 1;
}
int MERGE_SET(int x,int y){
	if(FIND_ROOT(x)==FIND_ROOT(y))return 0;
	CSET[x]=FIND_ROOT(y);
	return 1;
}
int main(){
	int n,m;
	cin >> n>>m;
	for(ri i=0;i<n;++i)NEW_SET(i);
	for(ri i=0;i<m;++i){
		int x,y;
		cin >> x >> y;
		MERGE_SET(x,y);
	}
	int cnt=0;
	memset(ved,0,sizeof(ved));
	for(int i=0;i<n;++i){
		if(!ved[FIND_ROOT(i)]){
			ved[FIND_ROOT(i)]=true;
			cnt++;
		}
	}
	cout << cnt;
}
