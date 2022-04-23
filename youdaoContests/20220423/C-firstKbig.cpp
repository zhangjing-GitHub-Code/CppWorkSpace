#include<iostream>
#include<cstdio>
#include<algorithm>
#define ri register int
using namespace std;
int main(){
    long long n,k,a[114514];
    scanf("%d%d",&n,&k);
    for(ri i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    printf("%d\n",a[n-k]);
    return 0;
}
