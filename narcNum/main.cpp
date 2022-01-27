<<<<<<< HEAD
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
			cmp+=(tmp%10)*(tmp%10)*(tmp%10);
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
=======
#include<iostream>
#include<vector>
using namespace std;
int main(){
	int in,cmp;
	vector<int> ans;
	//cin >> in;
	for (int i=100;i<1000;i++){
		int tmp=i;
		while (tmp){
			cmp+=(tmp%10)*(tmp%10)*(tmp%10);
			tmp /=10;
		}
		if (i == cmp){
			ans.push_back(i);
		}
	}
	for (int i=0;i<ans.size();i++){
		cout << ans[i] << endl;
	}
	return 0;
}
>>>>>>> 13e0d893c11c89b707fd9ebb36f2177ba21f52f5
