import java.util.*;
import java.lang.*;
import java.io.*;

class LAB_6{
	public static void main(String[] args) throws Exception{
		System.out.println("     -= LAB 6 =-     ");
		System.out.println("  by David Manzhula  ");
		System.out.println("");
		System.out.println("");
		
		Random r = new Random();
		
		Eagle ivan = new Eagle(10);
		Duck ostap = new Duck(3);
		
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
	int age;
	public Eagle(int a){
		this.age = a;
	}
	public void eat(){
		Random r = new Random();
		int food = age*(1 + r.nextInt(2)) + r.nextInt(10);
		System.out.println((new Date()).toLocaleString() + "> Орел поїв "+food+"кг мнєса");
	}
	public void move(){
		System.out.println((new Date()).toLocaleString() + "> Орел полетів");
	}
}
class Duck extends Bird{
	int age;
	public Duck(int age){
		this.age = age;
	}
	public void eat(){
		Random r = new Random();
		int food = age*(2 + r.nextInt(5))*10 + r.nextInt(10);
		String food_type = (r.nextBoolean() ? "риби" : "хліба");
		System.out.println((new Date()).toLocaleString() + "> Качка поїла "+food+"г "+food_type);
	}
	public void move(){
		System.out.println((new Date()).toLocaleString() + "> Качка полетіла");
	}
}