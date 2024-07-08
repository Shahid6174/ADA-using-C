#include <stdio.h>

// Function prototypes
void printSubset(int subset[], int size);
void findSubsets(int set[], int n, int target);

// Function to print the current subset
void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Function to find subsets that sum to the given target
void findSubsets(int set[], int n, int target) {
    int subset[n];
    int totalSubsets = 1 << n; // Total number of subsets (2^n)

    // Iterate over all possible subsets
    for (int i = 0; i < totalSubsets; i++) {
        int sum = 0;
        int subsetSize = 0;

        // Check which elements are included in the current subset
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset[subsetSize++] = set[j];
                sum += set[j];
            }
        }

        // If the sum of the current subset is equal to the target, print the subset
        if (sum == target) {
             printSubset(subset, subsetSize);
        }
    }
}

int main() {
    int set[10], n, target;

    // Input number of elements in the set
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    // Input elements of the set
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    // Input the target sum
    printf("Enter the target sum: ");
    scanf("%d", &target);

    // Find and print subsets that sum to the target
    findSubsets(set, n, target);

    return 0;
}
