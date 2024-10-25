#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printNGE(vector<int>& arr) {
    stack<int> st;
    vector<int> nge(arr.size(), -1); // Initialize NGE array with -1

    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            nge[st.top()] = arr[i]; // Update NGE for the element at st.top()
            st.pop(); // Remove the element from stack
        }
        st.push(i); // Push the current index to stack
    }

    // Print the NGE for each element
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " -> " << nge[i] << endl;
    }
}

int main() {
    vector<int> arr = {4, 5, 2, 25}; // Initialize the array with elements
    printNGE(arr); // Call the function to print NGE
    return 0; // Return 0 to indicate successful execution
}
