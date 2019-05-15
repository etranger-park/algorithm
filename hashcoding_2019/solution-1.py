import sys
from multiprocessing import Pool
import random

f = open("c_memorable_moments.txt", 'r')
lines = f.readlines()
f.close()

photos = []
for i in lines[1:]:
    t = i[:-1].split(' ')
    photos.append((t[0], t[1], set(t[2:])))

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

solution = []

lens = dict()
for i in range(len(photos)):
    p = photos[i]
    l = len(p[-1])
    if l not in lens.keys():
        lens[l] = {'H': [], 'V': []}
    lens[l][p[0]].append(i)

def process_bucket(l):
    bucket = lens[l]['H']
    if len(bucket) == 0:
        return []
    sequence = [bucket.pop()]
    while(len(bucket) > 0):
        s1 = get_slide([sequence[-1]])
        max_s = 0
        max_i = None
        max_idx = 0
        for idx, i in enumerate(bucket):
            s2 = get_slide([i])
            s = transition(s1, s2)
            if s > max_s:
                max_s = s
                max_i = i
                max_idx = idx
        if max_s == 0:
            sequence.append(bucket.pop())
        else:
            sequence.append(max_i)
            bucket = bucket[:max_idx] + bucket[max_idx+1:]
    print('finish {}: {}'.format(l, len(sequence)))
    return sequence


def merge_buckets(buckets):
    while(len(buckets) > 1):
        bucket = buckets.pop()
        s1 = get_slide([bucket[-1]])
        max_s = -1
        max_idx = None
        max_fl = None
        for idx, b in enumerate(buckets):
            for fl in [0, -1]:
                s2 = get_slide([b[fl]])
                s = transition(s1, s2)
                if s > max_s:
                    max_s = s
                    max_idx = idx
                    max_fl = fl
        next_bucket = buckets[max_idx]
        if max_fl == -1:
            next_bucket.reverse()
        buckets = buckets[:max_idx] + buckets[max_idx+1:] + [bucket + next_bucket]
    print(buckets)

    num_slides = 0
    for i in buckets[0]:
        num_slides += len(i)
        data = "%d\n" % i
        f.write(data)
    
    f = open("sol_c.txt", 'w')
    f.write("%d\n",num_slides)
    for i in buckets[0]:
        for d in i:
            data = "%d\n" % d
        f.write(data)
    f.close()
    
    return buckets[0]

buckets = []
with Pool(len(lens.keys())) as p:
    buckets.append(p.map(process_bucket, list(lens.keys())))

solution = merge_buckets(buckets)
score(solution)