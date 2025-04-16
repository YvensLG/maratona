n = int(input())
s1 = input()
s2 = input()
soma = 0

for i in range(n):
    a = abs(ord(s1[i]) - ord(s2[i]))
    soma += min(a, 10 - a)

print(soma)