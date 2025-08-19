// https://codeforces.com/problemset/problem/722/C

//Bruteforce Approach

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    int order[n];

    //Get array
    for(int i=0;i<n;i++) cin>>arr[i];

    //Get order of distroying
    for(int i=0;i<n;i++){
        cin>>order[i];
        order[i]-=1; //Offset
    } 

    int set[n+1] = {0};
    set[n]=-1;//Set the ending.
    
    //Distroying elements
    for (int d:order){
        set[d]=-1;

        //Get the max sum along different sets
        int maxSum=0;
        int currSum=0;
        for(int i=0;i<n+1;i++){
            
            if (set[i]==-1){
                maxSum=max(currSum,maxSum);
                currSum=0;
                continue;
            }
            
            currSum+=arr[i];
        }
        cout<<maxSum<<endl;
    }

    return 0;
}