#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include "UniquePointer.h"
#include "Transaction.h"
#include "Student.h"
#include "Speciality.h"
#include "Faculty.h"

using std::cout;
using std::cin;
using std::endl;

bool check_input(bool fail_flag);

//#define INPUT_CONDITION(text, value, condition) \
//    do cout << text; \
//    while (!check_input(!(cin >> value)) or !condition);
//
//#define INPUT(text, value) INPUT_CONDITION(text, value, true)

std::ostream& table(std::ostream& stream);

void CreateFaculty(Faculty& faculty);

void ShowStudents_Task(Faculty& faculty);
void ShowStudentInfo_Task(Faculty& faculty);
void ChangeStudentInfo_Task(Faculty& faculty);
void AddStudent_Task(Faculty& faculty);
void AddSubject_Task(Faculty& faculty);
void AddSpeciality_Task(Faculty& faculty);
//void RemoveStudent_Task(Faculty& faculty);
//void RemoveSubject_Task(Faculty& faculty);
//void RemoveSpeciality_Task(Faculty& faculty);
void SaveStudents_Task(Faculty& faculty);
void SaveOneStudent_Task(Faculty& faculty);

void ShowFaculty(std::ostream& out, const Faculty& faculty);
void ShowSpeciality(std::ostream& out, const Speciality& speciality);
void ShowStudent(std::ostream& out, const Student& student);
Transaction<Student>* FindStudent(Faculty& faculty, std::string name, std::string group);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Faculty fitu;
    CreateFaculty(fitu);

    bool exit = false;
    int choice;
    
    while (!exit)
    {
        do cout << "1. Показать студентов\n"
                   "2. Показать конкретного студента\n"
                   "3. Изменить информацию о студенте\n"
                   "4. Добавить студента\n"
                   "5. Добавить предмет\n"
                   "6. Добавить специальность\n"        
                   "7. Сохранить информацию о студентах в файл\n"
                   "8. Сохранить информацию о конкретном студенте в файл\n"
                   "9. Выход\n";
        while (!check_input(!(cin >> choice)));
        getc(stdin);

        switch (choice)
        {
            case 1:
                ShowStudents_Task(fitu);
            break;
            case 2:
                ShowStudentInfo_Task(fitu);
            break;
            case 3:
                ChangeStudentInfo_Task(fitu);
            break;
            case 4:
                AddStudent_Task(fitu);
            break;
            case 5:
                AddSubject_Task(fitu);
            break;
            case 6:
                AddSpeciality_Task(fitu);
            break;
            /*case 7:
                RemoveStudent_Task(fitu);
                break;
            case 8:
                RemoveSubject_Task(fitu);
                break;
            case 9:
                RemoveSpeciality_Task(fitu);
                break;*/
            case 7:
                SaveStudents_Task(fitu);
            break;
            case 8:
                SaveOneStudent_Task(fitu);
            break;
            case 9:
                exit = true;
            break;
        }
    }


    return 0;
}

void CreateFaculty(Faculty& faculty)
{
    Speciality isitvii("ИСиТвИИ");

    isitvii.AddSubject("Матем", 1);
    isitvii.AddSubject("ОАиП", 1);
    isitvii.AddSubject("ОС", 1);
    isitvii.AddSubject("Философ", 1);

    isitvii.AddSubject("АПК", 2);
    isitvii.AddSubject("БД", 2);
    isitvii.AddSubject("ДВ", 2);
    isitvii.AddSubject("ООП", 2);
    isitvii.AddSubject("ТВиМС", 2);

    isitvii.AddStudent("oleg", "024404", 2);
    isitvii.AddStudent("nikita", "024404", 2);
    isitvii.AddStudent("oleg", "124404", 1);
    isitvii.AddStudent("nikita", "124404", 1);

    faculty.AddSpeciality(isitvii);
}

bool check_input(bool fail_flag)
{
    if (fail_flag)
    {
        cin.clear();
        while (cin.get() != '\n');

        return false;
    }
    else return true;
}

