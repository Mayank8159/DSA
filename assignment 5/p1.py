# Each node stores data and a pointer to the next node
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# The linked list itself
class LinkedList:
    def __init__(self):
        self.head = None

    # Add a new node at the end
    def add(self, data):
        new_node = Node(data)
        if self.head is None:        # If list is empty
            self.head = new_node
        else:
            current = self.head
            while current.next:      # Traverse to the last node
                current = current.next
            current.next = new_node

    # Show all elements
    def show(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

# Example usage
my_list = LinkedList()
my_list.add(10)
my_list.add(20)
my_list.add(30)
my_list.show()  # Output: 10 -> 20 -> 30 -> None