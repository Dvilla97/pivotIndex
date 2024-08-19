#include <iostream>
#include <string>
#include <sstream>  // For stringstream
#include <vector>  // For vector

using namespace std;

int main() {
    int totalSum = 0;
    int leftSum = 0;
    vector<int> userVec;

    cout << "This is for pivot index\n";
    cout << "Give me a string of numbers separated by spaces:\n";

    // Read the entire line of input
    string input;
    getline(cin, input);

    // Initialize a stringstream with the input string
    stringstream ss(input);

    // Temporary variable to store parsed integers
    int num;

    // Parse integers from the stringstream and add them to the vector
    while (ss >> num) {
        userVec.push_back(num);
    }

    // Calculate the total sum of the array
    for (int pivNum : userVec) {
        totalSum += pivNum;
    }

    // Iterate through the array to find the pivot index
    for (int i = 0; i < userVec.size(); ++i) {
        // Check if the left sum equals the right sum
        if (leftSum == totalSum - leftSum - userVec[i]) {
            cout << "Pivot index is: " << i << endl;
            return 0;  // Return 0 to indicate successful completion
        }
        // Add the current element to the left sum
        leftSum += userVec[i];
    }

    // If no pivot index is found
    cout << "Pivot index is: -1" << endl;

    return 0;  // Return 0 to indicate successful completion
}