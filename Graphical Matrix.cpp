#include<iostream>
using namespace std;

#define v 3

void add(int mat[v][v], int i, int j){
  mat[i][j] = 1;
  mat[j][i] = 1;  
}

void display(int mat[v][v]){
  for(int i = 0; i < v; i++){
    for(int j = 0; j < v; j++){  
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  int mat[v][v] = {{0}};  

  add(mat, 0, 2);
  add(mat, 0, 1);
  add(mat, 1, 2);

  display(mat);
}
