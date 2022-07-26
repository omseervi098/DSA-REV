#include<bits/stdc++.h>
using namespace std;
class heap{
    vector<int>pq;
    public:
    void push(int data){
        pq.push_back(data);
        int i=pq.size()-1;
        while(i>0){
            if(pq[i]<pq[(i-1)/2])
                swap(pq[i],pq[(i-1)/2]);
            else
                break;
            i=(i-1)/2;
        }
        
    }
    int pop(){
        int data=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int i=0;
        while(i<pq.size()){
            int l=2*(i)+1;
            int r=2*(i)+2;
            int minidx=i;
            if( l<pq.size() and pq[minidx]>pq[l])
                minidx=l;
            if( r<pq.size() and pq[minidx]>pq[r])
                minidx=r;
                //cout<<pq[minidx]<<endl;
            if(minidx==i) break;
            swap(pq[i],pq[minidx]);
            i=minidx;

        }
        return data;
    }
    int get(){
        if(pq.size()==0) return -1;
        return pq[0];
    }
    int getsize(){
        return pq.size();
    }
};