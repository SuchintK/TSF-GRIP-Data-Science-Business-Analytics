#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
int* parent;    
int* rank;
    public:

DisjointSet(int n){
    parent= new int[n];
    rank= new int[n];
    for (int i=0; i<n; i++){
        parent[i]=i;
        rank[i]=1;
    }
}

    int Parent_Optimized1(int n){
    if (parent[n]==n)   return n;
    return parent[n]=Parent_Optimized1(parent[n]);
    }

    void UnionRankOptimized(int a, int b){
    int parent_a= Parent(a);
    int parent_b= Parent(b);
    if (rank[parent_a]>rank[parent_b])  parent[parent_b]= parent_a;
    else if (rank[parent_b]>rank[parent_a]) parent[parent_a]= parent_b;
    else{
    rank[parent_a]++;
    parent[parent_b]= parent_a;
    }
    }

    int Parent(int i){
    if (parent[i]==i)   return i;
    return Parent(parent[i]);
    }

    void Union(int a, int b){
        int parent_a= Parent(a);
        int parent_b= Parent(b);
        if (parent_a==parent_b) return;
        parent[parent_a]=parent_b;
    }

    bool FindIfSameGroup(int a, int b){
    return Parent(a)==Parent(b);
    }

};

int main(){
DisjointSet Djs(5);
Djs.UnionRankOptimized(0,2);
Djs.UnionRankOptimized(2,4);
Djs.UnionRankOptimized(3,1);
cout<<Djs.FindIfSameGroup(4,0)<<endl;
cout<<Djs.FindIfSameGroup(1,0)<<endl;
return 0;
}