/*
Title: Write a menu driven Java program to implement the Heap sort algorithm demonstrating 
heap data structure with modularity of programming language. 
Problem Statement: Sort below data using heap sort 13,4,11,15,59,27,19,3,5,93 & Provide 
facility for: 
1. Construct binary tree 
2. Transform binary tree to Max Heap 
3. Heapify 
4. Display the list in descending order
 */


import java.util.Arrays;
import java.util.Scanner;

public class HeapSortMenu {
    private int[] heap;
    private int size;

    public HeapSortMenu(int capacity) {
        heap = new int[capacity];
        size = 0;
    }

    private void buildHeap() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    private void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(index, largest);
            heapifyDown(largest);
        }
    }

    private void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    private void heapSort() {
        buildHeap();

        for (int i = size - 1; i >= 0; i--) {
            swap(0, i);
            size--;
            heapifyDown(0);
        }
    }

    private void displayDescending() {
        System.out.println("Elements in descending order:");
        for (int i = size - 1; i >= 0; i--) {
            System.out.print(heap[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();

        HeapSortMenu heapSortMenu = new HeapSortMenu(n);

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            heapSortMenu.heap[i] = scanner.nextInt();
            heapSortMenu.size++;
        }

        int choice;
        do {
            System.out.println("\n------ Heap Sort Menu ------");
            System.out.println("1. Construct Binary Tree");
            System.out.println("2. Transform Binary Tree to Max Heap");
            System.out.println("3. Heapify");
            System.out.println("4. Display List in Descending Order");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    heapSortMenu.buildHeap();
                    System.out.println("Binary tree constructed.");
                    break;
                case 2:
                    heapSortMenu.heapSort();
                    System.out.println("Binary tree transformed to Max Heap.");
                    break;
                case 3:
                    System.out.println("Enter the index to heapify: ");
                    int index = scanner.nextInt();
                    if (index >= 0 && index < heapSortMenu.size) {
                        heapSortMenu.heapifyDown(index);
                        System.out.println("Heapify operation completed.");
                    } else {
                        System.out.println("Invalid index.");
                    }
                    break;
                case 4:
                    heapSortMenu.displayDescending();
                    break;
                case 5:
                    System.out.println("Exiting program.");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 5);

        scanner.close();
    }
}


