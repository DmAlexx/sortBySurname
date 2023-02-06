#include "Student.h"

Student::Student(std::string name, std::string surName, std::string dateOfBirth, std::string phoneNumber, std::string adress, std::string groupNumber)
	: m_name(name)
	, m_surName(surName)
	, m_dateOfBirth(dateOfBirth)
	, m_phoneNumber(phoneNumber)
	, m_adress(adress)
	, m_groupNumber(groupNumber)
{
}

Student::Student(const Student& right)
	: m_name(right.m_name)
	, m_surName(right.m_surName)
	, m_dateOfBirth(right.m_dateOfBirth)
	, m_phoneNumber(right.m_phoneNumber)
	, m_adress(right.m_adress)
	, m_groupNumber(right.m_groupNumber)
{
}

Student& Student::operator=(const Student& right)
{
	m_name = right.m_name;
	m_surName = right.m_surName;
	m_dateOfBirth = right.m_dateOfBirth;
	m_phoneNumber = right.m_phoneNumber;
	m_adress = right.m_adress;
	m_groupNumber = right.m_groupNumber;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Student& right)
{
	out << right.m_surName << "; Ім'я - " << right.m_name << "; дата народження - " << right.m_dateOfBirth << "; номер телефона - " << right.m_phoneNumber << "; адреса - " << right.m_adress << "; група - " << right.m_groupNumber;
	return out;
}