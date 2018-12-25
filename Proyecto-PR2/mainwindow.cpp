#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this ->ingresar = new IngresarFact;
    this ->verInventario = new Ver_inventario;
    this ->vencimientos = new Vencimientos;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_l0_boton_ingresarFactura_clicked()
{
    this ->ingresar->show();
}

void MainWindow::on_l0_boton_verInventario_clicked()
{
    this -> verInventario->show();
}

void MainWindow::on_boton_vencimientos_clicked()
{
    this ->vencimientos->show();
}
