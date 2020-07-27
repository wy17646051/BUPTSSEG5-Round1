package softwareExam;

import java.util.Scanner;

public class A {
	private int a[];
	private int b[];
	private long n[];
	public A(long[] n, int[] a, int[] b) {
		this.a = a;
		this.b = b;
		this.n = n;	
	}
	//比较每升水的单价
	public int lowerPrice(int a, int b) {
		if(0.5*b > a) {
			return 1;
		}else if(0.5*b < a){
			return 2;
		}
		return 0;
	}
	public void compute(int q) {
		for(int temp=0; temp<q; temp++) {
			int lower = lowerPrice(a[temp],b[temp]);
			if(lower==0||lower==1) {
				System.out.println((long)(a[temp]*n[temp]));
			}
			else {
				if(n[temp]%2==0) {
					System.out.println((long)(n[temp]*0.5*b[temp]));
				}else
					System.out.println((long)((n[temp]-1)*0.5*b[temp]+a[temp]));
			}
		}
	}
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int q = sc.nextInt();
		long[] n = new long[q];
		int[] a = new int[q];
		int[] b = new int[q];
		for(int temp=0; temp<q; temp++) {
			n[temp] = sc.nextLong();
			a[temp] = sc.nextInt();
			b[temp] = sc.nextInt();
		}
		sc.close();
		A questionA = new A(n, a, b);
		questionA.compute(q);
	}

}
