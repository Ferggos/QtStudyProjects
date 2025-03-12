/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *addGroupBtn;
    QPushButton *addSpecBtn;
    QPushButton *addStudBtn;
    QPushButton *addTeachBtn;
    QPushButton *addDispBtn;
    QPushButton *addPerformBtn;
    QPushButton *SaveEdit;
    QTableWidget *dataTableWidget;
    QPushButton *dispDataBtn;
    QPushButton *updateRecordBtn;
    QPushButton *deleteRecordBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1212, 736);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush5(QColor(0, 0, 0, 127));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush6(QColor(127, 127, 127, 127));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        MainWindow->setPalette(palette);
        MainWindow->setTabletTracking(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        addGroupBtn = new QPushButton(centralwidget);
        addGroupBtn->setObjectName(QString::fromUtf8("addGroupBtn"));
        addGroupBtn->setGeometry(QRect(910, 60, 211, 29));
        addSpecBtn = new QPushButton(centralwidget);
        addSpecBtn->setObjectName(QString::fromUtf8("addSpecBtn"));
        addSpecBtn->setGeometry(QRect(910, 20, 211, 29));
        addStudBtn = new QPushButton(centralwidget);
        addStudBtn->setObjectName(QString::fromUtf8("addStudBtn"));
        addStudBtn->setGeometry(QRect(910, 100, 210, 29));
        addTeachBtn = new QPushButton(centralwidget);
        addTeachBtn->setObjectName(QString::fromUtf8("addTeachBtn"));
        addTeachBtn->setGeometry(QRect(910, 140, 211, 29));
        addDispBtn = new QPushButton(centralwidget);
        addDispBtn->setObjectName(QString::fromUtf8("addDispBtn"));
        addDispBtn->setGeometry(QRect(910, 180, 211, 29));
        addPerformBtn = new QPushButton(centralwidget);
        addPerformBtn->setObjectName(QString::fromUtf8("addPerformBtn"));
        addPerformBtn->setGeometry(QRect(910, 220, 211, 29));
        SaveEdit = new QPushButton(centralwidget);
        SaveEdit->setObjectName(QString::fromUtf8("SaveEdit"));
        SaveEdit->setGeometry(QRect(910, 260, 211, 40));
        dataTableWidget = new QTableWidget(centralwidget);
        if (dataTableWidget->columnCount() < 6)
            dataTableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        dataTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        dataTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        dataTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        dataTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        dataTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        dataTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (dataTableWidget->rowCount() < 1)
            dataTableWidget->setRowCount(1);
        dataTableWidget->setObjectName(QString::fromUtf8("dataTableWidget"));
        dataTableWidget->setGeometry(QRect(0, 20, 901, 540));
        dataTableWidget->setMinimumSize(QSize(740, 0));
        dataTableWidget->setGridStyle(Qt::PenStyle::SolidLine);
        dataTableWidget->setWordWrap(true);
        dataTableWidget->setRowCount(1);
        dataTableWidget->setColumnCount(6);
        dataTableWidget->horizontalHeader()->setVisible(true);
        dataTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        dataTableWidget->horizontalHeader()->setMinimumSectionSize(30);
        dataTableWidget->horizontalHeader()->setDefaultSectionSize(150);
        dataTableWidget->horizontalHeader()->setHighlightSections(false);
        dataTableWidget->horizontalHeader()->setStretchLastSection(true);
        dispDataBtn = new QPushButton(centralwidget);
        dispDataBtn->setObjectName(QString::fromUtf8("dispDataBtn"));
        dispDataBtn->setGeometry(QRect(910, 340, 211, 60));
        updateRecordBtn = new QPushButton(centralwidget);
        updateRecordBtn->setObjectName(QString::fromUtf8("updateRecordBtn"));
        updateRecordBtn->setGeometry(QRect(910, 430, 211, 40));
        deleteRecordBtn = new QPushButton(centralwidget);
        deleteRecordBtn->setObjectName(QString::fromUtf8("deleteRecordBtn"));
        deleteRecordBtn->setGeometry(QRect(910, 480, 211, 40));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1212, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addGroupBtn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\263\321\200\321\203\320\277\320\277\321\203", nullptr));
        addSpecBtn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        addStudBtn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", nullptr));
        addTeachBtn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        addDispBtn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\264\320\270\321\201\321\206\320\270\320\277\320\273\320\270\320\275\321\203", nullptr));
        addPerformBtn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\321\201\320\277\320\265\320\262\320\260\320\265\320\274\320\276\321\201\321\202\321\214", nullptr));
        SaveEdit->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem = dataTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = dataTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\320\274\320\265\321\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = dataTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = dataTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260 \320\272\320\276\320\275\321\202\321\200\320\276\320\273\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = dataTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\320\236\321\206\320\265\320\275\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = dataTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \321\201\320\264\320\260\321\207\320\270", nullptr));
        dispDataBtn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        updateRecordBtn->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        deleteRecordBtn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
