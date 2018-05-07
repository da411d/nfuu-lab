import java.util.*;
import java.lang.*;
import java.io.*;

class LAB_7{
	public static void main(String[] args) throws Exception{
		System.out.println("	 -= LAB 7 =-	 ");
		System.out.println("  by David Manzhula  ");
		System.out.println("");
		System.out.println("");
		
		String n1 = "A";
		System.out.println("0x" + n1 + "(16) = " + Integer.parseInt(n1, 16) + "(10)");

		int n2 = 17;
		System.out.println(n2 + "(10) = " + Integer.toOctalString(n2) + "(8)");
	}
}