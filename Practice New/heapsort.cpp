
#include<bits/stdc++.h>
void inplaceHeapSort(int input[], int n){
	int size;
    int j,parent,temp;
    for(int i=0;i<n;i++)
    {
        j=i;
        parent=(j-1)/2;
        while(j>0)
        {
            if(input[j]<input[parent])
            {
                temp=input[j];
                input[j]=input[parent];
                input[parent]=temp;
                j=parent;
                parent=(j-1)/2;
            }
            else
            {
                break;
            }
        }
    }
    int a,leftc,rightc,min,k;
    while(n)
    {
        a=input[0];
        input[0]=input[n-1];
        input[n-1]=a;
        n--;
        k=0;
        min=k;
        leftc=2*min+1;
        rightc=2*min+2;
        while(leftc<n)
        {
            if(input[min]>input[leftc])
            {
                min=leftc;
            }
            if(rightc<n && input[min]>input[rightc])
            {
                min=rightc;
            }
            if(min==k)
            {
                break;
            }
            temp=input[min];
            input[min]=input[k];
            input[k]=temp;
            k=min;
            leftc=2*k+1;
            rightc=2*k+2;
        }
    }

}

