#include <iostream>

using namespace std;

int main() {
    int queries;
    cin >> queries;
    long long n, a, b;
    long long ans;
    while (queries--) {
        ans = 0;
        cin >> n >> a >> b;
        if (a <= b * 0.5) {
            // choose a first
            ans = a * n;
        } else {
            long long num_b = n / 2;
            ans += num_b * b;
            if (n % 2 != 0) {
                ans += a;
            }
        }
        cout << ans << endl;
    }
    return 0;
}