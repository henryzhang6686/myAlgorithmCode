#include<stdio.h>
#include<stdlib.h>

int main(){
	int T[11]={0,3,5,7,9,23,34,67,88,92,100};
	int x,j;
	printf("(顺序查找)请输入要查找的x的值：");
	scanf("%d",&x);
	for(j=1;j<=10;j++){
		if(T[j] == x){
			printf("x存在，下标为%d\n",j);
			break;
		}
	}
	if(j==11){
		printf("x不存在，j=0\n");
	}
	
	int L,R,M;
	L=1;
	R=10;
	printf("(二分查找)请输入要查找的x的值：");
	scanf("%d",&x);
	while(L<R){
		M=(L+R)/2;
		if(T[M] == x){
			printf("x存在，下标为%d\n",M);
			break;
		}
		else if(T[M]<x){
			L=M+1;
		}
		else{
			R=M-1;
		}
	}
	if(L==R){
		printf("x不存在，j=0\n");
	}
	return 0;
}

