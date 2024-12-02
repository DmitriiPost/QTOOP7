#include "interface.h"
#include "TFsin.h"
#include "TFSi.h"
#include "complex.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("prog7");
    setFixedSize(400, 300);
    pol_deg_label = new QLabel("Precision:", this);
    pol_deg_label->setGeometry(10, 10, 50, 25);
    pol_deg = new QSpinBox(this);
    pol_deg->setGeometry(70, 10, 40, 25);

    x_label = new QLabel("x:", this);
    x_label->setGeometry(10, 40, 10, 25);
    x_re = new QLineEdit("1", this);
    x_re->setGeometry(25, 40, 20, 25);
    x_im = new QLineEdit("0", this);
    x_im->setGeometry(50, 40, 20, 25);

    sin_mode = new QRadioButton("SIN", this);
    sin_mode->setGeometry(10, 70, 50, 25);
    Si_mode = new QRadioButton("SI", this);
    Si_mode->setGeometry(10, 100, 50, 25);
    sin_mode->setChecked(true);

    calc_btn = new QPushButton("Calc SIN/SI with installed precision", this);
    calc_btn->setGeometry(10, 150, 380, 25);

    output = new QLabel(this);
    output->setGeometry(10, 230, 380, 70);

    connect(calc_btn, SIGNAL(pressed()), this, SLOT(calcFunc()));
}

TInterface::~TInterface()
{
    delete pol_deg_label;
    delete pol_deg;
    delete x_label;
    delete x_re;
    delete x_im;
    delete sin_mode;
    delete Si_mode;
    delete calc_btn;
    delete output;
}

void TInterface::calcFunc()
{
    QString s;
    int degree = pol_deg->text().toInt();
    double dot_re = x_re->text().toDouble();
    double dot_im = x_im->text().toDouble();
    TComplex x(dot_re, dot_im);
    if (sin_mode->isChecked())
    {
        s += "sin at x: ";
        TFsin<TComplex> func(degree);
        s << func.calcPolynom(x);
    }
    else
    {
        s += "si at x: ";
        TFSi<TComplex> func(degree);
        s << func.calcPolynom(x);
    }
    output->setText(s);
}
