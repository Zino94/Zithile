#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
    } else {
        int topElement = st.top(); // Store the top element
        st.pop(); // Remove the top element
        insertAtBottom(st, x); // Recur to insert at bottom
        st.push(topElement); // Push the stored element back
    }
}

// Function to reverse the stack using recursion
void reverseStack(stack<int>& st) {
    if (!st.empty()) {
        int topElement = st.top(); // Store the top element
        st.pop(); // Remove the top element
        reverseStack(st); // Recur to reverse remaining stack
        insertAtBottom(st, topElement); // Insert stored element at bottom
    }
}

// Function to print the stack
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " "; // Print the top element
        st.pop(); // Remove the top element
    }
    cout << endl; // Print a new line after printing the stack
}

int main() {
    stack<int> st; // Declare a stack of integers
    st.push(31); // Push elements to stack
    st.push(30);
    st.push(29);
    st.push(28);
    cout << "Original Stack: ";
    printStack(st); // Print the original stack

    reverseStack(st); // Reverse the stack

    cout << "Reversed Stack: ";
    printStack(st); // Print the reversed stack

    return 0; // Return 0 to indicate successful execution
}
