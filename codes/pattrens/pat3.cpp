#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    char c ='A';
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            c='A'+j;
            cout <<c;
            
        }
        cout << endl;
    }
}