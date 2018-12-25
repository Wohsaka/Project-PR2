#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

#include <QObject>
#include <QDate>

class Medicamento
{
        private:
                QString prinAct;
                QString nombre;
                QString lab;
                QString codigo;
                QString costo;
                QString cantidad;
                QDate fechaVenc;

        public:
                ///Constructores
                Medicamento();
                Medicamento(QString p, QString n, QString l, QString cod, QString cos,QString cant, QString f);

                ///Getters
                QString get_prinAct() const;
                QString get_nombre() const;
                QString get_lab() const;
                QString get_codigo() const;
                QString get_costo() const;
                QString get_cantidad() const;
                QDate get_fechaVenc() const;

                ///Setters
                int set_princAct(QString);
                int set_nombre(QString);
                int set_lab(QString);
                int set_codigo(QString);
                int set_costo(QString);
                int set_cantidad(QString);
                int set_fechaVenc(QString);

                bool operator==(const Medicamento &);


};

struct Ordenar
{
    int ordenarPor;

    Ordenar(int ordenarPor)
    {
        this ->ordenarPor = ordenarPor;
    }

    bool operator()(const Medicamento& m1, const Medicamento& m2) const
    {
        if(ordenarPor == 0)
            return(m1.get_nombre() < m2.get_nombre());

        else if(ordenarPor == 1)
            return(m1.get_cantidad().toInt() < m2.get_cantidad().toInt());

        else if(ordenarPor == 2)
            return(m1.get_costo().toFloat() < m2.get_costo().toFloat());

        else if(ordenarPor == 3)
            return(m1.get_prinAct() < m2.get_prinAct());

        else if(ordenarPor == 4)
            return(m1.get_lab() < m2.get_lab());

        else if(ordenarPor == 5)
            return(m1.get_fechaVenc() < m2.get_fechaVenc());

        return -1;

    }
};

#endif // MEDICAMENTO_H
