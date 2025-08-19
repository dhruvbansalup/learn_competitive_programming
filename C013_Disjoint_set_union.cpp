// # Disjoint Set Union (DSU) or Union-Find

// - Maintains a collection of disjoint sets
// - Each set has "representative" or "leader" element, which identifies the set

// ### Support Operations
// - **Find**: Determine the representative of the set containing a specific element
// - **Union**: Merge two sets into a single set

#include<iostream>
#include<vector>

using namespace std;

class UnionFind{
    private:
        //p- Parent Pointers
        //rank - rank/height of individual sets
        //setSize- size of individual sets
        vector<int>p,rank,setSize;
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

            //all the sets are currently one
            setSize.assign(N,1);

            //no of sets is N
            numSets=N;
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
            
            //Update setSizes and numSets
            setSize[parent]+=setSize[child];
            numSets--;
        }
        
        int getSetSize(int i){
            //returns the size of set i belongs to
            return rank[findSet(i)];
        }

        int numDisjointSets(){
            //returns n0. of disjoint sets present currently.
            return numSets;
        }
};


// Implementation for - https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
int main(){
    int N,Q;
    cin>>N>>Q;

    UnionFind UF(N+1);

    while(Q--){
        string s;
        cin>>s;

        int x,y;
        cin>>x>>y;
        
        if (s=="union")
            UF.unionSet(x,y);
        else{
            if(UF.isSameSet(x,y))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }

}