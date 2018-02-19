import java.util.*;
import java.lang.*;
import java.io.*;

class LAB_1{
	public static float fn_1(float x){
		return (float) Math.sin(x*x + 2*x + 1);
	}
	public static float fn_2(float x){
		return x >= 5 ? 
			(float) Math.log((x+1)/(x+2)) :
			(float) (2*Math.pow(x, 5) + 2*x*x);
	}
	
	public static void main(String[] args) throws Exception{
		System.out.println("     -= LAB 1 =-     ");
		System.out.println("  by David Manzhula  ");
		System.out.println("");
		System.out.println("");
		
		System.out.println("function 1");
		for(float i=-4; i<= 4; i+= 0.5){
			System.out.println("\tx: "+i+", y: "+fn_1(i));
		}
		
		
		System.out.println("");
		System.out.println("function 2");
		for(float i=4; i<= 6; i+= 0.35){
			System.out.println("\tx: "+i+", y: "+fn_1(i));
		}
		
	}
}