from random import randint


class SLLNode:
    value = None
    next = None


class DLLNode:
    value = None
    next = None
    prev = None


class SingleLinkedList:

    def __init__(self):
        self.head = None

    def insert_value(self, value):
        if self.head == None:
            self.head = SLLNode()
            self.head.value = value
        else:
            current_node = self.head
            while current_node.next != None:
                current_node = current_node.next
            current_node.next = SLLNode()
            current_node.next.value = value

    def delete_value(self, value):
        if self.head.value == value:
            prev = self.head  # memory management
            self.head = self.head.next
        else:
            current_node = self.head
            while current_node.next.value != value:
                if current_node.next.next == None:
                    raise Exception("No such value found")
                current_node = current_node.next
            prev = current_node.next  # memory management
            current_node.next = current_node.next.next
        del prev

    def print_list(self):
        current_node = self.head
        while current_node.next != None:
            yield current_node.value
            current_node = current_node.next


class DoubleLinkedList:

    def __init__(self):
        self.head = None

    def insert_value(self, value):
        if self.head == None:
            self.head = DLLNode()
            self.head.value = value
            self.head.next = self.head
            self.head.prev = self.head
        else:
            current_node = self.head
            while current_node.next != self.head:
                current_node = current_node.next

            current_node.next = DLLNode()
            current_node.next.value = value
            current_node.next.prev = current_node
            current_node.next.next = self.head
            self.head.prev = current_node.next

    def delete_value(self, value):
        if self.head.value == value:
            del_node = self.head  # memory management
            self.head = self.head.next
            del_node.prev.next = self.head
            self.head.prev = del_node.prev
        else:
            current_node = self.head
            while current_node.value != value:
                if current_node.next == self.head:
                    raise Exception("No such value found")
                current_node = current_node.next
            del_node = current_node  # memory management
            current_node.prev.next = current_node.next
            current_node.next.prev = current_node.prev
        del del_node

    def print_list(self):
        current_node = self.head
        while current_node.next != self.head:
            yield current_node.value
            current_node = current_node.next


def main():
    sll = SingleLinkedList()
    for _ in range(8):
        sll.insert_value(randint(1, 100))
    print("Single Linked List:", list(sll.print_list()))
    del_value = int(input("Enter value to delete: "))
    try:
        sll.delete_value(del_value)
    except Exception as e:
        print(e)
    print("Single Linked List:", list(sll.print_list()))

    dll = DoubleLinkedList()
    for _ in range(8):
        dll.insert_value(randint(1, 100))
    print("Double Linked List:", list(dll.print_list()))
    del_value = int(input("Enter value to delete: "))
    try:
        dll.delete_value(del_value)
    except Exception as e:
        print(e)
    print("Double Linked List:", list(dll.print_list()))


if __name__ == "__main__":
    main()
