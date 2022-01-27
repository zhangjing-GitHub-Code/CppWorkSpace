#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
  int n,idxy=0,idxo=0,old[40],you[40];
  string ido[80],idy[80];//young!!!
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    int tmp;
	string idtmp;
	cin>>idtmp>>tmp;
    if (tmp>=60){
      old[idxo]=tmp;
	  ido[idxo]=idtmp;
      idxo++;
    }else{
      you[idxy]=tmp;
	  idy[idxy]=idtmp;
	  idxy++;
    }
  }
  for (int i=0;i<idxo;i++){
    for (int j=0;j<idxo-i-1;j++){
      if (old[j]<old[j+1]){
        swap(old[j],old[j+1]);
		swap(ido[j],ido[j+1]);
      }
    }
  }
  for (int i=0;i<idxo;i++){
    cout<<ido[i]<<"\n";
  }
  for (int i=0;i<idxy;i++){
    cout<<idy[i];
    if (i<idxy)printf("\n");
  }
  return 0;
}
