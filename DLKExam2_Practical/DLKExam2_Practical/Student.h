#pragma once

#include <iostream>

class Student
{
private:
	std::string m_name;
	float m_gpa = 0;

public:
	void SetName(const std::string newName) { m_name = newName; }
	void SetGPA(const float newGPA) { m_gpa = newGPA; }

	std::string GetName() const { return m_name; }
	float GetGPA() const { return m_gpa; }

	

	void Display()
	{

	}

	Student()
	{
		m_name = "Unknown";
		m_gpa = 0;
	}

	Student(std::string const name, float const gpa)
	{
		SetName(name);
		SetGPA(gpa);
	}


};