#include "ingresarfact.h"
#include "ui_ingresarfact.h"
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <algorithm>
#include <QDir>
#include <QFileInfo>

IngresarFact::IngresarFact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IngresarFact)
{
    ui->setupUi(this);

    this ->ui->l1_line_fechaFactura->setText("dd/mm/aaaa");
    this ->ui->l1_line_fechaVencimiento_2->setText("dd/mm/aaaa");

    if(not QDir("./base de datos").exists())
    {
        QDir().mkdir("./base de datos");
    }

    QString nombreArch = "./base de datos/base.txt";
    QFile base_de_datos2(nombreArch);

    if(not QFileInfo::exists("./base de datos/base.txt"))
    {
        base_de_datos2.open(QIODevice::WriteOnly | QIODevice::Text);
        base_de_datos2.close();
    }

    if(not base_de_datos2.open(QIODevice::ReadOnly | QIODevice::Text ))
    {
        QMessageBox::information(0, "error", base_de_datos2.errorString());
    }
    QTextStream entrada(&base_de_datos2);

    while(not entrada.atEnd())
    {
        QString aux = entrada.readLine();
        QStringList datos = aux.split(':');
        Medicamento mediAux(datos.at(0),datos.at(1),datos.at(2),datos.at(3),datos.at(4),datos.at(5),datos.at(6));

        this->inventario.push_back(mediAux);
    }

    base_de_datos2.close();

    if(not QDir("./registro de facturas").exists())
    {
        QDir().mkdir("./registro de facturas");
    }
}

IngresarFact::~IngresarFact()
{
    delete ui;
}

void IngresarFact::on_l1_boton_atras_clicked()
{
    this->close();
}

void IngresarFact::on_l1_boton_cargarFactura_clicked()
{
    QString proveedor,fechaFactura,nroFactura;
    bool ok;

    proveedor = this ->ui->l1_line_proveedor->text();
    fechaFactura = this ->ui->l1_line_fechaFactura->text();
    nroFactura = this ->ui->l1_linea_nroFact->text();

    nroFactura.toLongLong(&ok);

    if(proveedor != "" and QDate::fromString(fechaFactura,"dd/MM/yyyy").isValid() == true and ok == true)
    {

        QString nombreArch = "./base de datos/base.txt";
        QFile base_de_datos2(nombreArch);
        base_de_datos2.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream salida(&base_de_datos2);

    for(uint k = 0; k < this -> inventario.size(); k++)
    {
        salida << this ->inventario[k].get_prinAct() <<':';
        salida << this ->inventario[k].get_nombre() <<':';
        salida << this ->inventario[k].get_lab() <<':';
        salida << this ->inventario[k].get_codigo() <<':';
        salida << this ->inventario[k].get_costo() <<':';
        salida << this ->inventario[k].get_cantidad() <<':';
        salida << this ->inventario[k].get_fechaVenc().toString("dd/MM/yyyy") <<'\n';
    }

    base_de_datos2.close();

    QFile fac("./registro de facturas/"+proveedor+'-'+nroFactura+".txt");
    fac.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream factura(&fac);

    factura <<"Proveedor: "<<proveedor<<" | "<<"Fecha: "<<fechaFactura<<" | "<<"Nro.: "<<nroFactura<<'\n';

    for(uint q = 0; q < this -> factura.size(); q++)
    {
        factura <<"Nombre: " <<this ->factura[q].get_nombre() <<" | ";
        factura <<"Cantidad: " <<this ->factura[q].get_cantidad() <<" | ";
        factura <<"Costo: " <<this ->factura[q].get_costo() <<" | ";
        factura <<"Laboratorio: " <<this ->factura[q].get_lab() <<" | ";
        factura <<"Vencimiento: " <<this ->factura[q].get_fechaVenc().toString("dd/MM/yyyy") <<" | ";
        factura <<"Componente: " <<this ->factura[q].get_prinAct() <<" | ";
        factura <<"Codigo: " <<this ->factura[q].get_codigo() <<'\n';
    }

    fac.close();
    QMessageBox::information(0,"Operacion","Factura cargada correctamente");
    this->ui->l1_line_proveedor->setText("");
    this->ui->l1_line_fechaFactura->setText("");
    this->ui->l1_linea_nroFact->setText("");

    }

    else
    {
        QMessageBox::information(0,"error","Formato de fechas invalido o informacion en blanco");
    }
}

void IngresarFact::on_l1_boton_anexar_2_clicked()
{
        QString nombre,principio,laboratorio,codigo,fechaVenc,costo,cantRecibida;
        bool existe = false;
        bool ok;

        nombre = this ->ui->l1_linea_nombre_2->text();
        principio = this ->ui->l1_linea_principioAct_2->text();
        laboratorio = this ->ui->l1_linea_laborat_2->text();
        codigo = this ->ui->l1_linea_codigo_2->text();
        fechaVenc = this ->ui->l1_line_fechaVencimiento_2->text();
        costo = this ->ui->l1_linea_costo_2->text();
        cantRecibida = this ->ui->l1_linea_cantidad_2->text();

        codigo.toULongLong(&ok);
        float p = costo.toFloat(&ok);
        cantRecibida.toUInt(&ok);


        if(nombre != "" and principio != "" and laboratorio != "" and ok == true and p > 0
                and QDate::fromString(fechaVenc,"dd/MM/yyyy").isValid() == true
                and QDate::fromString(fechaVenc,"dd/MM/yyyy") > QDate::currentDate())
        {

        Medicamento aux(principio,nombre,laboratorio,codigo,costo,cantRecibida,fechaVenc);

        for(uint k = 0; k < this -> inventario.size(); k++)
        {
            if(aux == inventario[k])
            {
            this ->inventario[k].set_cantidad(QString::number(this ->inventario[k].get_cantidad().toInt()+aux.get_cantidad().toInt()));
            existe = true;
            }

            else if(this->inventario[k].get_cantidad().toInt()==0 and this->inventario[k].get_costo() != aux.get_costo()
                    and aux.get_codigo() == this->inventario[k].get_codigo() and aux.get_fechaVenc() != this->inventario[k].get_fechaVenc()
                    and aux.get_lab() == this->inventario[k].get_lab() and aux.get_nombre() == this->inventario[k].get_nombre()
                    and aux.get_prinAct() == this->inventario[k].get_prinAct())
            {
                this->inventario[k].set_cantidad(aux.get_cantidad());
                this->inventario[k].set_costo(aux.get_costo());
                this->inventario[k].set_fechaVenc(aux.get_fechaVenc().toString("dd/MM/yyyy"));
                existe = true;
            }
        }


        if(existe == false)
            this ->inventario.push_back(aux);

        this->factura.push_back(aux);

        this ->ui->l1_line_fechaVencimiento_2->setText("dd/mm/aaaa");
        this ->ui->l1_linea_nombre_2->setText("");
        this ->ui->l1_linea_principioAct_2->setText("");
        this ->ui->l1_linea_laborat_2->setText("");
        this ->ui->l1_linea_codigo_2->setText("");
        this ->ui->l1_linea_costo_2->setText("");
        this ->ui->l1_linea_cantidad_2->setText("");

        }
        
        else
        {
            QMessageBox::information(0,"error","Formato de fechas invalido o informacion en blanco");
        }
}
