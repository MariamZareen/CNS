public class RailFenceCipher {
    
    public static String encrypt(String text, int rails) {
        StringBuilder[] fences = new StringBuilder[rails];
        for (int i = 0; i < rails; i++) {
            fences[i] = new StringBuilder();
        }
        
        int rail = 0;
        boolean down = true;
        for (char c : text.toCharArray()) {
            fences[rail].append(c);
            if (down) {
                rail++;
                if (rail == rails - 1) {
                    down = false;
                }
            } else {
                rail--;
                if (rail == 0) {
                    down = true;
                }
            }
        }
        
        StringBuilder result = new StringBuilder();
        for (StringBuilder fence : fences) {
            result.append(fence);
        }
        return result.toString();
    }
    
    public static String decrypt(String text, int rails) {
        StringBuilder[] fences = new StringBuilder[rails];
        for (int i = 0; i < rails; i++) {
            fences[i] = new StringBuilder();
        }
        
        int rail = 0;
        boolean down = true;
        int[] counts = new int[rails];
        for (int i = 0; i < text.length(); i++) {
            fences[rail].append(text.charAt(i));
            if (down) {
                rail++;
                if (rail == rails - 1) {
                    down = false;
                }
            } else {
                rail--;
                if (rail == 0) {
                    down = true;
                }
            }
        }
        
        StringBuilder result = new StringBuilder();
        rail = 0;
        down = true;
        for (int i = 0; i < text.length(); i++) {
            result.append(fences[rail].charAt(counts[rail]));
            counts[rail]++;
            if (down) {
                rail++;
                if (rail == rails - 1) {
                    down = false;
                }
            } else {
                rail--;
                if (rail == 0) {
                    down = true;
                }
            }
        }
        
        return result.toString();
    }
    
    public static void main(String[] args) {
        String plaintext = "Hello, World!";
        int rails = 3;
        String encrypted = encrypt(plaintext, rails);
        System.out.println("Encrypted: " + encrypted);
        
        String decrypted = decrypt(encrypted, rails);
        System.out.println("Decrypted: " + decrypted);
    }
}
