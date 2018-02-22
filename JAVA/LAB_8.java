import java.util.*;
import java.lang.*;
import java.io.*;

class LAB_8{
	public static void main(String[] args) throws Exception{
		System.out.println("	 -= LAB 8 =-	 ");
		System.out.println("  by David Manzhula  ");
		System.out.println("");
		System.out.println("");
		
		Scanner s = new Scanner(System.in);
		HashMap list = new HashMap();
		
		while(true){
			System.out.println("1 - Додати значення");
			System.out.println("2 - Пошук значення");
			System.out.println("3 - Видалення знення");
			System.out.println("4 - Вивести всі");
			System.out.println("0 - Вихід");
			System.out.println();
			
			System.out.print("Введи команду: ");int cmd = s.nextInt();
			
			switch(cmd){
				case 1:
					System.out.print("Введи назву країни: ");
					String key = s.next();
					
					System.out.print("Введи назву столиці: ");
					String value = s.next();
					
					list.put(key, value);
					System.out.println("Дані додано успішно!");
					break;
					
					
				case 2:
					System.out.print("Введи слово: ");
					String search = s.next();
				
					if(list.containsKey(search)){
						System.out.println("Знайдено збіг за ключем!");
						System.out.println("Пара: "+search+" - "+list.get(search));
						
					}else if(list.containsValue(search)){
						System.out.println("Знайдено збіг за значенням!");
						
					}else{
						System.out.println("Збіг не знайдено!");
						
					}
					break;
					
				case 3:
					System.out.print("Введи країну: ");
					String delete = s.next();
				
					System.out.println("Ви впевнені що бажаєте знищити країну?");
					System.out.print("Напишіть YES для підтвердження: ");
					String confirm = s.next();
					if(confirm.compareToIgnoreCase("yes") == 0){
						list.remove(delete);
						System.out.print("Видалено успішно!");
					}else{
						System.out.print("Операція скасована");
					}
					break;
					
				case 4:
					Iterator<String> keys = list.keySet().iterator();
					while (keys.hasNext()) {
						String k = keys.next().toString();
						String v = list.get(k).toString();
						System.out.println(k+" - "+v);
					}					
					break;
					
				case 0:
					return;
			}
			System.out.println();
			System.out.println();
		}
	}
}