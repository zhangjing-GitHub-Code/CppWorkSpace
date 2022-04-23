#include<iostream>
#include<cstdio>
#define ri register int
using namespace std;
int main(){
    int nmini,n;
    double nmin=1145141.9;
    scanf("%d",&n);
    for(ri i=1;i<=n;++i){
        int per,cost;
        scanf("%d%d",&per,&cost);
        double ratio=(double)per/cost;
        if (ratio<nmin){
            nmini=i;
            nmin=ratio;
        }
    }
    printf("%d\n",nmini);
    return 0;
}
