#include "student.c"
#include "course.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    Course *course = malloc(sizeof(Course));
    
    if (course == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    course->title = "Test course";
    course->students_amount = 0;
    course->students_array = malloc(10 * sizeof(Student));

    if (course->students_array == NULL) {
        printf("Memory allocation error\n");
        free(course);
        return 1;
    }

    printf("Options:\n1) Add a new student\n2) Find a student with highesth mean grade\n3) Change mean grade for a student\n4) Is some student a perfectionist\n5) Get status of the course\n6) Exit the program\n");

    while (1) {
        printf("structures> ");
        char command[20]; scanf("%s", command);

        if (strcmp(command, "1") == 0) {
            Student *student = malloc(sizeof(Student));

            if (student == NULL) {
                printf("Memory allocation error\n");
                free(course->students_array);
                free(course);
                return 1;
            }

            printf("Enter name (less than 20 characters): "); scanf("%s", student->name);
            printf("Enter age: "); scanf("%hd", &student->age);
            printf("Enter mean grade: "); scanf("%lf", &student->mean_grade);


            if (add_student(course, student) == -1) {
                printf("Memory allocation error\n");
                free(course->students_array);
                free(student);
                free(course);
                return 1;
            } else printf("This student id is %d\n", course->students_amount - 1);
        }
        else if (strcmp(command, "2") == 0) {
            Student *best_student = find_best_student(course);
            printf("Best student: %s\n", best_student->name);
        }
        else if (strcmp(command, "3") == 0) {
            printf("Enter student id: ");
            int id; scanf("%d", &id);
            printf("Enter new mean grade: ");
            double mean; scanf("%lf", &mean);
            if (id < course->students_amount) {
                int res = change_mean_grade(&course->students_array[id], mean);
                if (res == -1) printf("Invalid mean grade\n");
            } else printf("No such student\n");
        } 
        else if (strcmp(command, "4") == 0) {
            printf("Enter student id: ");
            int id; scanf("%d", &id);
            if (id < course->students_amount) {
                if (is_perfectionist(&course->students_array[id])) {
                    printf("Yes\n");
                } else printf("No\n");
            } else printf("No such student\n");
        }
        else if (strcmp(command, "5") == 0) {
            printf("Title: %s\n", course->title);
            printf("Amount of students: %d\n", course->students_amount);
            for (int i = 0; i < course->students_amount; ++i) {
                printf("Student %d:\n\tName: %s\n\tAge: %d\n\tMean grade: %lf\n", i, course->students_array[i].name, course->students_array[i].age, course->students_array[i].mean_grade);
            }
        }
        else if (strcmp(command, "6") == 0) {
            free(course->students_array);
            free(course);
            return 0;
        }
        else printf("Invalid command\n");
    }
}