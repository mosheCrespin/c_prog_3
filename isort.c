#include <stdio.h>
#define SIZE 50

void shift_element(int* arr, int i){
    while(i>0){
        *(arr+i)= *(arr +i-1);
          i--;
    }

}

void insertion_sort(int* arr , int len){
    int i,j,temp;
    for(i=1; i<len; i++){
        j=i;
        temp=*(arr+i);
        while((j-1>=0)&&temp<*(arr+j-1))
        {//find the right place for arr[i]
            j=j-1;
        }
        if(j!=i){
        	shift_element(arr+j,i-j);
        	*(arr+j)=temp;
        }
    }
    }


int main(){
    int arr[SIZE];
    int i;
    for(i=0;i<SIZE;i++){
        scanf("%d" , arr+i);
    }
    insertion_sort(arr,SIZE);
    for(i=0;i<SIZE-1;i++){
        printf("%d,", *(arr+i));
        }
     printf("%d", *(arr+SIZE-1));



}




