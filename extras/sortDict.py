'''
# coursera

A nested dictionary is a dictionary whose keys are strings and whose 
values are string or other nested dictionaries. Given a string representation , 
we need to return a String representation where the entries are 
sorted by key(within each nested dictionary)

Input: { b:{cb:cranberry,bb:blueberry},a:apple,c:cherry}
Output:  { a:apple,b:{bb:blueberry,cb:cranberry},c:cherry}

'''

def doSort(input):
	res = "{"
	for x in sorted(input.keys()):
		res += str(x)
		res += ':'
		res += str(input[x])
		res += ','
	res = res[:-1]
	res += '}'
	
	return res

def isalpha(string):
	return (string >= 'a' and string <= 'z') or (string >= '0' and string <= '9')

def parseDict(string):
	key = str()
	dictt = dict()
	iter = 0
	while iter < len(string):
		if string[iter] == '{':
			iter += 1
			value, xiter = parseDict(string[iter:])
			iter += xiter
			if len(key) == 0:
				return value, iter
			else:
				dictt[key] = value
				key = str()
				
		elif isalpha(string[iter]):
			while isalpha(string[iter]):
				key += string[iter]
				iter += 1

		elif string[iter] == ':':
			iter += 1
			value = ''
			if isalpha(string[iter]):
				while isalpha(string[iter]):
					value += string[iter]
					iter += 1
				dictt[key] = value
				key = ''
		elif string[iter] == ',':
			iter += 1
		elif string[iter] == '}':
			return doSort(dictt), iter+1
		else:
			iter+=1
	return doSort(dictt) , iter+1

x,y = parseDict("{ b:{cb:cranberry,bb:blueberry},a:apple,c:cherry}")
print x



'''
# incorrect attempt

def isalpha(string):
	return (string >= 'a' and string <= 'z') or (string >= '0' and string <= '9')

def parseDict(string):
	key = str()
	dictt = dict()
	iter = 0
	while iter < len(string):
		if string[iter] == '{':
			iter += 1
			value, xiter = parseDict(string[iter:])
			iter += xiter
			if len(key) == 0:
				return value, iter
			else:
				dictt[key] = value
				key = str()
				
		elif isalpha(string[iter]):
			while isalpha(string[iter]):
				key += string[iter]
				iter += 1

		elif string[iter] == ':':
			iter += 1
			value = ''
			if isalpha(string[iter]):
				while isalpha(string[iter]):
					value += string[iter]
					iter += 1
				dictt[key] = value
				key = ''
		elif string[iter] == ',':
			iter += 1
		elif string[iter] == '}':
			return dictt, iter+1
		else:
			iter+=1
	return dictt , iter+1

#x,y = parseDict('{abc:123,def:{ghi:here},again:iam}')
x,y = parseDict('{ b:{cb:cranberry,bb:blueberry},a:apple,c:cherry}')
#inp = "{ b:{cb:cranberry,bb:blueberry},a:apple,c:cherry}"
#out = "{ a:apple,b:{bb:blueberry,cb:cranberry},c:cherry}"
print isinstance(x, dict),x
			

'''
