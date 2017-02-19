/*
 Vector strings with split function
 */

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string target,std::string delimeter);

int main(int argc, const char * argv[])
{
    std::vector<std::string> list;
        
    list = split("10,20,30",",");
    // searches each element in the list
    for(unsigned i = 0;i < list.size(); i++)
    {
        std::cout << list[i] << std::endl;
    }
    std::cout << "\n";
        
    list = split("do re mi fa so la ti do", " ");
    
    for(unsigned i = 0;i < list.size(); i++)
    {
        std::cout << list[i] <<  std::endl;
    }
    std::cout << "\n";
    return 0;
}
    
std::vector<std::string> split(std::string target,std::string delimeter){
    long index,lastIndex;
    std::vector<std::string> list;
    
    lastIndex = 0;
    index = target.find(delimeter);// index will equal the memory location of the delimeter
        
    //while index does find matches it will do the following
    while(index != std::string::npos)//string::npos means no matches found
    {
        // Extract a substr from lastIndex to index
        std::string s;
        s = target.substr(lastIndex, index - lastIndex);
        list.push_back(s);
        lastIndex = index +1;
        index = target.find(delimeter,lastIndex);
    }
    // put the last item into the vector
    list.push_back(target.substr(lastIndex,target.length() -lastIndex));
    

    return list;
}
