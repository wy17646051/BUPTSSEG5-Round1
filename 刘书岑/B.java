
import java.util.*;

public final class B{
	public static void main(String[] args){
		Scanner sca = new Scanner(System.in);
		String query = sca.nextLine();
		int num = Integer.parseInt(query);
		ArrayList all_out = new ArrayList();

		for(int i = 0; i < num; i++){
			int count = 0;
			Scanner scan = new Scanner(System.in);
			int sub_num =  Integer.parseInt(sca.nextLine());
			Scanner scann = new Scanner(System.in);
			String[] all_numbers = scann.nextLine().split(" ");

			for(int j = 0; j < sub_num; j++){
				if(Integer.parseInt(all_numbers[j]) % 3 == 0){
					count++;
					all_numbers[j] = "0";
					continue;
				} 
				else{
					for(int k = j + 1; k < sub_num; k ++){
						int temp = Integer.parseInt(all_numbers[j]) + Integer.parseInt(all_numbers[k]);
						if(temp % 3 == 0){
							count++;
							all_numbers[j] = "0";
							all_numbers[k] = "0";
							continue;
						} 
					}
					for(int m = j + 2; m < sub_num; m ++){
						int temp = Integer.parseInt(all_numbers[j]) + Integer.parseInt(all_numbers[m-1])  
									+ Integer.parseInt(all_numbers[m]);
						if(temp % 3 == 0){
							count++;
							all_numbers[j] = "0";
							all_numbers[m-1] = "0";
							all_numbers[m] = "0";
							continue;
						} 
					}
				}
			}

			all_out.add(count + " ");
		}

		for(int j = 0; j < num; j ++)
			System.out.println(all_out.get(j));

		
	}
}