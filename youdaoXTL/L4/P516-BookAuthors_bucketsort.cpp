#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#define ri register int
using namespace std;
struct au{
	vector<int>books;
	int outbookn=0;
} authorstomb[514];
au finala;
int main(){
	int n,no,nmax=-1,nmaxi=0;
	string ats;
	cin >> n;
	for(ri i=0;i<n;++i){
		cin >> no >> ats;
		for(ri yee=0;yee<ats.size();++yee){
			authorstomb[ats[yee]].outbookn++;
			authorstomb[ats[yee]].books.push_back(no);
		}
	}
	for(ri i='A';i<='Z';++i){
		if(nmax<authorstomb[i].outbookn){
			nmax=authorstomb[i].outbookn;
			nmaxi=i;
			finala=authorstomb[i];
		}
	}
	printf("%c\n%d\n",nmaxi,nmax);
	for(ri i=0;i<finala.books.size();++i){
		printf("%d\n",finala.books[i]);
	}
	return 0;
}
