import math


if __name__ == "__main__":

    cups = input()
    cups = int(cups)
    res = []
    for i in range(cups):
        arr = input().split(" ")
        water = int(arr[0])
        one = int(arr[1])
        two = int(arr[2])
        if(two/2<one):
            ans = water//2*two +(water%2*one)
        else:
            ans = water*one
        res.append(ans)
    for i in res:
        print(i)
    pass