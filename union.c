#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int parent[MAX],i;
void initialize(int n){
	for( i=0;i<n;i++){
		parent[i]=i;
	}
}
int find(int x){
	while(parent[x]!=x){
		x=parent[x];
	}
	return x;
}
void unionSets(int x,int y){
	int rootX=find(x);
	int rootY=find(y);
	
	if(rootX!=rootY){
		parent[rootY]=rootX;
	}
}
void displaySets(int n){
	printf("\nElements: ");
	for(i;i<n;i++){
		printf("%d",i);
	}
	printf("\nParent: ");
	for(i=0;i<n;i++){
		printf("%d",parent[i]);
	}
	printf("\n");
}
int main(){
	int n,choice,x,y;
	printf("Enter the no.of elements(max%d):",MAX);
	scanf("%d",&n);
	if(n>MAX||n<=0){
		printf("invalid no.of elements.Must between 1 and %d.\n",MAX);
	return 1;
	}
	initialize(n);
	
	printf("\nMenu:\n");
	printf("1: Union\n");
	printf("2: Find\n");
	printf("3: DisplaySets\n");
	printf("4: Exit\n");
	while(1){
		printf("Enter your choice:");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("Enter two numbers to union(0 to %d):",n-1);
				scanf("%d%d",&x,&y);
				if(x>=0&&x<n&&y>=0&&y<n){
					unionSets(x,y);
					printf("Union of %d and %d completed.\n",x,y);
				}else{
					printf("\n Invalid elements");
				}
				break;
				
				case 2:
					printf("Enter an element to find its set(0 to %d):",n-1);
					scanf("%d",&x);
					if(x>=0&&x<n){
						printf("Find(%d):Root=%d\n",x,find(x));
					}else{
						printf("\nInvalid element");
					}
					break;
					case 3:
						displaySets(n);
						break;
					case 4:
						printf("\n Exiting program.\n");
						return 0;
					default:
						printf("invalid choice.Please try again.\n");
		}
	}
	return 0;	
}
