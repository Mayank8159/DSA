#Give a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a positive integer smaller than or equal to length of the linked list.
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

    def left_shift(self, k):
        if self.head is None or self.head.next is None or k <= 0:
            return  # No need to shift if list is empty, has only one element, or k is invalid

        # Find the length of the list
        length = 0
        current = self.head
        while current:
            length += 1
            current = current.next

        # Normalize k in case it's greater than length
        k = k % length
        if k == 0:
            return  # No need to shift if k is 0

        # Find the new head after k shifts
        current = self.head
        for _ in range(k - 1):
            current = current.next
        new_head = current.next
        current.next = None

        # Find the last node and connect it to the old head
        last = new_head
        while last and last.next:
            last = last.next
        if last:
            last.next = self.head
        self.head = new_head

# Example usage
my_list = LinkedList()
my_list.add(10)
my_list.add(20)
my_list.add(30)
my_list.show()  # Output: 10 -> 20 -> 30 -> None
my_list.left_shift(2)
my_list.show()  # Output: 30 -> 10 -> 20 -> None
