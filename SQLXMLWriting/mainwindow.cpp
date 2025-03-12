#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), studentRecords("data.xml") {
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setUserName("ferggopost");
    db.setPassword("SanSan228");

    if (!db.open()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось подключиться к базе данных: " + db.lastError().text());
    }

    connect(ui->addSpecBtn, &QPushButton::clicked, this, &MainWindow::onAddSpeciality);
    connect(ui->addGroupBtn, &QPushButton::clicked, this, &MainWindow::onAddGroup);
    connect(ui->addStudBtn, &QPushButton::clicked, this, &MainWindow::onAddStudent);
    connect(ui->addTeachBtn, &QPushButton::clicked, this, &MainWindow::onAddTeacher);
    connect(ui->addDispBtn, &QPushButton::clicked, this, &MainWindow::onAddDiscipline);
    connect(ui->addPerformBtn, &QPushButton::clicked, this, &MainWindow::onAddPerformance);
    connect(ui->SaveEdit, &QPushButton::clicked, this, &MainWindow::onSaveEdit);
    connect(ui->dispDataBtn, &QPushButton::clicked, this, &MainWindow::displayData);
    connect(ui->updateRecordBtn, &QPushButton::clicked, this, &MainWindow::onUpdateRecord);
    connect(ui->deleteRecordBtn, &QPushButton::clicked, this, &MainWindow::onDeleteRecord);
    connect(ui->ImportSQLBtn, &QPushButton::clicked, this, &MainWindow::sqlImport);
    connect(ui->ExportSQLBtn, &QPushButton::clicked, this, &MainWindow::sqlExport);
}

void MainWindow::onSaveEdit(){
    studentRecords.saveXML("data.xml");
}

void MainWindow::onAddSpeciality() {
    QString code = QInputDialog::getText(this, "Добавить специальность", "Введите код специальности:");
    if (code.isEmpty()) return;

    QString name = QInputDialog::getText(this, "Добавить специальность", "Введите название специальности:");
    if (name.isEmpty()) return;

    studentRecords.addSpeciality(code, name); 
}


void MainWindow::onAddGroup() {
    QString code = QInputDialog::getText(this, "Добавить группу", "Введите код группы:");
    if (code.isEmpty()) return;

    QString name = QInputDialog::getText(this, "Добавить группу", "Введите название группы:");
    if (name.isEmpty()) return;

    QString specialityCode = QInputDialog::getText(this, "Добавить группу", "Введите код специальности:");
    if (specialityCode.isEmpty()) return;

    studentRecords.addGroup(code, name, specialityCode);
}


void MainWindow::onAddStudent() {
    QString code = QInputDialog::getText(this, "Добавить студента", "Введите код студента:");
    if (code.isEmpty()) return;

    QString name = QInputDialog::getText(this, "Добавить студента", "Введите имя студента:");
    if (name.isEmpty()) return;

    QString recordBookNumber = QInputDialog::getText(this, "Добавить студента", "Введите номер зачетной книжки:");
    if (recordBookNumber.isEmpty()) return;

    QString birthDate = QInputDialog::getText(this, "Добавить студента", "Введите дату рождения:");
    if (birthDate.isEmpty()) return;

    QString groupCode = QInputDialog::getText(this, "Добавить студента", "Введите код группы:");
    if (groupCode.isEmpty()) return;

    studentRecords.addStudent(code, name, recordBookNumber, birthDate, groupCode);
}

void MainWindow::onAddTeacher() {
    QString code = QInputDialog::getText(this, "Добавить преподавателя", "Введите код преподавателя:");
    if (code.isEmpty()) return;

    QString staffNumber = QInputDialog::getText(this, "Добавить преподавателя", "Введите табельный номер:");
    if (staffNumber.isEmpty()) return;

    QString name = QInputDialog::getText(this, "Добавить преподавателя", "Введите имя преподавателя:");
    if (name.isEmpty()) return;

    QString department = QInputDialog::getText(this, "Добавить преподавателя", "Введите отделение:");
    if (department.isEmpty()) return;

    QString position = QInputDialog::getText(this, "Добавить преподавателя", "Введите должность:");
    if (position.isEmpty()) return;

    studentRecords.addTeacher(code, staffNumber, name, department, position);
}

void MainWindow::onAddDiscipline() {
    QString code = QInputDialog::getText(this, "Добавить дисциплину", "Введите код дисциплины:");
    if (code.isEmpty()) return;

    QString name = QInputDialog::getText(this, "Добавить дисциплину", "Введите название дисциплины:");
    if (name.isEmpty()) return;

    int lectureHours = QInputDialog::getInt(this, "Добавить дисциплину", "Введите количество лекционных часов:");
    int practiceHours = QInputDialog::getInt(this, "Добавить дисциплину", "Введите количество практических часов:");
    int labHours = QInputDialog::getInt(this, "Добавить дисциплину", "Введите количество лабораторных часов:");
    int semester = QInputDialog::getInt(this, "Добавить дисциплину", "Введите семестр:");

    studentRecords.addDiscipline(code, name, lectureHours, practiceHours, labHours, semester);
}

