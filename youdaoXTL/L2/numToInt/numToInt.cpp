#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
int mi(int num,int mici){
    int res=1;
    for (int i=0;i<mici;i++){
        res*=num;
    }
    return res;
}
int toBin(int dex){
    int stack[100000],top=0;
    int tmp=dex;
    while (tmp>0){
        stack[++top]=tmp%2;
        tmp/=2;
    }
    int res=0;
    while (top>0){
        res=res*10+stack[top--];
    }
    return res;
}
int toDex(int bin){
    int stack[100000],top=0;
    int tmp=bin,cur=1;
    int res=0;
    while (tmp>0){
        res+=tmp%10*mi(2,cur-1);
        tmp/=10;
        cur++;
    }
    return res;
}
//Not suggested:
int toDexStr(string bin){
    string tmp=bin;
    int cur=1;
    int res=0;
    for(int i=tmp.size()-1;i>=0;i--){
        res+=(tmp[i]-'0')*mi(2,cur-1);
        cur++;
    }
    return res;
}
int main(){
    string num;
    printf("enter number: ");
    cin >> num;
    //int a=pow(2,2);
    cout<<toDexStr(num)<<endl;
    return 0;
}
/*#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
    int res=0;
    char num[1000];
    scanf("%s",num);
    //better func
    int quanz=1;
    for (int i=strlen(num)-1;i>=0;i--){
        int tmp=num[i]-'0';
        res+=tmp*quanz;
        quanz*=2;
    }
    printf("%d\n",res);
}*/