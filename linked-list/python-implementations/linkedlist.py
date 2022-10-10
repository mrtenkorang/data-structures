class Employee(object):
    def __init__(self, name=None, age=None, salary=None):
        self.name = name
        self.age = age
        self.salary = salary
        self.next = None


class linkedEmployees(object):
    def __init__(self):
        self.head = Employee()

    def addToEnd(self, name, age, salary):
        newEmployee = Employee(name, age, salary)
        current = self.head

        while current.next is not None:
            current = current.next
        current.next = newEmployee

    def addByIndex(self, index, name, age, salary):
        newEmployee = Employee(name, age, salary)
        current = self.head
        for i in range(index - 1):
            current = current.next
        follow = current.next
        newEmployee.next = follow
        current.next = newEmployee

    def display(self):
        current = self.head
        while current is not None:
            current = current.next
            if current is None:
                break
            print(current.name, current.age, current.salary)

    """def addToFront(self, name, age, salary):
        newEmployee = Employee(name, age, salary)
        newEmployee.next = self.head
        self.head = newEmployee """

    def getByIndex(self, index):
        current = self.head
        for i in range(index):
            current = current.next
        print("The employee at index ", index, ":\n\t", current.name, current.age, current.salary)

    def getByValue(self, value):
        current = self.head
        while 1:
            current = current.next
            if current.name == value or current.age == value or current.salary == value:
                print(current.name, current.age, current.salary)
            if current.next is None:
                break

    def getLen(self):
        current = self.head
        Len = -1
        while 1:
            if current is None:
                print(Len)
                break
            Len += 1
            current = current.next

    def deleteByIndex(self, index):
        current = self.head
        temp = Employee()
        if index == 1:
            self.head = current.next
        for i in range(index):
            temp = current
            current = current.next
        temp.next = current.next


if __name__ == '__main__':
    emp = linkedEmployees()

    emp.addToEnd("Joseph", 22, 10000)
    emp.addToEnd("Ofori", 24, 14000)
    emp.addToEnd("Francis", 28, 30000)
    emp.addToEnd("Tenkorang", 26, 15000)
    emp.addToEnd("Otonga", 27, 30000)

    emp.addByIndex(3, "Christopher", 28, 34000)

    emp.deleteByIndex(4)
    emp.display()
    print("\n")
    emp.getByValue(30000)

    emp.getByIndex(1)
    emp.getLen()
    # emp.display()
    # print("Added successfully..")
