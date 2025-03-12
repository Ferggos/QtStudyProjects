#include "sqlrecord.h"

sqlrecord::sqlrecord() {}

void sqlrecord::insertSpecialities(XMLElement *specialityElement, QSqlDatabase &db) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO specialities (code, namef) VALUES (:code, :name)");
    query.bindValue(":code", specialityElement->IntAttribute("code"));
    query.bindValue(":name", specialityElement->Attribute("name"));
    query.exec();
}

void sqlrecord::insertGroups(XMLElement *groupElement, QSqlDatabase &db) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO groups (code, namef, specialityCode) VALUES (:code, :name, :specialityCode)");
    query.bindValue(":code", groupElement->IntAttribute("code"));
    query.bindValue(":name", groupElement->Attribute("name"));
    query.bindValue(":specialityCode", groupElement->IntAttribute("specialityCode"));
    query.exec();
}

void sqlrecord::insertStudents(XMLElement *studentElement, QSqlDatabase &db) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO students (code, namef, recordBookNumber, birthDate, groupCode) "
                  "VALUES (:code, :name, :recordBookNumber, :birthDate, :groupCode)");
    query.bindValue(":code", studentElement->IntAttribute("code"));
    query.bindValue(":name", studentElement->Attribute("name"));
    query.bindValue(":recordBookNumber", studentElement->Attribute("recordBookNumber"));
    query.bindValue(":birthDate", studentElement->Attribute("birthDate"));
    query.bindValue(":groupCode", studentElement->IntAttribute("groupCode"));
    query.exec();
}

void sqlrecord::insertTeachers(XMLElement *teacherElement, QSqlDatabase &db) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO teachers (code, staffnumber, namef, department, position) "
                  "VALUES (:code, :staffNumber, :name, :department, :position)");
    query.bindValue(":code", teacherElement->IntAttribute("code"));
    query.bindValue(":staffNumber", teacherElement->Attribute("staffNumber"));
    query.bindValue(":name", teacherElement->Attribute("name"));
    query.bindValue(":department", teacherElement->Attribute("department"));
    query.bindValue(":position", teacherElement->Attribute("position"));
    query.exec();
}

void sqlrecord::insertDisciplines(XMLElement *disciplineElement, QSqlDatabase &db) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO disciplines (code, namef, lecturehours, practicehours, labhours, semester) "
                  "VALUES (:code, :name, :lectureHours, :practiceHours, :labHours, :semester)");
    query.bindValue(":code", disciplineElement->IntAttribute("code"));
    query.bindValue(":name", disciplineElement->Attribute("name"));
    query.bindValue(":lectureHours", disciplineElement->IntAttribute("lectureHours"));
    query.bindValue(":practiceHours", disciplineElement->IntAttribute("practiceHours"));
    query.bindValue(":labHours", disciplineElement->IntAttribute("labHours"));
    query.bindValue(":semester", disciplineElement->IntAttribute("semester"));
    query.exec();
}

void sqlrecord::insertPerformances(XMLElement *performanceElement, QSqlDatabase &db) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO performances (recordcode, disciplinecode, teachercode, studentcode, formofcontrol, grade, submissiondate) "
                  "VALUES (:recordCode, :disciplineCode, :teacherCode, :studentCode, :formOfControl, :grade, :submissionDate)");
    query.bindValue(":recordCode", performanceElement->IntAttribute("recordCode"));
    query.bindValue(":disciplineCode", performanceElement->IntAttribute("disciplineCode"));
    query.bindValue(":teacherCode", performanceElement->IntAttribute("teacherCode"));
    query.bindValue(":studentCode", performanceElement->IntAttribute("studentCode"));
    query.bindValue(":formOfControl", performanceElement->Attribute("formOfControl"));
    query.bindValue(":grade", performanceElement->IntAttribute("grade"));
    query.bindValue(":submissionDate", performanceElement->Attribute("submissionDate"));
    query.exec();
}

