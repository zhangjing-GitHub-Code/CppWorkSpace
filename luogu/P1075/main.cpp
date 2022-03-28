#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
bool prime[11451419]={true};
int main(){
	ll n;
	cin >> n;
	for(ll i=2;i<=n;++i)prime[i]=true;
	for(ll i=2;i*i<n;++i){
		if (prime[i]==true){
			for(ll j=i*2;j<=n;j+=i)prime[j]=false;
			if(n%i==0){
				cout << n/i;
				return 0;
			}
		}
	}
}
