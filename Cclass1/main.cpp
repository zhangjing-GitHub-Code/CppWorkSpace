#include <iostream>
using namespace std;
class test{
	public:
	int a;
	int b;
	float c;
	test(int inA,int inB,float inC){
		a=inA;
		b=inB;
		c=inC;
	}
	float sum(){
		return (float)a+(float)b+c;
	}
};
int main(){
	test a(1,2,3.5);
	cout << a.sum() << endl;
	return 0;
	//a.test(2,1,2.3);
}
