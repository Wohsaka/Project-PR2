#ifndef VENCIMIENTOS_H
#define VENCIMIENTOS_H

#include <QDialog>
#include "medicamento.h"

namespace Ui {
class Vencimientos;
}

class Vencimientos : public QDialog
{
    Q_OBJECT

public:
    explicit Vencimientos(QWidget *parent = 0);
    ~Vencimientos();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Vencimientos *ui;
    std::vector<Medicamento> inventario;
};

#endif // VENCIMIENTOS_H
