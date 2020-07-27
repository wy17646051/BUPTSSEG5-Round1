import java.util.Scanner;
import java.util.Stack;

public class E {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()){
            int n = in.nextInt();
            int m =in.nextInt();
            int s = in.nextInt();
            int[][] W = new int[n+1][n+1];
            for(int i=0;i<m;i++){
                int begin = in.nextInt();
                int end = in.nextInt();
                W[begin][end] = 1;
            }
            if(n==1){
                System.out.println(0);
            }else {
                int ans = bfs(W,s,n);
                System.out.println(ans);
            }

        }
    }
    private static int bfs(int[][] W,int s, int n){
        boolean[] flag = new boolean[n+1];
        flag[s] = true;
        Stack<Integer> stack = new Stack<>();
        stack.push(s);
        while (!stack.empty()){
            int begin = stack.pop();
            for(int i=1;i<=n;i++){
                if(W[begin][i]!=0&&!flag[i]){
                    stack.push(i);
                    flag[i] = true;
                }
            }
        }
        int k=0;
        for(int j=1;j<=n;j++){
            if(!flag[j]){
                stack.push(j);
                while (!stack.empty()){
                    int begin = stack.pop();
                    for(int i=1;i<=n;i++){
                        if(W[begin][i]!=0&&!flag[i]){
                            stack.push(i);
                            flag[i] = true;
                        }
                    }
                }
                k++;
            }
        }
        return k;
    }
}
