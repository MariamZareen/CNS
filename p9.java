//p9
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;
import java.io.UnsupportedEncodingException;

public class p9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the message to be hashed: ");
        String text = sc.nextLine();

        try {
            MessageDigest d = MessageDigest.getInstance("SHA-512");

            d.update(text.getBytes("UTF-8"));
            byte[] hashBytes = d.digest();

            StringBuilder hexString = new StringBuilder();
            for (byte i : hashBytes) {
                String hex = Integer.toHexString(0xff & i);
                if (hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }

            System.out.println("SHA-512 Hash: " + hexString.toString());
        } catch (NoSuchAlgorithmException | UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }
}