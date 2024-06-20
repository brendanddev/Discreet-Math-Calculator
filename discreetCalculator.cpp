// Including Headers: 
#include <iostream> // Input/Output stream library.
#include <cmath> // CMath library.

// Directive's:
using namespace std; // Standard Namespace Directive.

// EXECUTING FROM TERMINAL: 
// COMPILE: g++ -o discreetCalculator discreetCalculator.cpp
// RUN: ./discreetCalculator

// This function is responsible for finding the GCF (Greatest Common Factor) between two integers 
// 'a' and 'b'. The GCF is the largest whole number that is a factor of both integer 'a' and 'b'. 
// In other words, it is the largest whole number that can divide 'a' and 'b'. This function uses
// the Euclidean Algorithm to determine the GCF. It uses the modulo operator to do integer division,
// finding the quotient, and remainder of the division until the remainder is 0, and at that point the
// last non zero remainder will be the GCF.
int gcf(int a, int b) { // Function return type will be an 'int' (integer), taking two integers 'a' & 'b' as parameters.
    while (b != 0) { // Begins a while loop that will iterate through, updating values for 'a' and 'b' as long as 'b' is not 0.
        int tempA = b; // A variable 'tempA' is declared and initialized to the value assigned to 'b' in order to store the current value of 'b'.
        b = a % b; // 'b' is now assigned to the remainder of dividing 'a' and 'b'.
        a = tempA; // 'a' is now assigned to the value that is assigned to the temporary variable 'tempA'.
    }
    return a; // When 'b' is 0, which means the remainder is 0. The loop will terminate, and as a result 'a' will be the GCF.
}

// This function is responsible for finding the LCM (Least Common Multiple) between two integers 'a' and 'b'.
// The resulting integer will be the smallest positive number that is a multiple of both 'a' and 'b'. This function
// relies on the use of the 'gcf' function to perform the calculations.
int lcm(int a, int b) { // This function will return an integer value, and takes two integer parameters 'a' and 'b'.
    return (a / gcf(a, b)) * b; // The function will return the LCM of 'a' and 'b' relying on the relationship between the LCM and GCF.
}

// This function is repsonsible for determining if two integers 'a' and 'b' are congruent modulo 'm'. If the integer 'a' has the same remainder 
// as when integer 'b' is divided by 'm', these two integers are congruent mod 'm'. Inside the function two additional variables are declared and
// initialized to an integer 'remA' and 'remB' which are assigned to the remainder as a result of dividing 'a' by 'm', and 'b' by 'm'. An if statement
// is then used to compare these values, therefore determining if these two numbers are equal, thus determining congruence between the intgers 'a' and 'b'.
int congruenceCalculator(int a, int b, int m) { // Function returns an integer, takes three integers as parameters 'a', 'b', and 'm', where 'm' is the modulus.
    int remA = a % m; // Variable 'remA' is declared, initialized to the remainder when dividing 'a' by 'm'.
    int remB = b % m; // Variable 'remB' is declared, and initialized to the remainder when dividing 'b' by 'm'.

    // These lines of code use the 'cout' object to output the remainders 'remA' and 'remB' when the values of 'a' and 'b' are divided by the
    // modulus 'm'. These lines of code use the stream insetion operator '<<' to chain the outputs, and use the 'endl' output manipulator to 
    // insert a newline character so the outputs appear on different lines.
    cout << "Remainder of " << a << ", (mod " << m << "), is: " << remA << endl;
    cout << "Remainder of " << b << ", (mod " << m << "), is: " << remB << endl;

    // This if statement compares the variables 'remA' and 'remB' each of which hold the remainder as a result of dividing 'a' by 'm', and 'b' by 'm'.
    // The if statement checks if the remainders are equal, where if they are, the two integers 'a' and 'b' prove to be congruent mod 'm'.
    if (remA == remB) {
        // If the integers 'a' and 'b' are congruent, the 'cout' object is used to print the values of 'a', 'b', and 'm' also mentioning they are congruent.
        cout << a << ", and " << b << " are congruent mod " << m << endl;
    // If the remainders of 'a' and 'b' are not equal, the else statement will be executed as these values are not congruent mod 'm'.
    } else {
        // The 'cout' object is used to print the values of 'a', 'b', and 'm', and mentions 'a' and 'b' are not congruent mod 'm'.
        cout << a << ", and " << b << " are not congruent mod " << m << endl;
    }
}

