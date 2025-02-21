#include<iostream>

int main()
{
    int i,j,temp;
    int arr[]={10,5,7,9,4,12,35,76};
    for(i=1;i<(sizeof(arr)/sizeof(arr[0]));i++)
    {
        j=i-1;
        
        while(j>=0 &&arr[j]>arr[i])
        {
            temp = arr[j];            
            arr[j] = arr[j + 1];   // Shift element to the right`   
            arr[j + 1] = temp;      // Place the current element in the correct position
            j--;

        }     
    }
    for(int v=0;v<(sizeof(arr)/sizeof(arr[0]));v++){
        std::cout<<arr[v]<<",";
    }
    return 0;
}
/*sizeof(arr) gives you the total size in bytes of the entire array. If you have an array like int arr[8], and assuming each int is 4 bytes on your machine, sizeof(arr) will give you the total size in bytes of the entire array. For example, for int arr[8], sizeof(arr) would return 8 * 4 = 32 bytes.

sizeof(arr[0]) gives you the size of one element of the array. In this case, arr[0] is an int, so sizeof(arr[0]) will give you the size of a single integer, which is typically 4 bytes on most systems*/