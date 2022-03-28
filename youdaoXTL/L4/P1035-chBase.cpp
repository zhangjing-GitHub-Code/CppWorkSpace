#include<iostream>
#include<cstdio>
#define ri register int
using namespace std;
int getcur(char YEE){
	if(YEE>='0'&&YEE<='9')return YEE-'0';
	if(YEE>='A'&&YEE<='Z')return YEE-'A'+10;
	if(YEE>='a'&&YEE<='z')return YEE-'a'+10;
}
int cur2char(int d){
	if(d>=10)return d-10+'A';
	return d+'0';
}
long long bN2D(string basen,int base){
	long long wq=1,ans=0;
	for(int i=basen.size()-1;i>=0;--i){
		int cur=getcur(basen[i]);
		ans+=cur*wq;
		wq*=base;
	}
	return ans;
}
string D2bn(long long dec,int base){
	string ans;
	long long tmp=dec;
	while (tmp!=0){
		int cur=tmp%base;
		ans+=cur2char(cur);
		tmp/=base;
	}
	long long siz=ans.size();
	for(int i=0;i*2<siz;++i){
		swap(ans[i],ans[siz-1-i]);
	}
	return ans;
}
int main(){
	int preB,aftB;
	string baseNnum;
	cin >> preB >> baseNnum >> aftB;
	if(baseNnum=="0"){
		printf("0\n");
		return 0;
	}
	//printf("THE DEC IS : %lld\n",bN2D(baseNnum,preB));
	cout << D2bn(bN2D(baseNnum,preB),aftB);
	return 0;
}
