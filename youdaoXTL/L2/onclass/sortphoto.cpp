#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
  int n,idxm=0,idxf=0;
  float fm[40],m[40];
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    float tmp;
	string name;
	cin>>name>>tmp;
    //scanf("%s %f",&name,&tmp);
    if ('f'==name[0]){
      fm[idxf]=tmp;
      idxf++;
    }else{
      m[idxm]=tmp;
      idxm++;
    }
  }
  for (int i=0;i<idxm;i++){
    for (int j=0;j<idxm-i-1;j++){
      if (m[j]>m[j+1]){
        swap(m[j],m[j+1]);
      }
    }
  }
  for (int i=0;i<idxf;i++){
    for (int j=0;j<idxf-i-1;j++){
      if (fm[j]<fm[j+1]){
        swap(fm[j],fm[j+1]);
      }
    }
  }
  for (int i=0;i<idxm;i++){
    printf("%.2f ",m[i]);
  }
  for (int i=0;i<idxf;i++){
    printf("%.2f",fm[i]);
    if (i<idxf)printf(" ");
  }
  return 0;
}
