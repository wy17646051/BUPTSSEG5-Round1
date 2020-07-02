#define F
#ifdef F
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
/*F题*/

struct Node {
    int x;
    int y;
    Node(int x,int y):x(x),y(y){}
};


int main() {
    //思路：对包含物品的这些点的坐标进行排序，机器人按照顺序移动到这些点上取得物品
    //如果有一个物品需要机器人向左或向下移动，则结果为NO
    //移动时，先右移再上移

    //可以取得所有物品的条件:在排序之后的数组中，对于任意相邻位置的两个点A和B, A.x<=B.x && A.y<=B.y
	
	/*
	本题没来得及写程序，但是已经有了总体思路：

	1. 读入所有点的坐标，放到一个数组nodes中，并按照x轴的值大小进行升序排序
	2. 判断这个点序列是否满足条件：A[i].x<=A[i+1].x && A[i].y<=A[i+1].y
	3. 如果不满足满足2中条件，则结果为NO
	4. 如果满足条件，则从(0,0)开始，按照nodes数组中的顺序取物品
	5. 从(x0,y0)到(x1,y1)的移动，首先右移(x1-x0)步，再上移(y1-y0)步
	
	
	*/
    return 0;
}
#endif