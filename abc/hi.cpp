#include<iostream>
#include<vector>
#include<string>
using namespace std;

void substrs(string  x,string cs,vector<string> & v){

  if(x[0]=='\0'){
   v.push_back(cs);
   //cout << cs << endl;
    return ;
  }

  substrs(x.substr(1),cs+x[0],v);
  substrs(x.substr(1),cs,v);

  return ;
}

int main(){

  string x ="abc";
  vector<string> v;

  substrs(x,"",v);

   for(int i=0;i<v.size();i++){
    cout << v[i] << endl;
   }
}