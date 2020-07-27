#include <iostream>

using namespace std;

int main() {
    int queries;
    cin >> queries;
    while (queries--) {
        int n;
        cin >> n;
        int arr[n];
        int ans = 0;
        int tmp_1 = 0;
        int tmp_2 = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];

            // preprocess
            arr[i] = arr[i] % 3;

            // count
            if (arr[i] == 0) {
                ans++;
            } else if (arr[i] == 1) {
                tmp_1++;
            } else if (arr[i] == 2) {
                tmp_2++;
            }
        }

        if (tmp_1 > 0 && tmp_2 > 0) {
            int less = tmp_1 > tmp_2 ? tmp_2 : tmp_1;
            ans += less;
            tmp_1 -= less;
            tmp_2 -= less;
        }
        if (tmp_2 == 0) {
            ans += tmp_1 / 3;
        } else if (tmp_1 == 0) {
            // 只有2
            ans += tmp_2 / 3;
        }

        cout << ans << endl;
    }
    return 0;
}