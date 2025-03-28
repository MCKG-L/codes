package Java;

import java.util.Scanner;

public class Hello {
    /**
     * @param args
     */
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int a[] = new int[5];
            for (int i = 0; i < 5; i++) {
                a[i] = sc.nextInt();
            }
            for (int i = 0; i < a.length; i++) {
                System.out.println(a[i]);
            }
        }
        System.out.println("Hello World!");
    }
}