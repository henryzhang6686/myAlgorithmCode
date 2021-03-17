#include<iostream>
#include<cstdio>
using namespace std;

const int INF=100000;//正无穷
const int maxsize=100;//最大顶点数
int e[maxsize][maxsize];//邻接矩阵
int dis[maxsize];//距离表
int sign[maxsize];//标记
int vexnum,arcnum;//节点数，边数
int v1,v2,w;//v1:出发点，v2:结束点，w:边的权值

int main(){
	cout<<"请输入顶点数和边数："<<endl;
	cin>>vexnum>>arcnum;
	//初始化邻接矩阵,每一边的权值都是无穷大
	for(int i=1;i<=vexnum;i++){
		for(int j=1;j<=vexnum;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=INF;			
		}
	}
	//将各边的出发点，结束点以及权值，进行赋值
	cout<<"请输入各边的出发点，结束点以及权值"<<endl;
	for(int i=1;i<=arcnum;i++){
		cin>>v1>>v2>>w;
		e[v1][v2]=w;
	}

	for(int i=1;i<=vexnum;i++)
		dis[i]=e[1][i];

	//标记初始化为0
	for(int i=1;i<=vexnum;i++)
		sign[i]=0;
	sign[1]=1;//点1是出发点

	for(int i=0;i<vexnum-1;i++){  //n-1循环，（因为1节点自身已经确定）
		//找到距离1号顶点最近的顶点
		int min_weight=INF;
		int min_index=0;
		for(int k=1;k<=vexnum;k++){
			if(min_weight>dis[k] && sign[k]==0){
				min_index=k; 
				min_weight = dis[k];
			}
		}
		sign[min_index]=1;
		for(int j=1;j<=vexnum;j++){
			if(e[min_index][j]<INF){//表示点min_index到点i有边
				if(dis[j]>dis[min_index]+e[min_index][j]){
					dis[j]=dis[min_index]+e[min_index][j];
				}
			}
		}
	}
	for(int i=1;i<=vexnum;i++){
		cout<<"点1到点"<<i<<"的最短距离是";
		cout<<dis[i]<<endl;
	}
	return 0;
}
