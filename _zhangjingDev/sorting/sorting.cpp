#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

struct pos{
	int _x;
	int _y;
};
vector<pos> _dataList;
bool compareInt(int fir,int sec){
	return fir < sec;
}
bool comparePos(pos one,pos two){
	int one_sum=one._x+one._y;
	int two_sum=two._x+two._y;
	return one_sum < two_sum;
	}
void displayList(vector<pos> list){
	for (int i=0;i<list.size();i++){
		cout << list[i]._x << "," << list[i]._y << ";";
	}
}
void sortList(vector<pos> list){
	for (int i=0;i<list.size();i++){
		sort(_dataList.begin(),_dataList.end(),comparePos);
	}
}
void loadIn(){
	pos solo;
	int curInt;
	ifstream inFile("sorting.in");

	while (inFile >> curInt){
		solo._x=curInt;
		inFile >> curInt;
		solo._y=curInt;
		_dataList.push_back(solo);
	}
	inFile.close();
}
void Core(){
	sortList(_dataList);
	//sort(_dataList.begin(),_dataList.end(),comparePos);
}
void showOut(){
	displayList(_dataList);
	cout << endl;
}
void WriteOut(){
	ofstream outFile("sorting.out");
	for (int i=0;i<_dataList.size();i++){
		outFile << _dataList[i]._x << "," << _dataList[i]._y << ";";
	}
	outFile << endl;
}
int main(){
	loadIn();
	Core();
	showOut();
	WriteOut();
	return 0;
}
