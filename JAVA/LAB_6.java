import java.util.*;
import java.lang.*;
import java.io.*;

class LAB_6{
	public static void main(String[] args) throws Exception{
		System.out.println("     -= LAB 5 =-     ");
		System.out.println("  by David Manzhula  ");
		System.out.println("");
		System.out.println("");
		
		Random r = new Random();
		
		Eagle ivan = new Eagle();
		Duck ostap = new Duck();
		
		while(true){
			if(r.nextBoolean()){
				if(r.nextBoolean()) 
					ivan.eat();
				else
					ivan.move();
			}else{
				if(r.nextBoolean()) 
					ostap.eat();
				else
					ostap.move();
			}
			Thread.sleep(1500);
		}
	}
}


abstract class Bird{
	abstract void eat();
	abstract void move();
}

class Eagle extends Bird{
	public void eat(){
		System.out.println((new Date()).toLocaleString() + "> Орел поїв");
	}
	public void move(){
		System.out.println((new Date()).toLocaleString() + "> Орел полетів");
	}
}
class Duck extends Bird{
	public void eat(){
		System.out.println((new Date()).toLocaleString() + "> Качка поїла");
	}
	public void move(){
		System.out.println((new Date()).toLocaleString() + "> Качка полетіла");
	}
}