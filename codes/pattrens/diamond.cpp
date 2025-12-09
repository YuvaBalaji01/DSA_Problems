#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int h=n/2+1;
    for(int i=1;i<=n;i++){
        if(i<=h)
        {
            int s=1;
            while(s<=h-i){
                cout << " ";
                  s++;
            }
            for(int j=1;j<=i*2-1;j++){
               cout<< "*";
             }
        }
        else{
            int s=1;
            while(s<=h-(h*2-i)){
                cout << " ";
                  s++;
            }
            for(int j=1;j<=(h*2-i)*2-1;j++){
               cout<< "*";
             }
        }
        cout << endl;
    }
}