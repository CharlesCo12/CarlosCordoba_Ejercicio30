#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>

using namespace std;

void onda(int nmax, int tiempo, string filename);
const double dx=1.0;
const double beta=0.8;
const float pi=4*atan(1);
const double c=1;
int main(){
    lw(101,0.5,"datos.dat");
    return 0;
}

void lw(int nmax, int tiempo, string filename){  
    ofstream outfile;
    outfile.open(filename);
    float U[nmax][2]={0};
    U[0][1]=0;
    U[100][1]=0;
    double t = 0.0;
    double dt = beta*dx/c;
    for(int i=0;i<nmax;i++)
    {
        U[i][0]=3*sin(3.2*i*dx);
    } 
    for(int j=0;j<nmax;j++)
    {
        outfile << U[j][0] << " ";
        if(j==nmax-1){outfile<<endl;}
    }
    while(t<tiempo)
    {
        for(int i=1;i<nmax-i;j++)
        {
            U[i][1]=U[i][0]-(beta/4)*((U[i+1][0]*U[i+1][0]) - (U[i-1][0]*U[i-1][0])) + (beta*beta/8)*(((U[i+1][0]+U[i][0])*((U[i+1][0]*U[i+1][0]) - (U[i][0]*U[i][0]))) - ((U[i][0]+U[i-1][0])*((U[i][0]*U[i][0]) - (U[i-1][0]*U[i-1][0])));
        }
        for(int j=0;j<nmax;j++)
        {
            outfile << U[j][1] << " ";
            if(j==nmax-1){outfile<<endl;}
        }
        U[0][1]=0;
        U[100][1]=0;
        for(int i=0;i<nmax;j++)
        {
            U[i][0]=U[i][1];
        }
        t=t+dt;
    }        
    outfile.close();
}