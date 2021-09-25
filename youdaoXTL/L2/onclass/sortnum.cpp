#include <cstdio>
#include <iostream>
using namespace std;
int main(){
  int eval[20],idxe=0,idxo=0,odd[20];
  for (int i=0;i<10;i++){
    int tmp;
    scanf("%d",&tmp);
    if (tmp%2==0){
      eval[idxe]=tmp;
      idxe++;
    }else{
      odd[idxo]=tmp;
      idxo++;
    }
  }
  for (int i=0;i<idxo;i++){
    for (int j=0;j<idxo-1;j++){
      if (odd[j]<odd[j+1]){
        swap(odd[j],odd[j+1]);
      }
    }
  }
  for (int i=0;i<idxe;i++){
    for (int j=0;j<idxe-1;j++){
      if (eval[j]>eval[j+1]){
        swap(eval[j],eval[j+1]);
      }
    }
  }
  for (int i=0;i<idxo;i++){
    printf("%d ",odd[i]);
  }
  for (int i=0;i<idxe;i++){
    printf("%d",eval[i]);
    if (i<idxe)printf(" ");
  }
  return 0;
}
