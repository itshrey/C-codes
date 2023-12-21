#include<stdio.h>
void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void sort(int arr[][6], int size){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size;j++){
            if(arr[i][1]>arr[j][1] || (arr[i][1]==arr[j][1] && arr[i][2]>arr[j][2])){
                swap( &arr[i][0], &arr[j][0]);
                swap( &arr[i][1], &arr[j][1]);
                swap( &arr[i][2], &arr[j][2]);
            }
        }
    }
}

int main(){
    int n;
    printf("enter number of processes");
    scanf("%d", &n);

    int arr[n][6], ct_seq[n]; // pid at bt ct tat wt ,,  ct-at=tat,,  tat-bt=wt

    for(int i=0; i<n; i++){
        arr[i][0]=i;
        printf("enter arrival time and burst time for process %d\n", i+1);
        scanf("%d\n%d", &arr[i][1], &arr[i][2]);
        }
    
    sort(arr,n);
    
    int t=0, swt=0;
    for(int i=0; i<n; i++){
        if(arr[i][1]<=t){
            arr[i][3]=t+ arr[i][2];
            t= t+arr[i][2];
        }
        else{
            t=arr[i][1];
            arr[i][3]=t+ arr[i][2];
            t= t+arr[i][2];
        }
        ct_seq[i]=arr[i][0]+1;
        arr[i][4]=arr[i][3]-arr[i][1];
        arr[i][5]=arr[i][4]-arr[i][2];
        swt=swt+arr[i][5];
    }

    float awt;
    awt= (float)swt/n;
    printf("\nPROCESS\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\t%d\n", ct_seq[i], arr[i][3],arr[i][4],arr[i][5] );
    }
    printf("average waiting time is: %f", awt);
}
