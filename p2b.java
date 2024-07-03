import java.util.*; 
public class p2b{ 
     char[][] matrix; 
      
    //  Constructor 
      p2b(String key){ 
         matrix=generateMatrix(key); 
     } 
      
    //  f1 
     char[][] generateMatrix(String key){ 
        key=key.toUpperCase().replaceAll("[^A-Z]","").replace('J','I'); 
        StringBuilder sb=new StringBuilder(); 
        Set<Character> set=new HashSet<>(); 
         
        for(char c:key.toCharArray()){ 
            if(set.add(c)){ 
                sb.append(c); 
            } 
        } 
        for(char c='A';c<='z';c++){ 
            if(c!='J' && set.add(c)){ 
                sb.append(c); 
            } 
        } 
         
        char[][] matrix=new char[5][5]; 
        for(int i=0;i<25;i++){ 
            matrix[i/5][i%5]=sb.charAt(i); 
        } 
        return matrix; 
    } 
     
    // f2 
    private String preprocessMessage(String msg){ 
         msg=msg.toUpperCase().replaceAll("[^A-Z]","").replace('J','I'); 
        StringBuilder sb=new StringBuilder(msg); 
        for(int i=0;i<sb.length()-1;i+=2){ 
            if(sb.charAt(i)==sb.charAt(i+1)){ 
                sb.insert(i+1,'X'); 
            } 
        } 
        if(sb.length()%2!=0){ 
            sb.append('X'); 
        } 
        return sb.toString(); 
    } 
     
    // f3 
    private int[] findPosition(char ch){ 
        for(int i=0;i<5;i++){ 
            for(int j=0;j<5;j++){ 
                if(matrix[i][j]==ch){ 
                    return new int[]{i,j}; 
                } 
            } 
        } 
        return null; 
    } 
     
    // f4 
    public String encrypt(String plaintext){ 
        return processMessage(plaintext,true); 
    } 
     
    //f5 
    public String decrypt(String ciphertext){ 
        return processMessage(ciphertext,false); 
    } 
     
    // f6 
    private String processMessage(String msg,boolean encrypt){ 
        msg=preprocessMessage(msg); 
        StringBuilder res=new StringBuilder(); 
        int shift=encrypt?1:-1; 
         
        for(int i=0;i<msg.length();i+=2){ 
            char a=msg.charAt(i); 
            char b=msg.charAt(i+1); 
            int[] posA=findPosition(a); 
            int[] posB=findPosition(b); 
            if(posA[0]==posB[0]){ 
                res.append(matrix[posA[0]][(posA[1]+shift+5)%5]); 
                res.append(matrix[posB[0]][(posB[1]+shift+5)%5]); 
            } 
            else if(posA[1]==posB[1]){ 
                res.append(matrix[(posA[0]+shift+5)%5][posA[1]]); 
                res.append(matrix[(posB[0]+shift+5)%5][posB[1]]); 
            } 
            else{ 
                res.append(matrix[posA[0]][posB[1]]); 
                res.append(matrix[posB[0]][posA[1]]); 
            } 
        } 
        return res.toString(); 
    } 
    public static void main(String[] args){ 
        // Scanner sc=new Scanner(System.in); 
        // System.out.printf("Enter plaintext:"); 
        // String plaintext=sc.nextLine(); 
        // System.out.println("Enter key:"); 
        // String key=sc.nextLine(); 
         
         String key="MONARCHY"; 
        String plaintext="INSTRUMENTS"; 
 
         
        p2b cipher=new p2b(key); 
         
        String ct=cipher.encrypt(plaintext); 
        String dt=cipher.decrypt(ct); 
         
         System.out.println("Ciphertext: " + ct); 
        System.out.println("Decrypted Text: " + plaintext); 
    } 
} 