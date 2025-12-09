#include<iostream>
#include<string>
using namespace std;

string substrs(string s){
    
    string ans  = "";
    int n = s.length();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string cs  = s.substr(i,j-i+1);
            int x=0;
            int y=cs.length()-1;
            bool flag =true;
            while(x<=y){
              
                if(cs[x++]!=cs[y--]) {flag = false; break;}
            }

            if(flag && ans.length()<cs.length()) ans = cs;
        }
    }

    return ans;
}

int main(){

    string s ="babad";
    cout << substrs(s);
}