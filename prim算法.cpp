#include<bits/stdc++.h>
using namespace std;
void Prim(int n,int A[ ][100])
{
    int  weight[100];//δ������С�������ĵ㵽�Ѿ�������С�������ĵ㼯����С�ߵ�Ȩֵ 
    int adjvex[100];//������С�������ĵ㵽�Ѿ�������С�������ĵ㼯����С�ߵĳ����� 
    bool flag[n+1];//��ʾ�Ƿ��Ѿ�Ϊ��С���������㣬��ʼΪfalse
    memset(weight,0,sizeof(weight));
    memset(adjvex,0,sizeof(adjvex));
    flag[1]=true;//�����Ȱ�1��Ϊ��ʼ����
    for(int i=2;i<=n;i++){//����ӽڵ�һ��ʼ
        flag[i]=false;
        adjvex[i]=1;
        weight[i]=A[1][i];
    }
    for(int i=1;i<n;i++){
        int  min=100000;
        int j=1;
        for(int k=2;k<=n;k++){//ͨ���Ƚϵõ�δ������С�������ĵ㵽�Ѿ�������С�������ĵ㼯����С�ߣ����Ѷ�Ӧ�������Ϊj
            if((weight[k]<min)&&(flag[k]==false)){
                min=weight[k];
                j=k;
            }
        }
        cout <<"ѡ��"<< "("<<adjvex[j] << "," <<j<<")" << endl;
        flag[j]=true;//��flag[j]��Ϊtrue
        for(int k=2;k<=n;k++){//�����µĶ�����������㣬����Ҫ���·������㵽�����㼯�����·������������adjvex[j] 
            if((A[j][k]<weight[k])&&(flag[k]==false)){
                weight[k]=A[j][k];
                adjvex[k]=j;
            }
        }
    }


}
int main()
{
    cout << "������ͼ�Ķ�����" << endl;
    int n;
    cin >>n;
    cout << "������ͼ�ı���" << endl;
    int m;
    cin >> m;
    cout << "������ͼ�ıߵ������˵�ͱߵĳ���" << endl;
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

