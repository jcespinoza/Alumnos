#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
 {
    qApp->setStyle("fusion");

    ui->setupUi(this);
    inicializar();
    tipoSort = Qt::AscendingOrder;
    this->rows="";
    this->columns= "";
    loadData();
    connect(ui->twTable->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortSlot(int)));
    suma=0;
    divi=0;
    ui->tbwSeccion->setCurrentIndex(0);
    on_bSaveData_clicked();

}

void MainWindow::inicializar(){

    ui->twTable->setColumnWidth(0,170);
    ui->twTable->setColumnWidth(1,173);
    ui->twTable->setColumnWidth(2,173);

    ui->leNombre->setText("");
    ui->leApellido->setText("");
    ui->leNota1->setText("0");
    ui->leNota2->setText("0");
    ui->leNota3->setText("0");
    ui->leNota4->setText("0");
    ui->leNota5->setText("0");

    // ui->lePromedio->setText("0");
    //ui->leNumeraCuenta->setText("0");
}

void MainWindow::vaciarLabels(){

    ui->leNombre->setText("");
    ui->leApellido->setText("");
    ui->leNota1->setText("0");
    ui->leNota2->setText("0");
    ui->leNota3->setText("0");
    ui->leNota4->setText("0");
    ui->leNota5->setText("0");
    ui->lePromedio->setText("");
    ui->leNumeraCuenta->setText("");
    ui->cb1->setChecked(false);
    ui->cb2->setChecked(false);
    ui->cb3->setChecked(false);
    ui->cb4->setChecked(false);
    ui->cb5->setChecked(false);
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
   vaciarLabels();
    suma=0;
    divi=0;
}


