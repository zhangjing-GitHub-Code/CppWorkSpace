#include <cstdio>
#include<cstring>
#include <iostream>
using namespace std;
int main(){
  int charcnt[128],namx=-1,nmax=-1;
  char all[325];
  for (int i='A';i<='Z';i++)charcnt[i]=0;
  for (int i=0;i<4;i++){                    //concatenate four lines to one string
    char tmp[85];
    cin.getline(tmp,81);
    strcat(all,tmp);
  }
  for (int i=0;i<strlen(all);i++){
    if (all[i]>='A'&&all[i]<='Z'){
      charcnt[all[i]]++;                            // count `uppercase`
      if (namx<charcnt[all[i]])namx=charcnt[all[i]];
    }else if (all[i]>='a'&&all[i]<='z'){
      charcnt[all[i]-32]++;                         // count `lowercase`
      if (nmax<charcnt[all[i]-32])nmax=charcnt[all[i]-32];
    }
  }
  namx=namx>nmax?namx:nmax;    //choose bigger value between `uppercase` and `lowercase` letters
  for (int i=namx;i>0;i--){
    for (int j='A';j<='Z';j++){
      if ((charcnt[j]-i)>=0){
        printf("* ");
      }else{
        printf("  ");
      }
    }
    printf("\n");
  }
  printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n"); 
  return 0; 
}