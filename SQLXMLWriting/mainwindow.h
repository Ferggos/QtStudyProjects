#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QFileDialog>
#include "records.cpp"
#include <QtSql>
#include "sqlrecord.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSaveEdit();
    void onAddSpeciality();
    void onAddGroup();
    void onAddStudent();
    void onAddTeacher();
    void onAddDiscipline();
    void onAddPerformance();
    void displayData();
    void onUpdateRecord();
    void onDeleteRecord();
    void sqlImport();
    void sqlExport();

private:
    Ui::MainWindow *ui;
    StudentRecords studentRecords;
    QSqlDatabase db;
    sqlrecord sqlRecord;
    QString findEntityName(const QString& parentTag, const QString& entityTag,
                           const QString& codeAttr, const QString& code,
                           const QString& nameAttr);
};

#endif
