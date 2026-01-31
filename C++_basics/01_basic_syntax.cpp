#include <iostream>   // Provides input/output stream objects
using namespace std;  // Allows use of cout, cin without std::

int main() {
    // 1. Basic output
    cout << "Hello, C++!" << endl;

    // 2. Variable declarations
    int a = 10;
    int b = 20;
    double pi = 3.14;
    char grade = 'A';
    bool isPassed = true;

    // 3. Output variables
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "pi = " << pi << endl;
    cout << "grade = " << grade << endl;
    cout << "Passed? " << isPassed << endl;

    // 4. User input
    int x;
    cout << "Enter an integer: ";
    cin >> x;

    // 5. Basic arithmetic
    cout << "x + a = " << x + a << endl;

    // 6. If-else statement
    if (x > 0) {
        cout << "x is positive" << endl;
    } else if (x < 0) {
        cout << "x is negative" << endl;
    } else {
        cout << "x is zero" << endl;
    }

    // 7. For loop
    cout << "Counting from 1 to 5: ";
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    // 8. While loop
    int count = 3;
    cout << "Countdown: ";
    while (count > 0) {
        cout << count << " ";
        count--;
    }
    cout << endl;

    return 0;  // End of program
}
