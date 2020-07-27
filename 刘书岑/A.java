import java.util.*;

public final class A{

	public static void main(String[] args){
		Scanner sca = new Scanner(System.in);
		String query = sca.nextLine();
		ArrayList all_out = new ArrayList();
		int num = Integer.parseInt(query);

		for(int i = 0; i < num; i++){
			Scanner scan = new Scanner(System.in);
			String num_q = sca.nextLine();
			String[] numbers = num_q.split(" ");
			int total = Integer.parseInt(numbers[0]);
			int cost_a = Integer.parseInt(numbers[1]);
			int cost_b = Integer.parseInt(numbers[2]);
			if(total * cost_a > total * cost_b){
				all_out.add(total * cost_a + " ");
			}	
			else all_out.add(total * cost_b + " ");
		}
		
		for(int j = 0; j < num; j ++)
			System.out.println(all_out.get(j));
	}
}
