#include<iostream>
#include<string>
using namespace std;

int editdistance_dp(string s1,string s2,int ** op){

    int n = s1.length()+1;
    int m = s2.length()+1;

    for(int i=0;i<m;i++){
        op[0][i]=i;
    }

    for(int i=1;i<n;i++){
        op[i][0]=i;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
           if(s1[i-1] == s2[j-1]) {
            op[i][j] = op[i-1][j-1]; // characters match, no cost
        } else {
            op[i][j] = 1 + min(op[i-1][j-1], min(op[i-1][j], op[i][j-1]));
        }
        }
    }

    return op[n-1][m-1];
}

int editdistance(string s1,string s2){

    if(s1.length()==0 || s2.length()==0){
        if(s1.length()==0) return s2.length();
        else return s1.length();
    }

    if(s1[0]==s2[0]) return editdistance(s1.substr(1),s2.substr(1));

    int deletion = 1+editdistance(s1,s2.substr(1));
    int insertion = 1+editdistance(s1.substr(1),s2);
    int replace  = 1+editdistance(s1.substr(1),s2.substr(1));

    int ans = min(deletion,min(insertion,replace));

    return ans ;
}

int main(){
    string s1 = "xyz";
    string s2 = "xab";

    int ** op = new int*[4];
    for(int i=0;i<4;i++){
        op[i]=new int[4];
    }

    cout << editdistance(s1,s2) << endl ;

    cout << editdistance_dp(s1,s2,op) << endl;

    
}