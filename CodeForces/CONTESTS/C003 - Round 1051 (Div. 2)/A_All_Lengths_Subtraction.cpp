#include<bits/stdc++.h>
using namespace std;


bool sol(int n, int arr[]){
    int pvs=0;
    bool decreaseStarted=0;
    for (int i=0;i<n;i++){
        if (arr[i]<pvs){
            decreaseStarted=1;
        }
        else if (arr[i]>pvs && decreaseStarted)
        {
            return 0;
        }
        pvs=arr[i];
    }
    return 1;
}

int main(){
    int cases;
    cin>>cases;

    for (int i=0;i<cases;i++){
        int n;
        cin>>n;
        int p[n];
        for(int j=0;j<n;j++){
            cin>>p[j];
        }

        if (sol(n,p))
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}