// This function is used to check if an integer is a prime number, where a prime number is an integer larger than 2,
// that can only be divided itself, or 1. In essence, a prime number will only have two whole number factors, itself,
// and 1.
bool primeCheck(int n) { // This function will return a boolean value, and takes one parameter 'n' as an integer.
    // The first if statement checks if 'n' is less than, or equal to 1, as prime numbers are greater than 1,
    // so if 'n' is 1 or less, the function will return false as this is not a prime number.
    if (n <= 1) {
        // Returns false as if 'n' is less than or equal to 1, it is not prime.
        return false;
    }
    // This if statement checks if 'n' is 2, or 3. This is because both 2 and 3 are prime, so this eliminates 
    // the need to check both numbers.
    if (n == 2 || n == 3) {
        // Returns true as 2 and 3 are both prime numbers.
        return true;
    }
    // This if statement checks if the integer 'n' is evenly divisible by 2 or 3. The reason for this is because 
    // any number that is divisible by 2 or 3 besides themselves will not be prime. This if statement will return 
    // false indicating the number is not prime.
    if (n % 2 == 0 || n % 3 == 0) {
        // Returns false to indicate this will not be a prime number.
        return false;
    }
    // A new integer 'sqrtLimit' is declared and initialized to the square root of 'n' using the 'cmath' library.
    // This is because the limit for checking factors/divisors of an integer is their square root, in this case the 
    // square root of 'n'.
    int sqrtLimit = sqrt(n);
    // This for loop begins at 5, will terminate when the current iteration 'i' is less than, or equal to the square root
    // of 'n' 'sqrtLimit', and increments by 6 each iteration. This is because the if statements before the loop have already
    // checked any primes before 5: 2, and 3. After eliminating these two primes, and their multiples, we can now assume that
    // every prime that follows 5 will be of the form '6 * k +- 1', this reduces the need of code duplication, and ensures 
    // efficiency in the function.
    for (int i = 5; i <= sqrtLimit; i += 6) {
        // The if statement checks if 'n' is evenly divisible by 'i', or 'i + 2'. This is because if 'n' is evenly divisible by
        // the current iteration 'i', or 'i + 2' (to check any evens), this means 'n' has a divisor other than 1, and 'n' itself, 
        // which means 'n' would not be prime. 
        if (n % i == 0 || n % (i + 2) == 0) {
            // If 'n' does have a divsior other than 1 or itself, the return will be false as this means it is not a prime.
            return false;
        }
    }
    // If the inner if statement does not find a divsior, this means the number will be prime, and we return true.
    return true;
}

// This function is responsible for checking if an integer is a perfect square. A perfect square number is a positive integer
// that is given as a result of multiplying an integer by itself. It is technically a number that is a product of the number itself.
bool perfSquare(int x) { // This function will return a boolean value, and takes an integer 'x' as a parameter.
    // An integer variable 'squareRoot' is declared and initialized to the square root of the parameter 'x'.
    // The square root of the number is assigned to an integer variable to truncate the floating point part of the number.
    int squareRoot = sqrt(x);
    // The following line of code checks if the square root of 'x' 'squareRoot' can be multiplied by itself, and give 'x' as 
    // a result. If this is the case, the number is considered a perfect square, and the function will return true. Otherwise,
    // the function will return false as this will not be considered a perfect square.
    return (squareRoot * squareRoot == x);
}

