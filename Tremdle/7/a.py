x, y, z = map(int, input().split())
ans = 1000000000
for a in range(101):
    ans = min(ans, abs(a - x) + abs(a - y) + abs(a - z))
print(ans)