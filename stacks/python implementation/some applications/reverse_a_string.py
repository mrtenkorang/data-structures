class create(object):
	def __init__(self, letter):
		self.letter  = letter
		self.next = None

class Reverse(object):
	def __init__(self, word):
		self.head = None
		self.word = word

	def reverse(self):
		reWord = ""
		for i in range(len(self.word)):
			let = create(self.word[i])
			let.next = self.head
			self.head = let
		temp = self.head
		while temp is not None:
			reWord += temp.letter
			temp = temp.next
		return reWord
		

def main():
	r = Reverse("Incredulous")
	w = r.reverse()
	print(w)
		
		
if __name__ == '__main__':
	main()			
