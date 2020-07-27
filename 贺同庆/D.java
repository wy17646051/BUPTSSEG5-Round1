import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()){
            int n = in.nextInt();
            int[] b = new int[n];
            int ans = findMinOp(b);
            System.out.println(ans);
        }
    }
    static int findMinOp(int[] b){
        if(b.length<=2)
            return 0;
        int min=b[1]-b[0];
        int max=min;
        int[] dis = new int[b.length];
        for(int i=1;i<b.length-1;i++){
            int cur = b[i+1]-b[i];
            dis[i] = cur;
            if(cur<min)
                min = cur;
            if(cur>max)
                max = cur;
        }
        if(max-min>4)
            return -1;
        else {
            int mid = (min+max)/2;
            int num = 0;
            for(int i=0;i<dis.length;i++){

                if(Math.abs(mid-dis[i])>=1)
                    num++;
            }
            return num;
        }
    }
}

