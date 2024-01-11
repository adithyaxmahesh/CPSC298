#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat> // Include the cfloat library for DBL_DIG

using namespace std;

int main() {
    double pi = 0.0;
    int n;

    cout << "Enter the upper bound for the summation index (n): ";
    cin >> n;

    for (int k = 0; k <= n; ++k) {
        pi += pow(-1, k) / (2 * k + 1);
    }
    pi *= 4; 

    cout << fixed << setprecision(DBL_DIG);
    cout << "PI (approx): " << pi << "; n: " << setw(7) << n << endl;
    cout << "PI (actual): 3.141592653589793" << endl;

    return 0;
}
