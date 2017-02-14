//Description: This program was made to test vectors.

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void inOrder(const vector<int>&v);
void inReverseOrder(const vector<int>&v);
void withIteration(vector<int>&v);
void sorted(vector<int>&v);


int main(int argc, const char * argv[])
{
    vector<int> v;
    int integers;
    
    cout << "Hello, can you please enter some integers.\n";
    cout << "\n<Put a space between the integers, once you entered the \ndesired integers please enter a character and press enter>\n";
    cout << "\nMy integers: ";
    
    //once the user enters a non-integer then it will stop
    while (cin >> integers)
    {
        v.push_back(integers);
    }
    
    inOrder(v);
    inReverseOrder(v);
    
    v.push_back(22);// puts the number 22 into the vector
    cout << "\nWith the number (22) pushed into the vector, it is now:";
    inOrder(v);
    inReverseOrder(v);
    
    withIteration(v);
    sorted(v);
    
    cout << "\n";
    
    return 0;
}
//This function will print the vector in order
void inOrder(const vector<int>& v)
{
    cout << "\nThe integers you entered in order are:\n";
    
    for(int i=0;i < v.size();i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
//This function will print the vector in reverse order.
void inReverseOrder(const vector<int>& v)
{
    cout <<"\nThe integers you entered in reverse order are:\n";
    
    for(long i=v.size()-1;  i >= 0; i--)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
//This function will print the vector using iteration
void withIteration(vector<int>&v)
{
    vector<int>::iterator it;
    cout << "\nThe integers you entered in order by using an iteration are:\n";
    for (it=v.begin(); it!=v.end(); ++it)
    {
        cout <<  *it <<" ";
    }
    cout << "\n";
}
//This function will use iteration and sort out the vector in increasing order
void sorted(vector<int>&v)
{
    vector<int>::iterator it;
    cout << "\nThe integers you entered sorted are:\n";
    for (it=v.begin(); it!=v.end(); ++it)
    {
        sort(v.begin(),v.begin()+v.size());
        cout <<  *it <<" ";
    }
    cout << "\n";
}
