#include<bits/stdc++.h>
using namespace std;
void Prim(int n,int A[ ][100])
{
    int  weight[100];//未加入最小生成树的点到已经加入最小生成树的点集的最小边的权值 
    int adjvex[100];//加入最小生成树的点到已经加入最小生成树的点集的最小边的出发点 
    bool flag[n+1];//表示是否已经为最小生成树顶点，初始为false
    memset(weight,0,sizeof(weight));
    memset(adjvex,0,sizeof(adjvex));
    flag[1]=true;//假设先把1作为初始顶点
    for(int i=2;i<=n;i++){//假设从节点一开始
        flag[i]=false;
        adjvex[i]=1;
        weight[i]=A[1][i];
    }
    for(int i=1;i<n;i++){
        int  min=100000;
        int j=1;
        for(int k=2;k<=n;k++){//通过比较得到未加入最小生成树的点到已经加入最小生成树的点集的最小边，并把对应出发点记为j
            if((weight[k]<min)&&(flag[k]==false)){
                min=weight[k];
                j=k;
            }
        }
        cout <<"选边"<< "("<<adjvex[j] << "," <<j<<")" << endl;
        flag[j]=true;//把flag[j]设为true
        for(int k=2;k<=n;k++){//由于新的顶点加入树顶点，所以要更新非树顶点到树顶点集的最短路径，出发顶点adjvex[j] 
            if((A[j][k]<weight[k])&&(flag[k]==false)){
                weight[k]=A[j][k];
                adjvex[k]=j;
            }
        }
    }


}
int main()
{
    cout << "请输入图的顶点数" << endl;
    int n;
    cin >>n;
    cout << "请输入图的边数" << endl;
    int m;
    cin >> m;
    cout << "请输入图的边的两个端点和边的长度" << endl;
    int A[100][100];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            A[i][j]=100000;
        }
    }
    int start,end,w;
    for(int i=1;i<=m;i++){
        cin >>start >> end >> w;
        A[start][end]=w;
        A[end][start]=w;
    }
    Prim(n,A);
    return 0;

}

