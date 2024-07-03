 import java.util.Scanner; 
public class p2a{ 
    public static String encrypt(String p,int key){ 
        String e1=""; 
        for(char ch:p.toCharArray()){ 
            if(Character.isLowerCase(ch)){ 
                char e2=(char)(((ch-'a'+key)%26)+'a'); 
                e1+=e2; 
            } 
            else if(Character.isUpperCase(ch)){ 
                char e2=(char)(((ch-'A'+key)%26)+'A'); 
                e1+=e2; 
            } 
            else{ 
                e1+=ch; 
            } 
        } 
        return e1; 
    } 
    public static String decrypt(String p,int key){ 
        return encrypt(p,26-key); 
    } 
    public static void main(String args[]){ 
        Scanner sc=new Scanner(System.in); 
        System.out.println("Enter plaintext:"); 
        String plaintext=sc.nextLine(); 
        System.out.println("Enter key:"); 
        int key=sc.nextInt(); 
        String c=encrypt(plaintext,key); 
        String d=decrypt(c,key); 
        System.out.println("Encrypted text is "+c); 
        System.out.println("Decrypted text is "+d); 
    } 
} 