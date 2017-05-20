//implementacion del metodo de euler para resolver el sistema de ecuaciones
#include<iostream>
#include<cmath>
#include<vector>

//declaracion de constantes
const double e=0.6;//excentricidad

//declaracion de funciones
void Stormer_Verlet(std::vector <double> &x, double &h);
double f(const std::vector <double> &x, const int &index);

int main(void)
{
  double h;
  h=0.0001;
  std::vector<double> x{1-e,0.0,0.0,std::sqrt((1+e)/(1-e))};
  for(int ii=0; ii<=500000; ++ii)
    {
      std::cout<<ii*h<<"\t"<<x[0]<<"\t"<<x[1]<<"\t"<<x[2]<<"\t"<<x[3]<<std::endl;
      Stormer_Verlet(x,h);
    }
  return 0;
}

double f(const std::vector <double> &x, const int &index)
{
  if(index==0)
    {
      double r=std::sqrt(x[0]*x[0]+x[2]*x[2]);
      return -x[0]/std::pow(r,3);
    }
  else if(index==2)
    {
      double r=std::sqrt(x[0]*x[0]+x[2]*x[2]);
      return -x[2]/std::pow(r,3);
    }
  else
    {
      return 0;
    }
}

void Stormer_Verlet(std::vector <double> &x, double &h)
{
  std::vector <double> tmp=x;
  x[0]+=h*(x[1]+h*f(tmp,0)/2);
  x[1]+=h*(f(tmp,0)+f(x,0))/2;
  x[2]+=h*(x[3]+h*f(tmp,2)/2);
  x[3]+=h*(f(tmp,2)+f(x,2))/2;
}
