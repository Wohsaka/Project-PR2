#ifndef INGRESARFACT_H
#define INGRESARFACT_H

#include <QDialog>
#include "medicamento.h"

namespace Ui {
class IngresarFact;
}

class IngresarFact : public QDialog
{
    Q_OBJECT

public:
    explicit IngresarFact(QWidget *parent = 0);
    ~IngresarFact();

private slots:
    void on_l1_boton_atras_clicked();

    void on_l1_boton_cargarFactura_clicked();

    void on_l1_boton_anexar_2_clicked();

private:
    Ui::IngresarFact *ui;
    std::vector<Medicamento> inventario;
    std::vector<Medicamento> factura;
};

#endif // INGRESARFACT_H
