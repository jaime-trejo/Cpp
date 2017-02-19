/*
 Using recursion with a recursion sort type of function.
 */
#include <iostream>

void RecursionSort(int arr[], int index_first,int index_last);

int main(int argc, const char * argv[]) {
    int arr[] = {5,4,3,2,1,7,6,9,8,0};
    
    RecursionSort(arr,0,9);
    
    for (int i = 0; i<10;i++)
    {
        std::cout << arr[i] << " " ;
    }
    
     std::cout << "\n" <<  std::endl;
    return 0;
}
void RecursionSort(int arr[], int index_first,int index_last)
{
    // if index_first is greater than or equal to index_last then it will return
    if(index_first >= index_last)
    {
        return;
    }
    
    // Find the index of the smallest element ranging from index_first to index_last
    
    int min = arr[index_first]; // min value is set to arr[index_first]
    int index_min = index_first;
    
    //scans through the array
    for(int i = index_first +1; i<=index_last; i++)
    {
        
        if(arr[i]< min)
        {
            min = arr[i];// sets min to the new array
            index_min = i;// set index_min to i
        }
    }
    // swap arr[index_min] with arr[index_first]
    int temp = arr[index_min];
    arr[index_min] = arr[index_first];
    arr[index_first] = temp;
    
    // calls RecursionSort and index_first increments by 1 so it goes to the next
    RecursionSort(arr,index_first +1,index_last);
}