void sqlrecord::deleteTables(QSqlDatabase &db){
    QSqlQuery query(db);

    query.prepare("DELETE FROM Performances CASCADE;");
    if (!query.exec()) {
        qDebug() << "Ошибка при удалении данных из таблицы Performances: " << query.lastError().text();
    }

    query.prepare("DELETE FROM Disciplines CASCADE;");
    if (!query.exec()) {
        qDebug() << "Ошибка при удалении данных из таблицы Disciplines: " << query.lastError().text();
    }

    query.prepare("DELETE FROM Teachers CASCADE;");
    if (!query.exec()) {
        qDebug() << "Ошибка при удалении данных из таблицы Teachers: " << query.lastError().text();
    }

    query.prepare("DELETE FROM Students CASCADE;");
    if (!query.exec()) {
        qDebug() << "Ошибка при удалении данных из таблицы Students: " << query.lastError().text();
    }

    query.prepare("DELETE FROM Groups CASCADE;");
    if (!query.exec()) {
        qDebug() << "Ошибка при удалении данных из таблицы Groups: " << query.lastError().text();
    }

    query.prepare("DELETE FROM Specialities CASCADE;");
    if (!query.exec()) {
        qDebug() << "Ошибка при удалении данных из таблицы Specialities: " << query.lastError().text();
    }

    qDebug() << "Все данные успешно удалены.";
}

void sqlrecord::parseAndInsertData(const char *filePath, QSqlDatabase &db) {
    XMLDocument doc;
    if (doc.LoadFile(filePath) == XML_SUCCESS) {
        XMLElement *root = doc.FirstChildElement("StudentRecords");
        if (!root) return;

        deleteTables(db);

        // Insert Specialities
        XMLElement *specialities = root->FirstChildElement("Specialities");
        if (specialities) {
            for (XMLElement *speciality = specialities->FirstChildElement("Speciality"); speciality; speciality = speciality->NextSiblingElement("Speciality")) {
                insertSpecialities(speciality, db);
            }
        }

        // Insert Groups
        XMLElement *groups = root->FirstChildElement("Groups");
        if (groups) {
            for (XMLElement *group = groups->FirstChildElement("Group"); group; group = group->NextSiblingElement("Group")) {
                insertGroups(group, db);
            }
        }

        // Insert Students
        XMLElement *students = root->FirstChildElement("Students");
        if (students) {
            for (XMLElement *student = students->FirstChildElement("Student"); student; student = student->NextSiblingElement("Student")) {
                insertStudents(student, db);
            }
        }

        // Insert Teachers
        XMLElement *teachers = root->FirstChildElement("Teachers");
        if (teachers) {
            for (XMLElement *teacher = teachers->FirstChildElement("Teacher"); teacher; teacher = teacher->NextSiblingElement("Teacher")) {
                insertTeachers(teacher, db);
            }
        }

        // Insert Disciplines
        XMLElement *disciplines = root->FirstChildElement("Disciplines");
        if (disciplines) {
            for (XMLElement *discipline = disciplines->FirstChildElement("Discipline"); discipline; discipline = discipline->NextSiblingElement("Discipline")) {
                insertDisciplines(discipline, db);
            }
        }

        // Insert Performances
        XMLElement *performances = root->FirstChildElement("Performances");
        if (performances) {
            for (XMLElement *performance = performances->FirstChildElement("Performance"); performance; performance = performance->NextSiblingElement("Performance")) {
                insertPerformances(performance, db);
            }
        }
    }
}

void sqlrecord::updateXmlWithDbChanges(const char *filePath, QSqlDatabase &db) {
    XMLDocument doc;
    XMLError loadResult = doc.LoadFile(filePath);

    if (loadResult != XML_SUCCESS) {
        qDebug() << "Ошибка при загрузке XML файла";
        return;
    }

    XMLElement *root = doc.RootElement();

    updateSpecialities(doc, root, db);
    updateGroups(doc, root, db);
    updateStudents(doc, root, db);
    updateTeachers(doc, root, db);
    updateDisciplines(doc, root, db);
    updatePerformances(doc, root, db);

    doc.SaveFile(filePath);
}

