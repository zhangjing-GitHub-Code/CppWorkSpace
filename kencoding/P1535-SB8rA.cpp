#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,smap[1001][1001],fmap[1001][1001],ans;
int main(){
    memset(smap,0x1F1F1F,sizeof(smap));
    memset(fmap,0x1F1F1F,sizeof(fmap));
    ans=0x1F1F1F;
    scanf("%d%d",&n,&m);
	for (int a=1;a<=m;a++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(fmap[u][v]>w)fmap[u][v]=w;
		if(smap[u][v]>w)smap[u][v]=w;
		if(fmap[v][u]>w)fmap[v][u]=w;
		if(smap[v][u]>w)smap[v][u]=w;
	}
    for (int a=1;a<=n;a++){
      for (int b=1;b<a;b++) //环的长度定义为一个点到另一个点的、两个不同道路的长度之和。
        for (int c=b+1;c<a;c++) //本算法将自环排除在外。
          if (ans>smap[b][c]+fmap[c][a]+fmap[a][b])
            ans=smap[b][c]+fmap[c][a]+fmap[a][b]; // [(c --> a --> b)+(b --> c)の最短路] 即为 b 与 c 的最小环。
      for (int b=1;b<=n;b++)
        for (int c=1;c<=n;c++)
          if (smap[b][a]+smap[a][c]<smap[b][c])
            smap[b][c]=smap[b][a]+smap[a][c]; //顺便利用Floyd算法，进行最短路径的更新。
    }
    printf("%d",ans);
    return 0;
}
