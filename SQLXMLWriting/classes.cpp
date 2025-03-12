#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;


// === Классы ===

// Класс Speciality
class Speciality {
public:
    string code;
    string name;

    Speciality(const string& c, const string& n) : code(c), name(n) {}

    void toXML(XMLElement* parent, XMLDocument& doc) const {
        auto* specElement = doc.NewElement("Speciality");
        specElement->SetAttribute("code", code.c_str());
        specElement->SetAttribute("name", name.c_str());
        parent->InsertEndChild(specElement);
    }
};

// Класс Group
class Group {
public:
    string code;
    string name;
    string specialityCode;

    Group(const string& c, const string& n, const string& sc)
        : code(c), name(n), specialityCode(sc) {}

    void toXML(XMLElement* parent, XMLDocument& doc) const {
        auto* groupElement = doc.NewElement("Group");
        groupElement->SetAttribute("code", code.c_str());
        groupElement->SetAttribute("name", name.c_str());
        groupElement->SetAttribute("specialityCode", specialityCode.c_str());
        parent->InsertEndChild(groupElement);
    }
};

// Класс Student
class Student {
public:
    string code;
    string name;
    string recordBookNumber;
    string birthDate;
    string groupCode;

    Student(const string& c, const string& n, const string& rbn, const string& bd, const string& gc)
        : code(c), name(n), recordBookNumber(rbn), birthDate(bd), groupCode(gc) {}

    void toXML(XMLElement* parent, XMLDocument& doc) const {
        auto* studentElement = doc.NewElement("Student");
        studentElement->SetAttribute("code", code.c_str());
        studentElement->SetAttribute("name", name.c_str());
        studentElement->SetAttribute("recordBookNumber", recordBookNumber.c_str());
        studentElement->SetAttribute("birthDate", birthDate.c_str());
        studentElement->SetAttribute("groupCode", groupCode.c_str());
        parent->InsertEndChild(studentElement);
    }
};

// Класс Teacher
class Teacher {
public:
    string code;
    string staffNumber;
    string name;
    string department;
    string position;

    Teacher(const string& c, const string& sn, const string& n, const string& dep, const string& pos)
        : code(c), staffNumber(sn), name(n), department(dep), position(pos) {}

    void toXML(XMLElement* parent, XMLDocument& doc) const {
        auto* teacherElement = doc.NewElement("Teacher");
        teacherElement->SetAttribute("code", code.c_str());
        teacherElement->SetAttribute("staffNumber", staffNumber.c_str());
        teacherElement->SetAttribute("name", name.c_str());
        teacherElement->SetAttribute("department", department.c_str());
        teacherElement->SetAttribute("position", position.c_str());
        parent->InsertEndChild(teacherElement);
    }
};

// Класс Discipline
class Discipline {
public:
    string code;
    string name;
    int lectureHours;
    int practiceHours;
    int labHours;
    int semester;

    Discipline(const string& c, const string& n, int lh, int ph, int labh, int sem)
        : code(c), name(n), lectureHours(lh), practiceHours(ph), labHours(labh), semester(sem) {}

    void toXML(XMLElement* parent, XMLDocument& doc) const {
        auto* disciplineElement = doc.NewElement("Discipline");
        disciplineElement->SetAttribute("code", code.c_str());
        disciplineElement->SetAttribute("name", name.c_str());
        disciplineElement->SetAttribute("lectureHours", lectureHours);
        disciplineElement->SetAttribute("practiceHours", practiceHours);
        disciplineElement->SetAttribute("labHours", labHours);
        disciplineElement->SetAttribute("semester", semester);
        parent->InsertEndChild(disciplineElement);
    }
};

// Класс Performance
class Performance {
public:
    string recordCode;
    string disciplineCode;
    string teacherCode;
    string studentCode;
    string formOfControl;
    int grade;
    string submissionDate;

    Performance(const string& rc, const string& dc, const string& tc, const string& sc, const string& foc, int g, const string& sd)
        : recordCode(rc), disciplineCode(dc), teacherCode(tc), studentCode(sc), formOfControl(foc), grade(g), submissionDate(sd) {}

    void toXML(XMLElement* parent, XMLDocument& doc) const {
        auto* performanceElement = doc.NewElement("Performance");
        performanceElement->SetAttribute("recordCode", recordCode.c_str());
        performanceElement->SetAttribute("disciplineCode", disciplineCode.c_str());
        performanceElement->SetAttribute("teacherCode", teacherCode.c_str());
        performanceElement->SetAttribute("studentCode", studentCode.c_str());
        performanceElement->SetAttribute("formOfControl", formOfControl.c_str());
        performanceElement->SetAttribute("grade", grade);
        performanceElement->SetAttribute("submissionDate", submissionDate.c_str());
        parent->InsertEndChild(performanceElement);
    }
};
