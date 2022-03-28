#include<iostream>
#include<cstdio>
#define ri register int
using namespace std;
int m[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	int w,md=1,mi=1;
	cin >> w;
	--w;
	for(ri i=1;i<=365;++i){
		if(mi==m[md]+1){
			mi=1;
			md++;
		}
		if(w==4&&mi==13)cout << md << endl;
		mi++;
		w=(w+1)%7;
	}
	return 0;
}
