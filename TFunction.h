#ifndef TFUNCTION_H
#define TFUNCTION_H

#include "polynom.h"

template <class number>
class TFunction: protected TPolynom<number>
{
public:
    TFunction(int degree, number*);
    using TPolynom<number>::calcPolynom;
};

template <class number>
TFunction<number>::TFunction(int degree, number* derivates) : TPolynom<number>(degree)
{
    TPolynom<number>::coeffs.changeSize(degree + 1);
    TPolynom<number>::coeffs.changeElement(derivates[0], 0);
    int factor = 1;
    for (int i = 1; i <= degree; i++)
    {
        TPolynom<number>::coeffs.changeElement(derivates[i] / number(factor), i);
        factor = factor * (i + 1);
    }
}

#endif // TFUNCTION_H

