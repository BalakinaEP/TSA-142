
#include <iostream>
#include <iomanip>
#include <ctime>

int getValue();

size_t getSize();

void checkN(const int n);

int** getNewArray(const size_t m, const size_t n);

void printArray(int** array, const size_t m, const size_t n);

void fillArray(int** array, const size_t m, const size_t n);

void changeMaxElementInLine(int** array, const size_t m, const size_t n);

size_t getMaxIndexInLine(int* array, const size_t n);

void deleteArray(int** array, const size_t m, const size_t n);

int** copyArray(int** array, const size_t m, const size_t n);

int getCountOfMinNegative(int** array, const size_t m, const size_t n);

void addNewColumns(int** array, const size_t m, const size_t n, int** newarray);

int findMinNegative(int** array, const size_t m, const size_t n);

int findFirstNegative(int** array, const size_t m, const size_t n);

void fillRandom(int** array, const size_t m, const size_t n, const int start, const int end);

using namespace std;

enum {RANDOM = 5, MANUAL =6};

int main()
{
    cout<< "Enter m: ";
    size_t m = getSize();
    cout<< "Enter n: ";
    size_t n = getSize();
    int** array = getNewArray(m,n);
    cout<< "Enter the way to fill array: "<< (int)MANUAL<<
        " to fill manually, "<< (int)RANDOM<< " to fill randomly: ";
    int choise = getValue();
    int start = 0;
    int end = 0;
    switch (choise)
    {    
        case RANDOM:    cout<< "Enter start: ";
                        start = getValue();
                        cout<< "Enter end: ";
                        end = getValue();
                        fillRandom(array, m, n, start, end);
                        break;
        case MANUAL:    fillArray(array,m,n);
                        break;
        default:
                        cout<<"Error"<<endl;
                        return 1;
                        break;
    }
    printArray(array, m, n);
    cout<<endl;
    int** arrayCopy = copyArray(array,m,n);
    changeMaxElementInLine(arrayCopy,m,n);
    printArray(arrayCopy,m,n);
    deleteArray(arrayCopy,m,n);
    
    size_t newn = n + getCountOfMinNegative(array,m,n);
    int** resultarray = getNewArray(m,newn);
    addNewColumns(array,m,n,resultarray);
    printArray(resultarray,m,newn);
    deleteArray(resultarray,m,newn);
    deleteArray(array,m,n);
    
    return 0;
}

void fillRandom(int** array, const size_t m, const size_t n, const int start, const int end)
{
    srand(time(0));
    for (size_t i = 0; i<m; i++ )
    {
        for (size_t j = 0; j<n; j++)
        {
            array[i][j] = rand() % (end - start +1 ) + start;
        }
    }
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

int** getNewArray(const size_t m, const size_t n)
{
    int** array = new int*[n];
    for (size_t i = 0; i<n; i++)
    {
        array[i] = new int [m];
    }
    return array;
}

void printArray(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i<m; i++ )
    {
        for (size_t j = 0; j<n; j++)
        {
            cout<<setw(6)<<array[i][j];
        }
        cout<<endl;
    }
}

void fillArray(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i<m; i++ )
    {
        for (size_t j = 0; j<n; j++)
        {
            cout<<"Enter array["<<i<<","<<j<<"] = ";
            array[i][j] = getValue();
        }
    }
}

size_t getMaxIndexInLine(int* array, const size_t n)
{
    size_t  maxIndex =0; 
    for (size_t i=0; i<n; i++)
    {
        if (array[i] > array[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void changeMaxElementInLine(int** array, const size_t m, const size_t n)
{
    for (size_t i=0; i<m;i++)
    {
        size_t maxIndex = getMaxIndexInLine(array[i],n);
        array[i][maxIndex]*=5;
    }
}

int** copyArray(int** array, const size_t m, const size_t n)
{
    int** result = getNewArray(m,n);
    for (size_t i = 0; i<m; i++ )
    {
        for (size_t j = 0; j<n; j++)
        {
            result[i][j] = array[i][j];
        }
        cout<<endl;
    }
    return result;
}

void deleteArray(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i<n; i++)
    {
        delete [] array[i];
    }
    delete [] array;
}


int findFirstNegative(int** array, const size_t m, const size_t n)
{
    for (size_t i = 0; i<m; i++ )
    {
        for (size_t j = 0; j<n; j++)
        {
            if (array[i][j]<0)
            {
                return array[i][j];
            }
        }
    }
    cout<<"No negative elements"<<endl;
    abort();
}

int findMinNegative(int** array, const size_t m, const size_t n)
{
    int minNegative = findFirstNegative(array,m,n);
    for (size_t i = 0; i<m; i++ )
    {
        for (size_t j = 0; j<n; j++)
        {
            if (array[i][j]<minNegative)
            {
                minNegative = array[i][j];
            }
        }
    }
    return minNegative;
}

void addNewColumns(int** array, const size_t m, const size_t n, int** newarray)
{
    int minNegative = findMinNegative(array, m, n);
    size_t newj = 0;
    for (size_t j = 0; j<n; j++)
    {
        for (size_t i = 0; i<m; i++ )
        {
            newarray[i][newj] = array [i][j];
            
        }
        for (size_t i = 0; i<m; i++)
        {
            if (array [i][j] == minNegative)
            {
                for (size_t k=0; k<m; k++)
                {
                    newarray[k][newj+1] = 0;
                }
                newj++;
                break;
            }
            
        }
        newj++;
    }
}
    
    int getCountOfMinNegative(int** array, const size_t m, const size_t n)
    {
        int result = 0;
        int minNegative = findMinNegative(array,m,n);
        for (size_t j = 0; j<n; j++)
        {
        for (size_t i = 0; i<m; i++)
        {
            if (array [i][j] == minNegative)
            {
                result++;
                break;
            }
            
        }
        }
        return result;
    }

