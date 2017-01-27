import java.util.Scanner;
import java.math.BigInteger;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        BigInteger f = BigInteger.valueOf(1);
        for(int i = 1; i <= N; i++) {
            f = f.multiply(BigInteger.valueOf(i));
        }
        System.out.print(f.toString());
    }
}
