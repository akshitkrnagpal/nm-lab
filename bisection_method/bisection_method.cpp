#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define ERROR 0.0001
#define ITERATIONS 20

long double bisect (long double left, long double right)
{
	return (left+right)/2;
}

long double f(long double x)
{
	return pow(x,3)-4*x-9;
}

long double root_by_bisection ( long double (*f)(long double), int range[], bool debug=false)
{
	long double left = range[0];
	long double right = range[1];

	if( f(left) * f(right) > 0)
	{
		(debug) ? cout<<"There may be no solution between ["<<range[0]<<","<<range[1]<<"]\n" : cout<<"" ;
		return 0;
	}

	int count = 0;

	for(int i=0;i<ITERATIONS;i++)
	{
		long double mid = bisect(left,right);
		(debug) ? cout<<mid<<endl : cout<<"";

		if( fabs(f(mid)) < ERROR || fabs(left-right) < ERROR )
		{
			(debug) ? cout<<"Number of iterations performed => "<<count<<endl : cout<<""; 
			return mid;
		}

		if( f(mid) * f(left) < 0 )
			right = mid;
		else
			left = mid;

		count++;
	}

	(debug) ? cout<<"Number of iterations performed => "<<count<<endl : cout<<endl; 
	return (left+right)/2;
}

int main()
{
	int range[2] = {2,3};

	cout<<setprecision(30)<<root_by_bisection(f,range)<<endl;
}
