import java.io.*;
import java.util.*;
public class LAB_9
{
	public static void main(String[ ] args) throws Exception{
		byte b1[] = new byte[8];
		System.out.print("Перший потік: ");
		for (int i=0; i<b1.length; i++){
			b1[i] = (byte)(Math.random()*10);
			System.out.print(b1[i] + " ");
		}
		System.out.println();
		
		byte b2[] = new byte[8];
		System.out.print("Другий потік: ");
		for (int i=0; i<b2.length; i++){
			b2[i]=(byte)(Math.random( )*10);
			System.out.print(b2[i] + " ");
		}
		System.out.println();

		InputStream in1 = new ByteArrayInputStream(b1);
		InputStream in2 = new ByteArrayInputStream(b2);
		Vector list = new Vector();
		list.add(in1);
		list.add(in2);
		InputStream all = new SequenceInputStream(list.elements());
		int count = 0;
		System.out.print("Послідовний сумарний потік: ");
		int x;
		while ((x = all.read()) != -1){
			System.out.print(x+" ");
			count++;
		}
		System.out.println();
		System.out.println("Загальна кількість елементів: " + count);
		in1.close();
		in2.close();
		all.close();
	}
}
