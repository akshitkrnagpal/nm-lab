#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define ERROR 0.0001
#define ITERATIONS 20

long double x[ITERATIONS+1];

long double f(long double x)
{
	return pow(x,3)-4*x-9;
}

long double f_der(long double x)
{
    return 3*pow(x,2) -4;
}

long double guess(long double x)
{
    return x - (f(x)/f_der(x));
}

long double root_by_newton_raphson ( long double (*f)(long double), long double start, bool debug=false)
{
	
	x[0] = start;
	
	int count = 0;

	for(int i=0;i<ITERATIONS;i++)
	{
		x[i+1] = guess(x[i]);
		(debug) ? cout<<x[i+1]<<endl : cout<<"";

		if( fabs(f(x[i+1])) < ERROR )
		{
			(debug) ? cout<<"Number of iterations performed => "<<count<<endl : cout<<""; 
			return x[i+1];
		}

		count++;
	}

	(debug) ? cout<<"Number of iterations performed => "<<count<<endl : cout<<endl; 
	return x[20];
}

int main()
{
	cout<<setprecision(30)<<root_by_newton_raphson(f,2,true)<<endl;
}
