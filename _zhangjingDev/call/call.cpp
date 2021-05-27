#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
int canCall(int min){
  int ans=0;
  if (min==1) return 1;
  ans += pow(2,min-1);
  ans += canCall(min - 1);
  return ans;
}
int main(){
  int people,ans=0;
  printf("how many people needed to call? ");
  scanf("%d",&people);
  for (int i=1;i<people+1;i++){
	  if (canCall(i)>=people){
		  ans=i;
		  break;
	  }
  }
  cout << ans <<endl;
  return 0;
}
