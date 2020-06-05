import math
import time

start = time.perf_counter()
I0 = 0.0
for n in range(1, 10000000):
    I0 = I0+(-1)**(n-1)*1./(2*n-1)
    print(n, I0, 4*I0, math.pi-4*I0)
    if abs(math.pi-4*I0) < 1e-6:
        break
        print(n, I0, 4*I0)
end = time.perf_counter()
print("%f seconds" % (end - start))