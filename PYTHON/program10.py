s = input ("enter the sting")
l = s.split()
m = max(len(word) for word in l)
w = [word for word in l if len(word) == m]
if len(w)>1:
    print("BINGO")
else:
    print("the word is",".".join(w))