void ShowStudents_Task(Faculty& faculty)
{
    int choice;

    do
    {
        cout << "Выберите специальность:\n1. Все\n";

        for (int i = 2; i < faculty.GetSpecialityCount() + 2; i++)
        {
            cout << i << ". " << faculty[i - 2].GetName() << endl;
        }
    }
    while (!check_input(!(cin >> choice)) or choice < 1 or choice > faculty.GetSpecialityCount() + 1);

    if (choice == 1)
        ShowFaculty(cout, faculty);
    else
        ShowSpeciality(cout, faculty[choice - 2] );
}

void ShowFaculty(std::ostream& out, const Faculty& faculty)
{
    for (const auto& speciality : faculty)
    {
        ShowSpeciality(out, speciality );
    }
}

void ShowSpeciality(std::ostream& out, const Speciality& speciality)
{
    out << std::left;

    out << speciality.GetName() << ":\n";

    for (int i = 0; i < Speciality::COURSES_COUNT; i++)
    {
        if (speciality.GetCourses(i + 1).empty())
            continue;

        out << i + 1 << "-й курс:\n";
        out << table << "Имя" << table << "Группа";

        for (const auto& subject : speciality.GetCourses(i + 1))
        {
            out << table << subject;
        }

        out << endl;

        for (const auto& student : speciality.GetStudents(i + 1))
        {
            out << table << student->GetName() << table << student->GetGroup();

            for (const auto& grade : student->GetGrades())
            {
                out << table << grade.value;
            }

            out << endl;
        }

        out << endl;
    }

    out << std::right;
}

std::ostream& table(std::ostream& stream)
{
    stream << std::setw(15);
    return stream;
}


void ShowStudentInfo_Task(Faculty& faculty)
{
    std::string name, group;

    cout << "Введите имя студента: ";
    std::getline(cin, name);

    cout << "Введите номер группы: ";
    std::getline(cin, group);

    cout << endl;

    Transaction<Student>* student = FindStudent(faculty, name, group);

    if (student)
    {
        ShowStudent(cout, student->GetCurrentState());
    }
    else
    {
        cout << "Студент не найден\n\n";
    }
}



void ShowStudent(std::ostream& out, const Student& student)
{
    out << "Имя: " << student.GetName() << endl;
    out << "Группа: " << student.GetGroup() << endl;
    out << "Оценки:\n";

    for (const auto& grade : student.GetGrades())
    {
        out << "\t" << grade.subject << ": " << grade.value << endl;
    }
    
    out << endl;
}

void ChangeStudentInfo_Task(Faculty& faculty)
{
    std::string name, group;

    cout << "Введите имя студента: ";
    std::getline(cin, name);

    cout << "Введите номер группы: ";
    std::getline(cin, group);

    cout << endl;

    Transaction<Student>* student = FindStudent(faculty, name, group);

    if (student)
    {
        int choice;
        Student test = student->GetCurrentState();

        do cout << "Выберите, что вы хотите изменить:\n1. Имя\n2. Группа\n3. Оценка по предмету\n";
        while (!check_input(!(cin >> choice)) or choice < 1 or choice > 3);
        getc(stdin);

        switch (choice)
        {
            case 1:
                cout << "Введите новое имя: ";
                std::getline(cin, name);

                test.SetName(name);
            break;
            case 2:
                cout << "Введите новую группу: ";
                std::getline(cin, group);

                test.SetGroup(group);
            break;
            case 3:
                do
                {
                    cout << "Введите название предмета: ";
                    std::getline(cin, name);
                }
                while (!test.IsValidSubject(name));

                do cout << "Введите оценку: ";
                while (!check_input(!(cin >> choice)) or choice < 1 or choice > 10);

                test.SetGrade(name, choice);
            break;
        }

        student->BeginTransaction(test);

        cout << "Новая запись:\n";
        ShowStudent(cout, student->GetCurrentState());

        do cout << "1. Сохранить изменения\n2. Отменить изменения\n";
        while (!check_input(!(cin >> choice)) or choice < 1 or choice > 2);

        if (choice == 1)
        {
            student->Commit();
        }
        else
        {
            student->RollBack();
        }
    }
    else
    {
        cout << "Студент не найден\n\n";
    }
}

