#Write a program to convert a string into a linked list of characters
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def add(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

    def show(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

# Function to convert a string to a linked list
def string_to_linked_list(s):
    linked_list = LinkedList()
    for char in s:
        linked_list.add(char)
    return linked_list

# Example usage
my_string = "Hello"
linked_list = string_to_linked_list(my_string)
linked_list.show()  # Output: H -> e -> l -> l -> o -> None