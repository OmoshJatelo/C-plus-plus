#include<iostream>
#include<random>
using namespace std;

void bubble_sort(int array[], int array_size)
{//the firs loop runs untill we reach the index of the second last element beacuse the greatest element would have been inserted into its position
    for(int i=0;i<array_size-1;i++){
        // this inner loop swaps the elements as long as the number on the left is greater than the one on the right
        for(int j=0;j<array_size-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                swap(array[j],array[j+1]);
            }
        }
    }

}

void display_sorted(int arr[], int arr_size){
    for(int i=0;i<arr_size;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}

int main()
{
   /* int numbers;
    cout<<"how many random numbers do you want to generate and sort";
    cin>,numbers;
    srand(time(0));
    for(int i=0;i<numbers,i++){
        int arr[i]=rand()%1000;

    }*/
    
    int arr[]={547,456,8769,43,67,343,89,455,889,9,455,43,232,767,43,76743,645,65,234,7657,4353,6756};
    int arr_size=sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr, arr_size);
    display_sorted(arr, arr_size);
    return 0;

}