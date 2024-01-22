#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double pi;
    const int max_n = 1048576; // 2^20

    for (int n = 2; n <= max_n; n *= 2) {
        pi = 0.0;
        for (int k = 0; k <= n; ++k) {
            pi += pow(-1, k) / (2 * k + 1);
        }
        pi *= 4; 

        cout << fixed << setprecision(15);
        cout << "PI (approx): " << pi << "; n: " << setw(7) << n << endl;
    }

    cout << "PI (actual): 3.141592653589793" << endl;

    return 0;
}
