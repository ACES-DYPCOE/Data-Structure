# Printing String using double quotes 
print("Hello ")

a = "ACES"
print(a)

# Printing String using double quotes 
print('Hello ')

b = 'DYPCOE'
print(b +'\n')


# Multiline Strings using double quotes 
a = """Lorem ipsum dolor sit amet,
consectetur adipiscing elit,
sed do eiusmod tempor incididunt
ut labore et dolore magna aliqua."""
print(a +'\n') 

# Multiline Strings using single quotes 
b = '''Lorem ipsum dolor sit amet,
consectetur adipiscing elit,
sed do eiusmod tempor incididunt
ut labore et dolore magna aliqua.'''
print(b +'\n') 

# Accessing elements in strings
print("Printing 3rd Element from ACES : " + a[2])

# Slicing
name = "ACES-DYPCOE"
print("Slicing : " + name[2:8])

# Negative Indexing 
print("Negative Indexing: " + name[-5:-2])

# String Length
name = "ACES-DYPCOE"
print(len(name))

########## String Methods ##########

# strip() Method
name = "ACES-DYPCOE"
print(name.strip())

# lower() Method
name = "ACeS-DYpCoE"
print(name.lower())

# upper() Method
name = "aCes-dyPcoe"
print(name.upper())

# replace() Method
name = "ACES-DYPCOE"
print(name.replace("C", "J"))

# split() Method
name = "ACES DYPCOE"
print(name.split())

# Check String
txt = "The rain in Spain stays mainly in the plain"
x = "ain" in txt
print(x)  # returns True/False

# String Concatenation
a = "ACES"
b = "DYPCOE"
c = a + b
print(c)

# String Format method
age = 21
txt = "My name is Ajay, and I am {}"
print(txt.format(age))

# format using multiple agruments 
quantity = 3
item_no = 567
price = 49.95
myorder = "I want {} pieces of item {} for {} dollars."
print(myorder.format(quantity, item_no, price))


#printing in the different forms

print("Hello world")
a="hello"
print(f"hey {a}")
print(f"hello {0} this is {1}.".format("red","code"))


