public class Armstrong {

    public static boolean isArmstrong(int n) {
        int originalNum = n;
        int numOfDigits = (int) Math.log10(n) + 1;
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += Math.pow(digit, numOfDigits);
            n /= 10;
        }
        return originalNum == sum;
    }

    public static void main(String[] args) {
        int n = 153;
        if (isArmstrong(n)) {
            System.out.println(n + " is an Armstrong number");
        } else {
            System.out.println(n + " is not an Armstrong number");
        }
    }

}
