#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filemanager.h"
#include <QDebug>
#include <QList>
#include <QString>
#include <QInputDialog>
#include <QDir>
#include <QByteArray>
#include <QTableWidget>
#include "tabladedatos.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void inicializar();
    void vaciarLabels();
    void llenarListaLabels();
    void loadData();
    QString rows, columns;
    QList<QString>*data;
    QList<QString>labels;
    QStringList tableHeader;
    FileManager  manager;
    void SacarPromedio(int nota, int estado);
    void SacarPromedioDeTabla();
    float suma;
    float divi;
    void ActualizarTablabusqueda();
    QList<TablaDeDatos> busqueda;
    void llenarListaBusqueda();
    ~MainWindow();
    
private slots:
    void on_bAddRow_clicked();

    void on_bSaveData_clicked();

    void on_bDeleteRow_clicked();

    void sortItems(int, Qt::SortOrder);

    void sortSlot(int);

    void on_bAddColumna_clicked();

    void on_pbPromedio_clicked();

    void on_cb1_stateChanged(int arg1);

    void on_cb2_stateChanged(int arg1);

    void on_cb3_stateChanged(int arg1);

    void on_cb4_stateChanged(int arg1);

    void on_cb5_stateChanged(int arg1);


    void on_leNota1_textChanged(const QString &arg1);

    void on_tbwSeccion_currentChanged(int indextw);

    void on_lebusqueda_textChanged(const QString &arg1);

    void on_bCambiar_clicked();

private:
    Ui::MainWindow *ui;
    Qt::SortOrder tipoSort;
};

#endif // MAINWINDOW_H
