
def gcd(a, b):
  if(a < b):
    b, a = a, b
  rest = a % b
  if(rest == 0):
    return b
  
  return gcd(b, rest)

# 알파벳 아스키 코드
ALPHABETS = range(65, 91) 

test_case = int(input())
for test_index in range(test_case):
  get_line = input()
  N, L = map(int, get_line.strip().split())
  input_nums = list(map(int, input().strip().split()))
  cryp_arr = []
  first_diff = 0
  for i in range(L - 1):
    if(input_nums[i] != input_nums[i+1]):
      first_diff = i
      break
  
  first_cryp = gcd(input_nums[first_diff], input_nums[first_diff + 1])
  cryp_arr.append(input_nums[first_diff] / first_cryp)
  cryp_arr.append(first_cryp)
  cryp_arr.append(input_nums[first_diff + 1] / first_cryp)
  
  for i in range(first_diff + 2, L):
    check_num = input_nums[i]
    next_crypt = check_num / cryp_arr[-1]
    cryp_arr.append(next_crypt)

  for i in range(first_diff - 1, -1, -1):
    prev_num = input_nums[i]
    prev_crypt = prev_num / cryp_arr[0]
    cryp_arr.insert(0, prev_crypt)
  
  cryp_set = set(cryp_arr)
  sorted_arr = sorted(cryp_set)
  cryp_dict = dict(zip(sorted_arr, ALPHABETS))

  answer_arr = list(map(lambda x: chr(cryp_dict[x]), cryp_arr))
  answer_str = ''.join(answer_arr)
  print("Case #%d: %s" % (test_index + 1, answer_str))