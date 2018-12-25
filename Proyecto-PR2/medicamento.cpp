#include "medicamento.h"

///Constructores

Medicamento::Medicamento()
{
    this -> prinAct = "Principio Activo";
    this -> nombre = "Nombre Original";
    this -> lab = "Laboratorio";
    this -> codigo = "000000001";
    this -> costo = "00.00";
    this -> fechaVenc.setDate(1998,07,06);
}

Medicamento::Medicamento(QString p, QString n, QString l, QString cod, QString cos, QString cant, QString f)
{
    this -> set_princAct(p);
    this -> set_nombre(n);
    this -> set_lab(l);
    this -> set_codigo(cod);
    this -> set_costo(cos);
    this -> set_cantidad(cant);
    this -> set_fechaVenc(f);
}

///Getters
QString Medicamento::get_prinAct() const
{
    return (this -> prinAct);
}
QString Medicamento::get_nombre() const
{
    return (this -> nombre);
}
QString Medicamento::get_lab() const
{
    return (this -> lab);
}
QString Medicamento::get_codigo() const
{
    return (this -> codigo);
}
QString Medicamento::get_costo() const
{
    return (this -> costo);
}
QString Medicamento::get_cantidad() const
{
    return (this ->cantidad);
}
QDate Medicamento::get_fechaVenc() const
{
    return (this -> fechaVenc);
}

///Setters
int Medicamento::set_princAct(QString p)
{
    this -> prinAct = p;
    return 0;
}

int Medicamento::set_nombre(QString n)
{
    this -> nombre = n;
    return 0;
}
int Medicamento::set_lab(QString l)
{
    this -> lab = l;
    return 0;
}

int Medicamento::set_codigo(QString cod)
{
    bool ok;

    if(0 > cod.toLongLong(&ok))
        return -1;

    if(ok == false)
            return -1;

    this -> codigo = cod;
    return 0;
}

int Medicamento::set_costo(QString cos)
{
    bool ok;

    if(0 > cos.toFloat(&ok))
        return -1;

    if(ok == false)
        return -1;

    this -> costo = cos;
    return 0;
}

int Medicamento::set_cantidad(QString cantidad)
{
    if(cantidad.toInt() < 0)
        return -1;

    this ->cantidad = cantidad;
    return 0;
}

int Medicamento::set_fechaVenc(QString f)
{
    QDate valida = QDate::fromString(f,"dd/MM/yyyy");

    if(valida < QDate::currentDate())
        return -1;

    this -> fechaVenc = valida;
    return 0;
}

bool Medicamento::operator==(const Medicamento &m)
{
    return(this->prinAct == m.get_prinAct() and this->nombre == m.get_nombre() and this->lab ==m.get_lab()
           and this->codigo == m.get_codigo() and this->costo == m.get_costo() and this->fechaVenc == m.get_fechaVenc());
}