// This function is resposnible for checking if an integer belongs to the Fibonacci Sequence. The Fibonacci Sequence is a sequence
// of numbers where each number in the sequence is equal to the sum of the two numbers before it.
bool fibonacciCheck(int n) { // Function will return a boolean value, and takes an integer 'n' as a prameter. 
    // In order to determine if the integer 'n' belongs to the Fibonacci Sequence, I have used a well known property of Fibonacci Numbers.
    // This uses the 'perfSquare' function, to first determine if the number is a perfect square, and the multiplies the number 'n' by 5,
    // itself, and adding or subtracting 4. If either of these statements return true, the number is considered apart of the Fibonacci Sequence.
    // If not, the number is not considered apart of the Fibonacci Sequence.
    return perfSquare(5 * n * n + 4) || perfSquare(5 * n * n - 4);
}

// This will be the main function of the Discreet Calculator program. It acts as the entry point for the code, the program. 
int main() {
    // Three integer variables are declared 'choice', 'a', 'b', and 'm' but are not yet initialized. 
    int choice, a, b, m;

    // This is the start of a 'do-while' loop code block. This acts as the entry point for the menu of the Discreet Calculator,
    // where what happens next is dependant on what the user enters. The 'cout' object is used to output text to the user, which
    // allows them to select an option by entering a number from the kyeboard.
    do {
        cout << "\nBrendan's Discreet Calculator Math Menu:\n"; // Menu text header.
        cout << "1. Find GCF\n"; // Indicates the user enters '1' to choose this option.
        cout << "2. Find LCM\n"; // Indicates the user enters '2' to choose this option.
        cout << "3. Check Congruence\n"; // Indicates the user enters '3' to choose this option.
        cout << "4. Prime Check\n"; // Indicates the user enters '4' to choose this option.
        cout << "5. Fibonacci Check\n"; // Indicates the user enters '5' to choose this option.
        cout << "6. Exit\n"; // Indicates the user enters '6' to choose this option, quit the program. 
        cout << "Enter your choice, or '6' to quit"; // Indicates that the user must enter the corresponding number to select an option. 
        // Depending on what the user enters, the 'cin' input stream is used to assign the number entered by the user into the 'choice' 
        // variable to then operate the switch case. 
        cin >> choice; 

        // This is the beggining of the switch case which is responsible for operating the menu driven Discreet Calculator program.
        // Depending on what the user has entered which is saved into the 'choice' variable, the corresponding case will execute.
        switch(choice) {
            // Case 1 is responsible for finding the GCF of two values 'a' and 'b' entered by the user.
            case 1:
                // Uses the 'cout' output stream to prompt the user to enter an integer 'a'.
                cout << "Enter a value 'a': ";
                // Uses the 'cin' input operator to assign the value the user has entered into the variable 'a'.
                cin >> a;
                // Uses the 'cout' output stream to prompt the user to enter a second integer 'b'.
                cout << "Enter a value 'b': ";
                // Uses the 'cin' input operator to assign the value the user has entered for 'b' into the variable 'b'.
                cin >> b;
                // This line then outputs the GCF of the two values using the 'cout' output stream to output the GCF, where
                // the GCF is found by calling upon the 'gcf' function.
                cout << "The GCF is: " << gcf(a, b);
                // The 'break' statement is used to terminate this case, and return to the main menu.
                break;
            // Case 2 is responsible for finding the LCM of two values 'a' and 'b'.    
            case 2:
                // Uses the 'cout' output stream to prompt the user to enter an integer 'a'.
                cout << "Enter a value 'a': ";
                // Uses the 'cin' input operator to assign the value the user has entered into the variable 'a'.
                cin >> a;
                // Uses the 'cout' output stream to prompt the user to enter an integer 'b'.
                cout << "Enter a value 'b': ";
                // Uses the 'cin' input operator to assign the value the user has entered into the variable 'b'.
                cin >> b;
                // This line then outputs the LCM of the two values using the 'cout' output stream to output the LCM, where
                // the LCM is determined by calling upon the 'lcm' and passing 'a' and 'b' as arguments.
                cout << "The LCM of " << a << " and " << b << " is: " << lcm(a, b);
                // The 'break' statement is used to terminate this case, and return to the main menu.
                break;
            // Case 3 is responsible for checking if two values 'a' and 'b' are congruent mod 'm'.
            case 3:
                // Uses the 'cout' output stream to prompt the user to enter an integer 'a'.
                cout << "Enter an integer for 'a': ";
                // Uses the 'cin' input operator to assign the value the user has entered into the variable 'a'.
                cin >> a;
                // Uses the 'cout' output stream to prompt the user to enter an integer 'b'.
                cout << "Enter an integer for 'b': ";
                // Uses the 'cin' input operator to assign the value the user has entered into the variable 'b'.
                cin >> b;
                // Uses the 'cout' output stream to prompt the user to enter an integer 'm' which will be the modulus.
                cout << "Enter the modulus 'm': ";
                // Uses the 'cin' input operator to assign the value the user has entered into the variable 'm' as the modulus.
                cin >> m;

                // This if statement is used to ensure that the modulus 'm' is not 0, as this will result in an error.
                if (m != 0) {
                    // A call is made to the 'congruenceCalculator' function to check if 'a' and 'b' are congruent in mod 'm'.
                    congruenceCalculator(a, b, m);
                // This else statement will execute if the mod 'm' is 0, using the 'cout' output stream to prompt the user the mod
                // cannot be 0.    
                } else {
                    cout << "The mod cannot be 0!" << endl;
                }
                // The 'break' statement is used to terminate this case, and return to the main menu.
                break;
            // Case 4 is responsible for checking if a number is a prime number.
            case 4:
                // Uses the 'cout' output stream to prompt the user to enter an integer 'a'.
                cout << "Enter an integer: ";
                // Uses the 'cin' input operator to assign the value the user has entered into the variable 'a'.
                cin >> a;

                // This if statement first makes a call to the 'primeCheck' function, as this function returns true
                // if the number is prime.
                if (primeCheck(a)) {
                    // If the number is prime, the program outputs the number, and that it is a prime number.
                    cout << a << ", is a prime number!\n";
                // This else statement will execute if the number is not prime.
                } else {
                    // If the number is not prime, the program will output the number, and that it is not prime.
                    cout << a << ", is not a prime number!\n";
                }
                // The 'break' statement is used to terminate this case, and return to the main menu.
                break;
            // Case 5 is used to check if a number is a Fibonacci Number / apart of the Fibonacci Sequence.
            case 5:
                // Uses the 'cout' output stream to prompt the user to enter an integer 'a'.
                cout << "Enter an integer: ";
                // Uses the 'cin' input operator to assign the value the user has entered into the variable 'a'.
                cin >> a;

                // This if statement makes a call to the 'fibonacciCheck' function passing the user entered value
                // assigned to 'a' as an argument.
                if (fibonacciCheck(a)) {
                    // If the function returns true, meaning the number is considered a Fibonacci Number, the number is 
                    // output to the console, and the user is prompted that it is a Fibonacci Number.
                    cout << a << ", is a Fibonacci number!\n";
                // If the number is not a Fibonacci Number, the else statement will be executed. 
                } else {
                    // Since the number is not a Fibonacci Number, the number itself and that the number is not a Fibonacci
                    // Number is output to the console.
                    cout << a << ", is not a Fibonacci number!\n";
                }
                // The 'break' statement is used to terminate this case, and return to the main menu.
                break;
            // Case 6 is responsible for prompting the user with a goodbye message, as choosing this option indicates that
            // the user would like to exit the program.    
            case 6:
                cout << "Exiting the Calculator! Goodbye!";
                // The 'break' statement is used to terminate this case, and return to the main menu.
                break;
            // The Default Case is responsible for the case where the user enters an invalid menu option, an option that is not
            // listed. The user will be prompted that their choice is not a choice, and they must try again.
            default:
                cout << "This was not a choice, please try again!";
                // The 'break' statement is used to terminate this case, and return to the main menu.
                break;
        }
    // This while loop is responsible for iterating through/executing the switch case as long as the user enters a choice
    // that is not 6.
    } while (choice != 6);
    // This line of code signifies that the program succesfully executed, and is terminating with a status code of 0.
    // This completes the execution of the main function in the program.
    return 0;
}
