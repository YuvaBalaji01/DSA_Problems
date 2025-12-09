#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<n*2;j++){
            if(j==n)
            cout << i;
            else if  (j<n){
                if(j+i>n)
                cout << j+i-n;
                else
                cout << " ";
            }
            else {
                if((n*2)-j+i>n)
                cout << ((n*2)-j+i)-n;
                else
                cout << " ";
            }
            
            
        }
        cout << endl;
    }
}