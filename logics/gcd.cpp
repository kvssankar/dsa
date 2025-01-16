#include <iostream>
using namespace std;

// Function to find the GCD of two numbers using the Euclidean Algorithm
int gcd(int a, int b) {
    // Loop until b becomes 0
    while (b != 0) {
        // Store the remainder of a divided by b
        int remainder = a % b;
        
        // Update a to b, and b to the remainder
        a = b;
        b = remainder;
    }
    
    // When b becomes 0, a contains the GCD
    return a;
}

int main() {
    int num1, num2;
    
    // Input two numbers
    cout << "Enter two numbers to find their GCD: ";
    cin >> num1 >> num2;
    
    // Call the gcd function and display the result
    int result = gcd(num1, num2);
    cout << "The GCD of " << num1 << " and " << num2 << " is: " << result << endl;
    
    return 0;
}
