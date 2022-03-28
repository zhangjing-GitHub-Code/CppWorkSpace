#include<iostream>
#include<cstdio>
#define CAN_AABDD a>1&&b>0&&d>1
#define DEL_AABDD a-=2;b--;d-=2
#define CAN_ABCD a>0&&b>0&&c>0&&d>0
#define DEL_ABCD a--;b--;c--;d--
#define CAN_CCD c>1&&d>0
#define DEL_CCD c-=2;d--
#define CAN_BBB b>2
#define DEL_BBB b-=3
#define CAN_AD a>0&&d>0
#define DEL_AD a--;d--
using namespace std;
int main(){/*{{{*/
    int a,b,c,d,mk1,mk2,mk3,mk4,mk5;
    mk1=mk2=mk3=mk4=mk5=0;
    cin >> a >> b >> c >> d;
    for(int i=0;i<31;i++){
        if(CAN_AABDD){
            mk1++;
            DEL_AABDD;
            continue;
        }
        if(CAN_ABCD){
            mk2++;
            DEL_ABCD;
            continue;
        }
        if(CAN_CCD){
            mk3++;
            DEL_CCD;
            continue;
        }
        if(CAN_BBB){
            mk4++;
            DEL_BBB;
            continue;
        }
        if(CAN_AD){
            mk5++;
            DEL_AD;
            continue;
        }
    }
    cout << mk1 << endl << mk2 << endl << mk3 << endl << mk4 << endl << mk5;
}/*}}}*/
