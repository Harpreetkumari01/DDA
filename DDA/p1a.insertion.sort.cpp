#include<iostream>
using namespace std;
                                                        
class shortt
{
      public:      
              int a[10],i,c=0,n;
      void array()
      {    cout<<"enter the no of inputs :";
           cin>>n;
          cout<<"enter inputs: ";
          for(i=0;i<n;i++)
          cin>>a[i];
          }    
      void sort()
      {
              int temp,k;
              for(int i=1;i<=n-1;i++)
              {
                      for(int j=0;j<=i;j++)
                      {
                         if(a[j]>a[i])
                         {
                                     
                                        temp=a[j];
                                        a[j]=a[i];
                                        for(k=i;k>j;k--)
                                         {
                                         c++;
                                        a[k]=a[k-1];
                                         }
                                        a[k+1]=temp;
                                         
                         }
                      }
              }
    
           
      }
      void display()
      {
           for(int i=0;i<n;i++)
           cout<<a[i]<<"\t";
           cout<<endl;
      cout<<"\n Num Of cmp : "<<c<<endl;
   }  
       
             
      };
      int main()
      {
          shortt s1;
          s1.array();
          s1.sort();
          cout<<"Array after sorting\n ";
          s1.display();
          }