void sqlrecord::updateSpecialities(XMLDocument &doc, XMLElement *root, QSqlDatabase &db) {
    QSqlQuery query(db);
    query.prepare("SELECT code, namef FROM specialities");
    query.exec();

    XMLElement *specialities = root->FirstChildElement("Specialities");
    if (!specialities) {
        specialities = doc.NewElement("Specialities");
        root->InsertEndChild(specialities);
    }

    QSet<int> updatedCodes;

    while (query.next()) {
        int code = query.value(0).toInt();
        QString name = query.value(1).toString();

        bool found = false;
        for (XMLElement *speciality = specialities->FirstChildElement("Speciality"); speciality; speciality = speciality->NextSiblingElement("Speciality")) {
            if (speciality->IntAttribute("code") == code) {
                found = true;
                speciality->SetAttribute("name", name.toStdString().c_str());
                break;
            }
        }

        if (!found) {
            XMLElement *speciality = doc.NewElement("Speciality");
            speciality->SetAttribute("code", code);
            speciality->SetAttribute("name", name.toStdString().c_str());
            specialities->InsertEndChild(speciality);
        }

        updatedCodes.insert(code);
    }

    for (XMLElement *speciality = specialities->FirstChildElement("Speciality"); speciality;) {
        XMLElement *nextSpeciality = speciality->NextSiblingElement("Speciality");
        int code = speciality->IntAttribute("code");
        if (!updatedCodes.contains(code)) {
            specialities->DeleteChild(speciality);
        }
        speciality = nextSpeciality;
    }
}

void sqlrecord::updateGroups(XMLDocument &doc, XMLElement *root, QSqlDatabase &db) {
    QSqlQuery query(db);
    query.prepare("SELECT code, namef, specialityCode FROM groups");
    query.exec();

    XMLElement *groups = root->FirstChildElement("Groups");
    if (!groups) {
        groups = doc.NewElement("Groups");
        root->InsertEndChild(groups);
    }

    QSet<int> updatedCodes;

    while (query.next()) {
        int code = query.value(0).toInt();
        QString name = query.value(1).toString();
        int specialityCode = query.value(2).toInt();

        bool found = false;
        for (XMLElement *group = groups->FirstChildElement("Group"); group; group = group->NextSiblingElement("Group")) {
            if (group->IntAttribute("code") == code) {
                found = true;
                group->SetAttribute("name", name.toStdString().c_str());
                group->SetAttribute("specialityCode", specialityCode);
                break;
            }
        }

        if (!found) {
            XMLElement *group = doc.NewElement("Group");
            group->SetAttribute("code", code);
            group->SetAttribute("name", name.toStdString().c_str());
            group->SetAttribute("specialityCode", specialityCode);
            groups->InsertEndChild(group);
        }

        updatedCodes.insert(code);
    }

    for (XMLElement *group = groups->FirstChildElement("Group"); group;) {
        XMLElement *nextGroup = group->NextSiblingElement("Group");
        int code = group->IntAttribute("code");
        if (!updatedCodes.contains(code)) {
            groups->DeleteChild(group);
        }
        group = nextGroup;
    }
}

