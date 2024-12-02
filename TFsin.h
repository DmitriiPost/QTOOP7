#ifndef TFSIN_H
#define TFSIN_H
#include "TFunction.h"

template <class number>
class TFsin : public TFunction<number>
{
    number* d;
    number* c(int degree)
    {
        d = new number[degree + 1];
        for (int i = 0; i <= degree; i++)
        {
            if (i % 4 == 1)
            {
                d[i] = 1;
            }
            else if (i % 4 == 3)
            {
                d[i] = -1;
            }
            else
            {
                d[i] = 0;
            }
        }
        return d;
    }

public:
    TFsin(int degree) : TFunction<number>(degree, c(degree)){}
    ~TFsin() {delete[] d;}
};


#endif // TFSIN_H
