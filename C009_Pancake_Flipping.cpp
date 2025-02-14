// The Pancake have 2 sides happy side and blank side
// they are prepred in the Rew
// You have to flip all upside
// but with a overside flipper (it does not flip position i.e on its place)

// Inputs:
// T: Test case no
// S: the initial state of pancake each char in S is + or -
// K: size of oversized flipper  
// 2<=K<=len of S

#include<iostream>
#include<vector>
using namespace std;

char flip(char c){
    if (c=='+'){
        return '-';
    } else {
        return '+';
    }
}

pair<bool,int> CanBeFlipped(string s,int k){
    int n=s.length();
    int Flips_Required=0;
    for (int i=0;i<n-k+1;i++){
        if (s[i] == '+'){
            continue;
        }else{ //"-"
            Flips_Required+=1;
            for (int j=i;j<i+k+1;j++){
                s[i]=flip(s[i]);
            }
        }
    }
    bool flag=true;
    for (int i=n-k+1;i<n;i++){
        if (s[i]=='-'){
            flag=false;
            break;
        }
    }
    return make_pair(flag, Flips_Required);
}

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        string s;
        cin>>s;
        int k;
        cin>>k;
        pair<bool, int> result = CanBeFlipped(s, k);
        cout << "Case #" << i << ": " << (result.first ? "YES" : "NO") << " " << result.second << endl;
    }
}