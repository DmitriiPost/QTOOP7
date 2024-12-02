#ifndef POLYNOM_H
#define POLYNOM_H
#include "array.h"
#include <iostream>

using namespace std;

template <class number>
class TPolynom
{
public:
	TPolynom();
	TPolynom(number, int);
    TPolynom(number, number*, int);
    TPolynom(int);

	void printFirst();
	void printSecond();
	number calcPolynom(number);
	void input();
	void changeCoeff(number);
	void changeRoot(int, number);
	void changeRootSize(int);
    QString polynomCanonToQString();
    QString polynomClassicToQString();

protected:
    TArray<number> coeffs;

private:
    TArray<number> roots;
    number seniorCoeff;

	void calcCoeff();
};

template <class number>
TPolynom<number>::TPolynom()
{
    seniorCoeff = 0;
    roots;
}

template <class number>
void TPolynom<number>::calcCoeff()
{
    int degree = roots.getSize();
    coeffs.changeSize(degree + 1);
    coeffs.changeElement(1, 1); // коэф. полинома первой степени
    coeffs.changeElement(roots.getElem(0) * (-1), 0);

    for (int k = 2; k <= degree; k++)
    {
        // коэф. полинома степени k
        coeffs.changeElement(coeffs.getElem(k - 1), k);
        for (int i = k - 1; i > 0; i--)
        {
            coeffs.changeElement(coeffs.getElem(i - 1) - coeffs.getElem(i) * roots.getElem(k - 1), i);
        }
        coeffs.changeElement(coeffs.getElem(0) * roots.getElem(k - 1) * (-1), 0);
    }

    for (int i = 0; i <= degree; i++)
    {
        coeffs.changeElement(coeffs.getElem(i) * seniorCoeff, i);
    }
}

template <class number>
TPolynom<number>::TPolynom(number seniorC, int len)
{
    seniorCoeff = seniorC;
    TArray<number> r(len);
    roots = r;
    calcCoeff();
}

template <class number>
TPolynom<number>::TPolynom(number seniorC, number* arr, int len)
{
    seniorCoeff = seniorC;
    roots.changeSize(len);
    for (int i = 0; i < len; i++)
    {
        roots.changeElement(arr[i], i);
    }
    calcCoeff();
}

template <class number>
TPolynom<number>::TPolynom(int degree)
{
    seniorCoeff = 1;
    roots.changeSize(degree);
    for (int i = 0; i < degree; i++)
    {
        coeffs.changeElement(0, i);
        roots.changeElement(0, i);
    }
}

template <class number>
void TPolynom<number>::printFirst()
{
    int degree = coeffs.getSize() - 1;
    for (int i = degree; i >= 0; i--)
    {
        if (coeffs.getElem(i) != 0)
        {
            if (i != degree)
            {
                cout << (coeffs.getElem(i) > 0 ? " + " : " ");
            }
            cout << coeffs.getElem(i);
            if (i > 0)
            {
                cout << "x ^ " << i;
            }
        }
    }
    cout << "\n";
}

template <class number>
void TPolynom<number>::printSecond()
{
    cout << seniorCoeff;
    int degree = roots.getSize();
    for (int i = degree - 1; i >= 0; i--)
    {
        cout << "(x - " << roots.getElem(i) << ")";
    }
}


template <class number>
number TPolynom<number>::calcPolynom(number x)
{
    number res = 0;
    int degree = coeffs.getSize() - 1;
    for (int i = degree; i >= 0; i--)
    {
        res = res * x + coeffs.getElem(i);
    }
    return res;
}

template <class number>
void TPolynom<number>::input()
{
    cout << "Введите коэффициент an: ";
    cin >> seniorCoeff;
    int n;
    cout << "Введите количество корней полинома: ";
    cin >> n;
    roots.changeSize(n);
    cout << "Введите корни полинома: ";
    for (int i = 0; i < n; i++)
    {
        number root;
        cin >> root;
        roots.changeElement(root, i);
    }
    calcCoeff();
}

template <class number>
void TPolynom<number>::changeCoeff(number newCoeff)
{
    seniorCoeff = newCoeff;
}

template <class number>
void TPolynom<number>::changeRoot(int index, number newRoot)
{
    roots.changeElement(newRoot, index);
    calcCoeff();
}

template <class number>
void TPolynom<number>::changeRootSize(int newSize)
{
    roots.changeSize(newSize);
    calcCoeff();
}

template <class number>
QString TPolynom<number>::polynomCanonToQString()
{
    QString s = "";
    int degree = coeffs.getSize() - 1;
    for (int i = degree; i >= 0; i--)
    {
        if (coeffs.getElem(i) != 0)
        {
            if (i != degree)
            {
                s += " + ";
            }
            s << coeffs.getElem(i);
            if (i > 0)
            {
                s += "x ^ ";
                s += QString().setNum(i);
            }
        }
    }
    return s;
}

template <class number>
QString TPolynom<number>::polynomClassicToQString() {
    QString s = "";
    s << seniorCoeff;
    int degree = roots.getSize();
    for (int i = degree - 1; i >= 0; i--)
    {
        s += "(x - ";
        s << roots.getElem(i);
        s += ")";
    }
    return s;
}


#endif // POLYNOM_H
