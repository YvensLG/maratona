l, r = map(int, input().split())
if r == l:
    print(r)
elif(r - l == 1):
    print(-1)
else:
    print(r - 1)