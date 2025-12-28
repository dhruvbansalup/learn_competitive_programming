// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1099

#include<iostream>
#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class UnionFind
{
private:
    unordered_map<int, int>p;
    unordered_map<int, unordered_set<int>> enemies;
public:
    UnionFind(){}
    int getSet(int x){
        if (p[x] != x) {
            p[x] = getSet(p[x]);
        }
        return p[x];
    }
    void makeSet(int x){
        p[x]=x;
    }

    void setFriends(int a, int b){
        if (p.find(a) == p.end()) makeSet(a);
        if (p.find(b) == p.end()) makeSet(b);
        //union
        if (areFriends(a,b)) return;
        if (areEnemies(a,b)) {cout<<-1<<endl; return;}

        int x=getSet(a);
        int y=getSet(b);
        p[x]=y;

        //Combine Enemies
        enemies[y].insert(enemies[x].begin(),enemies[x].end());
    }
    void setEnemies(int a, int  b){
        if (areFriends(a,b)) {cout<<-1<<endl;return;}
        if (areEnemies(a,b)) return;
        
        int x=getSet(a);
        int y=getSet(b);

        enemies[x].insert(y);
        enemies[y].insert(x);
    }

    bool haveCommonEnemy(int a, int b){
        int x=getSet(a);
        int y=getSet(b);
        for (auto e1:enemies[x]){
            if (areEnemies(e1,y)) return 1;
        }
        return 0;
    }

    bool areFriends(int a, int b){
        if (getSet(a)==getSet(b)) return 1; else return 0;
    }
    bool areEnemies(int a, int b){
        int x=getSet(a);
        int y=getSet(b);

        for (auto e:enemies[x]){
            if (e==y) return 1;
        }
        for (auto e:enemies[y]){
            if (e==x) return 1;
        }
        return 0;
    }
};




int main(){
    
    int n;
    cin>>n;
    
    UnionFind war;

    int f,a,b;
    for (int i=0;i<n;i++){
        cin>>f>>a>>b;
        switch(f){
            case 1:
                war.setFriends(a,b);
                break;
            case 2:
                war.setEnemies(a,b);
                break;
            case 3:
                cout<<war.areFriends(a,b)<<endl;
                break;
            case 4:
                cout<<war.areEnemies(a,b)<<endl;
                break;
            default:
                break;
        }
    }

}