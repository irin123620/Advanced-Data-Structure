#include <stdio.h>

#define N 10     // size of universal set

void inputSet(int s[]) {
    printf("Enter %d bits (0 or 1): ", N);
    for (int i = 0; i < N; i++)
        scanf("%d", &s[i]);
}

void display(int s[]) {
    for (int i = 0; i < N; i++)
        printf("%d ", s[i]);
    printf("\n");
}

void Union(int a[], int b[], int result[]) {
    for (int i = 0; i < N; i++)
        result[i] = a[i] | b[i];
}

void Intersection(int a[], int b[], int result[]) {
    for (int i = 0; i < N; i++)
        result[i] = a[i] & b[i];
}

void Difference(int a[], int b[], int result[]) {
    for (int i = 0; i < N; i++)
        result[i] = a[i] & (!b[i]);
}

int main() {
    int A[N], B[N], R[N];
    int choice;

    printf("Enter Set A:\n");
    inputSet(A);

    printf("Enter Set B:\n");
    inputSet(B);

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Union\n2. Intersection\n3. Difference (A - B)\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Union(A, B, R);
                printf("Union: ");
                display(R);
                break;

            case 2:
                Intersection(A, B, R);
                printf("Intersection: ");
                display(R);
                break;

            case 3:
                Difference(A, B, R);
                printf("Difference (A-B): ");
                display(R);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
