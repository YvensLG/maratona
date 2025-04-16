n = int(input())
a = input().split()
flag = False
for i in a:
  if(i == '1'):
    flag = True
print("Hard" if flag else "Easy")