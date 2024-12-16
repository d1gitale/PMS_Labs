#include "student.h"

void change_mean_grade(Student *student, double grade) {
    student->mean_grade = grade;
}

int is_perfectionist(Student *student) {
    return student->mean_grade >= 8.6;
}