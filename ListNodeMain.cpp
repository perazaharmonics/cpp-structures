#include <iostream>
#include <string>
using namespace std;

// Define a struct for a linked list node
struct ListNode 
{
    string dirname; // Store the directory name
    ListNode *next; // Pointer to the next node in the list

    // Constructor to initialize the node with a directory name
    ListNode(string x) : dirname(x), next(nullptr) {}
};

// Function to delete the entire linked list
void deleteList(ListNode** head)
{
    ListNode* current = *head; // Start from the head node
    ListNode* next;

    while (current != nullptr)
    {
        next = current->next; // Save the next node
        delete current; // Delete the current node
        current = next; // Move to the next node
    }

    *head = nullptr; // Set the head to nullptr after the list is deleted 
}

// Function to insert a new node at the end of the linked list
void insert(ListNode** head, string dirname)
{
    ListNode* newNode = new ListNode(dirname); // Create a new node with the given directory name
    if (*head == nullptr)
    {
        *head = newNode; // If the list is empty, make the new node the head

    }
    else
    {
        ListNode* temp = *head; // Start from the head node
        while (temp->next != nullptr)
        {
            temp = temp->next; // Traverse to the last node

        }
        temp->next = newNode; // Append the new node to the last node
    }
}

int main(int argc, char* argv[])
{
    ListNode* head = nullptr; // Initialize the head of the linked list as nullptr

    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i]; // Get the current command line argument
        if(arg == "-dir" && i+1 < argc)
        { // Check if the argument is "-dir" and there is a next argument
            insert(&head, argv[++i]); // Insert the next argument as a new node and increment i

        }
    }

    // Print the list
    ListNode* temp = head; // Start from the head node
    while (temp != nullptr) 
    {
        cout << temp->dirname << endl; // Print the directory name
        temp = temp->next; // Move to the next node
    }
    deleteList(&head); // Deallocate the memory occupied by the list
    return 0;
}