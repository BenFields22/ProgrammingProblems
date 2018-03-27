#if string has all unique characters

class Person:
	"""docstring for Person"""
	def __init__(self, name = "None Given", age="none given",gender="none given"):
		self.name = name
		self.age = age
		self.gender = gender	
	def printInfo(self):
		print("Name:'{0}'' is Age:'{1}'' and is a Gender:'{2}'".format(self.name,self.age,self.gender))


		

def unique(myStr):
	print("Test string is: %s" % myStr)
	length = len(myStr)
	print('The length is: {0}'.format(length))
	for i in range(length):
		character = myStr[i]
		for j in range(length):
			if j == i:
				continue
			else:
				if myStr[i] == myStr[j]:
					print("Failed on character {}".format(myStr[i]))
					return 0;

	return 1

a = unique("benjami")
if a:
	print("It is made of unique characters")
else:
	print("It is not made of unique characters")

me = Person("ben",25,"male")
me.printInfo()





