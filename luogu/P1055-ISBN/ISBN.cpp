?*That f**ks
#include<iostream>
#include<cstdio>
using namesapce std;
string check(string ISBN){
    string TMP=ISBN;
    int verf=0;
    for(int i=0;i<TMP.size();++i)if(TMP[i]=='-')TMP.erase(TMP.begin()+i);
    for(int i=0;i<TMP.size()-1;++i){
        verf+=(TMP[i]-'0')*(i+1)%11;
    }
    if(verf==(TMP[TMP.size()]-'0'))return (string)"Right";
    else return verf+'0';
}
int main(){
    string ISBN;
    cin >> ISBN;
    string ANS=check(ISBN);
    cout << ANS;
    return 0;
}*/
#include<iostream>
#include<cstdio>
using namespace std;
string check(string ISBN){
    string TMP=ISBN;
    string ans=ISBN;
    ans.erase(ans.end()-1);
    long long verf=0;
    for(int i=0;i<TMP.size();++i)if(TMP[i]=='-')TMP.erase(TMP.begin()+i);
    for(int i=0;i<TMP.size()-1;++i){
        verf+=((TMP[i]-'0')*(i+1));
    }
    if(verf%11==10){
        ans+='X';
    }else{
        ans+=verf%11+'0';
    }
    //cout << ISBN[ISBN.size()-1]-8<<endl;
    if(verf%11==(TMP[TMP.size()-1]-48)||(verf%11==10&&TMP[TMP.size()]=='X')){
        cout<<"Right";
        return "Right";
    }else{
        return ans;
    }
}
int main(){
    string ISBN;
    cin >> ISBN;
    string ANS=check(ISBN);
    if(ANS!="Right")cout<<ANS;
    return 0;
}