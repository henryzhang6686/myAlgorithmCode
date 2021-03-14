#include "stdio.h"
#include "stdlib.h"
#define MAX_VERtEX_NUM 20
#define VertexType int
typedef struct edge{
    VertexType start;
    VertexType end;
    VertexType weight;
}edges[MAX_VERtEX_NUM];

typedef struct {
    VertexType vex;//顶点数据
    int sign;//标签
}judge[MAX_VERtEX_NUM];
judge judges;

//qsort排序函数中使用，使edges结构体中的边按照权值大小升序排序
int cmp(const void *a,const void*b){
    return  ((struct edge*)a)->weight - ((struct edge*)b)->weight;
}

//初始化连通网函数
void CreateUDN(edges *edgess,int *vexnum,int *arcnum){
    printf("输入连通网的边数：\n");
    scanf("%d %d",&(*vexnum),&(*arcnum));
    printf("输入连通网的顶点：\n");
    for (int i=0; i<(*vexnum); i++) {
		scanf("%d",&(judges[i].vex));
        judges[i].sign=i;
    }
    printf("输入各边的起始点和终点及权重：\n");
    for (int i=0 ; i<(*arcnum); i++) {
        scanf("%d,%d,%d",&(*edgess)[i].start,&(*edgess)[i].end,&(*edgess)[i].weight);
    }
}

//判断point点是否是顶点
int Locatevex(int vexnum,int point){
    for (int i=0; i<vexnum; i++) {
		if (judges[i].vex==point) {
            return i;
        }
    }
    return -1;
}
int main(){
   
    int arcnum,vexnum;
    edges edgess;
    CreateUDN(&edgess,&vexnum,&arcnum);
    
	//对连通网中的所有边进行升序排序，结果仍保存在edges数组中
    qsort(edgess, arcnum, sizeof(edgess[0]), cmp);

    //创建一个空的结构体数组，用于存放最小生成树
    edges minTree;

    //设置一个用于记录最小生成树中边的数量的常量
    int num=0;

    //遍历所有的边
    for (int i=0; i<arcnum; i++) {
        
        int initial=Locatevex(vexnum, edgess[i].start);
        int end=Locatevex(vexnum, edgess[i].end);
        //如果顶点位置存在且顶点的标记不同，说明不在一个集合中，不会产生回路
		if (initial!=-1&& end!=-1&&judges[initial].sign!=judges[end].sign) {
            //记录该边，作为最小生成树的组成部分
            minTree[num]=edgess[i];
            //计数+1
            num++;
            //将新加入生成树的顶点标记全部更改为一样的
            for (int k=0; k<vexnum; k++) {
				if (judges[k].sign==judges[end].sign) {
					judges[k].sign=judges[initial].sign;
                }
            }
            //如果选择的边的数量和顶点数相差1，证明最小生成树已经形成，退出循环
            if (num==vexnum-1) {
                break;
            }
        }
    }
    
    for (int i=0; i<vexnum-1; i++) {
        printf("%d,%d\n",minTree[i].start,minTree[i].end);
    }
    return 0;
}