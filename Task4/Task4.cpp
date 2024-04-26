#include <iostream>
#include <random>

void FillArray(int* arr, int size)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 100);

    for (auto it = arr; it != (arr + size); ++it)
    {
        *it = dist6(rng);
    }
}

void PrintArray(int* arr, int size)
{
    std::cout << "[ ";
    for (auto it = arr; it != (arr + size); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << "]\n";
}

int main()
{
    int arr[10];
    FillArray(arr, 10);

    std::cout << "Array: ";
    PrintArray(arr, 10);

    std::cout << "\nFourth element: " << *(arr + 3) << '\n';
    std::cout << "Element with index 4: " << *(arr + 4) << '\n';
}