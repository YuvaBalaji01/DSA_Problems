#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class maxPQ{

    vector<int> pq;

    public:

    void insert(int d){
        pq.push_back(d);

        int c=pq.size()-1;
        int p = (c-1)/2;

        while(p>=0){
            if(pq[p]  < pq[c] ) swap(pq[p],pq[c]);
            
            c=p;
            p=(c-1)/2;
        }

    }

    void print(){
        for(int i=0;i<pq.size();i++) cout << pq[i] << " ";
    }
};