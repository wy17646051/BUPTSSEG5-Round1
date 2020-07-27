package 陈延昭;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class B {
    public static void main (String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        int[] n = new int[t];
        for (int i = 0; i < t; i++) {
            n[i] = s.nextInt();
            int[] array = new int[n[i]];
            for(int j =0; i<n[i];i++){
                array[j] = s.nextInt();
            }
            B b = new B();
            b.caculate(array);
        }
    }

    public int caculate(int[] array){
        ArrayList<Integer> list1 = new ArrayList<Integer>();
        ArrayList<Integer> list2 = new ArrayList<Integer>();
        for(int i=0;i< array.length;i++){
            for(int j=0;j<array.length;j++) {
                if (array[i] > array[j]) {
                    int n;
                    n=array[i];
                    array[i] = array[j];
                    array[j] = n;
                }
            }
        }
        for(int i=0;i< array.length;i++){
            if(array[i]%3==0){
                list1.add(array[i]);
            }else{
                list2.add(array[i]);
            }

        }

        return 0;
    }
}
