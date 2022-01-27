#include <cstdio>
#include <iostream>
using namespace std;
int main(){
  int n,isRep[106],index=0;//num[20052];
  scanf("%d",&n);
  for(int i=10;i<105;i++){
    isRep[i]=0;
  }
  for (int i=0;i<n;i++){
    int in;
    scanf("%d",&in);
    if(isRep[in]==0){
      isRep[in]=1;
      cout << in<<" ";
      ///num[index]=in;
      //index++;
    }
  }
  /*for (int i=0;i<index;i++){
    printf("%d ",num[i]);
  }*/
  cout << endl;
  return 0;
}