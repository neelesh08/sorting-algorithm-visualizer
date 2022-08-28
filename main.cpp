//A MENU DRIVEN PROGRAM IN C++ TO VISUALIZE ALGORITHMS OF SORTING TECHNIQUES
#include <iostream>
#include <graphics.h>
#include <ctime>

using namespace std;

int i,j,k,n;

// function to display array while sorting  
void display(int a[])
{
	cleardevice();
	int i,n = 50;
	int start_x = 100,start_y = 400 , end_x = 100;
	cout<<"\nArray while sorting:\n";
	for (i = 0; i < n; i++)
	{
		line(start_x , start_y , end_x , start_y - a[i]);
		start_x += 5;
		end_x += 5; 
		delay(.1);
		cout << a[i] <<" ";
	}			
}

//function to display final output after sorting array
void final_display(int a[], int b[] , int n)
{
    int x_in1 = 100 ,x_in2 = 100; 
	int x_out1 = 600 ,x_out2 = 600 , y1 = 400;
	cleardevice();
	for(j = 0; j < n; j++)
	{
		line(x_in1 , y1 , x_in2 , y1 - b[j]);
		x_in1 += 5;
		x_in2 += 5;
		delay(10);	
	}
	cout<<endl<<"Array after sorting:"<<endl;
	for(i = 0;i < n; i++)
	{
		line(x_out1 , y1 , x_out2 , y1 - a[i]);
		x_out1 += 5;
		x_out2 += 5;
		delay(10);
		cout<< a[i] <<" ";	
	}
	delay(5000);	
}

// Function to swap numbers 
void swap(int* a1, int* b1) 
{ 
    int temp = *a1; 
    *a1 = *b1; 
    *b1 = temp; 
} 


//start of quick sort

/* This function takes last element as pivot, places the pivot element at its correctposition in sorted  array, and places 
   all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */
int partition(int a[], int l, int h) 
{ 
    int x = a[h]; 
    i = (l - 1); 
    for ( j = l; j <= h - 1; j++)
    { 
        if (a[j] <= x)
        { 
            i++; 
            swap(&a[i], &a[j]); 
        } 
    } 
    swap(&a[i + 1], &a[h]); 
    return (i + 1); 
} 
  
/* A[] --> Array to be sorted, l --> Starting index, h --> Ending index */
void quick_sort(int a[], int l, int h) 
{ 
    if (l < h) 
    { 
        /* Partitioning index */  
        int p = partition(a, l, h);
	    display(a);
        quick_sort(a, l, p - 1);	
        quick_sort(a, p + 1, h); 
    } 
} 

//end of quick Sort


//start of merge sort

// Merge two subarrays L and M into arr
void merge(int a[], int p , int q , int r) 
{
  
  // Create L ? A[p..q] and M ? A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], M[n2];
  for ( i = 0; i < n1; i++)
    L[i] = a[p + i]; 
  for ( j = 0; j < n2; j++)
    M[j] = a[q + 1 + j]; 

  // Maintain current index of sub-arrays and main array
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) 
  {
    if (L[i] <= M[j]) 
    {
    	a[k] = L[i]; i++;
    } 
	else 
	{
      a[k] = M[j]; j++;
    }
    k++;
  }

  // When we run out of elements in either L or M, pick up the remaining elements and put in A[p..r]
  while (i < n1) 
  {
    a[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) 
  {
    a[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void merge_sort(int a[], int l, int r) 
{
  if (l < r) 
  {
  
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;
	display(a);
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    
    // Merge the sorted subarrays
    merge(a, l, m, r);
  }
}

//end of merge sort


//start of heap sort

// function build Max Heap where value of each child is always smaller than value of their parent
void heapify(int a[], int n)  
{  
    for ( i = 1; i < n; i++) 
    { 
        
        // if child is bigger than parent 
        if (a[i] > a[(i - 1) / 2])
        { 
             j = i;
             
            // swap child and parent until parent is smaller
            while (a[j] > a[(j - 1) / 2])
            { 
                swap(a[j], a[(j - 1) / 2]); 
                j = (j - 1) / 2; 
            } 
        } 
    }
	 
} 
  
void heap_sort(int a[], int n)
{ 
    heapify(a, n);
    for (i = n - 1; i > 0; i--)
    { 
        
        // swap value of first indexed with last indexed 
        swap(a[0], a[i]);    	
     	display(a); 
     	
        // maintaining heap property after each swapping
         j = 0;  
        do
        { 
            n = (2 * j + 1); 
              
            // if left child is smaller than right child point index variable to right child 
            if (a[n] < a[n + 1] && n < (i - 1)) 
                n++; 
          
            // if parent is smaller than child then swapping parent with child having higher value 
            if (a[j] < a[n] && n < i) 
                swap(a[j], a[n]);
            j = n; 
        } while (n < i); 
    } 
} 

// end of heap sort


// Start of selection sort

void selection_sort(int a[], int n)
{
	int min;
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{ 
			if (a[min] > a[j])
			{
				min = j;
			}
		}
		swap(a[i], a[min]);
		display(a);
	}
}

// end of selection sort


//main function 

int main() 
{   
   initwindow (1000,500);	
   int b[100],a[100];
   int ch;
   
   jump:
   
   clock_t start_time;
   clock_t final_time;
   	
   int start_x = 100 ,start_y = 400 ,end_x = 100;
   n = 50;
   
   for (i = 0; i < n; i++)
   {
   	  a[i] = rand()%350;
   }
	cleardevice();	
	cout<<endl<<"Given array is:"<<endl;
	   
	for (i = 0; i < n; i++)
   {
		line(start_x, start_y , end_x , start_y - a[i]);
		start_x += 5;
		end_x  += 5;
		b[i] = a[i];
		cout<< a[i] <<" ";
		delay(3);
   }
   
   cout<<"\nSorting Techniques Available:"<<endl;
   cout<<"1.Quick Sort"<<endl<<"2.Merge Sort"<<endl<<"3.Heap Sort"<<endl<<"4.Selection Sort"<<endl<<"5.Exit"<<endl;
   label:cout<<"Enter your choice:";
   cin>>ch;
   switch(ch)
   {
       case 1:start_time = clock();
	   		  quick_sort(a, 0 , n - 1);
			    break;
       case 2:start_time = clock();
	   		  merge_sort(a, 0 , n - 1);
                break;
       case 3:start_time = clock();
	   		  heap_sort(a, n);
              break;
       case 4:start_time = clock();
	   		  selection_sort(a, n);   
	   		  break; 
	   case 5:cout<< "Program Exited" <<" "<<endl;  
			  exit(0);		
       default:cout<<"INVALID CHOICE!!!,TRY AGAIN..."<<endl;
       		   goto label;        ;
   }
   final_display(a, b , n);
   final_time = clock();
   cout<<endl<<"The execution time is " <<(final_time - start_time)/1000 <<" seconds" <<" ";
   goto jump;
   return 0;
}
