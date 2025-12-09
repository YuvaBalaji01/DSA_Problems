#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

int closestcost(vector<int> Base , vector<int> toppings ,int k){

    int ans = INT_MAX;
    int n = Base.size();
    int m = toppings.size();

    for(int i=0;i<n;i++){

       

        int totalcombinations = pow(3,m);

        for(int t=0; t<=totalcombinations;t++){
            int cost = Base[i];
            int temp  =t;
            
            for(int j=0;j<m;j++){
                int times = temp%3;
                temp/=3;
                cost+=times*toppings[j];
            }

            int diff1 = abs(ans-k);
            int diff2 = abs(cost-k);

            if(diff2<diff1 || (diff1==diff2 && cost<ans)) ans=cost;
        }


    }

    return ans;
}


int main(){

    vector<int> Base;
    vector<int> Toppings;

    Base.push_back(2);
   

    Toppings.push_back(2);
    

    int ans  = closestcost(Base,Toppings,7);

    cout << ans << endl;


}