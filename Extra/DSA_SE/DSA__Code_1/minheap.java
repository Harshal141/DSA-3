import java.util.Scanner;

public class HeapSort{
    private int[] arr;
    private int N;

    public void convertoMaxHeap(){
        for(int i=N/2 -1;i>=0;i--){
            heapify(i,N);
        }
    }

    public void heapsort(){
        convertoMaxHeap();
        for(int i=N-1;i>0;i--){
            int temp=arr[0];
            arr[0]=arr[i];
            arr[i]=temp;
            heapify(0,i);
        }
    }

    public void heapify(int i,int size){
        int largest=i;
        int left=2*i +1;
        int right=2*i +2;

        if(left<size && arr[left]<arr[largest])
            largest=left;

        if(right<size && arr[right]<arr[largest])
            largest=right;

        if(largest!=i){
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
            heapify(largest,size);
        }
    }
  static void display(int arr[],int n) {
        int N = arr.length;
        if(n==0)
        for (int i = 0; i < N; ++i)
            System.out.print(arr[i] + " ");
        else
            for (int i = N-1; i > -1; --i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
    public static void main(String args[]){
        //Scanner scanner=new Scanner(System.in);
         Scanner scanner = new Scanner(System.in);
        HeapSort heapsort=new HeapSort();
       
       int choice;
        do {
            System.out.println("Menu:");
            System.out.println("1. Construct Tree");
            System.out.println("2. Convert to min heap");
            System.out.println("3. Perform heap sort");
            System.out.println("4. Heapify about a particular index");
            System.out.println("5. Display array in ascending order");
            System.out.println("6. Exit");
              System.out.println("Enter Choice ");
            choice=scanner.nextInt();
            switch(choice){
            case 1: System.out.println("Enter no. of elements : ");
                    int n=scanner.nextInt();
                    heapsort.N = n;
                    heapsort.arr = new int[n];
                    for(int i=0;i<n;i++){
                            heapsort.arr[i]=scanner.nextInt();
                    }
                     System.out.println("1. Constructed Tree is ::");
                    heapsort.display(heapsort.arr,0);
                    break;
            case 2:heapsort.convertoMaxHeap();
                    heapsort.display(heapsort.arr,0);
                    break;

            case 3:heapsort.heapsort();
                     System.out.println("Tree Sorted ");
                    break;

            case 4: System.out.print("Enter the index to heapify around: ");
                        int index = scanner.nextInt();
                    heapsort.heapify(index,heapsort.N);
                    heapsort.display(heapsort.arr,0);
                    break;
            case 5:heapsort.display(heapsort.arr,1);
                    break;

            default:break;
            }
          
            
        }while(choice!=6);
    }
}