void AddStudent_Task(Faculty& faculty)
{
    int spec, course;

    do
    {
        cout << "Выберите специальность:\n";

        for (int i = 1; i <= faculty.GetSpecialityCount(); i++)
        {
            cout << i << ". " << faculty[i - 1].GetName() << endl;
        }
    }
    while (!check_input(!(cin >> spec)) or spec < 1 or spec > faculty.GetSpecialityCount());
    spec--;

    do cout << "Укажите курс (1-" << Speciality::COURSES_COUNT << "): ";
    while (!check_input(!(cin >> course)) or course < 1 or course > Speciality::COURSES_COUNT);
    getc(stdin);

    std::string name, group;

    cout << "Введите имя студента: ";
    std::getline(cin, name);

    cout << "Введите номер группы: ";
    std::getline(cin, group);

    cout << endl;

    faculty[spec].AddStudent(name, group, course);
}

void AddSubject_Task(Faculty& faculty)
{
    int choice;

    do
    {
        cout << "Выберите специальность:\n";

        for (int i = 0; i < faculty.GetSpecialityCount(); i++)
        {
            cout << i + 1 << ". " << faculty[i].GetName() << endl;
        }
    }
    while (!check_input(!(cin >> choice)) or choice < 1 or choice > faculty.GetSpecialityCount());
    getc(stdin);

    std::string name;
    int course;

    cout << "Введите название предмета: ";
    std::getline(cin, name);

    do cout << "Введите номер курса: ";
    while (!check_input(!(cin >> course)) or course < 1 or course > Speciality::COURSES_COUNT);

    faculty[choice - 1].AddSubject(name, course);
}

void AddSpeciality_Task(Faculty& faculty)
{
    std::string name;

    cout << "Введите название специальности: ";
    std::getline(cin, name);

    faculty.AddSpeciality(name);
}

//void RemoveStudent_Task(Faculty& faculty)
//{
//}
//
//void RemoveSubject_Task(Faculty& faculty)
//{
//    int choice;
//
//    do
//    {
//        cout << "Выберите специальность:\n";
//
//        for (int i = 0; i < faculty.GetSpecialityCount(); i++)
//        {
//            cout << i + 1 << ". " << faculty[i].GetName() << endl;
//        }
//    }
//    while (!check_input(!(cin >> choice)) or choice < 1 or choice > faculty.GetSpecialityCount());
//    getc(stdin);
//
//    std::string name;
//    int course;
//
//    cout << "Введите название предмета: ";
//    std::getline(cin, name);
//
//    do cout << "Введите номер курса: ";
//    while (!check_input(!(cin >> course)) or course < 1 or course > Speciality::COURSES_COUNT);
//
//    faculty[choice - 1].RemoveSubject(name, course);
//}
//
//void RemoveSpeciality_Task(Faculty& faculty)
//{
//    std::string name;
//
//    cout << "Введите название специальности: ";
//    std::getline(cin, name);
//
//    if (faculty.IsSpeciality(name))
//    {
//        faculty.RemoveSpeciality(name);
//    }
//}

void SaveStudents_Task(Faculty& faculty)
{
    std::ofstream file("fitu.txt");

    ShowFaculty(file, faculty);

    file.close();
}

void SaveOneStudent_Task(Faculty& faculty)
{
    std::string name, group;

    cout << "Введите имя студента: ";
    std::getline(cin, name);

    cout << "Введите номер группы: ";
    std::getline(cin, group);

    cout << endl;

    Transaction<Student>* student = FindStudent(faculty, name, group);

    if (student)
    {
        std::ofstream file(student->GetCurrentState().GetName() + std::string("_") + student->GetCurrentState().GetGroup() + std::string(".txt"));
        ShowStudent(file, student->GetCurrentState());
        file.close();
    }
    else
    {
        cout << "Студент не найден\n\n";
    }
}

Transaction<Student>* FindStudent(Faculty& faculty, std::string name, std::string group)
{
    for (auto& speciality : faculty)
    {
        for (int i = 1; i <= Speciality::COURSES_COUNT; i++)
        {
            for (auto& student : speciality.GetStudents(i))
            {
                if (student->GetName() == name and student->GetGroup() == group)
                {
                    return &student;
                }
            }
        }
    }

    return nullptr;
}