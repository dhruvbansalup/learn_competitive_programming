// Paint

// Bob is instructed by his father to paint a row of cubes. Initially, there are no cubes in the row. But Bob has a lot of unpainted cubes. His father gives him specific instructions and expects him to follow these instructions. Solve this problem using either of the methods discussed in the quiz (online and offline). The merging technique would be used to solve this online.

// These are the queries:

// Type 1 → Put an unpainted cube in the end of the row and paint it to colour "c".

// Type 2 → Paint all blocks which were painted with colour “c1” to colour “c2”.

// Input:

// First line contains Q(number of queries). This if followed by Q lines, each containing a query.

// Query of Type is given as follows:
// 1 X → place a cube in the end and paint it X

// Query of Type is given as follows:
// 2 X Y → Paint all blocks which were painted with colour X to colour Y

// Output:
// The final state of the boxes after all the queries are made

// Constraints:
// Q ≤ 105
// 1 ≤ X ≤ 105 and 1 ≤ Y ≤ 105

#include <iostream>
#include<vector>
using namespace std;

class DSU{
    private:
    vector<int> p;
    public:
    void addBox(int color){
        p.push_back(color);
    }
    void changeColor(int from, int to){
        for (int i=0;i<p.size();i++){
            if (p[i]==from) p[i]=to;
        }
    }
    vector<int> currState(){
        return p;
    }
};

int main()
{
    int n;
    cin >> n;

    DSU a;

    for (int i = 0; i < n; i++)
    {
        int q, x, y;
        cin>>q>>x;
        if (q==2) cin>>y;
        if (q==1) a.addBox(x); else a.changeColor(x,y);
    }
    
    for (auto x:a.currState()){
        cout<<x<<" ";
    }
}
