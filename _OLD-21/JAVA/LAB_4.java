import java.util.*;
import java.lang.*;
import java.io.*;

class LAB_4{
	public static void main(String[] args) throws Exception{
		System.out.println("     -= LAB 4 =-     ");
		System.out.println("  by David Manzhula  ");
		System.out.println("");
		System.out.println("");
		
		String s = "NFUU, IDTD, KN-21, Computer Science";
		
		String s1 = s.substring(0, s.lastIndexOf(","));
		System.out.println("Рядок 1: "+s1);
		
        String s2 = "";
		for(int i=s1.length()-1; i>=0; i--)s2 += s1.charAt(i);
		System.out.println("Рядок 2: "+s2);
		
		String s3 = s1.toUpperCase();
		int comp = s1.compareToIgnoreCase(s3);
		System.out.println("Рядок 3: " + s3 + " - " + (comp == 0 ? "Рядки рівні" : comp));
		
		System.out.println("Факультет: "+s1.split(", ")[1]);
		
		String s4 = s1+s3;
		System.out.println("Рядок 4: "+s4);
		
		char search = 'N';
		System.out.println("Перше входження букви \""+search+"\": "+s1.indexOf(search));
		System.out.println("Останнє входження букви \""+search+"\": "+s1.lastIndexOf(search));
		
	}
}