import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

/*
    第一类Stirling数s(n, k)：把n个不同的元素分配到k个圆排列里，圆不能为空。
    s(n, k) = s(n-1, k-1) + (n-1)*s(n-1, k),
    s(0,0) = 1, s(k, 0) = 0, 1<=k<=n
*/
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger s[][] = new BigInteger[51][51];
        BigInteger total[] = new BigInteger[51];

        for(int i = 1; i <= 50; i++) {
            s[i][0] = BigInteger.valueOf(0);
            s[i][i] = BigInteger.valueOf(1);
            for(int j = 1; j < i; j++) {
                s[i][j] = s[i-1][j].multiply(BigInteger.valueOf(i-1));
                s[i][j] = s[i][j].add(s[i-1][j-1]);
            }
        }
 
        total[0] = BigInteger.valueOf(1);
        for(int i = 1; i <= 50; i++)
            total[i] = total[i-1] .multiply(BigInteger.valueOf(i)); //总次数就是50!
 
        while(scanner.hasNextInt()) {
            int n, k;
            n = scanner.nextInt();
            k = scanner.nextInt();
            BigInteger sum, gcd;
            sum = BigInteger.valueOf(0);
            // EZ能赢只有在奇数次操作的时候
            for(int i = 1; i <= k; i += 2)
                sum = sum.add(s[n][i]); // 计算出能赢的总可能数
            gcd = sum.gcd(total[n]);
            System.out.println(sum.divide(gcd) + "/" + total[n].divide(gcd));
        }
    }
 
}
