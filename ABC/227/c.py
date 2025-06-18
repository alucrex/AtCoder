import math
n = int(input())
lim = int(math.pow(n, 1.0/3.0))
ans = lim * (lim+1) * (lim+2) / 6
print(int(ans))