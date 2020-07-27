import math


if __name__ == "__main__":

    cups = input()
    cups = int(cups)
    res = []
    for i in range(cups):
        nums = input()
        arr = input().split(" ")
        arr.sort()
        two_cup = 0
        one_cup = 0
        ans = 0
        for a in arr:
            if(a=='3'):
                ans+=1
            if(a=='2'):
                two_cup +=1
            if(a=='1'):
                one_cup +=1
        ans+=min(one_cup,two_cup)
        ans+=(one_cup-min(one_cup,two_cup))//3
        res.append(ans)
    for i in res:
        print(i)
    pass