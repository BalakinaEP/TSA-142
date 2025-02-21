#include <iostream>
#include <stdlib.h>
using namespace std;
/**
 * @brief считывает значение с клавиатуры с проверкой ввода
 * @return введенное значение
 */
double getValue();

/**
 * @brief проверяет существование треуголька по введенным сторонам
 * @param a - первая сторона треугольника
 * @param b - вторая сторона треугольника
 * @param c - третья сторона треугольника
 */
void checkExist(const double a, const double b, const double c);

/**
 * @brief рассчитывает периметр треугольника
 * @param a - первая сторона треугольника
 * @param b - вторая сторона треугольника
 * @param c - третья сторона треугольника
 * @return периметр треугольника
 */
double getPerimetr(const double a, const double b, const double c);

/**
 * @brief точка входа в программу
 * @return 0, если прогамма выполнена корректно, иначе 1 
 */
int main()
{
    cout<<"Enter first side ";
    double a = getValue();
    cout<<"Enter second side ";
    double b = getValue();
    cout<<"Enter third side ";
    double c = getValue();
    checkExist(a, b, c);
    cout<<"Perimetr is "<<getPerimetr(a,b,c)<<endl;

    return 0;
}

double getValue()
{
    double value;
    cin>>value;
    if (cin.fail())
    {
        cout<<"Incorrect value"<<endl;
        abort();
    }
    return value;
}

void checkExist(const double a, const double b, const double c)
{
    if (a + b <= c or a + c <= b or b + c <= a)
    {
        cout<<"It can't be triangle"<<endl;
        abort();
    }
}

double getPerimetr(const double a, const double b, const double c)
{
    return a + b + c;
}
