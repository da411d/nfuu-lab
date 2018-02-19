import java.util.*;
import java.lang.*;
import java.io.*;

class LAB_3{
	public static void main(String[] args) throws Exception{
		System.out.println("     -= LAB 3 =-     ");
		System.out.println("  by David Manzhula  ");
		System.out.println("");
		System.out.println("");
		
		Random r = new Random();
		int[][] arr = new int[10][10];

		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				arr[i][j] = 10 + r.nextInt(90);
			}
		}
		int max = arr[0][1];
		
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				if(i<j){
					if(max < arr[i][j])max = arr[i][j];
				}
				System.out.print(arr[i][j]+" ");
			}
			System.out.println("");
		}
		
		System.out.println("");
		System.out.println("Max element: "+max);
	}
}