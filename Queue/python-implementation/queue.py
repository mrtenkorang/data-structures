class Person(object):
	def __init__(self, name, age):
		self.name = name
		self.age = age
		self.next = None


class queuePerson(object):
	def __init__(self):
		self.head = None
		self.temp = None

	def enQueue(self, name, age):
		per = Person(name, age)
		if self.head is None:
			self.head = per
			self.temp = per
			return self.head
		self.temp.next = per
		self.temp = per
		return self.head
	
	def front(self):	
		return self.head.name, self.head.age

	def deQueue(self):
		self.head = self.head.next
	
	def isEmpty(self):
		if self.head is None:
			return "Empty"
		return "Not Empty"
		
def main():
	pers = queuePerson()
	head = pers.enQueue("Tenkorang", 22) 
	head = pers.enQueue("Joseph", 23) 
	head = pers.enQueue("Ofori", 21) 
	head = pers.enQueue("Adelaide", 20) 

	head = pers.front()
	print(head)

	pers.deQueue()

	head = pers.front()
	print(head)


	head = pers.isEmpty()
	print(head)		

if __name__ == '__main__':
	main()		

					
	
						
		
		