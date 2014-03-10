#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
 {

    ui->setupUi(this);
    inicializar();
    tipoSort = Qt::AscendingOrder;
    this->rows="";
    this->columns= "";
    loadData();
    connect(ui->twTable->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortSlot(int)));


}

void MainWindow::inicializar(){

    ui->twTable->setColumnWidth(0,170);
    ui->twTable->setColumnWidth(1,173);
    ui->twTable->setColumnWidth(2,173);

    ui->leNombre->setText("");
    ui->leApellido->setText("");
    ui->leNota1->setText("0");
    ui->leNota2->setText("0");
     ui->lePromedio->setText("0");
    ui->leNumeraCuenta->setText("0");
}

void MainWindow::vaciarLabels(){

    ui->leNombre->setText("");
    ui->leApellido->setText("");
    ui->leNota1->setText("");
    ui->leNota2->setText("");
    ui->lePromedio->setText("");
    ui->leNumeraCuenta->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bAddRow_clicked()
{
   int row = ui->twTable->rowCount()+1;
   int column =0;
   ui->twTable->setRowCount(row);
   llenarListaLabels();
   for(int i = 0 ; i<ui->twTable->columnCount();i++)
        ui->twTable->setItem(row-1,i,new QTableWidgetItem((QString)labels.at(i)));

   labels.clear();
}


void MainWindow::llenarListaLabels(){

    labels.push_back(ui->leNumeraCuenta->text());
    labels.push_back(ui->leNombre->text());
    labels.push_back(ui->leApellido->text());
    labels.push_back(ui->leNota1->text());
    labels.push_back(ui->leNota2->text());
    labels.push_back(ui->lePromedio->text());

}

void MainWindow::on_bSaveData_clicked()
{
    int rows = ui->twTable->rowCount();
    int columns = ui->twTable->columnCount();
    QString rows1,columns1;
    rows1.setNum(rows);
    columns1.setNum(columns);
    rows1+=";";
    columns1+=";";
    QByteArray arr;

    arr.push_back(rows1.toStdString().c_str());
    arr.push_back(columns1.toStdString().c_str());


    /*for(int j = 0 ; j<columns; j++){
        QString headerText=ui->twTable->horizontalHeaderItem(j)->text();

            headerText+=";";
            arr.push_back(headerText.toStdString().c_str());

    }*/

    for(int i = 0 ; i<rows;i++)
    {
        for(int j=0;j<columns;j++){
            QString data = ui->twTable->item(i,j)->text();

                data+=";";
                arr.push_back(data.toStdString().c_str());

        }
    }

    this->manager.writeOnFile(arr);



}

void MainWindow::loadData(){


    int cantidadFilas= 0, cantidadColumnas = 0;
    QByteArray arr = manager.readOnFile();
    QString data(arr), temp;
    temp = data;
    int index= temp.indexOf(";");
    temp.truncate(index);
     index+=1;
    data =data.mid(index);
    cantidadFilas = temp.toInt();
    temp = data;



    index= temp.indexOf(";");
    temp.truncate(index);
    index+=1;
    data = data.mid(index);
    cantidadColumnas = temp.toInt();


    qDebug()<<temp;

    ui->twTable->setRowCount(cantidadFilas);

    for(int i = 0 ; i<cantidadFilas;i++)
    {
        for(int j=0;j<cantidadColumnas;j++){

            temp = data;


            index= temp.indexOf(";");
            temp.truncate(index);
            index+=1;
            data =data.mid(index);
            ui->twTable->setItem(i,j, new QTableWidgetItem(temp));


        }
    }


}

void MainWindow::on_bDeleteRow_clicked()
{
    ui->twTable->removeRow(ui->twTable->currentRow());


}

void MainWindow::sortItems(int index, Qt::SortOrder tipo =Qt::AscendingOrder)
{
    if(tipoSort == Qt::AscendingOrder)
        tipoSort = Qt::DescendingOrder;
    else
        tipoSort = Qt::AscendingOrder;

    ui->twTable->sortItems(index, tipoSort);

}

void MainWindow::sortSlot(int index)
{
    sortItems(index);
}


void MainWindow::on_bAddColumna_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Nombre"),
                                              tr("Ingrese el nombre de la columna: "), QLineEdit::Normal,
                                         "Vacio", &ok);
         if (ok && !text.isEmpty())
         {

                ui->twTable->insertColumn(ui->twTable->columnCount()-1);
                 QTableWidgetItem* newOne = new QTableWidgetItem(text);

                 ui->twTable->setHorizontalHeaderItem(ui->twTable->columnCount()-2,newOne);
                int column = ui->twTable->columnCount()+1;


         }
}

void MainWindow::on_pbPromedio_clicked()
{

}

void MainWindow::on_leNota1_textChanged(const QString &arg1)
{
    SacarPromedio();
}

void MainWindow::on_leNota2_textChanged(const QString &arg1)
{
    SacarPromedio();
}

void MainWindow::SacarPromedio()
{
    float nota1=  ui->leNota1->text().toFloat();
    float nota2=  ui->leNota2->text().toFloat();
    float resultado = (nota1+nota2)/2;
    QString result;
    result.setNum(resultado);
    ui->lePromedio->setText(result);
}


void MainWindow::SacarPromedioDeTabla()
{

}


