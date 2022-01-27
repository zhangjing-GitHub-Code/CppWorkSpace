#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct chip{
	int c,u;
	vector<int> knownIDs;
}nodes[114514];
struct edge{
	int u,v,w;
};
vector<int> outChips;
vector<edge> chips[114514];
bool ved[114514]={false};
int main(){
	int n,l,cnt=1;
	cin >> n >> l;
	for(int i=1;i<=n;++i){
		cin >> nodes[i].c >> nodes[i].u;
	}
	for(int i=1;i<=l;++i){
		int u,v,w;
		cin >> u >> v >> w;
		chips[u].push_back((edge){u,v,w});
	}
	for(int i=1;i<=n;++i){
		if(chips[i].size()==0)outChips.push_back(i);
	}
	for(int i=1;i<=n;++i){
		bool change=false;
		for(int j=1;j<=l;++j){
			for(int k=0;k<chips[j].size();++k){
				if(chips[j].empty()||nodes[j].c-nodes[j].u<=0)break;
				change=true;
			//printf("nodes[chips[%d][%d].v(%d)].c->",j,k,chips[j][k].v);
			//cout <<nodes[chips[j][k].v].c<<";chips[j][k].w*nodes[j].c>"<<chips[j][k].w*nodes[j].c<<";nodes[chips[j][k].v].u->"<<nodes[chips[j][k].v].u<<endl;
				nodes[chips[j][k].v].c+=chips[j][k].w*(nodes[j].c-nodes[j].u);//-nodes[chips[j][k].v].u;
			//printf("now nodes[chips[%d][%d].v].c is ->",j,k);
			//cout <<nodes[chips[j][k].v].c<<endl;
				chips[j].erase(chips[j].begin()+k);
			}
		}
		if(!change)break;
	}
	for(int i=0;i<outChips.size();++i){
		printf("%d %d\n",outChips[i],nodes[outChips[i]].c-nodes[outChips[i]].u);
	}
	if(outChips.size()==0)cout << "NULL" << endl;
	return 0;
}
