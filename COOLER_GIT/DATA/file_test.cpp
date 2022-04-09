#include<bits/stdc++.h>
using namespace std;
int main(){
	ofstream fin;
	ifstream gin;
	fin.open("C:/Users/slaha/Desktop/lolo.txt");
	gin.open("C:/Users/slaha/Desktop/cp/COOL_GIT/COOLER_GIT/DATA/def.cpp");
	string st;
	while(!gin.eof()){
		getline(gin,st);
		fin<<st<<endl;
	}

		
	gin.close();
	fin.close();
	return 0;
}