#include <cstdio>
#include <iostream>
#include<vector>
using namespace std;
//long long size=11000000000;
//int *isprime=new int[10000000005];
//vector <long long> isprime;
int main(){
  //for (long long i=2;i<100000000;i++) isprime.push_back(i);
  long long n;
  cin >> n;
  static int *isprime=new int[n];
  for (long long i=2;i<n;i++) isprime[i]=1;
  for (long long i=2;i<n;i++){
    if (isprime[i]==1){
      for (long long j=i*2;j<=n;j+=i){
        isprime[j]=0;
      }
    }
  }
  if(isprime[n]){
    printf("prime");
    delete isprime;
    return 0;
  }
  //isprime[i]==1
  cout << "composite";
  delete isprime;
  return 0;
}