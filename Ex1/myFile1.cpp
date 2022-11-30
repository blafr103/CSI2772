/*Ex1 devoir4 CSI2772A*/

#include <iostream> 
#include "myFile1a.h"
#include "myFile1b.h"
using namespace std;


int main() {
	Course* Math = new Course(100, 60);
	Course* ITI = new Course(200, 120);
	Student* Yan = new Student(1, 35);
	Student* Jane = new Student(2, 35);
	Yan->addCourse(Math, 15);
	Yan->addCourse(ITI, 12);
	Jane->addCourse(Math, 11);
	Jane->addCourse(ITI, 16);
	cout << "The total hours of Yan is " << Yan->totalHours() << endl;
	cout << "The average of Yan is " << Yan->average() << endl;
	cout << "The total hours of Jane is " << Jane->totalHours() << endl;
	cout << " The average of Jane is " << Jane->average() << endl;
	delete Math;
	delete ITI;
	delete Yan;
	delete Jane;
	cout << " Enter a number to exit..." << endl;
	return 0;
}

//////////Exercise 1 a)/////////////
////////////////////////////////////

//define course() constructor
Course::Course(int number, int hours) {
	this->num = number;
	this->hours = hours;
}

//define getNum()
int Course::getNum() {
	return this->num;
}

//define getHours()
int Course::getHours() {
	return this->hours;
}
//////////////////////////////////////
//////////////////////////////////////


//////////Exercise 1 b)/////////////
////////////////////////////////////


Student::Student(int numID, int maxCourses) {
	//initialized all values, using maxCourses to determine the array sizes
	this->numID = numID;
	this->nbCourses = 0;
	this->maxCourses = maxCourses;
	this->List_grades = new int[maxCourses];
	this->List_courses = new Course * [maxCourses];
}
//destructor destroys objects
Student::~Student() {
	delete List_grades;
	delete List_courses;
}

double Student::average() {
	double g = 0;
	//travel through all courses and add the hours from getCourses() then return it divided by the amount of course (average)
	for (int i = 0; i < this->nbCourses;i++) {
		g = g + this->List_grades[i];
	}

	return g / this->nbCourses;
	
}

int Student::totalHours() {
	double h = 0;
	//travel through all courses and add the hours from getHours()
	for (int i = 0; i < this->nbCourses; i++) {
		h = h + this->List_courses[i]->getHours();
	}

	return h;
}

bool Student::addCourse(Course* course, int note) {
	//check to see if course limit is reached
	if(this->maxCourses < this->nbCourses) {
		return false;
	}
	else {
		//add the course to the end of the course list with its data, and add the grade to grade list
		this->List_courses[nbCourses] = new Course(course->getNum(), course->getHours());
		this->List_grades[nbCourses] = note;
		//up the amount of current courses
		nbCourses++;
		return true;
	}

}

//////////////////////////////////////
//////////////////////////////////////