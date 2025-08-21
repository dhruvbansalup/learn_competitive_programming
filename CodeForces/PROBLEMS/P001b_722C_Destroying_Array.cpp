// https://codeforces.com/problemset/problem/722/C

//Disjoint Set Union

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class UnionFind{
    private:
        //p- Parent Pointers
        //rank - rank/height of individual sets
        //setSize- size of individual sets
        vector<int>p,rank,setSize,sumSet;
        //numSets - no of disjoint sets
        int numSets;

    public:
        //Initialization
        UnionFind(int N){
            //creats N singleton sets
            p.assign(N,0); //add n 0's to the list p
            
            //assign every one as own parent:
            for(int i=0;i<N;i++)
                p[i]=i;
            
            //the height of all trees is zero
            rank.assign(N,0);

            //initialize sumSet (initial weight =0)
            sumSet.assign(N,0);

            //all the sets are currently one
            setSize.assign(N,1);

            //no of sets is N
            numSets=N;
        }

        void makeSet(int i, int x){
            p[i]=i;
            rank[i]=0;
            setSize[i]=1;
            sumSet[i]=x;
            numSets+=1;
        }

        long long sumOfSet(int x){
            int set=findSet(x);
            return(sumSet[set]);
        }

        int findSet(int i){
            //if already a representative
            if (p[i]==i) return i;
            //otherwise
            else return p[i]=findSet(p[i]);
        }

        bool isSameSet(int i, int j){
            //if i and j belongs to same set
            return findSet(i)==findSet(j);
        }

        void unionSet(int i, int j){
            // check if already union
            if (isSameSet(i,j)) return;

            //Get representative
            int x=findSet(i);
            int y=findSet(j);
            
            int parent,child;

            //Decide which one is to be the representative (parent)
            if (rank[x]>rank[y]){
                parent=x; //big rank is repr.
                child=y; //smaller rank is child
            }else{
                parent=y;
                child=x;
            }
            
            //change the repr. of child
            p[child]=parent;
            
            //increase the tree size if needed.
            if (rank[parent]==rank[child]) rank[parent]++;
            
            //Update the sumSet
            sumSet[parent]+=sumSet[child];

            //Update setSizes and numSets
            setSize[parent]+=setSize[child];
            numSets--;
        }
};



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

    //Status of no. 0 - Destroyed, 1-present
    bool state[n];
    fill_n(state, n, 0);

    //Initialize DSU with n indexes
    UnionFind UF(n);

    //reverse the order of deletions
    reverse(order, order + n);
    
    vector<long long> answers;


    //The last answer is always zero
    answers.push_back(0);

    long long currAns=0;

    for (auto x:order){
        state[x]=1;
        UF.makeSet(x,arr[x]);

        //Left set is available then merge
        if(x-1>=0 and state[x-1]) UF.unionSet(x-1,x);
        //Right Set is available
        if(x+1<n and state[x+1]) UF.unionSet(x,x+1);

        currAns=max(UF.sumOfSet(x),currAns);
        answers.push_back(currAns);
    }

    answers.pop_back();

    reverse(answers.begin(),answers.end());
    //Print Answe
    for (auto x: answers)
        cout<<x<<endl;

}

