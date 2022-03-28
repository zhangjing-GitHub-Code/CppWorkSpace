#include <iostream>
int main(){
    freopen("genJz.in","r",stdin);        
    freopen("genJz.out","w",stdout);
    int a[20][20]={0},b[5][5]={{0,1},{1,0},{0,-1},{-1,0}},d=0,n,m,cnt=0,x=1,y=1;
    scanf("%d %d",&n,&m);
    while (cnt < n * m){
        cnt++;
        a[x][y]=cnt;
        if (x+b[d][0]<1||x+b[d][0]>n||y+b[d][1]<1||y+b[d][1]>m||a[x+b[d][0]][y+b[d][1]]){
            d=(d+1)%4;
        }
        x+=b[d][0];
        y+=b[d][1];
        /*for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                printf("%3d",a[i][j]);
            }
            printf("\n");
        }*/
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
}
