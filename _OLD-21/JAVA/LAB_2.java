import java.util.*;
import java.lang.*;
import java.io.*;

class LAB_2{
	public static void main(String[] args) throws Exception{
		System.out.println("     -= LAB 2 =-     ");
		System.out.println("  by David Manzhula  ");
		System.out.println("");
		System.out.println("");
		
		Random r = new Random();
		int[] arr = new int[10];
		float[] arr_new = new float[10];
		int sum = 0;
		
		for(int i=0; i<10; i++){
			arr[i] = 10 + r.nextInt(40);
			sum += arr[i];
		}
		
		for(int i=0; i<10; i++){
			arr_new[i] = (float)arr[i] / (float)sum;
			
			System.out.println((i+1)+": "+arr_new[i]);
		}
	}
}