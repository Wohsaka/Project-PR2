#include "ver_inventario.h"
#include "ui_ver_inventario.h"
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <algorithm>
#include <QDir>
#include <QFileInfo>

Ver_inventario::Ver_inventario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ver_inventario)
{
    ui->setupUi(this);

    if(not QDir("./base de datos").exists())
    {
        QDir().mkdir("./base de datos");
    }

    QString nombreArch = "./base de datos/base.txt";
    QFile base_de_datos(nombreArch);

    if(not QFileInfo::exists("./base de datos/base.txt"))
    {
        base_de_datos.open(QIODevice::WriteOnly | QIODevice::Text);
        base_de_datos.close();
    }

    if(not base_de_datos.open(QIODevice::ReadOnly | QIODevice::Text ))
    {
        QMessageBox::information(0, "error", base_de_datos.errorString());
    }
    QTextStream entrada(&base_de_datos);

    while(not entrada.atEnd())
    {
        QString aux = entrada.readLine();
        QStringList datos = aux.split(':');
        Medicamento mediAux(datos.at(0),datos.at(1),datos.at(2),datos.at(3),datos.at(4),datos.at(5),datos.at(6));

        this->inventario.push_back(mediAux);
    }

    base_de_datos.close();

    this -> ui->tableWidget->setRowCount(this -> inventario.size());
    this -> ui->tableWidget->setColumnCount(7);
    this -> ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this ->ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Descripcion"));
    this ->ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Cantidad"));
    this ->ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("Costo"));
    this ->ui->tableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem("Principio Activo"));
    this ->ui->tableWidget->setHorizontalHeaderItem(4,new QTableWidgetItem("Laboratorio"));
    this ->ui->tableWidget->setHorizontalHeaderItem(5,new QTableWidgetItem("Vencimiento"));
    this ->ui->tableWidget->setHorizontalHeaderItem(6,new QTableWidgetItem("Codigo"));


    for( uint k = 0; k < this ->inventario.size(); k++)
    {
        this ->ui->tableWidget->setItem(k,0,new QTableWidgetItem(this->inventario[k].get_nombre()));
        this ->ui->tableWidget->setItem(k,1,new QTableWidgetItem(this->inventario[k].get_cantidad()));
        this ->ui->tableWidget->setItem(k,2,new QTableWidgetItem(this->inventario[k].get_costo()));
        this ->ui->tableWidget->setItem(k,3,new QTableWidgetItem(this->inventario[k].get_prinAct()));
        this ->ui->tableWidget->setItem(k,4,new QTableWidgetItem(this->inventario[k].get_lab()));
        this ->ui->tableWidget->setItem(k,5,new QTableWidgetItem(this->inventario[k].get_fechaVenc().toString("dd/MM/yyyy")));
        this ->ui->tableWidget->setItem(k,6,new QTableWidgetItem(this->inventario[k].get_codigo()));
    }
}

Ver_inventario::~Ver_inventario()
{
    delete ui;
}

void Ver_inventario::on_l2_boton_ordenarPorNombre_clicked()
{
    std::sort(this ->inventario.begin(), this ->inventario.end(),Ordenar(0));

    for( uint k = 0; k < this ->inventario.size(); k++)
    {
        this ->ui->tableWidget->setItem(k,0,new QTableWidgetItem(this->inventario[k].get_nombre()));
        this ->ui->tableWidget->setItem(k,1,new QTableWidgetItem(this->inventario[k].get_cantidad()));
        this ->ui->tableWidget->setItem(k,2,new QTableWidgetItem(this->inventario[k].get_costo()));
        this ->ui->tableWidget->setItem(k,3,new QTableWidgetItem(this->inventario[k].get_prinAct()));
        this ->ui->tableWidget->setItem(k,4,new QTableWidgetItem(this->inventario[k].get_lab()));
        this ->ui->tableWidget->setItem(k,5,new QTableWidgetItem(this->inventario[k].get_fechaVenc().toString("dd/MM/yyyy")));
        this ->ui->tableWidget->setItem(k,6,new QTableWidgetItem(this->inventario[k].get_codigo()));
    }
}

void Ver_inventario::on_l2_boton_ordenarPorCantidad_clicked()
{
    std::sort(this ->inventario.begin(), this ->inventario.end(),Ordenar(1));

    for( uint k = 0; k < this ->inventario.size(); k++)
    {
        this ->ui->tableWidget->setItem(k,0,new QTableWidgetItem(this->inventario[k].get_nombre()));
        this ->ui->tableWidget->setItem(k,1,new QTableWidgetItem(this->inventario[k].get_cantidad()));
        this ->ui->tableWidget->setItem(k,2,new QTableWidgetItem(this->inventario[k].get_costo()));
        this ->ui->tableWidget->setItem(k,3,new QTableWidgetItem(this->inventario[k].get_prinAct()));
        this ->ui->tableWidget->setItem(k,4,new QTableWidgetItem(this->inventario[k].get_lab()));
        this ->ui->tableWidget->setItem(k,5,new QTableWidgetItem(this->inventario[k].get_fechaVenc().toString("dd/MM/yyyy")));
        this ->ui->tableWidget->setItem(k,6,new QTableWidgetItem(this->inventario[k].get_codigo()));
    }
}

