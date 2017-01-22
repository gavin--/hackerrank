import java.util.Scanner;
import java.math.BigInteger;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t1 = scanner.nextInt(), t2 = scanner.nextInt(), n = scanner.nextInt();
        BigInteger f1 = BigInteger.valueOf(t1), f2 = BigInteger.valueOf(t2);
        for(int i = 3; i <= n; i++) {
            BigInteger temp = f2;
            f2 = f1.add(f2.multiply(f2));
            f1 = temp;
        }
        System.out.print(f2.toString());
    }
}
