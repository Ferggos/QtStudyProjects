#ifndef SQLRECORD_H
#define SQLRECORD_H

#include <QtSql>
#include "tinyxml2.h"

using namespace tinyxml2;

class sqlrecord
{
public:
    // Метод для подключения к базе данных
    bool connectToDatabase(QSqlDatabase &db);

    void updateXmlWithDbChanges(const char *filePath, QSqlDatabase &db);
    // Метод для парсинга XML и вставки данных в БД
    void parseAndInsertData(const char *filePath, QSqlDatabase &db);

    // Методы для вставки данных в таблицы
    void insertSpecialities(XMLElement *specialityElement, QSqlDatabase &db);
    void insertGroups(XMLElement *groupElement, QSqlDatabase &db);
    void insertStudents(XMLElement *studentElement, QSqlDatabase &db);
    void insertTeachers(XMLElement *teacherElement, QSqlDatabase &db);
    void insertDisciplines(XMLElement *disciplineElement, QSqlDatabase &db);
    void insertPerformances(XMLElement *performanceElement, QSqlDatabase &db);

    // Обновление секции Specialities
    void updateSpecialities(XMLDocument &doc, XMLElement *root, QSqlDatabase &db);

    // Обновление секции Groups
    void updateGroups(XMLDocument &doc, XMLElement *root, QSqlDatabase &db);

    // Обновление секции Students
    void updateStudents(XMLDocument &doc, XMLElement *root, QSqlDatabase &db);

    // Обновление секции Teachers
    void updateTeachers(XMLDocument &doc, XMLElement *root, QSqlDatabase &db);

    // Обновление секции Disciplines
    void updateDisciplines(XMLDocument &doc, XMLElement *root, QSqlDatabase &db);

    // Обновление секции Performances
    void updatePerformances(XMLDocument &doc, XMLElement *root, QSqlDatabase &db);

    void deleteTables(QSqlDatabase &db);

    // Конструктор класса
    sqlrecord();
};

#endif // SQLRECORD_H
