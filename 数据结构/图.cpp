#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int vertexnum,arcnum;//顶点数 边数
char vertex[100];//储存顶点的数组
int arc[100][100];//储存边的数组
int visited[100];
typedef char T;

//邻接节点
struct ArcNode{
    int adjvex;
    ArcNode *next;
};

//顶点节点
struct VertexNode{
    T vertex;
    ArcNode *firstedge;
}adjlist[100];

//输入邻接矩阵
void InputGraphmtx(T a[]){
    int i,j;
    for(i = 0;i < vertexnum;i++)
        vertex[i] = a[i];
    for(i = 0;i < vertexnum;i++)
        for(j = 0;j < vertexnum;j++)
            arc[i][j] = 0;
    for(int k = 0;k < arcnum;k++){
        cout<<"请输入第"<<k + 1<<"条边：";
        cin>>i>>j;
        arc[i][j] = 1;
        arc[j][i] = 1;//无向矩阵
    }
}

//输入邻接表
void InputGraghInk(T a[]){
    int i,j,m,k;
    ArcNode *s,*p;
    for(i = 0;i < vertexnum;i++){
        adjlist[i].vertex = a[i];
        adjlist[i].firstedge = NULL;
    }
    for(i = 0;i < vertexnum;i++){
        cout<<"请输入与第"<<i + 1<<"个结点相连的边数：";
        cin>>m;
        for(int k = 0;k < m;k++){
            cout<<"请输入与第"<<i + 1<<"个结点相连的第"<<k + 1<<"个点:";
            cin>>j;
            if(k == 0){
                s = new ArcNode;
                s->adjvex = j;
                s->next = adjlist[i].firstedge;
                adjlist[i].firstedge = s;
            }
            else{
                p = adjlist[i].firstedge;
                while(p->next != NULL)
                    p = p->next;
                s = new ArcNode;
                s->adjvex = j;
                s->next = p->next;
                p->next = s;
            }
        }
    }
}

//输出邻接矩阵
void OutputGraphmtx(){
    for(int i = 0;i < vertexnum;i++){
        for(int j = 0;j < vertexnum;j++)
            cout<<arc[i][j]<<" ";
        cout<<endl;
    }
}

//输出邻接表
void OutputGraphInk(){
    ArcNode *p;
    for(int i = 0;i < vertexnum;i++){
        p = adjlist[i].firstedge;
        cout<<adjlist[i].vertex<<":";
        while(p){
            cout<<p->adjvex<<" ";
            p = p->next;
        }
        cout<<endl;
    }
}

//邻接矩阵转换为邻接表
void MatToList(){
    ArcNode *p;
    int i,j;
    for(i = 0;i < vertexnum;i++){
        adjlist[i].vertex = vertex[i];
        adjlist[i].firstedge = NULL;
    }
    for(i = 0;i < vertexnum;i++)
        for(j = vertexnum - 1;j >= 0;j--)
            if(arc[i][j] != 0){
                p = new ArcNode;
                p->adjvex = j;
                p->next = adjlist[i].firstedge;
                adjlist[i].firstedge = p;
            }
}

//邻接表转换为邻接矩阵
void ListToMat(){
    int i,j;
    ArcNode *p;
    for(i = 0;i < vertexnum;i++)
        vertex[i] = adjlist[i].vertex;
    for(i = 0;i < vertexnum;i++){
        p = adjlist[i].firstedge;
        while(p){
            j = p->adjvex;
            arc[i][j] = 1;
            p = p->next;
        }
    }
}

//邻接矩阵深度优先搜索
void Mat_DFS(int v){
    int i,j;
    for(i = 0;i < vertexnum;i++)
        visited[i] = 0;
    stack<T> s;
    cout<<vertex[v]<<" ";
    visited[v] = 1;
    s.push(vertex[v]);
    while(!s.empty()){
        j = s.top() - 'a';
        for(i = 0;i < vertexnum;i++)
            if(arc[j][i] == 1 && visited[i] == 0){
                cout<<vertex[i]<<" ";
                visited[i] = 1;
                s.push(vertex[i]);
                break;
            }
        if(i == vertexnum)
            s.pop();
    }
}

//邻接表深度优先搜索
void List_DFS(int v){
    int i,j;
    ArcNode *p;
    for(i = 0;i < vertexnum;i++)
        visited[i] = 0;
    stack<T> s;
    cout<<adjlist[v].vertex<<" ";
    visited[v] = 1;
    s.push(adjlist[v].vertex);
    while(!s.empty()){
        i = s.top()- 'a';
        p = adjlist[i].firstedge;
        while(p){
            j = p->adjvex;
            if(visited[j] == 0){
                cout<<adjlist[j].vertex<<" ";
                visited[j] = 1;
                s.push(vertex[j]);
                break;
            }
            p = p->next;
        }
        if(p == NULL)
            s.pop();
    }
}

//邻接矩阵广度优先搜索
void Mat_BFS(int v){
    int i,j;
    for(i = 0;i < vertexnum;i++)
        visited[i] = 0;
    queue<T> q;
    cout<<vertex[v]<<" ";
    visited[v] = 1;
    q.push(vertex[v]);
    while(!q.empty()){
        j = q.front()- 'a';
        q.pop();
        for(i = 0;i < vertexnum;i++)
            if(arc[j][i] == 1 && visited[i] == 0){
                cout<<vertex[i]<<" ";
                visited[i] = 1;
                q.push(vertex[i]);
            }
    }
}

//邻接表广度优先搜索
void List_BFS(int v){
    int i,j;
    ArcNode *p;
    for(i = 0;i < vertexnum;i++)
        visited[i] = 0;
    queue<T> q;
    cout<<adjlist[v].vertex<<" ";
    visited[v] = 1;
    q.push(adjlist[v].vertex);
    while(!q.empty()){
        i = q.front()- 'a';
        q.pop();
        p = adjlist[i].firstedge;
        while(p){
            j = p->adjvex;
            if(visited[j] == 0){
                cout<<adjlist[j].vertex<<" ";
                visited[j] = 1;
                q.push(vertex[j]);
            }
            p = p->next;
        }
    }
}

int main(){
    char a[] = {'a','b','c','d','e','f'};
    vertexnum = 6;
    arcnum = 7;
    cout<<"输入邻接矩阵："<<endl;
    InputGraphmtx(a);
    //InputGraghInk(a);
    //ListToMat();
    cout<<"输出邻接矩阵："<<endl;
    OutputGraphmtx();cout<<endl;
    MatToList();
    cout<<"输出邻接表："<<endl;
    OutputGraphInk();cout<<endl;
    cout<<"输出邻接矩阵BFS："<<endl;
    Mat_BFS(0);cout<<endl;
    cout<<"输出邻接表BFS："<<endl;
    List_BFS(0);cout<<endl;
    cout<<"输出邻接矩阵DFS："<<endl;
    Mat_DFS(0);cout<<endl;
    cout<<"输出邻接表DFS："<<endl;
    List_DFS(0);
    return 0;
}
