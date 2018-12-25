#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "medicamento.h"
#include "ingresarfact.h"
#include "ver_inventario.h"
#include "vencimientos.h"
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_l0_boton_ingresarFactura_clicked();

    void on_l0_boton_verInventario_clicked();

    void on_boton_vencimientos_clicked();

private:
    Ui::MainWindow *ui;
    IngresarFact *ingresar;
    Ver_inventario *verInventario;
    Vencimientos *vencimientos;

};

#endif // MAINWINDOW_H
