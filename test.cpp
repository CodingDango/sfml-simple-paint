Question #1

Write a program that asks the user to enter two integers, one named smaller, the other named larger. If the user enters a smaller value for the second integer, use a block and a temporary variable to swap the smaller and larger values. Then print the values of the smaller and larger variables. Add comments to your code indicating where each variable dies. Note: When you print the values, smaller should hold the smaller input and larger the larger input, no matter which order they were entered in.

The program output should match the following:

Enter an integer: 4
Enter a larger integer: 2
Swapping the values
The smaller value is 2
The larger value is 4

-- Below is my code.

#include <iostream>

int getInteger(std::string_view prompt)
{
    int n {};
    std::cout << prompt;
    std::cin >> n;

    return n;
}

int main() 
{// Block of main starts here
    int smaller { getInteger("Enter an integer: ") };
    int larger { getInteger("Enter a larger integer: ") };

    // Preferable we could have used a function, but this is
    // For the challenge requirements.
    if (smaller > larger)
    { // Nested block starts here
        std::cout << "Swapping the values\n";

        int temp = smaller;
        smaller = larger;
        larger = temp;
    } // Nested block ends here, temp the variable we initialized will be destroyed here.

    std::cout << "The smaller value is " << smaller
              << "The larger value is " << larger 
              << '\n';

}// Block of main ends here. smaller, and larger will be destroyed here.

Question #2

What’s the difference between a variable’s scope, duration, and lifetime? By default, what kind of scope and duration do local variables have (and what do those mean)?

-- My answer: a variables scope is the block where it is located in? the duration means the lifetime of the object, meaning when it will be destoryed, lifetime is the same as duration? by default, scope and duration for local variables is when the block starts and ends?