// # Reversort

// Reversort is an algorithm to sort a list of distinct integers in increasing order. The algorithm is based on the "Reverse" operation. Each operation reverses the order of elements in a subsequence of the list. The pseudocode of the algorithm is the following:

// Reversort(L):
//     for i = 1 to length(L) - 1
//         j = position with the minimum value in L between i and length(L)
//         Reverse(L[i..j])
// 

//Cost = C
// n-1 < C < n(n+1)/2 -1

#include<bits/stdc++.h>
using namespace std;

int reversort(vector<int> &L){
    int cost=0;
    for(int i=0;i<L.size()-1;i++){
        
        // Find the min element
        int m=*min_element(L.begin()+i,L.end());
        //get index of min
        auto x=find(L.begin(),L.end(),m);
        //reverse 
        reverse(L.begin()+i,x+1);

        cost+=distance(L.begin(),x)-i+1;

    }
    return cost;
}

int main(){
    int n;
    cin>>n;
    vector <int> L;
    
    for(int i =0;i<n;i++){
        int num;
        cin>>num;
        L.push_back(num);
    }

    cout<<"Cost: "<<reversort(L)<<"\n";

    for (int i = 0; i < L.size(); i++) {
        cout << L[i] << " ";
    }
    
}