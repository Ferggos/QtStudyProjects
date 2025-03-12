#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "tinyxml2.h"
#include <QString>
#include <QMessageBox>
#include <QLineEdit>
#include <QInputDialog>
#include "classes.cpp"

using namespace tinyxml2;
using namespace std;



// === Класс StudentRecords ===

class StudentRecords {
public:
    XMLDocument doc;

    auto* getRoot(){
        return doc.FirstChildElement("StudentRecords");
    }

    void loadXML(const string& filename) {
        if (doc.LoadFile(filename.c_str()) == XML_SUCCESS) {
            cout << "XML файл загружен успешно.\n";
        } else {
            cout << "XML файл не найден, будет создан новый.\n";
            auto* root = doc.NewElement("StudentRecords");
            root->InsertEndChild(doc.NewElement("Specialities"));
            root->InsertEndChild(doc.NewElement("Groups"));
            root->InsertEndChild(doc.NewElement("Students"));
            root->InsertEndChild(doc.NewElement("Teachers"));
            root->InsertEndChild(doc.NewElement("Disciplines"));
            root->InsertEndChild(doc.NewElement("Performances"));
            doc.InsertFirstChild(root);
        }
    }

    void saveXML(const string& filename) {
        doc.SaveFile(filename.c_str());
        cout << "Изменения сохранены в " << filename << ".\n";
    }

    StudentRecords(const string& filename) {
        loadXML(filename);
    }

    void addSpeciality(QString code, QString name) {
        Speciality speciality(code.toStdString(), name.toStdString());
        auto* root = doc.FirstChildElement("StudentRecords");
        auto* specialitiesNode = root->FirstChildElement("Specialities");
        speciality.toXML(specialitiesNode, doc);
    }

    void addGroup(QString code, QString name, QString specialityCode) {
        Group group(code.toStdString(), name.toStdString(), specialityCode.toStdString());
        auto* root = doc.FirstChildElement("StudentRecords");
        auto* groupsNode = root->FirstChildElement("Groups");
        group.toXML(groupsNode, doc);
    }


    void addStudent(QString code, QString name, QString recordBookNumber, QString birthDate, QString groupCode) {
        Student student(code.toStdString(), name.toStdString(), recordBookNumber.toStdString(),
                        birthDate.toStdString(), groupCode.toStdString());
        auto* root = doc.FirstChildElement("StudentRecords");
        auto* studentsNode = root->FirstChildElement("Students");
        student.toXML(studentsNode, doc);
    }


    void addTeacher(QString code, QString staffNumber, QString name, QString department, QString position) {
        Teacher teacher(code.toStdString(), staffNumber.toStdString(), name.toStdString(), department.toStdString(), position.toStdString());
        auto* root = doc.FirstChildElement("StudentRecords");
        auto* teachersNode = root->FirstChildElement("Teachers");
        teacher.toXML(teachersNode, doc);
    }



    void addDiscipline(QString code, QString name, int lectureHours, int practiceHours, int labHours, int semester) {
        Discipline discipline(code.toStdString(), name.toStdString(), lectureHours, practiceHours, labHours, semester);
        auto* root = doc.FirstChildElement("StudentRecords");
        auto* disciplinesNode = root->FirstChildElement("Disciplines");
        discipline.toXML(disciplinesNode, doc);
    }


    void addPerformance(QString recordCode, QString disciplineCode, QString teacherCode, QString studentCode, QString formOfControl, int grade, QString submissionDate) {
        Performance performance(recordCode.toStdString(), disciplineCode.toStdString(), teacherCode.toStdString(), studentCode.toStdString(), formOfControl.toStdString(), grade, submissionDate.toStdString());
        auto* root = doc.FirstChildElement("StudentRecords");
        auto* performancesNode = root->FirstChildElement("Performances");
        performance.toXML(performancesNode, doc);
    }



    void deleteRecord(const string& tableName, const string& recordCode) {
        auto* root = doc.FirstChildElement("StudentRecords");
        auto* table = root->FirstChildElement(tableName.c_str());

        if (!table) {
            cout << "Таблица " << tableName << " не найдена.\n";
            return;
        }

        XMLElement* record = table->FirstChildElement();
        while (record) {
            if (record->Attribute("code") && recordCode == record->Attribute("code")) {
                table->DeleteChild(record);
                cout << "Запись с кодом " << recordCode << " удалена из таблицы " << tableName << ".\n";
                return;
            }
            record = record->NextSiblingElement();
        }
        cout << "Запись с кодом " << recordCode << " не найдена в таблице " << tableName << ".\n";
    }

    void updateRecord(const string& tableName, const string& recordCode) {
        auto* root = doc.FirstChildElement("StudentRecords");
        if (!root) {
            QMessageBox::warning(nullptr, "Ошибка", "Не удалось найти корневой элемент.");
            return;
        }

        auto* table = root->FirstChildElement(tableName.c_str());
        if (!table) {
            QMessageBox::warning(nullptr, "Ошибка", QString::fromStdString("Таблица " + tableName + " не найдена."));
            return;
        }

        XMLElement* record = table->FirstChildElement();
        while (record) {
            if (record->Attribute("code") && recordCode == record->Attribute("code")) {
                while (true) {
                    bool ok;
                    QString input = QInputDialog::getText(
                        nullptr,
                        "Обновление записи",
                        "Введите атрибут и значение в формате 'имя_атрибута=значение'.\nОставьте поле пустым или нажмите 'Отмена' для завершения:",
                        QLineEdit::Normal,
                        "",
                        &ok
                        );

                    if (!ok || input.isEmpty()) break;

                    QStringList parts = input.split('=');
                    if (parts.size() != 2) {
                        QMessageBox::warning(nullptr, "Ошибка", "Неверный формат. Попробуйте снова.");
                        continue;
                    }

                    string attrName = parts[0].trimmed().toStdString();
                    string attrValue = parts[1].trimmed().toStdString();

                    record->DeleteAttribute(attrName.c_str());

                    record->SetAttribute(attrName.c_str(), attrValue.c_str());
                }

                QMessageBox::information(
                    nullptr,
                    "Успех",
                    QString::fromStdString("Запись с кодом " + recordCode + " обновлена в таблице " + tableName + ".")
                    );
                return;
            }

            record = record->NextSiblingElement();
        }

        QMessageBox::warning(
            nullptr,
            "Ошибка",
            QString::fromStdString("Запись с кодом " + recordCode + " не найдена в таблице " + tableName + ".")
            );
    }



};

