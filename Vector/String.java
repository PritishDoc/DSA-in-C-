/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
public class Main
{
	public static void main(String[] args) {
		System.out.println("Hello World");
		
		String str="java Program";
		int l=str.length();
		System.out.println(l);
		
		String str2=str.toUpperCase();
		System.out.println(str2);
		
		str2=str.trim();
		System.out.println(str2);
		
		str2=str.substring(3,7);
		
		System.out.println(str2);
		
		String str5="Pritish kumar ray";
		System.out.println(str5.startsWith("P"));
		System.out.println(str5.startsWith("P",6));
		System.out.println(str5.endsWith("ray"));
		
		
		for(int i=0;i<=str5.length();i++){
	//	System.out.print(str5.charAt(i));
		}
		
		String str6="www.udemy.com";
		System.out.println(str6.indexOf("udemy"));
	//	System.out.println(str6.indexof);
		
		
		
		String k="Java";
		String p="JavA";
		
		String m=new String("Java");
		
		System.out.println(k.equals(m));
		System.out.println(k.equalsIgnoreCase(p));
		System.out.println(k==m);
		System.out.println(k.compareTo(p));
	}
}