void MainWindow::onAddPerformance() {
    QString recordCode = QInputDialog::getText(this, "Добавить запись успеваемости", "Введите код записи:");
    if (recordCode.isEmpty()) return;

    QString disciplineCode = QInputDialog::getText(this, "Добавить запись успеваемости", "Введите код дисциплины:");
    if (disciplineCode.isEmpty()) return;

    QString teacherCode = QInputDialog::getText(this, "Добавить запись успеваемости", "Введите код преподавателя:");
    if (teacherCode.isEmpty()) return;

    QString studentCode = QInputDialog::getText(this, "Добавить запись успеваемости", "Введите код студента:");
    if (studentCode.isEmpty()) return;

    QString formOfControl = QInputDialog::getText(this, "Добавить запись успеваемости", "Введите форму контроля:");
    if (formOfControl.isEmpty()) return;

    int grade = QInputDialog::getInt(this, "Добавить запись успеваемости", "Введите оценку:");
    QString submissionDate = QInputDialog::getText(this, "Добавить запись успеваемости", "Введите дату сдачи:");
    if (submissionDate.isEmpty()) return;

    studentRecords.addPerformance(recordCode, disciplineCode, teacherCode, studentCode, formOfControl, grade, submissionDate);
}

void MainWindow::displayData() {
    ui->dataTableWidget->clearContents();
    ui->dataTableWidget->setRowCount(0);

    auto* root = studentRecords.getRoot();
    auto* performancesNode = root->FirstChildElement("Performances");

    if (!performancesNode) {
        return;
    }

    auto* performance = performancesNode->FirstChildElement("Performance");

    while (performance) {
        QString studentName = findEntityName("Students", "Student", "code", performance->Attribute("studentCode"), "name");
        QString disciplineName = findEntityName("Disciplines", "Discipline", "code", performance->Attribute("disciplineCode"), "name");
        QString teacherName = findEntityName("Teachers", "Teacher", "code", performance->Attribute("teacherCode"), "name");
        QString formOfControl = performance->Attribute("formOfControl");
        QString grade = QString::number(performance->IntAttribute("grade"));
        QString submissionDate = performance->Attribute("submissionDate");

        int row = ui->dataTableWidget->rowCount();
        ui->dataTableWidget->insertRow(row);
        ui->dataTableWidget->setItem(row, 0, new QTableWidgetItem(studentName));
        ui->dataTableWidget->setItem(row, 1, new QTableWidgetItem(disciplineName));
        ui->dataTableWidget->setItem(row, 2, new QTableWidgetItem(teacherName));
        ui->dataTableWidget->setItem(row, 3, new QTableWidgetItem(formOfControl));
        ui->dataTableWidget->setItem(row, 4, new QTableWidgetItem(grade));
        ui->dataTableWidget->setItem(row, 5, new QTableWidgetItem(submissionDate));

        performance = performance->NextSiblingElement("Performance");
    }
}


QString MainWindow::findEntityName(const QString& parentTag, const QString& entityTag, const QString& codeAttr, const QString& code, const QString& nameAttr) {
    auto* root = studentRecords.getRoot();
    if (!root) return "Не найдено";

    auto* parentNode = root->FirstChildElement(parentTag.toStdString().c_str());
    if (!parentNode) return "Не найдено";

    auto* entity = parentNode->FirstChildElement(entityTag.toStdString().c_str());
    while (entity) {
        const char* attributeValue = entity->Attribute(codeAttr.toStdString().c_str());
        if (attributeValue && code == QString(attributeValue)) {
            const char* name = entity->Attribute(nameAttr.toStdString().c_str());
            return name ? QString(name) : "Не найдено";
        }
        entity = entity->NextSiblingElement(entityTag.toStdString().c_str());
    }
    return "Не найдено";
}

void MainWindow::onUpdateRecord() {
    // Запрос имени таблицы
    QString tableName = QInputDialog::getText(this, "Обновление записи", "Введите имя таблицы:");
    if (tableName.isEmpty()) return;

    // Запрос кода записи
    QString recordCode = QInputDialog::getText(this, "Обновление записи", "Введите код записи:");
    if (recordCode.isEmpty()) return;

    // Вызов функции обновления записи
    studentRecords.updateRecord(tableName.toStdString(), recordCode.toStdString());

    QMessageBox::information(this, "Успех", "Запись обновлена.");
}

void MainWindow::onDeleteRecord() {
    QString tableName = QInputDialog::getText(this, "Удаление записи", "Введите имя таблицы:");
    if (tableName.isEmpty()) return;

    QString recordCode = QInputDialog::getText(this, "Удаление записи", "Введите код записи:");
    if (recordCode.isEmpty()) return;

    studentRecords.deleteRecord(tableName.toStdString(), recordCode.toStdString());

    QMessageBox::information(this, "Успех", "Запись удалена.");
}

void MainWindow::sqlImport(){
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите файл", "", "XML Files (*.xml)");

    if (filePath.isEmpty()) {
        return;
    }

    sqlRecord.parseAndInsertData(filePath.toStdString().c_str(), db);

    QMessageBox::information(this, "Успех", "Данные были успешно загружены из XML.");
}

void MainWindow::sqlExport(){
    sqlRecord.updateXmlWithDbChanges("data.xml", db);

    QMessageBox::information(this, "Успех", "XML файл был успешно обновлен.");
}



MainWindow::~MainWindow()
{
    delete ui;
}
