#include<iostream>
using namespace std;
int comp=0;
void swap(int arr[], int first, int second) 
{
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

int partition(int arr[], int left, int right) 
{
    int pivot = arr[right];
    cout<<"\npivot element: "<<pivot;
    int i = left - 1;

    for (int j = left; j < right; j++) 
	{
      if (arr[j] <= pivot) 
	  {
        i++;
		swap(arr, i, j);
      }
      comp++;
    }
	swap(arr, i + 1, right);
	cout<<"\narray after swapping: ";
	for(int i=0;i<right;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\ncomparison="<<comp;
	return i + 1; // Return the pivot's final resting position
}

void quicksort(int arr[], int left, int right) 
{
    if (left < right) 
	{
      int pivotFinalRestingPosition = partition(arr, left, right);

      quicksort(arr, left, pivotFinalRestingPosition - 1);
      quicksort(arr, pivotFinalRestingPosition + 1, right);
    }
}

int main()
{
	int n;
	cout<<"\nenter size of array: ";
	cin>>n;
	int A[n];
	cout<<"\nenter array elements: ";
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	int mid=n/2;
	quicksort(A,0,n-1);
	cout<<"\nsorted array: ";
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<"\nno. of comparisons= "<<comp;
	return 0;
}
