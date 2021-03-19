#include<iostream>
using namespace std;
void qingju(){
	//jsd 加速度
	for (float jsd=0.1;jsd<=40;jsd=jsd+0.1){
		for (float yang=0.1;yang<=10;yang=yang+0.1){
			if (((jsd+yang)*25)/75+jsd==yang){
				cout <<"yang:"<<yang;
				cout <<";jsd:"<<jsd;
				cout <<";ans:"<<(jsd+yang)*25/yang<<endl;
			}
		}
	}
}
int main(){
	qingju();
	return 0;
}
