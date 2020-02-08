from __future__ import print_function

mat = []
while True:
    try:
        s = raw_input()
        l = []
        for i in s.split():
            l.append(int(i))
        mat.append(l)
    except EOFError:
        break
n = len(mat)
for k in range(n):
    for i in range(n):
        for j in range(n):
            mat[i][j] += mat[i][k] * mat[k][j]
            if mat[i][j]:
                mat[i][j] = 1

for i in range(n):
    for j in range(n):
        print(1 if mat[i][j] else 0, end=' ' if j != n - 1 else '\n')
