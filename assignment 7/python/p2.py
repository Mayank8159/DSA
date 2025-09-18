# Stack implementation using a linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None

    def is_empty(self):
        return self.top is None

    def push(self, item):
        new_node = Node(item)
        new_node.next = self.top
        self.top = new_node

    def pop(self):
        if self.is_empty():
            raise IndexError("pop from empty stack")
        popped_node = self.top
        self.top = self.top.next
        return popped_node.data

    def peek(self):
        if self.is_empty():
            raise IndexError("peek from empty stack")
        return self.top.data

    def size(self):
        current = self.top
        count = 0
        while current:
            count += 1
            current = current.next
        return count
    
    def display(self):
        if self.is_empty():
            print("Stack is empty")
        else:
            print("Stack elements:")
            current = self.top
            while current:
                print(current.data)
                current = current.next
# Example usage
if __name__ == "__main__":
    stack = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.display()  # Output: 3, 2, 1
    print("Top element:", stack.peek())  # Output: 3
    print("Stack size:", stack.size())  # Output: 3
    print("Popped element:", stack.pop())  # Output: 3
    stack.display()  # Output: 2, 1
