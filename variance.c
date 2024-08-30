#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    double arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    double mean = sum / n;

    double squared_diff_sum = 0.0;
    for (int i = 0; i < n; i++) {
        squared_diff_sum += pow(arr[i] - mean, 2);
    }

    double variance = squared_diff_sum / n;
    double std_dev = sqrt(variance);

    printf("Mean: %f\n", mean);
    printf("Variance: %f\n", variance);
    printf("Standard Deviation: %f\n", std_dev);

    return 0;
}