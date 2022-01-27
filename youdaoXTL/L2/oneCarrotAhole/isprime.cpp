#include <cstdio>
#include <iostream>
using namespace std;
int main(){
  int n,isprime[10000];
  cin >> n;
  for (int i=0;i<10000;i++) isprime[i]=0;
  for (int i=2;i<10000;i++) isprime[i]=1;
  for (int i=0;i<10000;i++){
    if (isprime[i]==1){
      for (int j=i*2;j<10000;j=j+i){
        isprime[j]=0;
      }
    }
  }
  if(isprime[n]){
    printf("prime");
    return 0;
  }
  //isprime[i]==1
  cout << "composite";
  return 0;
}