/*#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct employee{
	int mID,passTo;
	vector<int> knownIDs;
}emp[214514],empt[214514];
bool ved[114514]={false};
bool foundMyself(employee *tEmp,int num){
	for(int i=1;i<=num;++i){
		for(int j=1;j<tEmp[i].knownIDs.size();++j){
			cout<<"if tEmp[i].knownIDs[j] ("<<tEmp[i].knownIDs[j]<< ") == i(" << i << ")" << endl;
			if(tEmp[i].knownIDs[j]==i)return true;
		}
	}
	return false;
}
int main(){
	int n,cnt=1;
	cin >> n;
	for(int i=1;i<=n;++i){
		emp[i].mID=i;
		int pto;
		cin >> pto;
		empt[i].passTo=pto;
		emp[i].passTo=pto;
		empt[i].knownIDs.push_back(i);
		emp[i].knownIDs.push_back(i);
		empt[i].mID=i;
	}
	cout << "now Calculating" << endl;
	while(true){
		for(int i=1;i<=n;++i){
			for(int j=0;j<emp[i].knownIDs.size();++j){
				empt[emp[i].passTo].knownIDs.push_back(emp[i].knownIDs[j]);
				cout << "pushed " << emp[i].knownIDs[j] << " -> empt:" <<emp[i].passTo<<endl;
			}
		}
		if(foundMyself(empt,n))break;
		cnt++;
		for(int i=1;i<=n;++i)emp[i]=empt[i];
	}
	cout << cnt << endl;
	return 0;
}*/
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct employee{
	int mID,passTo;
	vector<int> knownIDs;
}emp[214514],empt[214514];
bool ved[114514]={false};
bool foundMyself(employee *tEmp,int num){
	for(int i=1;i<=num;++i){
		for(int j=1;j<tEmp[i].knownIDs.size();++j){
			if(tEmp[i].knownIDs[j]==i)return true;
		}
	}
	return false;
}
int main(){
	int n,cnt=1;
	cin >> n;
	for(int i=1;i<=n;++i){
		emp[i].mID=i;
		int pto;
		cin >> pto;
		empt[i].passTo=pto;
		emp[i].passTo=pto;
		empt[i].knownIDs.push_back(i);
		emp[i].knownIDs.push_back(i);
		empt[i].mID=i;
	}
	while(true){
		for(int i=1;i<=n;++i){
			for(int j=0;j<emp[i].knownIDs.size();++j){
				empt[emp[i].passTo].knownIDs.push_back(emp[i].knownIDs[j]);
			}
		}
		if(foundMyself(empt,n))break;
		cnt++;
		for(int i=1;i<=n;++i)emp[i]=empt[i];
	}
	cout << cnt << endl;
	return 0;
}

