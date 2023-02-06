#include "Student.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>

void includeUkrChars()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
}
#endif // !_WIN32

namespace
{
    const std::vector<std::string> UKR_ALPHABET = { "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "'", "'" };
    const std::vector<std::string> UKR_ALPHABET_CAPS = { "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "'", "'" };
}

void firstMenu();
void secondMenu(int firstChoice, std::vector<Student>& dataBase);
void logic(std::vector<Student>& dataBase);
void addStudent(std::vector<Student>& dataBase, std::string name, std::string surName, std::string dateOfBirth, std::string phoneNumber, std::string adress, std::string groupNumber);
void eraseStudent(std::vector<Student>& dataBase, int secondChoice);
void dataBasePrint(std::vector<Student>& dataBase);
void editStudentValue(std::vector<Student>& dataBase, int changeValue, int secondChoice, std::string name, std::string surName, std::string dateOfBirth, std::string phoneNumber,
    std::string adress, std::string groupNumber);
void sortBySurName(std::vector<Student>& dataBase);
int recursionSort(std::vector<Student>& dataBase, int& i, int& j, int& tempValueFirst, int& tempValueNext, bool& indicatorI, bool& indicatorJ);
void compareCharAlphabetWithCharInString(std::vector<Student>& dataBase, int& tempValueFirst, int& tempValueNext, const std::vector<std::string> UkrAlphabet, int i, int j);
void fillDataBase(std::vector<Student>& dataBase);
void indicatorReset(bool& indicator, int& value);

int main()
{
#ifdef _WIN32
    includeUkrChars();
#endif
    std::vector<Student> dataBase;
    fillDataBase(dataBase);
    logic(dataBase);
    return 0;
}

void fillDataBase(std::vector<Student>& dataBase)
{
    dataBase.push_back(Student("������", "��������", "19.04.1980", "+380669795389", "�. �����", "E98-1"));
    dataBase.push_back(Student("�����", "��������", "01.03.1980", "+380671111111", "�. �������", "E98-1"));
    dataBase.push_back(Student("��������", "�������", "15.07.1993", "+380502222222", "�. ���", "E98-1"));
    dataBase.push_back(Student("������", "�����", "22.06.2004", "+380665522555", "�. �����", "E98-1"));
    dataBase.push_back(Student("�����", "��������", "15.11.2004", "+380665555555", "�. �����", "E98-1"));
    dataBase.push_back(Student("������", "���������", "12.05.2003", "+380661555555", "�. �����", "E98-1"));
    dataBase.push_back(Student("����", "�������", "21.03.2004", "+380665553355", "�. �����", "E98-1"));
    dataBase.push_back(Student("ͳ�������", "�������", "08.08.2004", "+380661555555", "�. �����", "E98-1"));
    dataBase.push_back(Student("�����", "������", "13.10.2004", "+380665125555", "�. �����", "E98-1"));
    dataBase.push_back(Student("���", "������", "26.11.2004", "+380665235555", "�. �����", "E98-1"));
    dataBase.push_back(Student("�����", "�������", "26.12.2004", "+380665576555", "�. �����", "E98-1"));
    dataBase.push_back(Student("������", "�����'��", "31.12.2004", "+380688555555", "�. �����", "E98-1"));
    dataBase.push_back(Student("����", "�����'��", "14.08.2004", "+380665551955", "�. �����", "E98-1"));
    dataBase.push_back(Student("���������", "�������", "09.08.2004", "+380663335555", "�. �����", "E98-1"));
    dataBase.push_back(Student("�����", "���������", "08.08.2004", "+380665551115", "�. �����", "E98-1"));
    dataBase.push_back(Student("������", "����������", "17.11.2004", "+380665222555", "�. �����", "E98-1"));
    dataBase.push_back(Student("�������", "��������", "07.01.2004", "+380665512155", "�. �����", "E98-1"));
    dataBase.push_back(Student("�����", "����������", "09.02.2004", "+380661455555", "�. �����", "E98-1"));
    dataBase.push_back(Student("������", "���������", "12.03.2004", "+380665455555", "�. �����", "E98-1"));
    dataBase.push_back(Student("������", "���'������", "15.05.2004", "+380665675555", "�. �����", "E98-1"));
    dataBase.push_back(Student("����", "���������", "19.04.2004", "+380665589555", "�. �����", "E98-1"));
    dataBase.push_back(Student("�������", "���'������", "22.06.2004", "+380665455555", "�. �����", "E98-1"));
    dataBase.push_back(Student("�����", "���'�������", "23.07.2004", "+380665559855", "�. �����", "E98-1"));
    dataBase.push_back(Student("�������", "���", "24.07.2004", "+380665455555", "�. �����", "E98-1"));
    dataBase.push_back(Student("������", "г�", "08.08.2004", "+380665123555", "�. �����", "E98-1"));
}

void firstMenu()
{
    std::cout << "������� �������� ��� �������� 0 ��� ������\n";
    std::cout << "1 - ������ ��������\n";
    std::cout << "2 - �������� ��������\n";
    std::cout << "3 - ����������� ������ ��������\n";
	std::cout << "4 - ���������� ���� ��� ��������\n";
    //�� �������� ���� ������� ���������� ������ ���� �� Windows
    std::cout << "5 - ��������� �� ������� �� �������\n";
}

void secondMenu(int firstChoice, std::vector<Student>& dataBase)
{
    int secondChoice = 0;
    int changeValue = 0;
    std::string name;
    std::string surName;
    std::string dateOfBirth;
    std::string phoneNumber;
    std::string adress;
    std::string groupNumber;

    switch (firstChoice)
    {
    case 1:
        std::cout << "������ ��'� ��������\n";
        std::cin >> name;
        std::cout << "������ ������� ��������\n";
        std::cin >> surName;
        std::cout << "������ ���� ����������\n";
        std::cin >> dateOfBirth;
        std::cout << "������ ����� ��������\n";
        std::cin >> phoneNumber;
        std::cout << "������ ������\n";
        std::cin >> adress;
        std::cout << "������ ����� ��������� �����\n";
        std::cin >> groupNumber;
        addStudent(dataBase, name, surName, dateOfBirth, phoneNumber, adress, groupNumber);
        break;

    case 2:
        dataBasePrint(dataBase);
        std::cout << "������ ���������� �����, ��������, ����� ������� ��������\n";
        std::cin >> secondChoice;
        eraseStudent(dataBase, secondChoice);
        break;

    case 3:
        dataBasePrint(dataBase);
        break;

    case 4:
        dataBasePrint(dataBase);
        std::cout << "������ ���������� �����, ��������, ���� ����� ������� ����������\n";
        std::cin >> secondChoice;

		std::cout << "1 - ���������� ��'� ��������\n";
		std::cout << "2 - ���������� ������� ��������\n";
		std::cout << "3 - ���������� ���� ����������\n";
		std::cout << "4 - ���������� ����� ��������\n";
		std::cout << "5 - ���������� ������\n";
		std::cout << "6 - ���������� ����� ��������� �����\n";
		std::cout << "������� �������\n";
		std::cin >> changeValue;
        editStudentValue(dataBase, changeValue, secondChoice, name, surName, dateOfBirth, phoneNumber, adress, groupNumber);
        break;
       
        case 5:
        sortBySurName(dataBase);
        break;
    }
}

void editStudentValue(std::vector<Student>& dataBase, int changeValue, int secondChoice, std::string name, std::string surName, std::string dateOfBirth, std::string phoneNumber, std::string adress, std::string groupNumber)
{
    switch (changeValue)
    {
    case 1:
        std::cout << "������ ��'� ��������\n";
        std::cin >> name;
        dataBase[secondChoice - 1].setName(name);
        std::cout << "���� ������\n";
        break;
    case 2:
        std::cout << "������ ������� ��������\n";
        std::cin >> surName;
        dataBase[secondChoice - 1].setSurName(surName);
        std::cout << "���� ������\n";
        break;
    case 3:
        std::cout << "������ ���� ����������\n";
        std::cin >> dateOfBirth;
        dataBase[secondChoice - 1].setDateOfBirth(dateOfBirth);
        std::cout << "���� ������\n";
        break;
    case 4:
        std::cout << "������ ����� ��������\n";
        std::cin >> phoneNumber;
        dataBase[secondChoice - 1].setPhoneNumber(phoneNumber);
        std::cout << "���� ������\n";
        break;
    case 5:
        std::cout << "������ ������\n";
        std::cin >> adress;
        dataBase[secondChoice - 1].setAdress(adress);
        std::cout << "���� ������\n";
        break;
    case 6:
        std::cout << "������ ����� ��������� �����\n";
        std::cin >> groupNumber;
        dataBase[secondChoice - 1].setGroupNumber(groupNumber);
        std::cout << "���� ������\n";
        break;
    }
}

void dataBasePrint(std::vector<Student>& dataBase)
{
    for (int i = 0; i < dataBase.size(); ++i)
    {
        std::cout << " " << i + 1 << ". " << dataBase[i] << "\n";
    }
    std::cout << std::endl;
}

void addStudent(std::vector<Student>& dataBase, std::string name, std::string surName, std::string dateOfBirth, std::string phoneNumber, std::string adress, std::string groupNumber)
{
    dataBase.push_back(Student(name, surName, dateOfBirth, phoneNumber, adress, groupNumber));
}

void eraseStudent(std::vector<Student>& dataBase, int secondChoice)
{
    dataBase.erase(dataBase.begin() + secondChoice - 1);
}

void logic(std::vector<Student>& dataBase)
{
    int firstChoice = 0;

    while (true)
    {
        firstMenu();
        std::cin >> firstChoice;
        if (firstChoice == 0)
        {
            break;
        }
        else
        {
            secondMenu(firstChoice, dataBase);
        }
    }
}

void sortBySurName(std::vector<Student>& dataBase)
{
    int j = 0;
    int i = 0;
    int tempValueFirst = 0;
    int tempValueNext = 0;
    bool indicatorI = 0;
    bool indicatorJ = 0;

    while (i < dataBase.size() - 1)
    {
        if (dataBase[i].getSurName() != dataBase[i + 1].getSurName())
        {
            if (dataBase[i].getSurName().size() <= dataBase[i + 1].getSurName().size())
            {
                indicatorReset(indicatorJ, j);
                if (j != dataBase[i].getSurName().size())
                {
                    recursionSort(dataBase, i, j, tempValueFirst, tempValueNext, indicatorI, indicatorJ);
                }
            }
            else
            {
                indicatorReset(indicatorJ, j);
                if (j != dataBase[i + 1].getSurName().size())
                {
                    recursionSort(dataBase, i, j, tempValueFirst, tempValueNext, indicatorI, indicatorJ);
                }
            }
            ++i;
            indicatorReset(indicatorI, i);
        }
        else
        {
            ++i;
        }
    }
}

int recursionSort(std::vector<Student>& dataBase, int& i, int& j, int& tempValueFirst, int& tempValueNext, bool& indicatorI, bool& indicatorJ)
{
    tempValueFirst = 0;
    tempValueNext = 0;
    if (j == 0)
    {
        compareCharAlphabetWithCharInString(dataBase, tempValueFirst, tempValueNext, UKR_ALPHABET_CAPS, i, j);
    }
    else
    {
        compareCharAlphabetWithCharInString(dataBase, tempValueFirst, tempValueNext, UKR_ALPHABET, i, j);
    }
   
    if (tempValueFirst > tempValueNext)
    {
        std::swap(dataBase[i], dataBase[i + 1]);
        indicatorI = 1;
        indicatorJ = 1;
        return i;
    }

    if (tempValueFirst == tempValueNext)
    {
        ++j;
        recursionSort(dataBase, i, j, tempValueFirst, tempValueNext, indicatorI, indicatorJ);
    }
    indicatorJ = 1;
    return i;
}

void compareCharAlphabetWithCharInString(std::vector<Student>& dataBase, int& tempValueFirst, int& tempValueNext, const std::vector<std::string> UkrAlphabet, int i, int j)
{
    for (auto& it : UkrAlphabet)
    {
        ++tempValueFirst;
        if (dataBase[i].getSurName()[j] == it[0])
        {
            break;
        }
    }
    for (auto& it : UkrAlphabet)
    {
        ++tempValueNext;
        if (dataBase[i + 1].getSurName()[j] == it[0])
        {
            break;
        }
    }
}

void indicatorReset(bool& indicator, int& value)
{
    if (indicator == 1)
    {
        value = 0;
        indicator = 0;
    }
}