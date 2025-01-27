#include<stdio.h>
#define N 4
void printSolution(int solution[N][N]){
for(int i =0;  i<N; i++){
for(int j =0; j<N; j++){
printf("%d",solution[i][j]);
}
printf("\n")
}
}
int isSafe(int maze[N][N], int x, int y){
if(x>=0 && x<N && y>=0 && y<N && maze[x][y] == 1){
return 1;
}
return 0;
}
int solveMazeUtil(int maze[N][N], int x, int y, int solution[N][N]){
if(x == N - 1 && y == N - 1){
solution[x][y] = 1;
return 1;
}
if(isSafe(mazex,y)){
solution[x][y] = 1;
if(solveMazeUtil(maze, x+1,y,solution)){
return 1;
}
solution[x][y] = 0;
return 0;
}
return 0;
}
int solveMaze(int maze[N][N]) {
int solution[N][N] = {0};
if(solveMazeUtil(maze, 0, 0, solution) == 0){
printf("No solution exists\n");
return 1;
}
int main(){
int maze[N][N] = {
{1,0,0,0},
{1,1,0,1},
{0,1,0,0},
{1,1,1,1}
};
solveMaze(maze);
return 0;
}
      