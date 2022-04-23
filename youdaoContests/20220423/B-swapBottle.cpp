#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    long long n,k;
    cin >> n >> k;
    long long drinked=0,tmpbottle=0;
    while(n!=0){
        drinked+=n;
        n+=tmpbottle;
        tmpbottle=n%k;
        n=n/k;
    }
    printf("%d\n",drinked);
    return 0;
}
