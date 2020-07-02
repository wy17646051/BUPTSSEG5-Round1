//思路有错，宽搜可以保证找到点，但源代码中对于路径的输出有误，即使用宽搜找到了，记录最短路径也是问题
//应该对输入节点先按R方向从小到大，再按U方向从小到大排序，然后以字典序先以R出发为主，U方向为辅，进行寻找，一边寻找一遍输出经过的路径。
// 我傻了


#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string.h>

using namespace std;

const int MAXN = 1005;


struct coord{
    int x;
    int y;
    coord(int x,int y):x(x),y(y){}
};

queue<coord> myQueue;

bool visited[MAXN][MAXN];
bool cityboxes[MAXN][MAXN];

bool bfs(int x, int y,int m){
    int num=0;
    string seq;
    seq.clear();
    myQueue.push(coord(0,0));
    int x2=0;
    int y2=0;
    while(!myQueue.empty()){
        x2 = myQueue.front().x;
        y2 = myQueue.front().y;
        myQueue.pop();

        if(num == m){
            cout<<"YES"<<endl;
            cout<<seq<<endl;
            return true;
        }



        for (int i = 0; i < 2; ++i) {
            if(x2+1>=1000 || y2+1>=1000  ){
                continue;
            }
            if(i==0){

                x2 += 1;
                if(cityboxes[x2][y2] == true){
                    seq += 'R';
                }
            }else if(i==1){
                y2 += 1;
                if(cityboxes[x2][y2] == true){
                    seq += 'U';
                }
            }

            myQueue.push(coord(x2,y2));

            if(cityboxes[x2][y2]){
                num += 1;
            }

        }

    }
    return false;

}


int main(){
    int cases=0;
    scanf("%d",&cases);


    for (int l = 0; l < cases; ++l) {

        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                visited[i][j] = false;
                cityboxes[i][j] = false;
            }
        }

        int m;
        scanf("%d",&m);



        int x1=0;
        int y1=0;
        for (int k = 0; k < m; ++k) {
            scanf("%d%d",&x1,&y1);
            cityboxes[x1][y1] = true;
        }

        if(!bfs(0,0,m)){
            cout<<"NO"<<endl;
        }


    }

}



