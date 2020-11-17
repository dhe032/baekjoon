#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

int a, b;

double binary_search(double low, double high) {
	double ret;
	double mid = (low + high) / 2;
	double y = a * mid + b;

	if (y == 0.0) return mid;
	if (low >= high) return INT_MAX;

	if (y > 0) ret = binary_search(low, mid);
	else ret = binary_search(mid, high);
	
	return ret;
}

int main(void) {
	cin >> a >> b;
	double answer = binary_search(-999.0, 999.0);
	answer *= 10000.0;
	answer = round(answer);
	answer /= 10000.0;
	cout.precision(4);
	cout << fixed;
	cout << answer << endl;
}