#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int cnt=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=i+i-1;j++){
            cout << cnt;
            cnt++;
        }
        cout << endl;
    }
}