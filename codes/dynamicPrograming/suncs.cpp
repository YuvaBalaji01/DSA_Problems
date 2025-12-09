#include<iostream>
#include<string>
using namespace std;

int suncs(string s,string v,int i,int j,int ** op){

    if(i==s.length()) return 1000;
    if(j==v.length()) return 1;

    if(op[i][j]!=-1) return op[i][j];

    int op1 = suncs(s,v,i+1,j,op);

    int k=j;
    while(k<v.length() && v[k]!=s[i]) k++;

    int op2;
    if(k==v.length()) op2=1;
    else op2 = 1+suncs(s,v,i+1,k+1,op);

    return op[i][j] = min(op1,op2);
}

int main(){

    string s;
    string v;
    cin >> s >> v;

    int** op = new int*[s.length()+1];

    for(int i=0;i<=s.length();i++){
        op[i] = new int[v.length()+1];
    }

    for(int i=0;i<=s.length();i++){
        for(int j=0;j<=v.length();j++){
            op[i][j]=-1;
        }
    }

    int ans = suncs(s,v,0,0,op);

    cout << ans << endl;

    for(int i=0;i<=s.length();i++) 
    delete [] op[i];

    delete [] op;
}