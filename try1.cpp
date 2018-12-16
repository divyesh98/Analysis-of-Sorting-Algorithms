#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
	
	return;
}

void bubble_sort(int* a_bubble){
	for(int i = 0 ; i < 49999 ; i++){
		for(int j = 0 ; j < 49999 - i ; j++){
			if(a_bubble[j] > a_bubble[j+1]){
				swap(&a_bubble[j], &a_bubble[j+1]);
			}
		}
	}
	return;
}

void insertion_sort(int* a_insertion){
	int i, key, j; 
	for (i = 1; i < 50000; i++) { 
		key = a_insertion[i]; 
		j = i-1; 
		
		while (j >= 0 && a_insertion[j] > key) { 
			a_insertion[j+1] = a_insertion[j];
			j = j-1; 
		}
		a_insertion[j+1] = key; 
	}
	
	return;
}

void selection_sort(int* a_selection){
    int i, j, min_idx; 
	
	for (i = 0; i < 49999; i++) {
		min_idx = i; 
		for (j = i+1; j < 50000; j++) 
			if (a_selection[j] < a_selection[min_idx]) 
				min_idx = j; 
  
  		swap(&a_selection[min_idx], &a_selection[i]); 
    }
	return;
}

void merge(int arr[], int l, int m, int r) { 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0;
    j = 0;
    k = l;
	 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void merge_sort(int* a_merge, int l, int r){
	if (l < r) { 
        int m = l+(r-l)/2; 
        
        merge_sort(a_merge, l, m); 
        merge_sort(a_merge, m+1, r); 
        merge(a_merge, l, m, r); 
    }
}

int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    
    do
    {
        do
            i++;
            
        while(a[i]<v&&i<=u);
        
        do
            j--;
        while(v<a[j]);
        
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    
    a[l]=a[j];
    a[j]=v;
    
    return(j);
}

void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
} 

void heapify(int arr[], int n, int i) {
    int largest = i; 
    int l = 2*i + 1;
    int r = 2*i + 2; 

    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) { 
        swap(&arr[i], &arr[largest]);  
        heapify(arr, n, largest); 
    }
    return;
}

void heap_sort(int* a_heap){
	for (int i = 50000 / 2 - 1; i >= 0; i--) 
		heapify(a_heap, 50000, i); 

    for (int i = 49999; i>=0; i--) {
        swap(&a_heap[0], &a_heap[i]); 
  
        heapify(a_heap, i, 0); 
    }
    return;
}

int main(){
	int n = 50000;
	clock_t start_t,end_t_bubble, end_t_selection, end_t_insertion, end_t_merge, end_t_quick, end_t_heap;

	float total_t_bubble, total_t_insertion, total_t_selection, total_t_merge, total_t_quick, total_t_heap;
	
	int i=0,j=0,x,temp;
	int a_insertion[n], a_bubble[n], a_selection[n], a_merge[n], a_quick[n], a_heap[n];
	
	for(i = 0 ; i < n ; i ++){
		a_insertion[i] = n - i;
		a_bubble[i] = n - i;
		a_selection[i] = n - i;
		a_merge[i] = n - i;
		a_quick[i] = n - i;
		a_heap[i] = n - i;
	}
	
	start_t=clock();
	printf("start_t= %ld\n", start_t);
	
	printf("Bubble sort started\n");
	bubble_sort(a_bubble);

	end_t_bubble=clock();
	printf("end_t1= %ld\n", end_t_bubble);
	
	printf("selection sort started\n");
	selection_sort(a_selection);
	
	end_t_selection = clock();
	printf("end_t2= %ld\n", end_t_selection);
	
	printf("Insertion sort started\n");
	
	insertion_sort(a_insertion);
	
	end_t_insertion = clock();
	printf("end_t3= %ld\n", end_t_insertion);
	
	printf("Merge sort started\n");
	merge_sort(a_merge, 0 , 49999);
	
	end_t_merge = clock();
	printf("end_t4= %ld\n", end_t_merge);
	
	//printf("Quick sort started\n");
	//quick_sort(a_quick, 0, 49999);
	
	//end_t_quick = clock();
	//printf("end_t5= %ld\n", end_t_quick);
	
	printf("heap sort started\n");
	heap_sort(a_heap);
	
	end_t_heap = clock();
	printf("end_t6= %ld\n", end_t_heap);
	//printf("start_t= %ld\n", start_t);

	//printf("end_t= %ld\n", end_t);

	printf("clock per sec= %ld\n",CLOCKS_PER_SEC);

	total_t_bubble=(end_t_bubble - start_t);
	total_t_selection = (end_t_selection - end_t_bubble);
	total_t_insertion = (end_t_insertion - end_t_selection);
	total_t_merge = (end_t_merge - end_t_insertion);
//	total_t_quick = (end_t_quick - end_t_merge);
	total_t_heap = (end_t_heap - end_t_merge);
	
	printf("total time for bubble sort = %f\n",total_t_bubble/CLOCKS_PER_SEC);
	printf("total time for insertion sort = %f\n",total_t_insertion/CLOCKS_PER_SEC);
	printf("total time for selection sort = %f\n",total_t_selection/CLOCKS_PER_SEC);
	printf("total time for merge sort = %f\n",total_t_merge/CLOCKS_PER_SEC);
	//printf("total time for quick sort = %f\n",total_t_quick/CLOCKS_PER_SEC);
	printf("total time for heap sort = %f\n",total_t_heap/CLOCKS_PER_SEC);
	
	/*printf("Bubble sorted\n");
	for(i = 0 ;i < n; i++){
		printf("%d ",a_bubble[i]);
	}
	printf("\n");
	printf("Insertion sorted\n");
	for(i = 0 ;i < n; i++){
		printf("%d ",a_insertion[i]);
	}
	printf("\n");
	printf("Selection sorted\n");
	for(i = 0; i < n; i++){
		printf("%d ",a_selection[i]);
	}
	printf("\n");
	printf("Merge sorted\n");
	for(i = 0 ;i < n; i++){
		printf("%d ",a_merge[i]);
	}
	printf("\n");
	printf("Quick sorted\n");
	for(i = 0 ;i < n; i++){
		printf("%d ",a_quick[i]);
	}
	printf("\n");
	printf("Heap sorted\n");
	for(i = 0; i < n; i++){
		printf("%d ",a_heap[i]);
	}*/

	
	return 0;

}
