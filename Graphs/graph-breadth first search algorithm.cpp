#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;

class graph
{
    int v;
    list<int> *l;
public:
    graph(int v){
        this->v=v;
        l=new list<int>[v];
    }

    void addEdge(int u,int v,bool bidir=true){
        l[u].push_back(v);
        if(bidir)
            l[v].push_back(u);
    }

    void printAdjacencyList(){
        for(int i=0;i<v;i++){
            cout<<i<<"->";
            for(list<int>::iterator it=l[i].begin();it!=l[i].end();it++)
                cout<<*it<<",";
            cout<<endl;
        }
    }

    void bfs(int src)
    {
        queue<int> q;
        map<int,bool> visit;
        q.push(src);
        visit[src]=true;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            cout<<node<<" ";
            for(list<int>::iterator it=l[node].begin();it!=l[node].end();it++){
                if(!visit[*it]){
                    q.push(*it);
                    visit[*it]=true;
                }
            }
        }
    }
};
int main()
{
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(0,2);

    cout<<"The adjacency list is as follows : \n";
    g.printAdjacencyList();
    cout<<endl;

    cout<<"Breadth first search algorithm : \n";
    g.bfs(0);
    cout<<endl;

}

