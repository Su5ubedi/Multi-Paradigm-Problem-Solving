#include <stdio.h>
#include <stdlib.h>

// Function to calculate mean
double calculate_mean(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (double)sum / size;
}

// Function to sort array (bubble sort for simplicity)
void sort_array(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate median
double calculate_median(int arr[], int size)
{
    // Create a copy to avoid modifying original array
    int *sorted = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        sorted[i] = arr[i];
    }

    sort_array(sorted, size);

    double median;
    if (size % 2 == 0)
    {
        median = (sorted[size / 2 - 1] + sorted[size / 2]) / 2.0;
    }
    else
    {
        median = sorted[size / 2];
    }

    free(sorted);
    return median;
}

// Function to calculate mode
void calculate_mode(int arr[], int size)
{
    int max_count = 0;

    // Find maximum frequency
    for (int i = 0; i < size; i++)
    {
        int count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > max_count)
        {
            max_count = count;
        }
    }

    // Print all values with maximum frequency
    printf("Mode(s): ");
    int printed = 0;
    for (int i = 0; i < size; i++)
    {
        int count = 1;
        int already_printed = 0;

        // Check if already printed
        for (int k = 0; k < i; k++)
        {
            if (arr[k] == arr[i])
            {
                already_printed = 1;
                break;
            }
        }

        if (already_printed)
            continue;

        // Count frequency
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        if (count == max_count)
        {
            if (printed > 0)
                printf(", ");
            printf("%d", arr[i]);
            printed++;
        }
    }
    printf("\n");
}

// Function to print array
void print_array(int arr[], int size)
{
    printf("Data: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");
}

int main()
{
    // Sample data
    int data[] = {1, 2, 2, 3, 4, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    printf("=== C Statistics Calculator (Procedural) ===\n");
    print_array(data, size);

    printf("Mean: %.2f\n", calculate_mean(data, size));
    printf("Median: %.2f\n", calculate_median(data, size));
    calculate_mode(data, size);

    return 0;
}