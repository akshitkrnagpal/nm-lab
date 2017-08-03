#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define ERROR 0.0001
#define ITERATIONS 20

long double x[ITERATIONS+2];

long double secant ( long double (*f)(long double), int n)
{
	return x[n-1] - f(x[n-1])*( (x[n-1]-x[n-2])/(f(x[n-1])-f(x[n-2])) );
}

long double f(long double x)
{
	return pow(x,3)-13*x-12;
}

long double root_by_muller ( long double (*f)(long double), bool debug=false)
{
	x[0] = 4.5;
	x[1] = 5.5;
	x[2] = 5;

	int count = 0;

	for(int i=0;i<ITERATIONS;i++)
	{
		long double h0 = x[i+1]-x[i];
		long double h1 = x[i+2]-x[i+1];
		
		long double delta0 = (f(x[i+1])-f(x[i]))/(x[i+1]-x[i]);
		long double delta1 = (f(x[i+2])-f(x[i+1]))/(x[i+2]-x[i+1]);
		
		long double a = (delta1-delta0)/(h1+h0);
		long double b = a*h1 + delta1;
		long double c = f(x[i+2]);
		
		x[i+3] = x[i+2] + (-2*c)/(b+sqrt(b*b-4*a*c));
		
		(debug) ? cout<<x[i+3]<<endl : cout<<"";

		if( fabs(f(x[i])) < ERROR )
		{
			(debug) ? cout<<"Number of iterations performed => "<<count<<endl : cout<<""; 
			return x[i+3];
		}

		count++;
	}

	(debug) ? cout<<"Number of iterations performed => "<<count<<endl : cout<<endl; 
	return x[22];
}

int main()
{
	cout<<setprecision(30)<<root_by_muller(f)<<endl;
}
