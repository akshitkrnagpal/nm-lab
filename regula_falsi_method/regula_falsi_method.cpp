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
	return pow(x,3)-4*x-9;
}

long double root_by_regula_falsi ( long double (*f)(long double), int range[], bool debug=false)
{
	x[0] = (long double) range[0];
	x[1] = (long double) range[1];


	if( f(x[0]) * f(x[1]) > 0)
	{
		(debug) ? cout<<"There may be no solution between ["<<range[0]<<","<<range[1]<<"]\n" : cout<<"" ;
		return 0;
	}

	int count = 0;

	for(int i=2;i<ITERATIONS;i++)
	{
		x[i] = secant (f,i);
		
		(debug) ? cout<<x[i]<<endl : cout<<"";

		if( fabs(f(x[i])) < ERROR && fabs(x[i]-x[i-1]) < ERROR )
		{
			(debug) ? cout<<"Number of iterations performed => "<<count<<endl : cout<<""; 
			return x[i];
		}

		if( f(x[i]) * f(x[i-1]) > 0 )
			x[i-1] = x[i-2];

		count++;
	}

	(debug) ? cout<<"Number of iterations performed => "<<count<<endl : cout<<endl; 
	return secant (f,count+2);
}

int main()
{
	int range[2] = {2,3};

	cout<<setprecision(30)<<root_by_regula_falsi(f,range)<<endl;
}
