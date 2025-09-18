#Write a program in python to check whether number of opening'(' and closing')' parentheses are equal or not in an expression using stack.
class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        return None

def check_parentheses(expression):
    stack = Stack()
    for char in expression:
        if char == '(':
            stack.push(char)
        elif char == ')':
            if stack.is_empty():
                return False
            stack.pop()
    return stack.is_empty()

# Example usage
if __name__ == "__main__":
    expr = input("Enter an expression: ")
    if check_parentheses(expr):
        print("Number of opening and closing parentheses are equal.")
    else:
        print("Unmatched parentheses found.")
