#ifndef COURSE_H
#define COURSE_H

#include "student.h"

typedef struct {
    char *title;
    int students_amount;
    double max_mean_grade;
    Student *students_array;
} Course;

int add_student(Course *course, Student *student);

Student* find_best_student(Course *course);

#endif