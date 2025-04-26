#include <iostream>

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciTail(int n, int a, int b)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fibonacciTail(n - 1, b, a + b);
}

int main()
{
    int n;

    std::cout << "Enter the number of Fibonacci terms: ";
    std::cin >> n;

    std::cout << "Standard Recursion: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << fibonacci(i) << " ";
    }

    std::cout << std::endl
              << "Tail Recursion: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << fibonacciTail(i, 0, 1) << " ";
    }
    std::cout << std::endl;

    return 0;
}
