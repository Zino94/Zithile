#include <iostream>
#include <deque>
#include <vector>

void firstNegativeInteger(const std::vector<int>& arr, int k) {
    std::deque<int> dq;
    for (int i = 0; i < arr.size(); i++) {
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        if (arr[i] < 0) {
            dq.push_back(i);
        }
        if (i >= k - 1) {
            if (!dq.empty()) {
                std::cout << arr[dq.front()] << " ";
            } else {
                std::cout << 0 << " ";
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;
    firstNegativeInteger(arr, k);
    return 0;
}

