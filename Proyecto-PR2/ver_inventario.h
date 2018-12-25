#ifndef VER_INVENTARIO_H
#define VER_INVENTARIO_H

#include <QDialog>
#include "medicamento.h"

namespace Ui {
class Ver_inventario;
}

class Ver_inventario : public QDialog
{
    Q_OBJECT

public:
    explicit Ver_inventario(QWidget *parent = 0);
    ~Ver_inventario();

private slots:
    void on_l2_boton_ordenarPorNombre_clicked();

    void on_l2_boton_ordenarPorCantidad_clicked();

    void on_l2_boton_reves_clicked();

    void on_l2_boton_ordenarPorCosto_clicked();

    void on_l2_boton_ordenarPorComponente_clicked();

    void on_l2_boton_ordenarPorLaboratorio_clicked();

    void on_l2_boton_ordenarPorVencimiento_clicked();

private:
    Ui::Ver_inventario *ui;
    std::vector<Medicamento> inventario;
};

#endif // VER_INVENTARIO_H
