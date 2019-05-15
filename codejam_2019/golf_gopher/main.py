# multiplicative inverse
import math
import sys

def modInverse(a, M):
  b = M
  y = 0
  x = 1

  if (M == 1):
    return 0

  while (a > 1 and b != 0):
    q = math.floor(a/ b)
    t = b
    b = a % b
    a = t
    t = y
    y = x - q * y
    x = t

  return (x % M + M) % M


# // x % m[i] = a[i]
def findMinX(m, a, n):
  mm = 1
  for i in range(n):
    mm *= m[i]

  res = 0

  for i in range(n):
    nk = mm / m[i]
    res += a[i] * nk * modInverse(nk, m[i])
  return res % mm

# main
PRIME = [3, 4, 5, 7, 11, 13, 17]
T, N, M = map(int, input().strip().split())

for test_index in range(T):
  m = []
  a = []
  for night in range(7):
    key = PRIME[night]
    m.append(key)
    send = (str(key) + ' ') * 17
    send += (str(key))
    print(send)
    sys.stdout.flush()
    result = map(int, input().strip().split())
    a.append(sum(result) % key)
  
  answer = findMinX(m,a, 7)
  print(int(answer))
  sys.stdout.flush()

  response = int(input().strip())
  if(response == 1):
    with open(str(test_index)+"tests.txt", 'w') as f:
      f.write(str(response))
    continue
  else:
    sys.exit(-1)    

# done
sys.exit(0)
      