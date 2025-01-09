#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5


struct hocsinh {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};


void nhaphs(struct hocsinh students[], int *currentLength) {
    students[0] = (struct hocsinh){1, "embedays", 20, "0123456789"};
    students[1] = (struct hocsinh){2, "babyboo", 21, "0987654321"};
    students[2] = (struct hocsinh){3, "haitu", 22, "0123987654"};
    students[3] = (struct hocsinh){4, "co be toc do", 19, "0987123456"};
    students[4] = (struct hocsinh){5, "ozawa", 23, "0912345678"};
    *currentLength = 5;
}


void printStudents(struct hocsinh students[], int currentLength) {
    printf("Danh sách sinh viên hiện tại:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d, Tên: %s, Tuổi: %d, Số điện thoại: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}


void swap(struct hocsinh *a, struct hocsinh *b) {
    struct hocsinh temp = *a;
    *a = *b;
    *b = temp;
}


void sortStudentsByName(struct hocsinh students[], int currentLength) {
    for (int i = 0; i < currentLength - 1; i++) {
        for (int j = i + 1; j < currentLength; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                swap(&students[i], &students[j]);
            }
        }
    }
}

int main() {
    struct hocsinh students[MAX_STUDENTS];
    int currentLength = 0;


    nhaphs(students, &currentLength);

    printf("Trước khi sắp xếp:\n");
    printStudents(students, currentLength);

    // Sắp xếp danh sách sinh viên theo tên
    sortStudentsByName(students, currentLength);

    printf("Sau khi sắp xếp:\n");
    printStudents(students, currentLength);

    return 0;
}
