f = open("a_example.txt", 'r')
lines = f.readlines()
f.close()


photos = []
for i in lines[1:]:
    t = i[:-1].split (' ')
    photos.append((t[0], t[1], set(t[2:])))
    
solution = [[0], [3], [1,2]]

def get_slide(idx):
    s = set()
    for i in idx:
        s = s | photos[i][-1]
    return s

def transition(s1, s2):
    return min(len(s1 - s2), len(s2 - s1), len(s1 & s2))

def score(sol):
    s = 0
    for i in range(len(sol) - 1):
        s += transition(get_slide(sol[i]), get_slide(sol[i+1]))
    return s 

print(score(solution))