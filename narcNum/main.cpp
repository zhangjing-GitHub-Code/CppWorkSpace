#include<iostream>
#include<vector>
using namespace std;
int main(){
	int in,cmp;
	vector<int> ans;
	cin >> in;
	for (int i=100;i<1000;i++){
		int tmp=i;
		while (tmp){
			cmp+=(tmp%10)^3;
			tmp /=10;
		}
		if (i == cmp){
			ans.push_back(i);
		}
	}
	for (int i=0;i<ans.size();i++){
		cout << ans[i];
	}
	return 0;
}
