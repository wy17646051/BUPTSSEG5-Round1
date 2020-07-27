import math


if __name__ == "__main__":

    cups = input()
    cups = int(cups)
    res = []
    for i in range(cups):
        arr = input().split(" ")
        arr2 = []#差值arr
        for i in range(len(arr)-1):
            arr2.append(int(arr[i])-int(arr[i+1]))
        for i in range(len(arr2)-1):
            if(arr2[i]-arr2[i+1]==1 or arr2[i]-arr2[i+1]==-1):
                ans+=1
            if(arr2[i]-arr2[i+1]==2 or arr2[i]-arr2[i+1]==21):
                ans+=1
        
        # res.append(ans)
        print(arr2)
    for i in res:
        print(i)
    pass