import java.util.Scanner;
import java.util.Arrays;

public class Solution {
    static boolean prime(long[] primes, long n) {
        for(long i : primes) {
            if(i * i  > n) {
                break;
            }
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    static long[] sieve() {
        boolean[] prime = new boolean[999984];
        Arrays.fill(prime, true);
        for(int i = 2; i * i < 999984; i++) {
            if(prime[i]) {
                for(int j = i * i; j < 999984; j += i) {
                    prime[j] = false;
                }
            }
        }
        int size = 0;
        for(boolean i : prime) {
            if(i) {
                size++;
            }
        }
        long[] primes = new long[size];
        for(int i = 2, j = 0; i < 999984; i++) {
            if(prime[i]) {
                primes[j] = i;
                j++;
            }
        }
        return primes;
    }
    
    public static void main(String[] args) {
        long[] primes = sieve();
        Scanner scanner = new Scanner(System.in);
        for(int T = scanner.nextInt(); T > 0; T--) {
            long N = scanner.nextLong(), K = scanner.nextLong();
            if(K == 1) {
                if(prime(primes, N) && N != 1) {
                    System.out.println("Yes");
                } else {
                    System.out.println("No");
                }
            } else if(K == 2) {
                if(N % 2 == 0 && N != 2 || N > 3 && prime(primes, N - 2)) {
                    System.out.println("Yes");
                } else {
                    System.out.println("No");
                }
            } else {
                if(N < 2 * K) {
                    System.out.println("No");
                } else {
                    System.out.println("Yes");
                }
            }
        }
    }
}
