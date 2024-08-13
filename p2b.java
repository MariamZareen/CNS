import java.util.*;

public class playfair{
    char[][] mat;
    
    playfair(String key){
    mat=generateMat(key);
    printMat();
    }
    
    private void printMat(){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                System.out.print(mat[i][j]+" "); 
            }
            System.out.println();
        }
    }
    char[][] generateMat(String key){
        key=key.toUpperCase().replaceAll("[^A-Z]","").replace('J','I');
        StringBuilder sb=new StringBuilder();
        Set<Character> set=new HashSet<>();
        
        for(char c:key.toCharArray()){
            if(set.add(c))
            sb.append(c);
        }
        
        for(char c='A';c<='z';c++){
            if(c!='J' && set.add(c))
            sb.append(c);
        }
        
        char[][] mat=new char[5][5];
        for(int i=0;i<25;i++){
            mat[i/5][i%5]=sb.charAt(i);
        }
        return mat;
    }
    
    private String preprocessMsg(String msg){
       msg=msg.toUpperCase().replaceAll("[^A-Z]","").replace('J','I');
       StringBuilder sb=new StringBuilder(msg); 
       
       for(int i=0;i<sb.length()-1;i+=2){
           if(sb.charAt(i)==sb.charAt(i+1))
           sb.insert(i+1,'X');
       }
        if(sb.length()%2!=0)
           sb.append('X');
       return sb.toString();
    }
    
    private int[] findPos(char c){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(mat[i][j]==c)
                return new int[] {i,j};
            }
            
        }
        return null;
    }
    
   public String encry(String pt){
    return processMsg(pt,true);
   }
    
    public String decry(String ct){
    return processMsg(ct,false);
    }
    
    private String processMsg(String msg,boolean encry){
        msg=preprocessMsg(msg);
       StringBuilder sb=new StringBuilder(); 
       int shift=encry?1:-1;
       
       for(int i=0;i<msg.length();i+=2){
       char a=msg.charAt(i);
       char b=msg.charAt(i+1);
       int[] posA=findPos(a);
       int[] posB=findPos(b);
       
       if(posA[0]==posB[0]){
       sb.append(mat[posA[0]][(posA[1]+shift+5)%5]);
      sb.append(mat[posB[0]][(posB[1]+shift+5)%5]);
       }
       else if(posA[1]==posB[1]){
        sb.append(mat[(posA[0]+shift+5)%5][posA[1]]);
       sb.append(mat[(posB[0]+shift+5)%5][posB[1]]);
       }
       else{
         sb.append(mat[posA[0]][posB[1]]);
         sb.append(mat[posB[0]][posA[1]]);
       }
       }
     return sb.toString();  
    }
    
    public static void main(String[] args){
      Scanner sc=new Scanner(System.in);
      
      System.out.print("Enter pt: ");
      String pt=sc.nextLine();
      System.out.println();
     
     System.out.print("Enter key: ");
      String key=sc.nextLine();
      System.out.println();
      
      playfair m=new playfair(key);
      String e=m.encry(pt);
      String d=m.decry(e);
     
     System.out.println("Encrypted txt: "+e);
      System.out.println("Decrypted txt: "+d);
    }
}
