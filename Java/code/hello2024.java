import java.util.Scanner;

public class hello2024 {
    static double circle(int radius){
        final double PI = 3.141592; // 실수형 상수 PI
        return radius * radius * PI;
    }
    public static void main(String[] args) { // 메인함수 헤더
        Scanner sc = new Scanner(System.in);
        try {
            System.out.print("R>>");
            int r = sc.nextInt();
            double x = circle(r);
            System.out.println("AREA = " + x);
        } catch (Exception e) {
            System.out.println("ERROR");
        } finally {
            sc.close(); // Scanner 인스턴스를 닫음
        }
    }
}
