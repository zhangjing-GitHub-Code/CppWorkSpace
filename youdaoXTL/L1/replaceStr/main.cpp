#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char str[40];
	char a,b;
	scanf("%s %c %c",str,&a,&b);
	int l=strlen(str);
	for (int i=0;i<=l;i++){
		if (str[i]==a){ 
			str[i]=b;
		}
	}
	printf("%s\n",str);
	return 0;
}
