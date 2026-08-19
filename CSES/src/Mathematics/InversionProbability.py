from decimal import Decimal, getcontext
import math
 
getcontext().prec = 50
 
class frac:
    def __init__(self, num, den):
        self.num = num // math.gcd(abs(num), abs(den))
        self.den = den // math.gcd(abs(num), abs(den))
 
    def soma(self, b):
        c = self.num * b.den + b.num * self.den
        d = self.den * b.den
        return frac(c, d)
 
def prob(a, b):
    x = min(a, b)
    result = a * x - x * (x + 1) // 2
    return frac(result, a * b)
 
def main():
    n = int(input())
    r = input().split()
    for i in range(n):
        r[i] = int(r[i])
 
    total = frac(0, 1)
 
    for i in range(n):
        for j in range(i):
            total = total.soma(prob(r[j], r[i]))
 
    print(f"{(Decimal(total.num) / Decimal(total.den)):.6f}")
 
main()