#include<iostream>
#include<cstdio>
using namespace std;

const int INF=100000;//������
const int maxsize=100;//��󶥵���
int e[maxsize][maxsize];//�ڽӾ���
int dis[maxsize];//�����
int sign[maxsize];//���
int vexnum,arcnum;//�ڵ���������
int v1,v2,w;//v1:�����㣬v2:�����㣬w:�ߵ�Ȩֵ

int main(){
	cout<<"�����붥�����ͱ�����"<<endl;
	cin>>vexnum>>arcnum;
	//��ʼ���ڽӾ���,ÿһ�ߵ�Ȩֵ���������
	for(int i=1;i<=vexnum;i++){
		for(int j=1;j<=vexnum;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=INF;			
		}
	}
	//�����ߵĳ����㣬�������Լ�Ȩֵ�����и�ֵ
	cout<<"��������ߵĳ����㣬�������Լ�Ȩֵ"<<endl;
	for(int i=1;i<=arcnum;i++){
		cin>>v1>>v2>>w;
		e[v1][v2]=w;
	}

	for(int i=1;i<=vexnum;i++)
		dis[i]=e[1][i];

	//��ǳ�ʼ��Ϊ0
	for(int i=1;i<=vexnum;i++)
		sign[i]=0;
	sign[1]=1;//��1�ǳ�����

	for(int i=0;i<vexnum-1;i++){  //n-1ѭ��������Ϊ1�ڵ������Ѿ�ȷ����
		//�ҵ�����1�Ŷ�������Ķ���
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
			if(e[min_index][j]<INF){//��ʾ��min_index����i�б�
				if(dis[j]>dis[min_index]+e[min_index][j]){
					dis[j]=dis[min_index]+e[min_index][j];
				}
			}
		}
	}
	for(int i=1;i<=vexnum;i++){
		cout<<"��1����"<<i<<"����̾�����";
		cout<<dis[i]<<endl;
	}
	return 0;
}
