import math
import time
PI = 3.141592653589793
EPS = 1e-6
i = 0
ans = 0.0
start = time.perf_counter()
while True:
    if i % 2 == 0:
        ans += 1.0 / (2 * i + 1)
    else:
        ans -= 1.0 / (2 * i + 1)
    i += 1
    if abs(4 * ans - PI) < EPS:
        break
end = time.perf_counter()

print("%d loops in %f seconds PI=%.12f" % (i, end-start,  4 * ans))