
#include <iostream>
#include <cmath>
#include <complex>
using namespace std;


const int res = 801;// resolution of pic

const int iterations = 500; // how detailed it is; more iterations the closer it is to true mandlebrot set.
double round_to(double value, double precision);
void Xvalues(double xArr[res],double offset);
void Yvalues(double yArr[res],double offset);

char graph[res][res];

bool formula(int iterations,double xArr[res],double yArr[res],int x, int y);

void draw(char graph[res][res],double xArr[res],double yArr[res]);


int main() {
  double t = res - 1.0;
  double offset = (2.0/t);// offset if abs of graph; 3 -> -2 - 1 & 4.0 -> -2 2 always starts at -2 
  double arr[res][res];
  double xArr[res];
  Xvalues(xArr, offset);
  double yArr[res];
  Yvalues(yArr, offset);
 

  bool test = formula(iterations,xArr,yArr,1,1);
  cout << test;
  
    //  complex<double> test (xArr[5],yArr[5]);
    //bool x = (abs(test*test) > 2.0);
    //cout << endl << test*test << true <<" T " << x;
  
  cout << endl << endl;
  draw(graph,xArr,yArr);
  
  return 0;
}


double round_to(double value, double precision){

  return round(value / precision) * precision;

}

void Xvalues(double xArr[res], double offset){

 for(int i = 0; i < res; i++){
    
    if(i == 0){
      xArr[i] = -1;
    }
    else{

      //      xArr[i] = round_to((xArr[i-1] + .1),.0001);
      xArr[i] = round_to((xArr[i-1] + offset),.0001);
    }
    
    // cout << xArr[i] << " ( " << i <<" ) ";
  }
  cout << endl;
 
}



void Yvalues(double yArr[res],double offset){

 for(int i = 0; i < res; i++){
    
    if(i == 0){
      yArr[i] = -2;
    }
    else{

      //    yArr[i] = round_to((yArr[i-1] + .1),.0001);
      yArr[i] = round_to((yArr[i-1] + offset ),.0001);
    }
    
    // cout << yArr[i] << " ( " << i <<" ) ";
  }
  cout << endl;
 
}


bool formula(int iterations,double xArr[res],double yArr[res], int x, int y){
  //Z = Z + C    c = x(real) + y(imaginary) 
  complex<double> c (xArr[x],yArr[y]);
  
  complex<double> Z = c;

  for(int i = 0; i < iterations; i++){
    
    Z = Z*Z + c;
  }
  //  cout << Z;

  if(abs(Z)>= 2){
    
    return false;
    
  }
  if(abs(Z) < 2){

    return true;
  }
}

void draw(char graph[res][res],double xArr[res],double yArr[res]){

  for(int i = 0; i < res; i++){
    for(int j = 0; j < res; j++){
      graph[i][j] = '"';
      // cout << graph[i][j];
    }
    // cout << endl;
  }
  // int liloffthetop = res;//(res-1)/4; // removes 1/4 of the excess at the top of the drawing
  for(int i = 10; i < res; i++){
    for(int j = 0; j < res; j++){
      bool compare = formula(iterations, yArr, xArr, i, j);
      if(compare == true){
	graph[i][j] = '#';
	cout << graph[i][j];
      }
      else if (compare == false){
	graph[i][j] = '"';
	cout << graph[i][j];
      }
      else{
	graph[i][j] = '?';
	cout << graph[i][j];
      }
    }
    cout << endl;
  }

}
