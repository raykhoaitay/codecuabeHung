import random

n = random.randint(3, 8)
q = random.randint(1, 15)

print(n, q)
for i in range(n):
    print(random.randint(1, 9), end = ' ')

print()
for i in range(q):
    t = random.randint(0, 1)

    if t == 0:
        l = random.randint(0, n//2+1)
        r = random.randint(l+1, n)

        b = random.randint(1, 3)
        c = random.randint(1, 5)
        print(t, l, r, b, c)
    elif t == 1:
        l = random.randint(0, n//2+1)
        r = random.randint(l+1, n)

        print(t, l, r)
