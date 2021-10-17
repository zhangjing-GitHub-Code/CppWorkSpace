#include <cstdio>
#include <iostream>
using namespace std;
int main(){
  int n;
  double AviWBC[512],WBC[512],nmax=-1,nmin=10000,sum=0,ave,shake=-1;
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    cin >> WBC[i];
    sum+=WBC[i];
    if (WBC[i]>nmax) nmax=WBC[i];
    if (WBC[i]<nmin) nmin=WBC[i];
  }
  ave=(float)(sum-nmax-nmin)/(n-2);
  int j=0;
  for (int i=0;i<n;i++){
    if (!(WBC[i]==nmax||WBC[i]==nmin)){
      AviWBC[j]=WBC[i];
      j++;
    }
  }
  for (int i=0;i<n-2;i++){
    if (AviWBC[i]<ave){
      if (shake < (ave-AviWBC[i])) shake=ave-AviWBC[i];
  }else{
      if (shake < (AviWBC[i])-ave) shake=AviWBC[i]-ave;
    }
  }
  printf("%.2f %.2f\n",ave,shake);
  return 0;
}