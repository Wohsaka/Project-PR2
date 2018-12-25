#include "vencimientos.h"
#include "ui_vencimientos.h"
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFileInfo>
#include <QMessageBox>
#include <algorithm>

Vencimientos::Vencimientos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Vencimientos)
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

    if(not QDir("./vencimientos").exists())
    {
        QDir().mkdir("./vencimientos");
    }
}

Vencimientos::~Vencimientos()
{
    delete ui;
}

void Vencimientos::on_pushButton_clicked()
{
    this->ui->listWidget->clear();
    int dias = this->ui->linea_dias->text().toInt();
    std::vector<QString> venc_proximo;

    std::sort(this->inventario.begin(),this->inventario.end(),Ordenar(5));

    for(uint k = 0; k < this->inventario.size(); k++)
    {
        if(QDate::currentDate().daysTo(this->inventario[k].get_fechaVenc()) <= dias)
        {
            venc_proximo.push_back(this->inventario[k].get_nombre()+" vence el: "+this->inventario[k].get_fechaVenc().toString("dd/MM/yyyy"));
        }
    }

    for(uint q = 0; q < venc_proximo.size(); q++)
    {
        this->ui->listWidget->addItem(venc_proximo[q]);
    }

    if(this->ui->checkBox->isChecked())
    {
        QFile venc("./vencimientos/vencimientos-"+this->ui->linea_dias->text()+"-dias despues del-"+QDate::currentDate().toString("dd-MM-yyyy"));
        venc.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream vencimientos(&venc);

        for(uint t = 0; t < venc_proximo.size(); t++)
        {
            vencimientos << venc_proximo[t] <<'\n';
        }

        QMessageBox::information(0,"Operacion","Vencimientos exportados correctamente");
    }
}
