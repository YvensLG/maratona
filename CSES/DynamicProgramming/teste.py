resp = []

def ok(a):
    aux = []

    while(a != 0):
        aux.append(a % 10)
        a = a // 10

    for i in range(1, len(aux)):
        if(aux[i] == aux[i - 1]):
            return False
        
    return True

resp.append(0)

for i in range(1, 110000):
    aux = resp[-1]
    if ok(i):
        resp.append(aux + 1)
    else:
        resp.append(aux)

for i in range(1, len(resp)):
    print(str(i) + " : " + str(resp[i - 1]))