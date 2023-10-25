#include<stdio.h>
#include<stdlib.h>
int main(){
  int a[10],i,key,flag=0,n,l,u,mid;
  printf("entre the number of elements:");
  scanf("%d",&n);
  printf("entre the elements in ascending order:\n");
  for(i=0;i<n;i++)
  {
    
    scanf("%d",&a[i]);
    
    if(a[i]<a[i-1]&&i!=0)
    {
      printf("wrong input...elements must be inserted into acsecnding order!!");
      exit(1);
    }
  }
  printf("\nentre the searching elements:");
  scanf("%d",&key);
  l=0;
  u=n-1;
  while(l<=u)
  {
    mid=(l+u)/2;
    if(a[mid]==key)
    {
      flag=1;
      break;
    }
    else if(key >a[mid])
    {
      l=mid+1;
    }
    else
    {
      u=mid-1;
    }
  }
  if(flag==1)
  {
    printf("\n%d is found at position :%d",key,mid);
  }
  else
  {
    printf("\n%d is not found",key);
  }
}