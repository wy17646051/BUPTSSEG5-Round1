#include <iostream>

using namespace std;

int main() {
    int queries;
    cin >> queries;
    while (queries--) {
        long long n;
        cin >> n;
        long long c_pos = n / 2;
        unsigned long long steps = 0;
        for (long long i = 1; i <= n; i = i + 2) {
            long long t = i / 2;
            steps = steps + t * (i - 1) * 4;
        }
        cout << steps << endl;
    }
    return 0;
}