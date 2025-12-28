// https://codeforces.com/problemset/problem/2180/B

#include<bits/stdc++.h>
using namespace std;

void ashmal(int n, string text[]){
    string s="";
    
    for (int k=0;k<n;k++){
        string str=text[k];
    
        string front=str+s;
        string back=s+str;

        if (front<back){
            s=front;
        }else{
            s=back;
        }
    }
    cout<<s<<endl;
}

int main(){
    int cases;
    cin>>cases;
    while (cases--){
        int n;
        cin>>n;
        string text[n];
        for (int i=0;i<n;i++){
            cin>>text[i];
        }
        ashmal(n, text);
    }
}