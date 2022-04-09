#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define fileio freopen("OUTPUT.txt","w",stdout); freopen("INPUT.txt","r",stdin);
#define ll long long
#define dou double
#define fastio cin.tie(0);
string operations[]={"Open - o O","New - n N [ n file_name file_info]","Info - i I","Delete - d D","Edit_info - c C","Exit - e E"};

class fifi{
    
public:
    string path;
    string info;
    string code;
    fifi(string pt,string nf){
        path=pt;
        info=nf;
        code=getfilename();

    }
    void print(){
        cout<<path<<"  satyam loda    "<<info<<endl;
    }
    string getpath(){
        return path;
    }
    string getinfo(){
        return info;
    }
    string getfilename(){
        string name;
        int i=path.length()-6;
        while(path[i]!='/'){
          name.push_back(path[i]);
          i--;
        }
        reverse(name.begin(),name.end());

        return name;
    }
};
int main(){
    string path="C:/Users/slaha/Desktop/cp/COOL_GIT/COOLER_GIT/main.txt";
    cout<<"-+-+-+-+-+-+-+ WELCOME TO COOL GIT +-+-+-+-+-+-+-"<<endl<<endl;

    fifi* obj=new fifi("C:/Users/slaha/Desktop/cp/COOL_GIT/COOLER_GIT/DATA\66.cpp")

    cin.sync();
    cin.get();
    return 0;
}