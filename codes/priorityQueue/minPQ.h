#include<iostream>
#include<vector>
using namespace std;

class minPQ{

    public :
    vector<int> data;
    int  index;

    minPQ(){
       
       index=0;
    }

    void deletion(vector<int> & v ){
        swap(v[0],v[v.size()-1]);

        
    }

    void heapify(vector<int> & v,int i){
     
        bool s =false;
        int pi = (i-1)/2;

        if(pi>=0 && v[pi] > v[i]){
            swap(v[pi],v[i]);
            s=true;
        }

        if(s)
        heapify(v,pi);

        return;
    }

    void insert(int d){
        data.push_back(d);
        heapify(data,index);
        index++;
    }

    int  remove(){

        if(isempty()) return -1;
        int n  = data.size();
        data[0]=data[n-1];
        int pi=0;
        data.pop_back();
        int lc =2*pi+1;
        int rc  = 2*pi+2;
        int mi;
        while(lc < n){
          mi=pi;
          if(data[mi] > data[lc]) mi=lc;
          if(data[mi] > data[rc]) mi=rc;

          if(mi==pi) break;

          pi=mi;
          lc=2*pi+1;
          rc=2*pi+2;
        }


        
    }

    bool isempty(){
        return data.size()==0;
    }

    int getsize(){
        return data.size();
    }

    int getmin(){
        return data[0];
    }



};






