import sys
import math
import queue

def make_test(n, i):
  test = ""
  left_num = math.ceil(n/2)
  right_num = math.floor(n/2)
  if(n!= 1 and n <= (1 << i)):
    i -= 1
  if i == 0:
    test = "1" * left_num + "0" * right_num
  else:
    test = make_test(left_num, i - 1) + make_test(right_num, i - 1)
  return test

def find_one_num(response, start, end):
  num = 0
  for i in range(start, end):
    if(response[i]=='1'):
      num += 1
  return num

def send_test(N, i):
  test_bit = make_test(N,i)
  print(test_bit)  
  sys.stdout.flush()

def divide_Bs(response, left, right, gap ,parent_B):
  num_one = find_one_num(response, left, right)
  expect_one_num = math.ceil(gap / 2)
  left_B = expect_one_num - num_one
  right_B = parent_B - left_B
  if(gap == 1):
    return left_B
  return left_B, right_B

# index는 몇 번째 인지 뜻한다 
def calc_next_Bs(N, index, Bs):
  send_test(N, index)
  response = input().strip()
  if(response == '-1'):
    sys.exit(-1)
  gaps = queue.Queue()
  gaps.put(N)
  for i in range(index):
    new_q = queue.Queue()
    while(not gaps.empty()):
      n = gaps.get()
      if(n<=2):
        new_q.put(n)
      else:
        new_q.put(math.ceil(n / 2))
        new_q.put(math.floor(n / 2))
    gaps = new_q

  start = 0
  end = 0
  new_Bs = []
  # print("Gap", list(gaps.queue))
  
  for B in Bs:
    gap = gaps.get()
    end = end + gap - B
    if(gap == 1):
      left_B = divide_Bs(response, start, end, gap, B)
      new_Bs.append(left_B)
    else:
      left_B, right_B = divide_Bs(response, start, end, gap, B)
      new_Bs.append(left_B)
      new_Bs.append(right_B)
    start = end
  
  return new_Bs

# main

PRIME = [3, 4, 5, 7, 11, 13, 17]
num_test_case = int(input().strip())

for test_index in range(num_test_case):
  N, B, F = map(int, input().strip().split())
  test_n = N
  index_2 = 0
  while(test_n > (1 << index_2)):
    index_2 += 1
  
  Bs = [B]
  for i in range(index_2):
    Bs = calc_next_Bs(N, i, Bs)
  
  answer = ""
  for i in range(N):
    if(Bs[i]==1):
      answer += str(i)
      answer += " "
  answer = answer.strip()
  print(answer)  
  sys.stdout.flush()
  response = int(input().strip())
  if(response == 1):
    # with open(str(test_index)+"tests.txt", 'w') as f:
    #   f.write(str(response))
    continue
  else:
    sys.exit(1)
    # print(response)
    # sys.stdout.flush()
  
# done
sys.exit(0)
      

# print(calc_next_Bs(8, 0 , [4], "1110"))
# print(calc_next_Bs(8, 2 , [1, 2, 1, 1], "100"))
# print(calc_next_Bs(9, 2 , [1, 2, 1, 1], "1011"))
# print(calc_next_Bs(9, 3 , [1, 0, 2, 1, 1], "0111"))
# print(calc_next_Bs(6, 2 , [2,0,2,0], "11"))
# print("[1, 1, 0, 1, 1, 0] <- sol")
# print(calc_next_Bs(2, 0 , [1], "1"))
# print("[0, 1] <- sol")
# print(calc_next_Bs(17, 4 , [1, 0, 1, 2, 0, 2, 2, 0, 0], "011101010"))
# print("[1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0] <- sol")



  
  
#   # with open('output.txt', 'w') as f:
#   #   f.write(response)
#   print("1010")
#   sys.stdout.flush()
#   response = input().strip()
#   # with open('output2.txt', 'w') as f:
#   #   f.write(response)
#   print("0 1 2")
#   sys.stdout.flush()
#   response = input().strip()
#   with open('result2.txt', 'w') as f:
#     f.write(response)
  

