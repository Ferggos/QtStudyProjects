## Задание

   Написать программу, которая добавляет, удаляет и изменяет записи данных, хранящиеся в xml формате. Если файла нет, то необходимо его создавать, если все записи в файле удалены, то файл должен оставаться пустым. Также мы должны выводить информацию из файла на экран в табличном виде. Для редактирования данных необходимо небольшое простое меню. Таблицы организовать внутри программы как классы. И главное таблицы связанны между собой.
   

«Учёт успеваемости студентов» Информация должна хранится в следующей структуре:
    - cпециальность (код специальности, название специальности);
    - учебная группа (код группы, название группы, код специальности);
    - cтудент (код студента, ФИО студента, № зачётки, дата рождения, код группы);
    - преподаватель (код преподавателя, табельный №, ФИО преподавателя, кафедра, должность);
    - дисциплина (код дисциплины, название дисциплины, количество лекционных часов, количество часов практических занятий, количество часов лабораторных занятий, семестр);
    - успеваемость (код записи, код дисциплины, код преподавателя, код студента, форма контроля, оценка, дата сдачи).
