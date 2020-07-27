import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int i=0;i<t;i++){
            int n=in.nextInt();
            long ans = findMinMove(n);
            System.out.println(ans);
        }
    }
    static long findMinMove(int n) {
        if (n == 1)
            return 0;
        long more = (n * 4 - 4) * ((n - 1) / 2);
        return findMinMove(n - 2) + more;
    }
}
