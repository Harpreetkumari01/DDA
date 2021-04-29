#include <iostream>
using namespace std;
int Get_max(int arr[], int size) 
{ 
    int max = arr[0]; 
    for (int i = 1; i < size; i++) 
    {
    	if (arr[i] > max) 
    	{
    		 max = arr[i]; 
		}        
	}
    return max; 
} 

void CountingSort(int arr[], int size, int pos)
{
	int count[10]={0};
	int *brr=new int[size];
	//initialize all elements to 0
	for(int i=0;i<size;i++)
	{
		brr[i]=0;
	}
	//counting of occurences of elements 
	for (int i=0;i<size;i++)
	{
		count[(arr[i]/pos)%10]++;
	}
	
	for(int i=1;i<10;i++)
	{
		count[i]=count[i]+count[i-1];
	}
	
	for(int i=size-1;i>=0;i--)
	{
		brr[--count[(arr[i]/pos)%10]]=arr[i];
	}
	
	for(int i=0;i<size;i++)
	{
		arr[i]=brr[i];
	}
	return;
}

void RadixSort(int arr[], int size)
{
	int max=Get_max(arr,size);
	for(int pos=1;max/pos>0;pos=pos*10)
	{
		CountingSort(arr,size,pos);
	}
}
  
 
int main()
{
	int size;
	cout<<"\nEnter the size of the array: ";
	cin>>size;
	int *arr=new int[size];
	cout<<"\nEnter the array elements: ";
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	RadixSort(arr,size);
 	cout << "\nSorted array is: ";
    for (int i =0; i <size; i++)
    {
    	cout << arr[i] << " ";
	}
    
    return 0;
}
