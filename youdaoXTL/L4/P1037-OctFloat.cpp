#include<iostream>
#include<cstdio>
#define ri register int
using namespace std;
double OF2DF(string oc){
	double ans=0.0;
	long long wq=8;
	for(ri i=0;i<oc.size()-2;++i){
		ans+=(double)(oc[i+2]-'0')/wq;
		wq*=wq;
	}
	return ans;
}
int main(){
	string oct;
	cin >> oct;
	cout << oct;
	printf(" [8] = %lf [10]\n",OF2DF(oct));
	return 0;
}
