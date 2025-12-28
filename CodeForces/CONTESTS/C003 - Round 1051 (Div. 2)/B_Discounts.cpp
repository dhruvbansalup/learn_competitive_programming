#include<bits/stdc++.h>
using namespace std;

bool desc(int a, int b) {
  	return a > b;
}

int sol(int noProd, int noDisc, int* prod, int* disc){

    //total cost
    int cost = 0;
    for (int i = 0; i < noProd; i++) {
        cost += prod[i];
    }

    //count 1
    int ones=0;
    for (int i=0;i<noDisc;i++)
        if (disc[i]==1) {
            ones++;
            disc[i]=0;
        }
    
    //sort
    sort(prod,prod+noProd,desc);
    sort(disc,disc+noDisc);

    //remove max val for ones
    for (int i=0;(i<ones && i<noProd);i++){
        cost-=prod[i];
        prod[i]=0;}
    
    //rem vouceher
    int idProd=ones;

    for (int i=ones; i<noDisc && idProd<noProd;i++){
        
        int voucherSize=disc[i];

        if(idProd+voucherSize-1<noProd){
            cost-=prod[idProd+voucherSize-1];
            idProd+=voucherSize;
        }
    }
    return cost;

}

int main(){
    int cases;
    cin>>cases;

    for (int i=0;i<cases;i++){
        int n,m;
        cin>>n>>m;
        int p[n],d[m];
        for(int j=0;j<n;j++){
            cin>>p[j];
        }
        for(int j=0;j<m;j++){
            cin>>d[j];
        }
        cout<<(sol(n,m,p,d))<<endl;
    }
}