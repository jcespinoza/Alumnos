/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lePromedio;
    QLineEdit *leApellido;
    QLabel *lblNombre;
    QLabel *lblNota1;
    QLineEdit *leNota1;
    QLabel *lblNumeroCuenta;
    QLineEdit *leNota2;
    QPushButton *bDeleteRow;
    QLineEdit *leNombre;
    QPushButton *bAddColumna;
    QLabel *lblNota2;
    QPushButton *bSaveData;
    QLabel *lblApellido;
    QLineEdit *leNumeraCuenta;
    QPushButton *bAddRow;
    QLabel *lblPromedio;
    QTableWidget *twTable;
    QWidget *tab_2;
    QComboBox *filtroCombo;
    QLabel *label;
    QLineEdit *leTermino;
    QLabel *label_2;
    QTableWidget *twTable_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(930, 545);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 931, 501));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        lePromedio = new QLineEdit(tab);
        lePromedio->setObjectName(QStringLiteral("lePromedio"));
        lePromedio->setGeometry(QRect(160, 130, 113, 20));
        lePromedio->setAlignment(Qt::AlignCenter);
        lePromedio->setReadOnly(true);
        leApellido = new QLineEdit(tab);
        leApellido->setObjectName(QStringLiteral("leApellido"));
        leApellido->setGeometry(QRect(10, 130, 113, 20));
        leApellido->setAlignment(Qt::AlignCenter);
        lblNombre = new QLabel(tab);
        lblNombre->setObjectName(QStringLiteral("lblNombre"));
        lblNombre->setGeometry(QRect(50, 60, 46, 13));
        lblNota1 = new QLabel(tab);
        lblNota1->setObjectName(QStringLiteral("lblNota1"));
        lblNota1->setGeometry(QRect(190, 10, 46, 13));
        leNota1 = new QLineEdit(tab);
        leNota1->setObjectName(QStringLiteral("leNota1"));
        leNota1->setGeometry(QRect(160, 30, 113, 20));
        leNota1->setAlignment(Qt::AlignCenter);
        lblNumeroCuenta = new QLabel(tab);
        lblNumeroCuenta->setObjectName(QStringLiteral("lblNumeroCuenta"));
        lblNumeroCuenta->setGeometry(QRect(30, 10, 71, 16));
        leNota2 = new QLineEdit(tab);
        leNota2->setObjectName(QStringLiteral("leNota2"));
        leNota2->setGeometry(QRect(160, 80, 113, 20));
        leNota2->setAlignment(Qt::AlignCenter);
        bDeleteRow = new QPushButton(tab);
        bDeleteRow->setObjectName(QStringLiteral("bDeleteRow"));
        bDeleteRow->setGeometry(QRect(0, 250, 131, 51));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/icons/Resources/delete"), QSize(), QIcon::Normal, QIcon::Off);
        bDeleteRow->setIcon(icon);
        leNombre = new QLineEdit(tab);
        leNombre->setObjectName(QStringLiteral("leNombre"));
        leNombre->setGeometry(QRect(10, 80, 113, 20));
        leNombre->setAlignment(Qt::AlignCenter);
        bAddColumna = new QPushButton(tab);
        bAddColumna->setObjectName(QStringLiteral("bAddColumna"));
        bAddColumna->setGeometry(QRect(150, 250, 131, 51));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/icons/Resources/add"), QSize(), QIcon::Normal, QIcon::Off);
        bAddColumna->setIcon(icon1);
        lblNota2 = new QLabel(tab);
        lblNota2->setObjectName(QStringLiteral("lblNota2"));
        lblNota2->setGeometry(QRect(200, 60, 51, 16));
        bSaveData = new QPushButton(tab);
        bSaveData->setObjectName(QStringLiteral("bSaveData"));
        bSaveData->setGeometry(QRect(150, 190, 131, 51));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/icons/Resources/save"), QSize(), QIcon::Normal, QIcon::Off);
        bSaveData->setIcon(icon2);
        lblApellido = new QLabel(tab);
        lblApellido->setObjectName(QStringLiteral("lblApellido"));
        lblApellido->setGeometry(QRect(50, 110, 46, 13));
        leNumeraCuenta = new QLineEdit(tab);
        leNumeraCuenta->setObjectName(QStringLiteral("leNumeraCuenta"));
        leNumeraCuenta->setGeometry(QRect(10, 30, 113, 20));
        leNumeraCuenta->setAlignment(Qt::AlignCenter);
        bAddRow = new QPushButton(tab);
        bAddRow->setObjectName(QStringLiteral("bAddRow"));
        bAddRow->setGeometry(QRect(0, 190, 131, 51));
        bAddRow->setIcon(icon1);
        lblPromedio = new QLabel(tab);
        lblPromedio->setObjectName(QStringLiteral("lblPromedio"));
        lblPromedio->setGeometry(QRect(190, 110, 46, 13));
        twTable = new QTableWidget(tab);
        if (twTable->columnCount() < 6)
            twTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        twTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        twTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        twTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        twTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        twTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        twTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        twTable->setObjectName(QStringLiteral("twTable"));
        twTable->setGeometry(QRect(290, 0, 621, 381));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        filtroCombo = new QComboBox(tab_2);
        filtroCombo->setObjectName(QStringLiteral("filtroCombo"));
        filtroCombo->setGeometry(QRect(20, 50, 171, 22));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 61, 16));
        leTermino = new QLineEdit(tab_2);
        leTermino->setObjectName(QStringLiteral("leTermino"));
        leTermino->setGeometry(QRect(20, 110, 171, 20));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 131, 16));
        twTable_2 = new QTableWidget(tab_2);
        if (twTable_2->columnCount() < 6)
            twTable_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        twTable_2->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        twTable_2->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        twTable_2->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        twTable_2->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        twTable_2->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        twTable_2->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        twTable_2->setObjectName(QStringLiteral("twTable_2"));
        twTable_2->setGeometry(QRect(290, 0, 621, 381));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 930, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(leNumeraCuenta, leNombre);
        QWidget::setTabOrder(leNombre, leApellido);
        QWidget::setTabOrder(leApellido, leNota1);
        QWidget::setTabOrder(leNota1, leNota2);
        QWidget::setTabOrder(leNota2, lePromedio);
        QWidget::setTabOrder(lePromedio, bAddRow);
        QWidget::setTabOrder(bAddRow, bSaveData);
        QWidget::setTabOrder(bSaveData, bDeleteRow);
        QWidget::setTabOrder(bDeleteRow, bAddColumna);
        QWidget::setTabOrder(bAddColumna, twTable);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        lblNombre->setText(QApplication::translate("MainWindow", "Nombre:", 0));
        lblNota1->setText(QApplication::translate("MainWindow", "Nota 1:", 0));
        lblNumeroCuenta->setText(QApplication::translate("MainWindow", "# De Cuenta:", 0));
        bDeleteRow->setText(QApplication::translate("MainWindow", "Eliminar", 0));
        bAddColumna->setText(QApplication::translate("MainWindow", "Agregar Columna", 0));
        lblNota2->setText(QApplication::translate("MainWindow", "Nota 2:", 0));
        bSaveData->setText(QApplication::translate("MainWindow", "Guardar", 0));
        lblApellido->setText(QApplication::translate("MainWindow", "Apellido:", 0));
        bAddRow->setText(QApplication::translate("MainWindow", "Agregar", 0));
        lblPromedio->setText(QApplication::translate("MainWindow", "Promedio: ", 0));
        QTableWidgetItem *___qtablewidgetitem = twTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "# Cuenta", 0));
        QTableWidgetItem *___qtablewidgetitem1 = twTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Nombre", 0));
        QTableWidgetItem *___qtablewidgetitem2 = twTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Apellido", 0));
        QTableWidgetItem *___qtablewidgetitem3 = twTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Nota", 0));
        QTableWidgetItem *___qtablewidgetitem4 = twTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Nota 2", 0));
        QTableWidgetItem *___qtablewidgetitem5 = twTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Promedio", 0));
#ifndef QT_NO_TOOLTIP
        twTable->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>click en el titulo para ordenarlo</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Registro", 0));
        filtroCombo->clear();
        filtroCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "# de Cuenta", 0)
         << QApplication::translate("MainWindow", "Nombre", 0)
         << QApplication::translate("MainWindow", "Apellido", 0)
        );
        label->setText(QApplication::translate("MainWindow", "Buscar por", 0));
        label_2->setText(QApplication::translate("MainWindow", "T\303\251rmino de Busqueda", 0));
        QTableWidgetItem *___qtablewidgetitem6 = twTable_2->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "# Cuenta", 0));
        QTableWidgetItem *___qtablewidgetitem7 = twTable_2->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Nombre", 0));
        QTableWidgetItem *___qtablewidgetitem8 = twTable_2->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Apellido", 0));
        QTableWidgetItem *___qtablewidgetitem9 = twTable_2->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Nota", 0));
        QTableWidgetItem *___qtablewidgetitem10 = twTable_2->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Nota 2", 0));
        QTableWidgetItem *___qtablewidgetitem11 = twTable_2->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Promedio", 0));
#ifndef QT_NO_TOOLTIP
        twTable_2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>click en el titulo para ordenarlo</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Consulta", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
