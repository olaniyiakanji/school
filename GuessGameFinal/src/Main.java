import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);
    static boolean exit = true;
    public static int numberScores = 0;
    public static int alphabetScores = 0;

    public static int numberChances = 0;
    public static int alphabetChances = 0;


    public static void main(String[] args) {
        Random random = new Random();
        star();
    }

    public static void star() {
        System.out.println("Welcome to the Guessing Game!");
        System.out.println("1. Guess the Number.");
        System.out.println("2. Guess the Alphabet");
        System.out.println("3. My Score.");
        System.out.println("4. Credit.");
        System.out.println("5. Exit");
        System.out.print("Choose an option please!:\n");

        int option = 0;
        boolean invalidInput = false;
        do {
            try {
                option = scanner.nextInt();
                invalidInput = false;
            } catch (InputMismatchException e) {
                System.out.println("Invalid input! Please enter a number between 1 and 5:");
                scanner.nextLine(); // clear the input buffer
                invalidInput = true;
            }

            if (!invalidInput) {
                switch (option) {
                    case 1 -> {
                        Guess guessNumber = new GuessNumber();
                        guessNumber.difficultyLevel();
                    }
                    case 2 -> {
                        Guess guessAlpha = new GuessAlpha();
                        guessAlpha.difficultyLevel();
                    }
                    case 3 -> {
                        if (Guess.numberPlayed) {
                            System.out.println("Number's Best Score: " + Main.numberScores + "\n");
                            System.out.println("Least Chances Used: " + numberChances + "\n");
                        } else {
                            System.out.println("Number's Best Score: Not Played \n");
                            System.out.println("Least Chances Used: \n");
                        }
                        if (Guess.alphabetPlayed) {
                            System.out.println("Alphabet Best Score: " + Main.alphabetScores + "\n");
                            System.out.println("Least Chances used: " + alphabetChances + "\n");
                        } else {
                            System.out.println("Alphabet's Best Score: Not Played\n");
                            System.out.println("Least Chances Used:\n");
                        }
                        
                        Guess.delay(4000);
                        star();

                    }
                    case 4 -> {
                        System.out.println("""
                                 Created by [ Abdelrahman & Abdalla ]
                                 Course of Study:Software Construction.\n""");
                        Guess.delay(4000);
                        star();

                    }
                    case 5 -> {
                        System.out.println("Thanks for playing!");
                        System.exit(0);
                    }
                    default -> {
                        System.out.println("Please try again.");
                        Guess.delay(3000);
                    }
                }
            }
        } while (invalidInput || option < 1 || option > 5);
    }
}

