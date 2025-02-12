// https://codeforces.com/problemset/problem/626/E

// Faild test cases


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//Defining global Variables
int n; vector <int> v;vector<long long>ps;

//Helper Function to calculate mean
// m - index of median. k-no of elements
double MeanFromMedian(int m, int k) {
    if (k==0){
        return v[m];
    }
    double sum;
    sum = (ps[m-1] - ps[m-k-1]) + v[m] + (ps[n-1] - ps[n-k-1]);
    return (sum) / ((2 * k) + 1);
}

int main(){

    //Getting Inputs
    cin>>n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    //Sort the given array
    sort(v.begin(), v.end());
    
    //Prefix Sum for Fast Calculation
    ps.push_back(v[0]);
    for (int i=1;i<n;i++){
        ps.push_back(ps.back()+v[i]);
    }

    //Answering Variables for Max values for Simple Skewness
    double MaxSkew=-1; int indexOfMedian; int ElementsToAdd;

    //Main Loop for each median
    for (int median=0;median<n;median++){
        
        int range=min(median,n-median-1);
        
        int L=0; int R=range;        
        int mid=(L+R)/2;
        double currMean;
        //Binary Search for finding no of elements each side of median
        while(L<R){
            currMean=MeanFromMedian(median,mid);
            
            //Check to increase or decrease
            int k=mid+1;
            int a=v[n-k];
            int b=v[median-k];

            if (double((a+b)/2)>currMean){// Increase
                L=min(mid+1,R);
            }else{  //Not Increase
                R=max(mid,L);
            }

            mid=(L+R)/2;
        }

        double currSkew=MeanFromMedian(median,mid)-v[median];
        if (currSkew>MaxSkew){
            MaxSkew=currSkew;
            indexOfMedian=median;
            ElementsToAdd=mid;
        }
    }

    //Print Result
    int count=(ElementsToAdd*2)+1;
    cout<<count<<"\n";
    for (int i=0;i<ElementsToAdd;i++){
        cout<<v[indexOfMedian-i]<<" ";
    }
    cout<<v[indexOfMedian]<<" ";
    for (int i=0;i<ElementsToAdd;i++){
        cout<<v[n-i-1]<<" ";
    }
}