void Ver_inventario::on_l2_boton_reves_clicked()
{
    std::reverse(this ->inventario.begin(), this ->inventario.end());

    for( uint k = 0; k < this ->inventario.size(); k++)
    {
        this ->ui->tableWidget->setItem(k,0,new QTableWidgetItem(this->inventario[k].get_nombre()));
        this ->ui->tableWidget->setItem(k,1,new QTableWidgetItem(this->inventario[k].get_cantidad()));
        this ->ui->tableWidget->setItem(k,2,new QTableWidgetItem(this->inventario[k].get_costo()));
        this ->ui->tableWidget->setItem(k,3,new QTableWidgetItem(this->inventario[k].get_prinAct()));
        this ->ui->tableWidget->setItem(k,4,new QTableWidgetItem(this->inventario[k].get_lab()));
        this ->ui->tableWidget->setItem(k,5,new QTableWidgetItem(this->inventario[k].get_fechaVenc().toString("dd/MM/yyyy")));
        this ->ui->tableWidget->setItem(k,6,new QTableWidgetItem(this->inventario[k].get_codigo()));
    }
}

void Ver_inventario::on_l2_boton_ordenarPorCosto_clicked()
{
    std::sort(this ->inventario.begin(), this ->inventario.end(),Ordenar(2));

    for( uint k = 0; k < this ->inventario.size(); k++)
    {
        this ->ui->tableWidget->setItem(k,0,new QTableWidgetItem(this->inventario[k].get_nombre()));
        this ->ui->tableWidget->setItem(k,1,new QTableWidgetItem(this->inventario[k].get_cantidad()));
        this ->ui->tableWidget->setItem(k,2,new QTableWidgetItem(this->inventario[k].get_costo()));
        this ->ui->tableWidget->setItem(k,3,new QTableWidgetItem(this->inventario[k].get_prinAct()));
        this ->ui->tableWidget->setItem(k,4,new QTableWidgetItem(this->inventario[k].get_lab()));
        this ->ui->tableWidget->setItem(k,5,new QTableWidgetItem(this->inventario[k].get_fechaVenc().toString("dd/MM/yyyy")));
        this ->ui->tableWidget->setItem(k,6,new QTableWidgetItem(this->inventario[k].get_codigo()));
    }
}

void Ver_inventario::on_l2_boton_ordenarPorComponente_clicked()
{
    std::sort(this ->inventario.begin(), this ->inventario.end(),Ordenar(3));

    for( uint k = 0; k < this ->inventario.size(); k++)
    {
        this ->ui->tableWidget->setItem(k,0,new QTableWidgetItem(this->inventario[k].get_nombre()));
        this ->ui->tableWidget->setItem(k,1,new QTableWidgetItem(this->inventario[k].get_cantidad()));
        this ->ui->tableWidget->setItem(k,2,new QTableWidgetItem(this->inventario[k].get_costo()));
        this ->ui->tableWidget->setItem(k,3,new QTableWidgetItem(this->inventario[k].get_prinAct()));
        this ->ui->tableWidget->setItem(k,4,new QTableWidgetItem(this->inventario[k].get_lab()));
        this ->ui->tableWidget->setItem(k,5,new QTableWidgetItem(this->inventario[k].get_fechaVenc().toString("dd/MM/yyyy")));
        this ->ui->tableWidget->setItem(k,6,new QTableWidgetItem(this->inventario[k].get_codigo()));
    }
}

void Ver_inventario::on_l2_boton_ordenarPorLaboratorio_clicked()
{
    std::sort(this ->inventario.begin(), this ->inventario.end(),Ordenar(4));

    for( uint k = 0; k < this ->inventario.size(); k++)
    {
        this ->ui->tableWidget->setItem(k,0,new QTableWidgetItem(this->inventario[k].get_nombre()));
        this ->ui->tableWidget->setItem(k,1,new QTableWidgetItem(this->inventario[k].get_cantidad()));
        this ->ui->tableWidget->setItem(k,2,new QTableWidgetItem(this->inventario[k].get_costo()));
        this ->ui->tableWidget->setItem(k,3,new QTableWidgetItem(this->inventario[k].get_prinAct()));
        this ->ui->tableWidget->setItem(k,4,new QTableWidgetItem(this->inventario[k].get_lab()));
        this ->ui->tableWidget->setItem(k,5,new QTableWidgetItem(this->inventario[k].get_fechaVenc().toString("dd/MM/yyyy")));
        this ->ui->tableWidget->setItem(k,6,new QTableWidgetItem(this->inventario[k].get_codigo()));
    }
}

void Ver_inventario::on_l2_boton_ordenarPorVencimiento_clicked()
{
    std::sort(this ->inventario.begin(), this ->inventario.end(),Ordenar(5));

    for( uint k = 0; k < this ->inventario.size(); k++)
    {
        this ->ui->tableWidget->setItem(k,0,new QTableWidgetItem(this->inventario[k].get_nombre()));
        this ->ui->tableWidget->setItem(k,1,new QTableWidgetItem(this->inventario[k].get_cantidad()));
        this ->ui->tableWidget->setItem(k,2,new QTableWidgetItem(this->inventario[k].get_costo()));
        this ->ui->tableWidget->setItem(k,3,new QTableWidgetItem(this->inventario[k].get_prinAct()));
        this ->ui->tableWidget->setItem(k,4,new QTableWidgetItem(this->inventario[k].get_lab()));
        this ->ui->tableWidget->setItem(k,5,new QTableWidgetItem(this->inventario[k].get_fechaVenc().toString("dd/MM/yyyy")));
        this ->ui->tableWidget->setItem(k,6,new QTableWidgetItem(this->inventario[k].get_codigo()));
    }
}
