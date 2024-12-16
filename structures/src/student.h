#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char name[20];
    short int age;
    double mean_grade;
} Student;

int change_mean_grade(Student *student, double grade);

int is_perfectionist(Student *student);

#endif