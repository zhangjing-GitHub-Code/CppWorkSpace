#include<iostream>
#include<cstdio>
#include<algorithm>
#define ri register int
using namespace std;
int stack[114514],top=0;
void OutStack(int top){
    int tmp=top;
    printf("The Stack is now: ");
    while(top>0){
        printf("%d ",stack[top--]);
    }
    printf("\n");
}
int main(){
    int n,k;
    char op;
    scanf("%d",&n);
    while(n--){
        scanf("\n%c %d",&op,&k);
        if(op=='B'){
            top=top>=k?top-k:0;
        }else{
            for(ri i=0;i<k;++i){
                int tmp;
                scanf("%d",&tmp);
                stack[++top]=tmp;
            }
        }
        //printf("top is %d;",top);
        //OutStack(top);
    }
    while(top){
        printf("%d ",stack[top--]);
    }
    return 0;
}