void MainWindow::llenarListaLabels(){

    labels.push_back(ui->leNumeraCuenta->text());
    labels.push_back(ui->leNombre->text());
    labels.push_back(ui->leApellido->text());
    labels.push_back(ui->leNota1->text());
    labels.push_back(ui->leNota2->text());
    labels.push_back(ui->leNota3->text());
    labels.push_back(ui->leNota4->text());
    labels.push_back(ui->leNota5->text());

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


  /*  for(int j = 0 ; j<columns; j++){
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
    llenarListaBusqueda();


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

   /* for(int j = 0 ; j<cantidadColumnas; j++){
        temp = data;
        index= temp.indexOf(";");
        temp.truncate(index);
        index+=1;
        data =data.mid(index);
        this->tableHeader.push_back(temp);

    }
    ui->twTable->setColumnCount(cantidadColumnas);
    ui->twTable->setHorizontalHeaderLabels(this->tableHeader);
*/
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
    int row=ui->twTable->currentRow();

   if(row<0)
   return;

    ui->twTable->removeRow(row);


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



void MainWindow::SacarPromedio(int nota,int estado)
{
    float nota1=  ui->leNota1->text().toFloat();
    float nota2=  ui->leNota2->text().toFloat();
    float nota3= ui->leNota3->text().toFloat();
    float nota4= ui->leNota4->text().toFloat();
    float nota5= ui->leNota5->text().toFloat();


    if(nota==1&&estado==2&&nota1>=0&&divi>=0)
    {
            suma+=nota1;
            divi+=1;
    }
    else if(nota==2&&estado==2&&nota1>=0&&divi>=0)
    {
        suma+=nota2;
        divi+=1;
    }
    else if(nota==3&&estado==2&&nota1>=0&&divi>=0)
    {
        suma+=nota3;
        divi+=1;
    }
    else if(nota==4&&estado==2&&nota1>=0&&divi>=0)
    {
        suma+=nota4;
        divi+=1;
    }
    else if(nota==5&&estado==2&&nota1>=0&&divi>=0)
    {
        suma+=nota5;
        divi+=1;
    }

    else if(nota==1&&estado==0)
    {
        suma-=nota1;
        divi-=1;

    }
    else if(nota==2&&estado==0)
    {
        suma-=nota2;
        divi-=1;
    }
    else if(nota==3&&estado==0)
    {
        suma-=nota3;
        divi-=1;
    }
    else if(nota==4&&estado==0)
    {
        suma-=nota4;
        divi-=1;
    }
    else if(nota==5&&estado==0)
    {
        suma-=nota5;
        divi-=1;
    }
        if(suma<=0||divi<=0)
        {
            ui->lePromedio->setText("0");
            return;
        }

    float resultado = (suma)/divi;
    QString result;
    result.setNum(resultado);
    ui->lePromedio->setText(result);


}


void MainWindow::SacarPromedioDeTabla()
{
}


void MainWindow::on_cb1_stateChanged(int arg1)
{
    if(arg1==2)
        ui->leNota1->setDisabled(true);
    else
        ui->leNota1->setDisabled(false);
   SacarPromedio(1,arg1);
}

void MainWindow::on_cb2_stateChanged(int arg1)
{
    if(arg1==2)
        ui->leNota2->setDisabled(true);
    else
        ui->leNota2->setDisabled(false);
    SacarPromedio(2,arg1);
}

void MainWindow::on_cb3_stateChanged(int arg1)
{
    if(arg1==2)
        ui->leNota3->setDisabled(true);
    else
        ui->leNota3->setDisabled(false);
    SacarPromedio(3,arg1);
}

void MainWindow::on_cb4_stateChanged(int arg1)
{
    if(arg1==2)
        ui->leNota4->setDisabled(true);
    else
        ui->leNota4->setDisabled(false);
    SacarPromedio(4,arg1);
}

void MainWindow::on_cb5_stateChanged(int arg1)
{
    if(arg1==2)
        ui->leNota5->setDisabled(true);
    else
        ui->leNota5->setDisabled(false);
    SacarPromedio(5,arg1);
}



void MainWindow::on_leNota1_textChanged(const QString &arg1)
{

}

void MainWindow::on_tbwSeccion_currentChanged(int indextw)
{
    ActualizarTablabusqueda();

}

void MainWindow::ActualizarTablabusqueda()
{
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

    ui->twTable_2->setRowCount(cantidadFilas);


    for(int i = 0 ; i<cantidadFilas;i++)
    {
        for(int j=0;j<cantidadColumnas;j++){

            temp = data;


            index= temp.indexOf(";");
            temp.truncate(index);
            index+=1;
            data =data.mid(index);
            ui->twTable_2->setItem(i,j, new QTableWidgetItem(temp));


        }
    }
}

void MainWindow::llenarListaBusqueda()
{
    busqueda.clear();
    TablaDeDatos datos;
    if(ui->twTable->rowCount()>0)
    {
        for(int row=0;row<=ui->twTable->rowCount()-1;row++)
        {

                datos.numero_de_cuenta=ui->twTable->item(row,0)->text();

                datos.nombre=ui->twTable->item(row,1)->text();
                datos.apellido=ui->twTable->item(row,2)->text();
                datos.nota1=ui->twTable->item(row,3)->text();
                datos.nota2=ui->twTable->item(row,4)->text();
                datos.nota3=ui->twTable->item(row,5)->text();
                datos.nota4=ui->twTable->item(row,6)->text();
                datos.nota5=ui->twTable->item(row,7)->text();
                datos.promedio=ui->twTable->item(row,8)->text();
                busqueda.push_back(datos);
        }
    }

}

void MainWindow::on_lebusqueda_textChanged(const QString &arg1)
{
   if(arg1=="")
   {
        ActualizarTablabusqueda();
        return;
   }
   QList<TablaDeDatos> *datosParaDibujar=new QList<TablaDeDatos>();


   for(int i=0;i<busqueda.size();i++)
   {
       if(busqueda.at(i).nombre.contains(arg1))
       {

           datosParaDibujar->push_back(busqueda.at(i));
       }
   }


  if(datosParaDibujar->size()>0)
  {
      ui->twTable_2->setRowCount(datosParaDibujar->size());
      for(int row=0;row<datosParaDibujar->size();row++)
      {

              ui->twTable_2->setItem(row,0, new QTableWidgetItem(datosParaDibujar->at(row).numero_de_cuenta));
              ui->twTable_2->setItem(row,1, new QTableWidgetItem(datosParaDibujar->at(row).nombre));
              ui->twTable_2->setItem(row,2, new QTableWidgetItem(datosParaDibujar->at(row).apellido));
              ui->twTable_2->setItem(row,3, new QTableWidgetItem(datosParaDibujar->at(row).nota1));
              ui->twTable_2->setItem(row,4, new QTableWidgetItem(datosParaDibujar->at(row).nota2));
              ui->twTable_2->setItem(row,5, new QTableWidgetItem(datosParaDibujar->at(row).nota3));
              ui->twTable_2->setItem(row,6, new QTableWidgetItem(datosParaDibujar->at(row).nota4));
              ui->twTable_2->setItem(row,7, new QTableWidgetItem(datosParaDibujar->at(row).nota5));
              ui->twTable_2->setItem(row,8, new QTableWidgetItem(datosParaDibujar->at(row).promedio));

  }

}
}

void MainWindow::on_bCambiar_clicked()
{
   int row =ui->twTable->currentRow();
   if(row<0)
       return;
   ui->leNumeraCuenta->setText(ui->twTable->item(row,0)->text());
   ui->leNombre->setText(ui->twTable->item(row,1)->text());
   ui->leApellido->setText(ui->twTable->item(row,2)->text());
   ui->leNota1->setText(ui->twTable->item(row,3)->text());
   ui->leNota2->setText(ui->twTable->item(row,4)->text());
   ui->leNota3->setText(ui->twTable->item(row,5)->text());
   ui->leNota4->setText(ui->twTable->item(row,6)->text());
   ui->leNota5->setText(ui->twTable->item(row,7)->text());

      ui->twTable->removeRow(ui->twTable->currentRow());

}
