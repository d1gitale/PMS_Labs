#include "student.h"
#include "course.h"

int add_student(Course *course, Student *student) {
    course->students_array[course->students_amount++] = student;
    return course->students_amount;
}

Student* find_best_student(Course *course) {
    Student *best_student = course->students_array[0];
    for (int i = 1; i < course->students_amount; ++i) {
        if (best_student->mean_grade < course->students_array[i]->mean_grade) {
            best_student = course->students_array[i];
        }
    }
    return best_student;
}