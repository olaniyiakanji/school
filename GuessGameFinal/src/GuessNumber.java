import java.util.Random;
import java.util.Scanner;

public class GuessNumber extends Guess {
    private int userNum;
    private int answer;
    private final Scanner scanner = super.scanner;
    private final Random random = super.random;
    public GuessNumber() {
        super();
        System.out.println("Instructions:\n" +
                " 1. Guess the number based on the given range.\n" +
                " 2. You are allowed to make one guess at a time.\n" +
                " 3. Difficulty will detrmines the chances & the Hints.\n" +
                " 4. If you use your Chances, you lose the game.");
               
        delay(4000);
           }

    public int getUserNum() {
        return userNum;
    }

    public void setUserNum(int userNum) {
        this.userNum = userNum;
    }

    public int getAnswer() {
        return answer;
    }

    public void setAnswer(int answer) {
        this.answer = answer;
    }

    public int getChances() {
        return chances;
    }

    public void setChances(int chances) {
        this.chances = chances;
    }
    @Override
    public void difficultyLevel() {
        numberPlayed=true;
        while (Main.exit) {
            System.out.print("""
            Start Menu 
            ---------- 
            Select a difficulty level 
            1. Easy 
            2. Medium 
            3. Hard 
            4. Return to main menu 
            ===> 
            """);

            int choice = 0;
            try {
                choice = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Please enter a number.");
                continue;
            }

            if (choice == 1) {
                setChances(5);
                alphanumeric (15, "1-15");

            } else if (choice == 2) {
                setChances(4);
                alphanumeric (20, "1-20");

            } else if (choice == 3) {
                setChances(3);
                alphanumeric (40, "1-40");
            } else if (choice == 4) {
                Main.star();
            } else {
                System.out.println("Invalid choice. Please select a valid option.");
            }

            // consume the newline character
            scanner.nextLine();
        }
    }


    @Override
    public void alphanumeric (int range, String b) {

        setAnswer(random.nextInt(range) + 1);
        int score = 0;
        int tries = 0;
        boolean win = false;
        
        System.out.println("Guess the number between " + b);
        while (tries < getChances()) {
            System.out.println("tries left --> "+((tries-chances)*-1));
            try {
                setUserNum(scanner.nextInt());
            } catch (Exception e) {
                System.out.println("\"Non-Number character entered!\"");
                break;
            }


            if (getUserNum() == getAnswer()) {
                win = true;
                score += 10 - tries;
                break;
            }else if (range!=20) {
                if (getUserNum() < getAnswer()) {
                    System.out.println("Too low! Try again.");
                } else if (getUserNum() > getAnswer()) {
                    System.out.println("Too high! Try again.");
                }
            }
            tries++;
        }
        if (win) {
            System.out.println("Congratulations, you win!");
            System.out.println("You guessed the number in " + (tries + 1) + " attempts.");
        } else {
            System.out.println("Sorry, you lost!");
            System.out.println("The secret number was " + getAnswer());
        }
        Main.numberChances=tries+1;
        Main.numberScores += score;
        delay(4000);
    }
}
