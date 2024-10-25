#include <iostream>
#include <queue>
#include <stack>

void interleaveQueue(std::queue<int>& q) {
    int n = q.size();
    std::stack<int> s;

    // Step 1: Push the first half of the queue into the stack
    for (int i = 0; i < n / 2; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue the stack's contents back to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move the first half (now at the back of the queue) to the front
    for (int i = 0; i < n / 2; i++) {
        q.push(q.front());
        q.pop();
    }

    // Step 4: Push the second half of the queue into the stack
    for (int i = 0; i < n / 2; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 5: Interleave the elements from the stack and the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        if (!q.empty()) {
            q.push(q.front());
            q.pop();
        }
    }
}

int main() {
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    interleaveQueue(q);

    // Print the interleaved queue
    std::cout << "Interleaved queue:\n";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;

    return 0;
}
