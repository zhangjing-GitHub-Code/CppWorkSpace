#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct edge{
	int u,v;
};
bool ved[114514]={false};
vector<edge> co[114514];
void DFS(int i){
	ved[i]=true;
	for(int j=0;j<co[i].size();++j){
		if(!ved[co[i][j].v])DFS(co[i][j].v);
	}
}
int main(){
	int a,b,ccom,to,cnt=0;
	cin >> a >> b;
	cin >> ccom;
	while(ccom!=0){
		cin >> to;
		co[ccom].push_back((edge){ccom,to});
		co[to].push_back((edge){to,ccom});
		cin >> ccom;
	}
	for(int i=1;i<=a;i++){
		if(!ved[i]){
			DFS(i);
			cnt++;
		}
	}
	cout << cnt-1 << endl;
	return 0;
}
