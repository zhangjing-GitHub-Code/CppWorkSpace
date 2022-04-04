#include<cstdio>
#include<iostream>
#include<set>
#define ri register int
#define rli register long int
using namespace std;
set<int> fm, mf;
int main(){
	short P;
	long int jiaohu, n;
	scanf("%d", &P);
	for (ri i = 0; i < P;++i){
		fm.clear();
		mf.clear();
		bool suc = true;
		scanf("%ld%ld", &n, &jiaohu);
		rli jh = 0;
		for (; jh < jiaohu;++jh){
			long int l, r;
			bool put = false;
			scanf("%ld%ld", &l, &r);
			if (fm.count(l) ==0 &&
				fm.count(r) == 0 &&
				mf.count(l) == 0 &&
				mf.count(r) == 0){
				fm.insert(l);
				mf.insert(r);
				put = true;
			}
			if (fm.count(l) != 0 && mf.count(r) == 0){
				mf.insert(r);
				put = true;
			}
			if (mf.count(l) != 0 && fm.count(r) == 0){
				fm.insert(r);
				put = true;
			}
			if ((suc&&put==false)||(fm.count(l) != 0 && fm.count(r) != 0) || (mf.count(l) != 0 && mf.count(r) != 0)){
				printf("No\n");
				suc = false;
				//break;
			}
		}
		/*for (; jh <jiaohu-1;++jh){
			int tmp, tmpp;
			scanf("%d%d", &tmp, &tmpp);
		}*/
		if (suc)printf("Yes\n");
	}
	return 0;
}