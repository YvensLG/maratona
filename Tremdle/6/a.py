d1, d2, d3 = map(int, input().split())
print(min(d1 + d3 + d2, 2 * (d1 + d3), 2 * (d2 + d3), 2 * (d1 + d2) ) )