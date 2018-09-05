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
				arr[i][j] = r.nextInt(90) - 45;
			}
		}
		int max = Integer.MIN_VALUE;
		
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				if(i<j){
					if(max < arr[i][j] && arr[i][j] < 0 && arr[i][j]%2 == -1)max = arr[i][j];
				}
				if(arr[i][j] >= 0)System.out.print(" ");
				if(Math.abs(arr[i][j]) < 10)System.out.print(" ");
				System.out.print(arr[i][j]+" ");
			}
			System.out.println("");
		}
		
		System.out.println("");
		System.out.println("Max element: "+max);
	}
}