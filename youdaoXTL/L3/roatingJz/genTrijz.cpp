#include <iostream>
int main(){
    int a[20][20]={0},b[5][5]={{1,0},{0,1},{-1,-1}},c[5][5]={{-1,0},{0,-1},{1,1}},d=0,n,cnt=0,x1=1,y1=1;
    scanf("%d",&n);
    int x2=n,y2=n+1;
    while (cnt < n * (n+1)){
        cnt++;
        a[x1][y1]=cnt;
        if (x1+b[d][0]<1||x1+b[d][0]>n||y1+b[d][1]<1||y1+b[d][1]>n||a[x1+b[d][0]][y1+b[d][1]]){
            d=(d+1)%3;
        }
        x1+=b[d][0];
        y1+=b[d][1];
        cnt++;
        a[x2][y2]=cnt;
        x2+=c[d][0];
        y2+=c[d][1];
        /*for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                printf("%3d",a[i][j]);
            }
            printf("\n");
        }*/
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n+1;j++){
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
}
