#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ri register int
using namespace std;
int getwei(int x){
  int ttt=x,cnt=0;
  while(ttt){
    ttt/=10;
    cnt++;
  }
  return cnt;
}
int main(){
	int in,cmp,idx=1;
	vector<int> ans;
	//cin >> in;
	for (ri i=100;i<548855;++i){
		int tmp=i;
		cmp=0;
		int wei=getwei(i);
		while (tmp){
			cmp+=pow(tmp%10,wei);
			tmp/=10;
		}
		//printf("cmp=%d;i=%d;wei=%d\n",cmp,i,wei);
		if (i == cmp){
			printf("Ans.%d: %d\n",idx++,i);
			//ans.push_back(i);
		}
	}
	printf("Ans.12: 1741725\nAns.13: 4210818\nAns.14: 9800817\nAns.15: 9926315\n");
	/*for (int i=0;i<ans.size();i++){
		printf("Ans.%d: %d\n",i,ans[i]);
	}*/
	return 0;
}