void sqlrecord::updateStudents(XMLDocument &doc, XMLElement *root, QSqlDatabase &db) {
    QSqlQuery query(db);
    query.prepare("SELECT code, namef, recordBookNumber, birthDate, groupCode FROM students");
    query.exec();

    XMLElement *students = root->FirstChildElement("Students");
    if (!students) {
        students = doc.NewElement("Students");
        root->InsertEndChild(students);
    }

    QSet<int> updatedCodes;

    while (query.next()) {
        int code = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString recordBookNumber = query.value(2).toString();
        QString birthDate = query.value(3).toString();
        int groupCode = query.value(4).toInt();

        bool found = false;
        for (XMLElement *student = students->FirstChildElement("Student"); student; student = student->NextSiblingElement("Student")) {
            if (student->IntAttribute("code") == code) {
                found = true;
                student->SetAttribute("name", name.toStdString().c_str());
                student->SetAttribute("recordBookNumber", recordBookNumber.toStdString().c_str());
                student->SetAttribute("birthDate", birthDate.toStdString().c_str());
                student->SetAttribute("groupCode", groupCode);
                break;
            }
        }

        if (!found) {
            XMLElement *student = doc.NewElement("Student");
            student->SetAttribute("code", code);
            student->SetAttribute("name", name.toStdString().c_str());
            student->SetAttribute("recordBookNumber", recordBookNumber.toStdString().c_str());
            student->SetAttribute("birthDate", birthDate.toStdString().c_str());
            student->SetAttribute("groupCode", groupCode);
            students->InsertEndChild(student);
        }

        updatedCodes.insert(code);
    }

    for (XMLElement *student = students->FirstChildElement("Student"); student;) {
        XMLElement *nextStudent = student->NextSiblingElement("Student");
        int code = student->IntAttribute("code");
        if (!updatedCodes.contains(code)) {
            students->DeleteChild(student);
        }
        student = nextStudent;
    }
}

void sqlrecord::updateTeachers(XMLDocument &doc, XMLElement *root, QSqlDatabase &db) {
    QSqlQuery query(db);
    query.prepare("SELECT code, staffNumber, namef, department, position FROM teachers");
    query.exec();

    XMLElement *teachers = root->FirstChildElement("Teachers");
    if (!teachers) {
        teachers = doc.NewElement("Teachers");
        root->InsertEndChild(teachers);
    }

    QSet<int> updatedCodes;

    while (query.next()) {
        int code = query.value(0).toInt();
        QString staffNumber = query.value(1).toString();
        QString name = query.value(2).toString();
        QString department = query.value(3).toString();
        QString position = query.value(4).toString();

        bool found = false;
        for (XMLElement *teacher = teachers->FirstChildElement("Teacher"); teacher; teacher = teacher->NextSiblingElement("Teacher")) {
            if (teacher->IntAttribute("code") == code) {
                found = true;
                teacher->SetAttribute("staffNumber", staffNumber.toStdString().c_str());
                teacher->SetAttribute("name", name.toStdString().c_str());
                teacher->SetAttribute("department", department.toStdString().c_str());
                teacher->SetAttribute("position", position.toStdString().c_str());
                break;
            }
        }

        if (!found) {
            XMLElement *teacher = doc.NewElement("Teacher");
            teacher->SetAttribute("code", code);
            teacher->SetAttribute("staffNumber", staffNumber.toStdString().c_str());
            teacher->SetAttribute("name", name.toStdString().c_str());
            teacher->SetAttribute("department", department.toStdString().c_str());
            teacher->SetAttribute("position", position.toStdString().c_str());
            teachers->InsertEndChild(teacher);
        }

        updatedCodes.insert(code);
    }

    for (XMLElement *teacher = teachers->FirstChildElement("Teacher"); teacher;) {
        XMLElement *nextTeacher = teacher->NextSiblingElement("Teacher");
        int code = teacher->IntAttribute("code");
        if (!updatedCodes.contains(code)) {
            teachers->DeleteChild(teacher);
        }
        teacher = nextTeacher;
    }
}

