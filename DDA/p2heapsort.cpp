#include <iostream>
 
using namespace std;
int c=0 ;
void Heap(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2*i;
 
 	while (j <= n)
	{
		if (j < n && a[j+1] > a[j])
		j = j+1;
	    c++;
		if (temp > a[j])
			break;
		else if (temp <= a[j])
		{
			a[j/2] = a[j];
			j = 2*j;
		}
	}
	a[j/2] = temp;
	return;
}
void HeapSort(int a[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		Heap(a, 1, i - 1);
	}
}
void MaxHeap(int a[], int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
		Heap(a, i, n);
}

int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
	n++;
	int arr[n];
	for(i = 1; i < n; i++)
	{
		cout<<"Enter element "<<i<<": ";
		cin>>arr[i];
	}
	
	MaxHeap(arr, n-1);
	HeapSort(arr, n-1);
	
 
	cout<<"\nSorted array";
 
	for (i = 1; i < n; i++)
		cout<<arr[i]<<"\t";
	cout<<"\n"<<"totalno of comparision: "<<c;
 
	return 0;
}
