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
bool comparePos(pos fir,pos sec){
	return (fir._x+fir._y) < (sec._x+sec._y);
	}
void displayList(vector<pos> list){
	for (int i=0;i<=list.size();i++){
		cout << list[i]._x << "," << list[i]._y << ";";
	}
}
void sortList(vector<pos> list){
	for (int i=0;i<=list.size();i++){
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
	inFile.close();
	}
}
void Core(){
	sortList
	//sort(_dataList.begin(),_dataList.end(),comparePos);
}
void showOut(){
	displayList(_dataList);
}
int main(){
	loadIn();
	Core();
	showOut();
	return 0;
}
