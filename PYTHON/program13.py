#Evaluate using condition statments
a = int(input("Enter the number "))
value = "odd" if a%2 else "even"
print(value)

l = input("Enter strings seperated by space: ")
list = l.split(" ")
item = input("enter the item to check: ")
result = "Available" if item in list else "Not Available"
print(result)