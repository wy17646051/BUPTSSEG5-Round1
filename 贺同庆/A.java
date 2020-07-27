import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for(int i=0;i<q;i++){
            long n = in.nextLong();
            long a = in.nextLong();
            long b = in.nextLong();
            long sum;
            if(b/2<a){
                if(n%2==0){
                    sum = n/2*b;
                }else {
                    sum = n/2*b+a;
                }
            }else {
                sum = n*a;
            }
            System.out.println(sum);
        }
    }

}
