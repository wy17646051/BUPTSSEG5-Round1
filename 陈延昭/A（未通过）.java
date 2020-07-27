package 陈延昭;

import java.util.ArrayList;
import java.util.Scanner;

public class A {
    public static void main (String[] args){
        int bottle1 = 1;
        int bottle2 = 2;
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();
        int n = number * 3;
        long[] input = new long[n];
        ArrayList<Long> answer;
        for(int i=0;i<n;i++){
            input[i] = scanner.nextLong();
        }
        for(int i=0;i<n;i=i+3){
            A qa = new A();
            answer = qa.caculate(input[i],bottle1,bottle2);
            System.out.println(qa.conpare(answer,input[i+1],input[i+2]));
        }


    }

    public ArrayList<Long> caculate(long n, int bottle1, int bottle2){
        ArrayList<Long> answer = new ArrayList<Long>();
        for(int i = 0; i<= n; i++){
            if(((n-i)%2)==0){
                answer.add((long) i);
                answer.add((long)(n-i)/2);
                //System.out.println(i);
                //System.out.println((int)(n-i)/2);
            }
        }
        return answer;
    }

    public long conpare(ArrayList<Long> answer,long a, long b){
        long cost1;
        long cost2;
        long cost;
        int number = answer.size();
        if (number <=2) {
            return cost = answer.get(0) * a + answer.get(1) * b;
        }
        while(number >2) {
                cost1 = answer.get(0) *a + answer.get(1) *b;
                cost2 = answer.get(2) *a + answer.get(3) *b;
                if (cost1 < cost2) {
                    answer.remove(2);
                    answer.remove(2);
                } else {
                    answer.remove(0);
                    answer.remove(0);
                }
            number = answer.size();
        }
        return cost = answer.get(0) * a + answer.get(1) * b;
    }
}
