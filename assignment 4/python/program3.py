# Define a Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Define a LinkedList class
class LinkedList:
    def __init__(self):
        self.head = None

    # Insert at the beginning
    def insert_at_beginning(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    # Print the linked list
    def print_list(self):
        current = self.head
        while current:
            print(f"{current.data} -> ", end="")
            current = current.next
        print("NULL")

# Main logic
if __name__ == "__main__":
    ll = LinkedList()
    
    # Insert some values
    ll.insert_at_beginning(10)
    ll.insert_at_beginning(20)
    ll.insert_at_beginning(30)

    # Print the linked list
    print("Linked List:")
    ll.print_list()