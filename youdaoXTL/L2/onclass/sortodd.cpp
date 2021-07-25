#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int N,odd[505],idx=0;
	scanf("%d",&N);
	for (int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		if (tmp%2){
			odd[idx++]=tmp;
		}
	}
	for (int i=0;i<idx;i++){
		bool issw=false;
		for (int j=0;j<idx-i-1;j++){
			if(odd[j]>odd[j+1]){
				issw=true;
				swap(odd[j],odd[j+1]);
			}
		}
		if (!issw)break;
	}
	for (int i=0;i<idx;i++){
		printf("%d",odd[i]);
		if (i<idx-1) printf(",");
	}
}
