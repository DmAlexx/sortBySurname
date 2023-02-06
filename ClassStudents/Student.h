#pragma once
#include <iostream>

class Student
{
public:
	Student(std::string name, std::string surName, std::string dateOfBirth, std::string phoneNumber, std::string adress, std::string groupNumber);
	Student(const Student& right);
	Student& operator=(const Student& right);
	friend std::ostream& operator<<(std::ostream& out, const Student& right);
	void setName(const std::string& name) { m_name = name; }
	void setSurName(const std::string& surName) { m_surName = surName; }
	void setDateOfBirth(const std::string& dateOfBirth) { m_dateOfBirth = dateOfBirth; }
	void setPhoneNumber(const std::string& phoneNumber) { m_phoneNumber = phoneNumber; }
	void setAdress(const std::string& adress) { m_adress = adress; };
	void setGroupNumber(const std::string& groupNumber) { m_groupNumber = groupNumber; }
	const std::string& getName() { return m_name; }
	const std::string& getSurName() { return m_surName; }
	const std::string& getDateOfBirth() { return m_dateOfBirth; }
	const std::string& getPhoneNumber() { return m_phoneNumber; }
	const std::string& getAdress() { return m_adress; }
	const std::string& getGroupNumber() { return m_groupNumber; }

private:
	std::string m_name;
	std::string m_surName;
	std::string m_dateOfBirth;
	std::string m_phoneNumber;
	std::string m_adress;
	std::string m_groupNumber;
};

