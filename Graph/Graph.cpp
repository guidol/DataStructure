#include<iostream>
#include"QueueCPP.h"
using namespace std;

class Graph{
    public:
        void BFS(int g[][7], int start, int n);
        int DFS(int g[][7], int start, int n);
};

void BFS(int g[][7], int start, int n){
    int i = start;
    int j;
    Queue queue;
    int visited[7]={0};
    //if(visited[i] == 0)
    cout<<i<<" ";
        visited[i]=1;
        queue.EnQueue(i);
    
    while(!queue.isEmpty())
    {
        i = queue.DeQueue();
        for(int j=1; j<n ; j++)
        {
            if(g[i][j] == 1 && visited[j] == 0)
            {
                cout<<j<<endl;
                visited[j]=1;
                queue.EnQueue(j);
            }
        }
    }
}

int DFS(int g[][7], int start, int n){
    int i = start;
    static int visited[7]={0};
    if(visited[i]==0)
    {   cout<<i<<" ";
        visited[i]=1;
        for(int j=1; j<n ; j++)
            {
                if(g[i][j] == 1 && visited[j] == 0)
                {
                    DFS(g,j,n);
                }
            }
    }
}




int main(){
    int G[7][7] = {{0,0,0,0,0,0,0},
                   {0,0,1,1,0,0,0},
                   {0,1,0,0,1,0,0},
                   {0,1,0,0,1,0,0},
                   {0,0,1,1,0,1,1},
                   {0,0,0,0,1,0,0},
                   {0,0,0,0,1,0,0}};
       // BFS(G,4,7);
          DFS(G,1,7);



        return 0;

}