#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QRadioButton>

class TInterface : public QWidget
{
    Q_OBJECT

    QLabel *pol_deg_label, *x_label, *output;
    QSpinBox *pol_deg;
    QLineEdit *x_re, *x_im;
    QPushButton *calc_btn;
    QRadioButton *sin_mode, *Si_mode;

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();

public slots:
    void calcFunc();
};
#endif // INTERFACE_H
