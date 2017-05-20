//implementacion del metodo de euler para resolver el sistema de ecuaciones
#include <iostream>
#include <cmath>
#include <vector>

//declaracion de constantes
const double e=0.6;//excentricidad

//declaracion de funciones
double f(const std::vector <double> &x, const int ind);
void euler (double h, std::vector<double> &x);

int main (void)
{
  
  std::vector<double> x{1-e,0.0,0.0,std::sqrt((1+e)/(1-e))};
  double h=0.00005;
  for ( int ii = 0; ii<=1000000; ii++)
    {
      std::cout<<h*ii<<"\t"<<x[0]<<"\t"<<x[1]<<"\t"<<x[2]<<"\t"<<x[3]<<"\t"<<(0.5*(x[1]*x[1]+x[3]*x[3])-1/std::sqrt(x[0]*x[0]+x[2]*x[2]))<<"\t"<<(x[0]*x[3]-x[2]*x[1])<<std::endl;
      euler (h, x);
    }
  return 0;
}
double f(const std::vector <double> &x, int ind)
{
  if(0==ind)
    {
      return x[1];
    }

  if(1==ind)
    {
      long double r;
      r=std::sqrt(x[0]*x[0]+x[2]*x[2]);
      return -x[0]/pow(r,3);
    }

  if(2==ind)
    {
      return x[3];
    }

  if(3==ind)
    {
      long double r;
      r=std::sqrt(x[0]*x[0]+x[2]*x[2]);
      return -x[2]/pow(r,3);
    }
}

void euler (double h, std::vector<double> &x)
{
  const int n=x.size();
  std::vector<double> tmp = x;
  for(int ii=0; ii<n; ++ii)
    {
      x[ii]=x[ii]+h*f(tmp, ii);
    }
}
