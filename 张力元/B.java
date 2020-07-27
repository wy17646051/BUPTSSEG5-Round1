package softwareExam;

import java.util.Scanner;

public class B {
	
	public void compute(int[] array) {
		if(array[1]==array[2]) {
			System.out.println(array[0]+array[1]);
		}else
			if(array[1]>array[2]) {
				System.out.println(array[0]+array[2]+(array[1]-array[2])/3);
			}else
				System.out.println(array[0]+array[1]+(array[2]-array[1])/3);
	}

	public static void main(String[] args) {
		B b = new B();
		
		int curr;
		Scanner sc = new Scanner(System.in);
		int q = sc.nextInt();
		for(int temp=0; temp<q; temp++) {
			int[] model = new int[3];
			int sub = sc.nextInt();
			for(int i=0; i<sub; i++) {
				curr=sc.nextInt();
				if(curr%3==0) {
					model[0]++;
				}else
					if(curr%3==1) {
						model[1]++;
					}
					else
						model[2]++;
			}
			b.compute(model);
		}
		sc.close();

	}

}
