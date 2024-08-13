//p10
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class md5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the text to hash: ");
        String text = sc.nextLine();

        try {
            MessageDigest d = MessageDigest.getInstance("MD5");

            d.update(text.getBytes());
            byte[] hashBytes = d.digest();

            StringBuilder hexString = new StringBuilder();
            for (byte i : hashBytes) {
                hexString.append(String.format("%02x", i));
            }

            System.out.println("Hash Value: " + hexString.toString());
        } catch (NoSuchAlgorithmException e) {
            System.out.println("No such algorithm: ");
        }
    }
}
