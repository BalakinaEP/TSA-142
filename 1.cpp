#include <iostream>
#include <cmath>
using namespace std;

/**
 *@brief - Функция для вычисления С по заданному уравнению 
 *@param a - значение переменной a
 *@param b - значение переменной b 
 *@return - возвращает рассчитанное значение
 */
double getC(const double a, const double b);

/**
 *@brief - Функция для вычисления D по заданному уравнению 
 *@param a - значение переменной a
 *@param b - значение переменной b 
 *@return - возвращает рассчитанное значение
 */
double getD(const double a, const double b);
/**
 *@brief - Точка входа в программу 
 *@return - возвращает 0, если программа выполнена корректно
 */
int main()
{
    const double a = 0.25;
    const double b = 0.2;
    cout<<"C = "<<getC(a,b)<<endl;
    cout<<"D = "<<getD(a,b);
    return 0;
}

double getC(const double a, const double b)
{
    return a * a + cos(a + b) - exp(a / b);
}

double getD(const double a, const double b)
{
    return a/(b+tan(a+b))+25*log(a);
}
