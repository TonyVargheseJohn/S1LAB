#Display grade from accepting mark from user\
#Method 1
a = int(input("Enter the mark "))
if (a>=80):
    print("Grade= A")
elif(a>=60):
    print("Grade=B")
elif (a>=50):
    print("Grade=C")
elif(a>=30):
    print("Grade=D")
else:
    print("Falied")
    
#Method 2
a = int(input("Enter a number:"))
Grade = "A" if a>=80 else "B" if a>=60 else "C" if a>=50 else "D" if a>=30 else "Failed"
print("Grade = ",Grade)