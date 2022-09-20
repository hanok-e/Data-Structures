#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::endl;

void max_sliding_window_naive(vector<int> const & A, int w) {
    if (w > A.size()) {
        cout << *max_element(A.begin(), A.end()) << " " << endl;
        return;
    }

    std::deque<int> dq;
    int i = 0; int j = 0;
    while (j < A.size()) {
        int curr = A[j];
        if (j-i+1 < w) {
            while (!dq.empty() && curr > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(curr);
            j++;
        } else if (j-i+1 == w) {
            while (!dq.empty() && curr > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(curr);
            cout << dq.front() << " ";
            if (A[i] == dq.front()) {
                dq.pop_front();
            }
            i++;
            j++;
        }
    }

    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
