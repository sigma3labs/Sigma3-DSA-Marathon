import java.util.Scanner;

public class AmbitiousKid {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array:");
        int n = sc.nextInt();
        int minAbs = Integer.MAX_VALUE;

        System.out.println("Enter the array elements:");
        for (int i = 0; i < n; i++) {
            int ai = sc.nextInt();
            minAbs = Math.min(minAbs, Math.abs(ai));
        }

        System.out.println("Minimum number of operations to make the product zero: " + minAbs);
    }
}
