# Define a Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Define a LinkedList class
class LinkedList:
    def __init__(self):
        self.head = None

    # Insert a node at the beginning
    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    # Delete a node with a specific value
    def delete_node(self, key):
        temp = self.head
        prev = None

        # If head node holds the key
        if temp and temp.data == key:
            self.head = temp.next
            return

        # Search for the key
        while temp and temp.data != key:
            prev = temp
            temp = temp.next

        # If key not found
        if temp is None:
            return

        # Unlink the node
        prev.next = temp.next

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

    print("Linked List:")
    ll.print_list()

    # Delete a node
    ll.delete_node(20)
    print("After deletion:")
    ll.print_list()