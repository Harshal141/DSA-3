import java.util.Arrays;
import java.util.Scanner;

public class HeapSortDemo {
    private static int[] heapArray;
    private static int heapSize;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] data = {13, 4, 11, 15, 59, 27, 19, 3, 5, 93};
        heapArray = Arrays.copyOf(data, data.length);
        heapSize = heapArray.length;

        int choice;
        do {
            System.out.println("------ Menu ------");
            System.out.println("1. Construct Binary Tree");
            System.out.println("2. Transform Binary Tree to Min Heap");
            System.out.println("3. Heapify");
            System.out.println("4. Display the List in Ascending Order");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    constructBinaryTree();
                    break;
                case 2:
                    transformToMinHeap();
                    break;
                case 3:
                    heapify();
                    break;
                case 4:
                    heapSort();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice! Please try again.");
                    break;
            }
            System.out.println();
        } while (choice != 5);

        scanner.close();
    }

    private static void constructBinaryTree() {
        System.out.println("Binary Tree:");
        for (int i = 0; i < heapSize; i++) {
            System.out.print(heapArray[i] + " ");
        }
        System.out.println();
    }

    private static void transformToMinHeap() {
        for (int i = (heapSize - 1) / 2; i >= 0; i--) {
            minHeapify(i);
        }
        System.out.println("Binary Tree transformed to Min Heap.");
    }

    private static void minHeapify(int i) {
        int smallest = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < heapSize && heapArray[leftChild] < heapArray[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < heapSize && heapArray[rightChild] < heapArray[smallest]) {
            smallest = rightChild;
        }

        if (smallest != i) {
            swap(i, smallest);
            minHeapify(smallest);
        }
    }

    private static void heapify() {
        int i;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the index to heapify (0-" + (heapSize - 1) + "): ");
        i = scanner.nextInt();
        if (i < 0 || i >= heapSize) {
            System.out.println("Invalid index!");
            return;
        }
        minHeapify(i);
        System.out.println("Heapified at index " + i + ".");
    }

    private static void heapSort() {
        System.out.println("Sorted List in Ascending Order:");
        for (int i = heapSize - 1; i >= 0; i--) {
            System.out.print(heapArray[0] + " ");
            swap(0, i);
            heapSize--;
            minHeapify(0);
        }
        System.out.println();
    }

    private static void swap(int i, int j) {
        int temp = heapArray[i];
        heapArray[i] = heapArray[j];
        heapArray[j] = temp;
    }
}
