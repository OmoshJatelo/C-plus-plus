#include <iostream>



using namespace std;
void selection_sort(int arr[], int n)
{

	for(int i=0;i<n-1;i++)
	{
		int minimum_index=i;
		for(int j=i+1;j<n;j++)
		{

			if(arr[j]<arr[minimum_index])
			{
				minimum_index=j;
			}

		}
		swap(arr[minimum_index],arr[i]);
	}
}
void display_list(int arry[],int n)
{


	for(int i=0;i<n;i++)
	{
		cout<<arry[i]<<"->";
	}
	cout<<"NULL"<<endl;


}

int main()
{
    cout << "This program uses selection sort algorithm to arrange elements in ascending order" << endl;

    int arry[]={3,4,8,1,67,3,8,9,4,6,8,4,2,78};
    int n=sizeof(arry)/sizeof(arry[0]);
    cout<<"this is the unsorted list:"<<endl;
    display_list(arry,n);
    cout<<"This is the sorted list:"<<endl;
    selection_sort(arry,n);
    display_list(arry,n);
    return 0;
}
