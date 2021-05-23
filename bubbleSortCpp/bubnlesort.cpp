#include<time.h>
#include<stdlib.h>
#include<vector>
#include<cstdio>
#include<iostream>
using namespace std;
vector<int> bubbleSort(vector<int> list){
	for (int j=0;j<list.size()-1;j++){
		for(int i=0;i<list.size()-1-j;i++){
			if (list[i]<list[i+1])swap(list[i],list[i+1]);
		}
	}
	return list;
}
int main(){
	srand((int)time(0));
	vector<int> mylst;
	for (int cnt=0;cnt<21;cnt++){
		mylst.push_back(rand()%15);
	}
	mylst=bubbleSort(mylst);
	for(int c=0;c<mylst.size();c++) cout << mylst[c] <<endl;
}
