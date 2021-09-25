#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector <int> insertsort(vector <int> in){
	for (int i=0;i<in.size();i++){
		for (int j=i;j>=0;j--){
			if ((in[j]<=in[i]||j==0)&&in[j+1]>=in[i]){
				//cout << "j->"<<j;
				in.insert(in.begin()+j,in[i]);
				in.erase(in.begin()+i+1);
				break;
			}
		}
	}
	return in;
}
int main(){
	vector <int> wdnmd;
	for (int i=9;i>=0;i--){
		wdnmd.push_back(i);
	}
	//for(int i=0;i<wdnmd.size();i++)cout<<wdnmd[i]<<",";
	wdnmd=insertsort(wdnmd);
	for(int i=0;i<wdnmd.size();i++)cout<<wdnmd[i]<<",";

}
