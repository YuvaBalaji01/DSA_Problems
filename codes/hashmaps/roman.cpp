#include<iostream>
#include<map>
using namespace std;

int main(){

    map<int,string> ma;
    int n = 27;
    ma[1000]="M";
    ma[900]="CM";
    ma[500]="D";
    ma[400]="CD";
    ma[100]="C";
    ma[90]="XC";
    ma[50]="L";
    ma[40]="XL";
    ma[10]="X";
    ma[9]="IX";
    ma[5]="V";
    ma[4]="IV";
    ma[1]="I";

    string ans ="";

    map<int,string> :: reverse_iterator it = ma.rbegin();

    while(it!=ma.rend()){

        while(n>=it->first){
      
            ans+=it->second;
            n-=it->first;

        }
        it++;
    }

    cout << ans << endl;
}
