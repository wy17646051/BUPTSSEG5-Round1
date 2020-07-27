import java.util.*;

public final class D{

	public static void main(String[] args){
		Scanner sca = new Scanner(System.in);
		int num = Integer.parseInt(sca.nextLine());
		Scanner scan = new Scanner(System.in);
		String[] all_numbers = scan.nextLine().split(" ");
		int count = 0;
		ArrayList sub = new ArrayList();
		if(num == 2 || num == 1) System.out.println(0);
		else{
			int flag = 0;
			for(int i = 1; i <= num - 1; i++){
				String diff  = (Integer.parseInt(all_numbers[i]) - Integer.parseInt(all_numbers[i-1])) + " ";
				sub.add(diff + " ");
				for(int j = 1; j <= num - 1; j++){
					if(diff.equals(sub.get(j))) continue;
					else flag = 1;
				}
			}
			if(flag == 0) System.out.println(0);
			else{
				for(int i = 1; i <= num - 1; i++){		
					for(int j = 1; j <= num - 1; j++){
						int diff  = Integer.parseInt(sub.get(i).toString()) - Integer.parseInt(sub.get(j).toString());
						if(diff > 4) System.out.println(0);
					}
				}
			}

		}		
		
	}
}