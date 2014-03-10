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
    FileManager  manager;
    void SacarPromedio();
    void SacarPromedioDeTabla();

    ~MainWindow();
    
private slots:
    void on_bAddRow_clicked();
    void on_bSaveData_clicked();
    void on_bDeleteRow_clicked();
    void sortItems(int, Qt::SortOrder);
    void sortSlot(int);
    void on_bAddColumna_clicked();
    void on_pbPromedio_clicked();
    void on_leNota1_textChanged(const QString &arg1);
    void on_leNota2_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Qt::SortOrder tipoSort;
};

#endif // MAINWINDOW_H
