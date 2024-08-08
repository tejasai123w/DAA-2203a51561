#include<stdio.h>
void merge(int a[],int lb,int mid,int ub,int n){
      int i,j,k;
    int b[n];
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid&&j<=ub){
         if(a[i]<=a[j]){
               b[k]=a[i];
               i++;
               k++;
         }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    if(i>mid){
     while(j<=ub){
      b[k]=a[j];
         j++;
         k++;
     }
    }
    else{
       while(i<=mid){
         b[k]=a[i];
           i++;
           k++;
       }    
    }
    for(k=lb;k<=ub;k++){
       a[k]=b[k];
    }
}
void mergesort(int a[],int lb,int ub,int n)
{
 if(lb<ub){
   int mid=(lb+ub)/2;
     mergesort(a,lb,mid,n);
     mergesort(a,mid+1,ub,n);
     merge(a,lb,mid,ub,n);
 }
}
 int main(){
     int i,j,k,n=4;
     int a[n];
     printf("Enter time to reach destination:\n");
     for(i=0;i<n;i++){
     scanf("%d",&a[i]);
     }
     mergesort(a,0,n-1,n);
     
     for(i=0;i<n;i++){
      printf("%d ",a[i]);
     }
     return 0;
 }
