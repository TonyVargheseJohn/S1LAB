#Total count
n = input("Enter the string")
v = ["a","e","i","o","u"]
count = 0
for i in n:
    if(i in v):
        count+=1
print(count)        