void sqlrecord::updateDisciplines(XMLDocument &doc, XMLElement *root, QSqlDatabase &db) {
    QSqlQuery query(db);
    query.prepare("SELECT code, namef, lectureHours, practiceHours, labHours, semester FROM disciplines");
    query.exec();

    XMLElement *disciplines = root->FirstChildElement("Disciplines");
    if (!disciplines) {
        disciplines = doc.NewElement("Disciplines");
        root->InsertEndChild(disciplines);
    }

    QSet<int> updatedCodes;

    while (query.next()) {
        int code = query.value(0).toInt();
        QString name = query.value(1).toString();
        int lectureHours = query.value(2).toInt();
        int practiceHours = query.value(3).toInt();
        int labHours = query.value(4).toInt();
        int semester = query.value(5).toInt();

        bool found = false;
        for (XMLElement *discipline = disciplines->FirstChildElement("Discipline"); discipline; discipline = discipline->NextSiblingElement("Discipline")) {
            if (discipline->IntAttribute("code") == code) {
                found = true;
                discipline->SetAttribute("name", name.toStdString().c_str());
                discipline->SetAttribute("lectureHours", lectureHours);
                discipline->SetAttribute("practiceHours", practiceHours);
                discipline->SetAttribute("labHours", labHours);
                discipline->SetAttribute("semester", semester);
                break;
            }
        }

        if (!found) {
            XMLElement *discipline = doc.NewElement("Discipline");
            discipline->SetAttribute("code", code);
            discipline->SetAttribute("name", name.toStdString().c_str());
            discipline->SetAttribute("lectureHours", lectureHours);
            discipline->SetAttribute("practiceHours", practiceHours);
            discipline->SetAttribute("labHours", labHours);
            discipline->SetAttribute("semester", semester);
            disciplines->InsertEndChild(discipline);
        }

        updatedCodes.insert(code);
    }

    for (XMLElement *discipline = disciplines->FirstChildElement("Discipline"); discipline;) {
        XMLElement *nextDiscipline = discipline->NextSiblingElement("Discipline");
        int code = discipline->IntAttribute("code");
        if (!updatedCodes.contains(code)) {
            disciplines->DeleteChild(discipline);
        }
        discipline = nextDiscipline;
    }
}

void sqlrecord::updatePerformances(XMLDocument &doc, XMLElement *root, QSqlDatabase &db) {
    QSqlQuery query(db);
    query.prepare("SELECT recordCode, disciplineCode, teacherCode, studentCode, formOfControl, grade, submissionDate FROM Performances");
    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса: " << query.lastError().text();
        return;
    }

    XMLElement *performances = root->FirstChildElement("Performances");
    if (!performances) {
        performances = doc.NewElement("Performances");
        root->InsertEndChild(performances);
    }

    QSet<int> updatedCodes;

    while (query.next()) {
        int recordCode = query.value(0).toInt();
        int disciplineCode = query.value(1).toInt();
        int teacherCode = query.value(2).toInt();
        int studentCode = query.value(3).toInt();
        QString formOfControl = query.value(4).toString();
        int grade = query.value(5).toInt();
        QString submissionDate = query.value(6).toString();

        bool found = false;

        for (XMLElement *performance = performances->FirstChildElement("Performance"); performance; performance = performance->NextSiblingElement("Performance")) {
            if (performance->IntAttribute("recordCode") == recordCode) {
                found = true;
                performance->SetAttribute("disciplineCode", disciplineCode);
                performance->SetAttribute("teacherCode", teacherCode);
                performance->SetAttribute("studentCode", studentCode);
                performance->SetAttribute("formOfControl", formOfControl.toStdString().c_str());
                performance->SetAttribute("grade", grade);
                performance->SetAttribute("submissionDate", submissionDate.toStdString().c_str());
                break;
            }
        }

        if (!found) {
            XMLElement *performance = doc.NewElement("Performance");
            performance->SetAttribute("recordCode", recordCode);
            performance->SetAttribute("disciplineCode", disciplineCode);
            performance->SetAttribute("teacherCode", teacherCode);
            performance->SetAttribute("studentCode", studentCode);
            performance->SetAttribute("formOfControl", formOfControl.toStdString().c_str());
            performance->SetAttribute("grade", grade);
            performance->SetAttribute("submissionDate", submissionDate.toStdString().c_str());
            performances->InsertEndChild(performance);
        }

        updatedCodes.insert(recordCode);
    }

    for (XMLElement *performance = performances->FirstChildElement("Performance"); performance;) {
        XMLElement *nextPerformance = performance->NextSiblingElement("Performance");
        int recordCode = performance->IntAttribute("recordCode");
        if (!updatedCodes.contains(recordCode)) {
            performances->DeleteChild(performance);
        }
        performance = nextPerformance;
    }
}

