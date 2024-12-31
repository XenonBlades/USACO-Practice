import sys
sys.stdin = open("cbarn.in", "r")
sys.stdout = open("cbarn.out", "w")

n = int(input().strip())
lst = [int(input().strip()) for _ in range(n)]
ans =  float('inf')


def suffle_lst(lst):
    return lst[1:] + [lst[0]]

def total_dis(lst):
    dis = 0
    for i in range(n):
        dis += (i)*lst[i]
    return dis


ans = min(total_dis(lst),ans)

for _ in range(n-1):
    lst = suffle_lst(lst)
    ans = min(total_dis(lst),ans)

print(ans)
