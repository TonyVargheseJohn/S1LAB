#Generate string by combination of 1st two characters
a = input("enter the string")
len = len(a)
if(len<2):
    print("empty string")
elif(len == 2):
    print(a[0:len] + a[-1::-1])
else:
    print(a[0:2] + a[len-2:len])