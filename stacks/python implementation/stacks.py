class createPerson(object):
	def __init__(self, name, age):
		self.name = name
		self.age = age
		self.next = None

class People(object):
	def __init__(self):
		self.head = None

	def Push(self, name, age):
		Person = createPerson(name, age)

		Person.next = self.head
		self.head = Person
		return self.head

	def Head(self):
		return self.head.name, self.head.age

	def Pop(self):
		self.head = self.head.next
		return self.head

def main():
	people = People()
	people.Push("Christopher", 26)
	people.Push("Tenkorang", 22)
	people.Push("David", 22)
	people.Push("Francis", 26)

	head = people.Pop()
	head = people.Head()
	print(head)		

if __name__ == '__main__':
	main()		

