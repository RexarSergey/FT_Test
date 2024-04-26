#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <format>

struct Student
{
	int id;
	std::string name;
	int age;
};

class DB_Class
{
public:
	void AddStudent(int id, std::string name, int age)
	{
		students.insert({ id, std::make_unique<Student>(Student{id, name, age}) });
	}

	void DeleteStudentByID(int id)
	{
		if (!students.contains(id))
		{
			std::cout << "<<DeleteStudentByID>> The is no student with id: " << id << '\n';
			return;
		}

		students.erase(id);
	}

	Student* GetStudentInfoByID(int id)
	{
		if (!students.contains(id))
		{
			std::cout << "<<GetStudentInfoByID>> The is no student with id: " << id << '\n';
			return;
		}

		Student* student = students[id].get();
		std::cout << std::format("Student ID: {0}\nStudent Name: {1}\nStudent Age: {2}\n\n",
			student->id, student->name, student->age);
	}

private:
	std::unordered_map<int, std::unique_ptr<Student>> students;
};

int main()
{
	DB_Class db;

	db.AddStudent(1, "Lena", 14);
	db.GetStudentInfoByID(1);
	db.DeleteStudentByID(1);

	db.GetStudentInfoByID(1);
	db.GetStudentInfoByID(1);

	return 0;
}