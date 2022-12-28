#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define fileio freopen("OUTPUT.txt","w",stdout); freopen("INPUT.txt","r",stdin);
#define ll long long
#define dou double
#define fastio cin.tie(0);
string operations[]={"Open - o O","New - n N [ n file_name file_info]","Info - i I","Delete - d D","Edit_info - c C[c file_name new_info]" ,"Exit - e E"};



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
    void s_info(string inn){
        info = inn;
        return;
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
        int i=path.length()-5;
        while(path[i]!='/'){
          name.push_back(path[i]);
          i--;
        }
        reverse(name.begin(),name.end());

        return name;
    }
};
fifi* getobjectpointer(string cd,vector<fifi*> &list){
    for(auto i: list ){
        if(i->code==cd){
            return i;
        }
    }
}
void showmenu(vector<fifi*> &list){

    cout<<endl<<endl<<"LIST OF FILES"<<setw(38)<<"OPERATIONS"<<endl;
    int vidx=0;
    int oidx=0;
    while(oidx<6){
        string fn="";
        if(vidx<list.size()){
            fn=list[vidx]->getfilename();
            cout<<"code ";
        }
        cout<<fn;
        int spaces;
        if(fn.empty()){
            spaces=41;
        }
        else{spaces=36-fn.length();} 
        for(int i=0;i<spaces;i++){
            cout<<" ";
        }
        cout<<operations[oidx]<<endl;
        oidx++;
        vidx++;
    }
    while(vidx<list.size()){
        cout<<"code ";
        cout<<list[vidx]->getfilename()<<endl;
        vidx++;
    }
    cout<<endl;
    cout<<"--------Enter Query in format [operation_char file_code]---------"<<endl;

   
    return;

}

string getfileinfo(string line){
    bool flag=false;
    int len=line.length();
    string nf;
    for(int i=0;i<len;i++){                                                             
        if(line[i]=='%'){
            if(line[i+1]=='$'){
                if(line[i+2]=='#'){
                    if(line[i+3]=='!'){
                        if(line[i+4]=='@'){
                            flag=true;
                            i+=4;
                            continue;
                        }
                    }
                }
            }
        }
         if (flag){
        nf.push_back(line[i]);
    }
    }
   
    return nf;

}



string getfilepath(string line){
    

    int len=line.length();
    string pt;
    for(int i=0;i<len;i++){                                                             
        if(line[i]=='%'){
            if(line[i+1]=='$'){
                if(line[i+2]=='#'){
                    if(line[i+3]=='!'){
                        if(line[i+4]=='@'){
                            break;
                        }
                    }
                }
            }
        }

     pt.push_back(line[i]);

    }
    return pt;
}


bool getquery(vector<fifi*> &list){

    string code;
    char ch;
    cin>>ch;
    if(ch=='e'||ch=='E'){
        cout<<"BYE BYE <3 "<<endl;
        return false;
    }//new
    else if(ch=='n'||ch=='N'){
            
            string nm;
            cin>>nm;
            string nfo;
            string tptp;
            getline(cin,nfo);
            string ptt="C:/Users/slaha/Desktop/COOL_GIT/DATA/"+nm+".cpp";
            list.push_back(new fifi(ptt,nfo));
            ofstream fin;
            ifstream gin;
            gin.open("C:/Users/slaha/Desktop/COOL_GIT/DATA/def.cpp");
            fin.open(ptt);
            while(!gin.eof()){
             getline(gin,tptp);
             fin<<tptp<<endl;
             }
            fin.close();
            cout<<"FILE CREATED !"<<endl;
    }
    //info
    else if(ch=='i'||ch=='I'){
        cin>>code;
        fifi* current_object=getobjectpointer(code,list);
        cout<<current_object->getinfo()<<endl;
    }//open
    else if(ch=='o'||ch=='O'){
        cin>>code;
        fifi* current_object=getobjectpointer(code,list);
        string sisi=current_object->getpath();
        char ch[100];
        int i;
        for( i=0;i<sisi.length();i++){
            ch[i]=sisi[i];
        }
        ch[i]='\0';
        system(ch);
        cout<<"File opened !!!"<<endl;

    }
    //CHANGE INFO
    else if(ch=='c'||ch=='C'){
        cin>>code;
        fifi* temp=getobjectpointer(code,list);

        string innnn;
        getline(cin,innnn);
        temp->s_info(innnn);
        cout<<"INFO UPDATED !"<<endl;
    }
    //delete
    else if(ch=='d'||ch=='D'){
        cin>>code;
        fifi* temp=getobjectpointer(code,list);
        string ss="del \""+temp->getpath()+"\"";
        
        char ch[100];
        int i;
        for( i=0;i<ss.length();i++){
            if(ss[i]=='/'){
                ch[i]='\\';
                continue;
            }
            else{ch[i]=ss[i];}
        }
        ch[i]='\0';
       
        system(ch);
        for(int i=0;i<list.size();i++){
            if(list[i]==temp){
            list.erase (list.begin()+i);
                break;
            }
        }
        cout<<"File deleted !!!"<<endl;

    }
    
   
    return true;

    
    
}
void initialise_vec_from_file(vector<fifi*> &list,string path){

        
        string line;
        ifstream fin(path);

        while(!fin.eof()){
        getline(fin,line);
        string pt,nf;

        pt=getfilepath(line);
    
        nf=getfileinfo(line);
        
        if(nf!=""&&pt!=""){
            list.push_back(new fifi(pt,nf));
        }
        
        }
        fin.close();
    
}
void update_file_from_vector(vector<fifi*> &list,string path){
    string line;
    ofstream fout;
    fout.open(path,ofstream::out | ofstream::trunc);
    for(int i=0;i<list.size();i++){
        string pt=list[i]->getpath();
        string nf=list[i]->getinfo();
        line=pt+"%$#!@"+nf;
        fout<<line<<endl;
        }

        fout.close();

}
int main(){
    /*fileio;*/
    string path="data.bin";
    cout<<"-+-+-+-+-+-+-+ WELCOME TO COOL GIT +-+-+-+-+-+-+-"<<endl<<endl;
    
    vector<fifi*> list;
    initialise_vec_from_file(list,path);
    

   
    while(1){
    showmenu(list);
    update_file_from_vector(list,path);
    if(!getquery(list)){
        break;
    }
    }
    
    


    


    cin.sync();
    cin.get();

   
    return 0;
} 



/*
at the starting of code execution

1->read for strings from file
2->use each string to create an object 
3->store these objects in a list
initialization completed
4-> show menu

execute the operations

finalizing or while closing of program
5-> update file from list of objects
end



*/