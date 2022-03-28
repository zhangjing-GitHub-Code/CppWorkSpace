#include<cstdio>
#include<iostream>
using namespace std;
void shunsj(int in[105][105],int n,int m){
    int ans[105][105]={0};
    for (int x=1;x<n;x++){
        for (int y=1;y<m;y++){
            ans[y][x]=in[x][y];
            //printf("%3d",ans[x][y]);
        }
        //cout << endl;
    }
    for (int x=1;x<m;x++){
        for (int y=1;y<n;y++){
            //ans[y][x]=in[x][y];
            printf("%3d",ans[x][y]);
        }
        cout << endl;
    }
}
int main(){
    int num[105][105],m,n;
    cin >>m>>n;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cin >> num[i][j];
        }
    }
    shunsj(num,m,n);
    return 0;
}
