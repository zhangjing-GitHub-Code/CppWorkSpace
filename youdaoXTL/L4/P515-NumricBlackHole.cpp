#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define ri register int
using namespace std;
int nums[5]={0},cnt=0;
bool AltBcmp(int a,int b){
	return a<b;
}
bool BltAcmp(int a,int b){
	return a>b;
}
int functi(int n){
	cnt++;
	int tmp=n,revnum[5],idx=0,nsmall=0,nbig=0;
	//printf("now fuck tmp into nums\n");
	while(tmp){
		nums[idx++]=tmp%10;
		tmp/=10;
	}
	for(ri i=0;i<4;++i)revnum[i]=nums[i];
	//printf("Sortnow;\n");
	sort(revnum,revnum+4,BltAcmp);
	sort(nums,nums+4,AltBcmp);
	for(ri i=0;i<4;++i){
		nsmall=nsmall*10+nums[i];
		nbig=nbig*10+revnum[i];
	}
	int dist=abs(nbig-nsmall);
	//printf("big:%d;small:%d;dist:%d\n",nbig,nsmall,dist);
	if(dist==6174)return cnt;
	return functi(dist);
}
int main(){
	int n;
	cin >> n;
	cout << functi(n);
	return 0;
}
