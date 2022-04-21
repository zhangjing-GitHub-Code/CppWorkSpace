#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<map>
#include<cstring>
#define ri register int
using namespace std;
struct YEE{
	int sid,num,rks;
	bool dist;// even/odd
}s[10011];
int sN;
char str[10];
map<int,int> iM;
void swp(int &v1,int &v2){
	int tmp=v1;
	v1=v2;
	v2=tmp;
}
int getIdx(int nu){
	map<int,int>::iterator it;
	if((it=iM.find(nu))!=iM.end())return it->second;
	else return -1;
}
void MKST(int x){//,U ,i, od dn keyboard<<1
	s[sN].num=x;
	s[sN].dist=0;
	s[sN].sid=sN;
	iM[x]=sN;
	++sN;
}
int FS(int idx){
	if(s[idx].sid==idx)return idx;
	else{
		int pre=s[idx].sid;
		s[idx].sid=FS(s[idx].sid);
		s[idx].dist=s[idx].dist^s[pre].dist;
		return s[idx].sid;
	}
}
bool MES(int n1,int n2,bool dt){
	int idx1=getIdx(n1),
		idx2=getIdx(n2);
	int id1=FS(idx1);
	int id2=FS(idx2);
	if(id1==id2)return ((s[idx1].dist^s[idx2].dist)==dt);
	if(s[id1].rks<s[idx2].rks){
		s[id1].sid=id2;
		s[id1].dist=s[idx1].dist^s[idx2].dist^dt;
	}else{
		s[id2].sid=id1;
		s[id2].dist=s[idx2].dist^s[idx1].dist^dt;
		if(s[id1].rks==s[id2].rks)s[id1].rks++;
	}
	return true;
}
int main(){
	int n,aN,i,f,t;//size of str,assert no.,i iterator,start node,end node
	bool b;
	scanf("%d%d",&n,&aN);
	sN=0;
	int eP=aN;
	memset(s,0,sizeof(s));
	for(i=1;i<=aN;++i){
		scanf("%d%d%s",&f,&t,str);
		if(f>t)swp(f,t);
		if(getIdx(f-1)==-1)MKST(f-1);
		if(getIdx(t)==-1)MKST(t);
		if(strcmp(str,"odd")==0)b=true;
		else b=false;
		if(!MES(f-1,t,b)){
			eP=i-1;
			break;
		}
	}
	printf("%d\n",eP);
	return 0;
}
