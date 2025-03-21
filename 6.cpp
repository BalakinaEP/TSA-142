
#include <iostream>

int getValue();

size_t getSize();

void checkN(const int n);

void fillArray(int* arr, const int n);

void printArray(int* arr, const int n);

int sumOfElements(int* arr, const int n);

void sortArray(int* arr, const int n);

size_t getIndexOfFirstNegative(int* arr, const int n);

int* copyArray(int* arr, const int n);

using namespace std;

int main()
{
    size_t n = getSize();
    int* arr = new int [n];
    fillArray(arr, n);
    printArray(arr,n);
    cout<<"Sum of elements multiples 3: "<< sumOfElements(arr,n)<<endl;
    int index = getIndexOfFirstNegative(arr,n);
    if (index == n)
        {
            cout<<"No negative elements"<<endl;
        }
    else
    {
        cout<<"Index of first negative element: "<< index+1<<endl;
    }    
    int* sortArr = copyArray(arr,n);
    sortArray(sortArr,n);
    printArray(sortArr,n);
    printArray(arr,n);
    delete [] sortArr;
    delete [] arr;

    return 0;
}

int getValue()
{
    int value = 0;
    cin>>value;
    if (cin.fail())
    {
        cout<<"Error"<<endl;
        abort();
    }
    return value;
}

size_t getSize()
{
    std::cout<<"Enter n"<<endl;
    int n = getValue();
    checkN(n);
    return (size_t)n;
}

void checkN(const int n)
{
    if (n<=0)
    {
        cout<<"Error"<<endl;
        abort();
    }
}

void fillArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout<<"Enter arr["<<i+1<<"] = ";
        arr[i] = getValue();
    }
}

void printArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int sumOfElements(int* arr, const int n)
{
    int result = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] % 3 == 0)
        {
            result += arr[i];
        }
    }
    return result;
}

size_t getIndexOfFirstNegative(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            return i;
        }
    }
    return n;
}

void sortArray(int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i; j < n; j++)
        {
            if (arr[i]>arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int* copyArray(int* arr, const int n)
{
    int* copyArr = new int [n];
    for (size_t i = 0; i < n; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}
