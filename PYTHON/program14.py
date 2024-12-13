#Factorial Fibnoacci Sum
# Factorail
a = int(input("Enter the number"))
fact = 1
for i in range(2,a+1):
    fact = fact * i
print("Factorial of",a,"is",fact)

#Fibnoacci Series
num1 = 0
num2 = 1
num3 = num1 + num2
n = int(input("Enter limit number"))
for i in range(3,n+3):
    print(num1,sep=",",end=" ")
    num1= num2
    num2 = num3
    num3 = num1 + num2
    
# Sum in list
w = input("Enter the numbers sperated by space")
l = w.split(" ")
sum=0
for i in l:
    sum+=int(i)
else:
    print("sum of elements is:",sum)