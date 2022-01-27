#include<cstdio>
#include<cstring>
int main(){
	char a[15][25];
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]);
		int L=strlen(a[i]);
		int flag = 0;
		if(a[i][0]<'A'|a[i][0]>'Z'){
			flag=1;
			continue;
		}else{
			for(int j=1;j<L;j++){
				if(a[i][j]<'a'|a[i][j]>'z'){
					flag=1;
					break;
				}
			}
		}
		if (!flag)  cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
