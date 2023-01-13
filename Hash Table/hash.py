# Hash table
# Hash table is a data structure in which elements are accessed with a keyword rather
# than an index

class hashitem:
	def __init__(self, key, value):
		self.key = key
		self.value = value

class hashTable:
	def __init__(self, size, slots, count):
		self.size = 256 # size of the slot list
		self.slots = [None for i in range(self.size)]# the slots list
		self.count = 0 # A variable to keep track of all taken slots


	# A method to hash the key of the data item to get an index for it in the hash table
	def _hash(self, key):
		multiplier = 1 
		"""The multiplier variable is used to multiply each hashed character with an interval
		of 1, this is to get a unique value for each data item, since diff strings may have the
		same hashed value"""
		hashValue = 0 # This will store the hashed value

		for char in key:# loop through the characters of the string key
			hashValue += multiplier * ord(char)
			"""Update the hash value with the ordinal number multiplied bu the multipler variable"""
			multiplier += 1# increase the multiplier variable
		return hashValue % self.size 
		"""Find and return the mod of the hash value with the size of the table, this is to make
		sure that all elements are in range """	

	# Collission avoidance techniques
	# There 3 techniques 1. Linear probing 2.Quadratic probing 3.Double probing

	# defining a method to add elements to the hashed table
	def put(self, key, value):
		item = hashitem(key, value)# create an item from the hash item class
		hashedValue = slef._hash(key)# store the return value of the hash method in hashedValue

		"""Check if the space or indes within the table size is not empty, This is determined by using 
		the value stored in the hashedValue, which was returned from the _hash method, to select an index
		in the slots list"""
		while self.slots[hashedValue] != None:
			"""if the space is no empty, then check if the key field of the data is the same as what
			is to be inserted"""
			if self.slots[hashedValue].key == key:
				"""If the key is the same, then break out of the loop beacuse, it means the same data
				exist aleready"""
				break
			"""Else if the slot is taken but the key is not the same, then it means a new place must be
			found for that particular data, so add 1 to the hashedValue and store it in the same variable
			and find its remainder with the size of the slots list"""
			hashedValue = (hashedValue + 1) % self.size

		"""Now check if the new slot is empty, by new slot I mean the new hashedValue generated above"""
		if self.slots[hashedValue] == None:
			self.count += 1 # if it is empty, increase the count variable
		self.slots[hashedValue] = item	# then put the item at that free slot





