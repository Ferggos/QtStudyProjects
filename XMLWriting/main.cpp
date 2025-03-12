#include "mainwindow.h"

#include "records.cpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    const string filename = "student_records.xml";
    StudentRecords records(filename);
    w.show();
    return a.exec();
}
