import java.util.*;
import java.lang.*;
import java.io.*;

class LAB_5{
	public static void main(String[] args) throws Exception{
		System.out.println("     -= LAB 5 =-     ");
		System.out.println("  by David Manzhula  ");
		System.out.println("");
		System.out.println("");
		
		StringBuffer s = new StringBuffer("Manzhula David Vadimovich 11 JUN 1999");
		StringBuffer s2 = new StringBuffer(s);
		
		int start = 16, len = 5;
		s2.delete(0, start-1);
		s2.setLength(len);
		
		
		System.out.println(s2);
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		
		
		
		
		
		
		
		System.out.println("1: "+s);
		
		s = s.delete(26, 33);
		System.out.println("2: "+s);
		
		s = s.append(" Ivano-Frankivsk");
		System.out.println("3: "+s);
		
		s = s.insert(30, " MALE");
		System.out.println("4: "+s);
		
		System.out.println("5: Length = "+s.length());
		
		s.setLength(s.indexOf("1999"));
		System.out.println("6: "+s);
		
		s.setLength(s.indexOf(" "));
		s.reverse();
		System.out.println("7: "+s);
	}
}