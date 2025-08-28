# Define a Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to insert at end
def insert_at_end(head, data):
    new_node = Node(data)
    if head is None:
        return new_node
    current = head
    while current.next:
        current = current.next
    current.next = new_node
    return head

# Function to print the list
def print_list(head):
    current = head
    while current:
        print(f"{current.data} -> ", end="")
        current = current.next
    print("NULL")

# Function to merge two sorted lists
def merge_sorted_lists(list1, list2):
    if not list1:
        return list2
    if not list2:
        return list1

    if list1.data < list2.data:
        result = list1
        result.next = merge_sorted_lists(list1.next, list2)
    else:
        result = list2
        result.next = merge_sorted_lists(list1, list2.next)
    return result

# Main logic
if __name__ == "__main__":
    list1 = None
    list2 = None

    # Insert values into list1
    for val in [1, 3, 5]:
        list1 = insert_at_end(list1, val)

    # Insert values into list2
    for val in [2, 4, 6]:
        list2 = insert_at_end(list2, val)

    print("List 1:")
    print_list(list1)

    print("List 2:")
    print_list(list2)

    # Merge and print
    merged = merge_sorted_lists(list1, list2)
    print("Merged List:")
    print_list(merged)