import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int i=0;i<t;i++){
            int n = in.nextInt();
            int[] a = new int[n];
            int left0=0,left1=0,left2=0;
            for(int j=0;j<n;j++){
                a[j] = in.nextInt();
                if(a[j]%3==0)
                    left0++;
                else if(a[j]%3==1)
                    left1++;
                else
                    left2++;
            }
            int max = left0;
            if(left1<=left2){
                max+=left1;
                max+=(left2-left1)/3;
            }else {
                max+=left2;
                max+=(left1-left2)/3;
            }
            System.out.println(max);
        }
    }
}
