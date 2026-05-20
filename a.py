import sys

def solve():
    # Reading input from standard input
    try:
        line1 = sys.stdin.readline()
        if not line1:
            return
        x = int(line1.strip())
        
        line2 = sys.stdin.readline()
        if not line2:
            return
        y = int(line2.strip())
        
        # Using the unicode character 'ell' for the variable name
        ℓ = x * y
        
        # Output the result
        print(ℓ)
    except ValueError:
        pass

if __name__ == "__main__":
    solve()