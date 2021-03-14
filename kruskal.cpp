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
    VertexType vex;//��������
    int sign;//��ǩ
}judge[MAX_VERtEX_NUM];
judge judges;

//qsort��������ʹ�ã�ʹedges�ṹ���еı߰���Ȩֵ��С��������
int cmp(const void *a,const void*b){
    return  ((struct edge*)a)->weight - ((struct edge*)b)->weight;
}

//��ʼ����ͨ������
void CreateUDN(edges *edgess,int *vexnum,int *arcnum){
    printf("������ͨ���ı�����\n");
    scanf("%d %d",&(*vexnum),&(*arcnum));
    printf("������ͨ���Ķ��㣺\n");
    for (int i=0; i<(*vexnum); i++) {
		scanf("%d",&(judges[i].vex));
        judges[i].sign=i;
    }
    printf("������ߵ���ʼ����յ㼰Ȩ�أ�\n");
    for (int i=0 ; i<(*arcnum); i++) {
        scanf("%d,%d,%d",&(*edgess)[i].start,&(*edgess)[i].end,&(*edgess)[i].weight);
    }
}

//�ж�point���Ƿ��Ƕ���
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
    
	//����ͨ���е����б߽����������򣬽���Ա�����edges������
    qsort(edgess, arcnum, sizeof(edgess[0]), cmp);

    //����һ���յĽṹ�����飬���ڴ����С������
    edges minTree;

    //����һ�����ڼ�¼��С�������бߵ������ĳ���
    int num=0;

    //�������еı�
    for (int i=0; i<arcnum; i++) {
        
        int initial=Locatevex(vexnum, edgess[i].start);
        int end=Locatevex(vexnum, edgess[i].end);
        //�������λ�ô����Ҷ���ı�ǲ�ͬ��˵������һ�������У����������·
		if (initial!=-1&& end!=-1&&judges[initial].sign!=judges[end].sign) {
            //��¼�ñߣ���Ϊ��С����������ɲ���
            minTree[num]=edgess[i];
            //����+1
            num++;
            //���¼����������Ķ�����ȫ������Ϊһ����
            for (int k=0; k<vexnum; k++) {
				if (judges[k].sign==judges[end].sign) {
					judges[k].sign=judges[initial].sign;
                }
            }
            //���ѡ��ıߵ������Ͷ��������1��֤����С�������Ѿ��γɣ��˳�ѭ��
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