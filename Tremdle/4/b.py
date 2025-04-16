from math import sqrt
a, b, c = map(int, input().split())
soma = sqrt(b * c / a) + sqrt(c * a / b) + sqrt(a * b / c) 
print(round(soma) * 4)