//Write a program to collect height and weight of N students. Find the highest weight/height ratio
#include <stdio.h>

struct Student {
    float height;
    float weight;
};

int main() {
    int N;
    printf("Enter the number of students: ");
    scanf("%d", &N);

    struct Student students[N];
    float maxRatio = 0.0;

    for (int i = 0; i < N; i++) {
        printf("Enter height and weight for student %d (format: height weight): ", i + 1);
        scanf("%f %f", &students[i].height, &students[i].weight);

        // Calculate weight/height ratio
        if (students[i].height != 0) {
            float ratio = students[i].weight / students[i].height;
            if (ratio > maxRatio) {
                maxRatio = ratio;
            }
        }
    }

    printf("Highest weight/height ratio: %.2f\n", maxRatio);
    return 0;
}