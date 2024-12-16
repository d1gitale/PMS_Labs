#include "student.h"

void change_mean_grade(Student *student, double grade) {
    if (grade < 0 || grade > 10) {
        return -1;
    }
    student->mean_grade = grade;
}

int is_perfectionist(Student *student) {
    return student->mean_grade >= 8.6;
}