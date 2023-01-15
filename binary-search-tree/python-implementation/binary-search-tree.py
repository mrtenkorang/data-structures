class nodeTree(object):
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None

class treeIplementation(object):
	def __init__(self):
		self.root = None


	def insert(self, data):
		if self.root == None:
			self.root = nodeTree(data)
		elif data <= self.root.data:
			self.left = nodeTree(data)
		else:
			self.right = nodeTree(data)

	def search(self, data):
		if self.root == None:
			return False
		elif data == self.root.data:
			return True
		elif data <= self.root.data:
			self.left = search(data)
		else:
			self.right = search(data)

tree = treeIplementation()		
tree.insert(10)
tree.insert(2)
tree.insert(3)
tree.insert(56)
tree.insert(5)
tree.insert(70)		
tree.insert(7)
tree.insert(8)

print(tree.search(1))					

