#include<iostream>
#include<climits>
#include<map>
#include<string>
using namespace std;

int lcs(string s1,string s2,map <string ,int> & m){

    if(s1.length()==0 || s2.length()==0) return 0;

    string key = s1+"|"+s2;

    if(m.count(key)>0)  return m[key] ;

    if(s1[0]==s2[0]){
        return 1+lcs(s1.substr(1),s2.substr(1),m);
    }
    
       int  a=lcs(s1.substr(1),s2,m);
        int b= lcs(s1,s2.substr(1),m);
        
        int length=max(a,b);
        
    m[key]=length;

    return length;
}

int main(){

    string s1 = "abcde";
    string s2 = "abcde";

    map<string,int> m;

    int ans = lcs(s1,s2,m);

    cout << ans << endl;
}