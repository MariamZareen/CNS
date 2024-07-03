//pg6
import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;
import java.util.Scanner;

public class p6 {

    public static String encrypt(String strToEncrypt, String secret) {
        try {
            SecretKeySpec s = new SecretKeySpec(secret.getBytes("UTF-8"), "AES");
            Cipher c = Cipher.getInstance("AES");
            c.init(Cipher.ENCRYPT_MODE, s);
            return Base64.getEncoder().encodeToString(c.doFinal(strToEncrypt.getBytes("UTF-8")));
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    public static String decrypt(String strToDecrypt, String secret) {
        try {
            SecretKeySpec s = new SecretKeySpec(secret.getBytes("UTF-8"), "AES");
            Cipher c = Cipher.getInstance("AES");
            c.init(Cipher.DECRYPT_MODE, s);
            return new String(c.doFinal(Base64.getDecoder().decode(strToDecrypt)));
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the key (16 characters for 128-bit AES): ");
        String key = sc.nextLine();

        if (key.length() != 16) {
            System.out.println("Key must be 16 characters long.");
           // sc.close();
            return;
        }

        System.out.println("Enter the plaintext: ");
        String pt = sc.nextLine();

        String encryptedString = encrypt(pt, key);
        String decryptedString = decrypt(encryptedString, key);

        System.out.println("Original String: " + pt);
        System.out.println("Encrypted String: " + encryptedString);
        System.out.println("Decrypted String: " + decryptedString);

        //sc.close();
    }
}