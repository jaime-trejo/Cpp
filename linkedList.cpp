/*
 A linked list is not fixed in size,but can grow and shrink while your program is running.
 A linked list is constructed by using pointers.
 */


#include <iostream>

class Node
{
public:
    // Constructors to initialize a node
    Node();
    Node(int value, Node *next);
    
    int getData() const; // Retrieve value for this node
    Node *getLink( ) const;// Retrieve next Node in the list
    void setData(int value);// Use to modify the value stored in the list
    void setLink(Node *next);// Use to change the reference to the next node
private:
    int data;
    Node *link;
};

typedef Node* NodePtr;
void head_insert(NodePtr &head, int the_number);

int main(int argc, const char * argv[]) {
    NodePtr head, tmp;
    
    // Create a list of nodes 4->3->2->1->0
    head = new Node(0, NULL);
    
    for (int i=1; i<5; i++)
    {
        head_insert(head, i);
    }
    
    tmp = head;
    while (tmp != NULL)
    {
        std::cout << tmp->getData() <<  std::endl;
        tmp = tmp->getLink();
    }
    // Delete all nodes in the list before exiting the program.
    tmp = head;
    while (tmp != NULL)
    {
        NodePtr nodeToDelete = tmp;
        tmp = tmp->getLink();
        delete nodeToDelete;
    }
    
    std::cout <<  std::endl;
    return 0;
}
//This function inserts a new node onto the head of the list
void head_insert(NodePtr &head, int the_number)
{
    
    NodePtr temp_ptr;
    // Uses the overloaded constructor to set temp_ptr->link to head and set the data value to the_number here
    temp_ptr = new Node(the_number,head);
    //Makes the head pointer point at the new node (use temp_ptr)
    head = temp_ptr;
}
Node::Node() : data(0), link(NULL)
{
    // deliberately empty
}
Node::Node(int value, Node *next) : data(value), link(next)
{
    // deliberately empty
}

int Node::getData( ) const
{
    return data;
}

Node* Node::getLink( ) const
{
    return link;
}

void Node::setData(int value)
{
    data = value;
}

void Node::setLink(Node *next)
{
    link = next;
}
