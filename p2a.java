import java.util.Scanner;

public class ceaser {

    public static String encrypt(String pt, int key) {
        String e1 = "";
        for (char ch : pt.toCharArray()) {
            if (Character.isLowerCase(ch)) {
                char e2 = (char) (((ch - 'a' + key) % 26) + 'a');
                e1 += e2;
            } else if (Character.isUpperCase(ch)) {
                char e2 = (char) (((ch - 'A' + key) % 26) + 'A');
                e1 += e2;
            } else {
                e1 += ch;
            }
        }
        return e1;
    }

    public static String decrypt(String pt, int key) {
        return encrypt(pt, 26 - key);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter plaintext:");
        String pt = sc.nextLine();

        System.out.println("Enter shift key:");
        int key = sc.nextInt();

        String c = encrypt(pt, key);
        String d = decrypt(c, key);
        System.out.println("Encrypted text is " + c);
        System.out.println("Decrypted text is " + d);
    }
}
