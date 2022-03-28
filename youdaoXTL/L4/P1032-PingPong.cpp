#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void decodeGame(char * WL,int mode){
	int i=0;
	int W=0,L=0;
	//printf("Current mode:%d\n",mode);
	while(WL[i]!='E'){
		/*W=0;
		L=0;*/
		//for(;i<strlen(WL);++i){
			if(WL[i]=='W')W++;
			if(WL[i]=='L')L++;
			int cha=W>L?W-L:L-W;
			if((cha>=2&&max(W,L)>=mode)){
				printf("%d:%d\n",W,L);
				//if(WL[i+1]=='E')printf("0:0");
				W=0;
				L=0;
				//break;
			}
			if(WL[i+1]=='E'){
				printf("%d:%d",W,L);
				//break;
			}
		//}
		++i;
	}
	if(WL[0]=='E')cout << "0:0";
	//printf("%d:%d\n",W,L);
}
int main(){
	char s[1945141];
	//cin >> s;
	int i=0;
	while(scanf("%c",&s[i])&&s[i]!='E')i++;
	decodeGame(s,11);
	cout << endl<<endl;;
	decodeGame(s,21);
	//cout << s[i];
	return 0;
}
