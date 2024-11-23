/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:52:16 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/23 19:20:05 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Function to merge two sub-arrays into a sorted array
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;

    // Calculate the sizes of the two sub-arrays
    int n1 = mid - left + 1; // Size of the left sub-array
    int n2 = right - mid;    // Size of the right sub-array

    // Create temporary arrays to hold the data
    int L[n1], R[n2];

    // Copy the elements into the left sub-array
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    // Copy the elements into the right sub-array
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the two sub-arrays into the original array
    i = 0; // Initial index of the left sub-array
    j = 0; // Initial index of the right sub-array
    k = left; // Initial index of the merged array

    while (i < n1 && j < n2)
    {
        // Compare elements from both sub-arrays and place the smaller one in the merged array
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++; // Move to the next element in the left sub-array
        }
        else
        {
            arr[k] = R[j];
            j++; // Move to the next element in the right sub-array
        }
        k++; // Move to the next position in the merged array
    }

    // Copy any remaining elements from the left sub-array (if any)
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements from the right sub-array (if any)
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive function to divide the array into smaller parts and sort them
void mergeSort(int arr[], int left, int right)
{
    if (left < right) // Base condition: if the array has more than one element
    {
        int mid = left + (right - left) / 2; // Calculate the middle index

        // Recursively divide and sort the left half
        mergeSort(arr, left, mid);

        // Recursively divide and sort the right half
        mergeSort(arr, mid + 1, right);

        // Merge the two sorted halves
        merge(arr, left, mid, right);
    }
}

int main()
{
    // Input array
    int arr[] = {5, 14, 154, 641500, 41111, 454, 25, 3, 0};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Display the original array
    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Perform Merge Sort on the array
    mergeSort(arr, 0, n - 1);

    // Display the sorted array
    printf("Sorted array in ascending order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
