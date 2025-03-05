#include <iostream>
#include <cmath>

using namespace std;
/**
 * @brief считывает целое число с клавиатуры с проверкой ввода
 * @return считанное значение
*/
int getValue();

/**
 * @brief считывает вещественное число с клавиатуры с проверкой ввода
 * @return считанное значение
*/
double getDouble();

/**
 * @brief проверяет, что введенное значение удовлетваряет условию n>=1
 * @param n считанное значение
*/
void checkN(const int n);

/**
 * @brief Рассчитывает сумму n первых членов ряда
 * @param n заданное число членов
 * @return сумму n первых членов ряда
*/
double sumN(const int n);

/**
 * @brief Рассчитывает следующий член ряда через рекуррентное выражение
 * @param curent текущий член ряда
 * @param i текущий индекс
 * @return следующий член ряда
*/
double getNext(const double current, const int i);

/**
 * @brief проверяет, что введенное значение удовлетваряет условию e>0
 * @param e считанное значение
*/
void checkE(const double e);

/**
 * @brief Рассчитывает сумму первых членов ряда, не превышающих по модулю e
 * @param e заданная точность
 * @return сумму первых членов ряда, не превышающих по модулю e
*/
double sumE(const double e);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена верно
*/
int main()
{
    setlocale(LC_ALL,"Russian");
    cout<<"Введите число членов ряда для рассчета последовательности: ";
    int n = getValue();
    checkN(n);
    cout<<"Сумма "<<n<<" членов ряда равна "<<sumN(n)<<endl;
    cout<<"Введите погрешность для рассчета последовательности: ";
    double e = getDouble();
    checkE(e);
    cout<<"Сумма членов ряда с точностью е равна "<<sumE(e)<<endl;;
    return 0;
}

int getValue()
{
    int value = 0;
    cin>>value;
    if (cin.fail())
    {
        cout<<"Ошибка ввода"<<endl;
        abort();
    }
    return value;
}

double getDouble()
{
    double value = 0.0;
    cin>>value;
    if (cin.fail())
    {
        cout<<"Ошибка ввода"<<endl;
        abort();
    }
    return value;
}

void checkN(const int n)
{
    if (n < 1)
    {
        cout << "Ошибка ввода"<< endl;
        abort();
    }
}

double sumN(const int n)
{
    
    const double first = (-1.0)/2;
    double curent = first;
    double result = first;
    for (int i = 1; i < n ; i++)
    {
        curent = getNext(curent, i);
        result += curent;
    }
    return result;
}

double getNext(const double curent, const int i)
{
    return curent * (-1.0)/(i+1)/(i+2);
}

void checkE(const double e)
{
        if (!(e > 0))
        {
        cout << "Ошибка ввода"<< endl;
        abort();
        }
}

double sumE(const double e)
{
    const double first = (-1.0)/2;
    double curent = first;
    double result = 0;
    for (int i = 1; abs(curent) > e ; i++)
    {
        result += curent;
        curent = getNext(curent, i);
        
    }
    return result;
}
