import java.util.Random;
import java.util.Scanner;

public abstract class Guess {
    protected Scanner scanner;
    protected Random random;
    protected int chances;
    public static boolean numberPlayed=false;
    public static boolean alphabetPlayed=false;

    public Guess() {
        this.scanner = new Scanner(System.in);
        this.random = new Random();
    }


    public abstract void difficultyLevel();

    public void alphanumeric(int range, String b) {
        // Empty implementation
    }
    public static void delay(int Number){ try {

        Thread.sleep(Number);
    } catch (InterruptedException e) {

        e.printStackTrace();
    }}
}
