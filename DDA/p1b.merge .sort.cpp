#include <iostream>
using namespace std;
#include <conio.h>
int comp=0;
void merge(int *,int, int , int );
void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if(a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
            comp++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
            comp++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
    cout<<"\n comparision: "<<comp;
    
}
int main()
{
    int a[20], i, b[20],n;
    cout<<"enter the number of inputs:";
    cin>>n;
    cout<<"enter  the inputs \n";
    for (i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    mergesort(a, 0, n-1);
    cout<<"\n"<<"sorted array\n";
    for (i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<"\n"<<"the no. of comparisons:\n"<<comp<<endl;
    getch();
}
