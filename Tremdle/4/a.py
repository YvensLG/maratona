n = int(input())
s = [""] * n
ans = False
for i in range(n):
    s[i] = input()
    if(not ans and s[i][0] == 'O' and s[i][1] == 'O'):
        s[i] = '++' + s[i][2:]
        ans = True
    
    elif(not ans and s[i][3] == 'O' and s[i][4] == 'O'):
        s[i] = s[i][:3] + '++'
        ans = True

if(ans):
    print('YES')
    for i in range(n):
        print(s[i])
else:
    print('NO')
    
