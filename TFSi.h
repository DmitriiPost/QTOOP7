#ifndef TFSI_H
#define TFSI_H
#include "TFunction.h"

template <class number>
class TFSi : public TFunction<number>
{
    number* d;
    number* c(int degree)
    {
        d = new number[degree + 1];
        for (int i = 0; i <= degree; i++)
        {
            if (i % 4 == 1)
            {
                d[i] = number(1) / number(i);
            }
            else if (i % 4 == 3)
            {
                d[i] = (number(-1) / number(i));
            }
            else
            {
                d[i] = 0;
            }
        }
        return d;
    }

public:
    TFSi(int degree) : TFunction<number> (degree, c(degree)){}
    ~TFSi() {delete[] d;}
};

#endif // TFSI_H
