#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>

using namespace std;

void lw(int nmax, double tiempo, string filename);
const double dx=0.01;
const double beta=1;
const float pi=4*atan(1);
const double c=1;
int main(){
    lw(101,2,"datos.dat");
    return 0;
}

void lw(int nmax, double tiempo, string filename){  
    ofstream outfile;
    outfile.open(filename);
    float U[nmax][2]={0};
    double t = 0.0;
    double dt = 0.01;
    float x;
    for(int i=0;i<nmax;i++)
    {
        x=i*dx;
        U[i][0]=0.05*sin(4*pi*x);
        U[i][1]=0;
    } 
    for(int j=0;j<nmax;j++)
    {
        outfile << U[j][0] << " ";
        if(j==nmax-1){outfile<<endl;}
    }
    while(t<tiempo)
    {
        for(int i=1;i<nmax-1;i++)
        {
            float a1 = U[i+1][0]*U[i+1][0];
            float a2 = U[i-1][0]*U[i-1][0];
            float a3 = U[i][0]*U[i][0];
            U[i][1]=U[i][0]-(beta/4)*(a1-a2)+(beta*beta)*((U[i+1][0]+U[i][0])*(a1-a3) - (U[i][0]+U[i-1][0])*(a3-a2))/8;
        }      
        for(int j=0;j<nmax;j++)
        {
            outfile << U[j][1] << " ";
            if(j==nmax-1){outfile<<endl;}
        }
        for(int i=0;i<nmax;i++)
        {
            U[i][0]=U[i][1];
        }
        t=t+dt;
    }        
    outfile.close();
}