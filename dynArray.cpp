/*
 Dynamic Arrays
 This program will contain functions that adds and removes elements from an array.
 */

#include<string>
#include<iostream>
using namespace std;

/*
 Adds an entry to the dynamic array, returning a pointer to the
 expanded array. size should contain the size of the array. It
 will be updated when the array is expanded.
 */
string* addEntry(string *dynamicArray, int &size, string newEntry);

/*
 Removes an entry from the dynamic array, returning a pointer to the
 smaller array. size should contain the size of the array. It
 will be updated when the element is deleted. If the entry is not
 found in the array, the original (unmodified) array will be
 returned.
*/
string* deleteEntry(string *dynamicArray, int &size, string entryToDelete);

void print(string *dynamicArray, int size);

int main(int argc, const char * argv[]) {
    
    int size = 5;
    string *names = new string[size];
    names[0] = "Neil";
    names[1] = "Chris";
    names[2] = "Heather";
    names[3] = "Walt";
    names[4] = "Apu";
    
    
    cout << "Initial list: " << endl;
    print(names,size);
    
    
    names = addEntry(names,size,"Ned");
    names = addEntry(names,size,"Seymour");
    cout << "After adding names: " << endl;
    print(names,size);
    
    
    cout << "After deleting Chris: " << endl;
    names = deleteEntry(names,size,"Chris");
    print(names,size);
    
    cout << "After deleting Joe: " << endl;
    names = deleteEntry(names,size,"Joe");// calls function to delete non-existent name
    print(names,size);
    
    cout << "After deleting Ned: " << endl;
    names = deleteEntry(names,size,"Ned");
    print(names,size);
    
    // delete array
    delete[] names;
    
    return 0;
}
string* addEntry(string *dynamicArray, int &size, string newEntry)
{
    string *newArray = new string[size+1];// creates new array, size+1 for an extra spot
   
    
    for(int i = 0; i < size; i++)
    {
        newArray[i] = dynamicArray[i];
    }
    // copy new entry to the end of the array
    newArray[size] = newEntry;
    size++;
    delete[] dynamicArray;// delete dynamicArray
    
    return newArray;// return the newArray
}
string* deleteEntry(string *dynamicArray, int &size, string entryToDelete)
{
    string *result = dynamicArray; //create a dynamicArray for the result and set equal to dynamicArray
    int index_of_entry_to_delete = -1; //if index not found it will stay at -1 otherwise it will change
    
    //loop through the array to see if it's in the array, but stop when target found
    for(int i = 0;(i<size) && (index_of_entry_to_delete == -1); i ++)
    {
        if(dynamicArray[i] == entryToDelete)// if it does find it capature the index at where it was located, first entry only
        {
            index_of_entry_to_delete = i;
        }
    }
    
    if ( index_of_entry_to_delete > -1)
    {
        result = new string[size -1];//make new array with an one element smaller on the heap
        
        for(int i = 0, j = 0; i <size;i++)// start a copy
        {
            // skip over the deleted element
            if(i !=index_of_entry_to_delete)
            {
                result[j++] = dynamicArray[i];// copies
            }
        }
        size--; // decrement the size since size was passed by reference
        delete[] dynamicArray; //delete dynamicArray for more memory
        
    }
    
    return result;
    
}
void print(string *dynamicArray, int size)
{
    
    for( int i = 0; i < size;i++)
    {
        cout << i << ":" << dynamicArray[i] << endl;
    }
    cout << endl;
}
