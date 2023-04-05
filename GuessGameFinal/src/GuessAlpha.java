import java.util.Random;
import java.util.Scanner;

public class GuessAlpha extends Guess {
    private char userAlpha;
    private char answer=(char) getAnswer();
    private final Scanner scanner = super.scanner;
    private final Random random = super.random;
    String vowelsSound;
    String consonantVowels;
    public GuessAlpha() {
        super();
        System.out.println("""
                Instructions:
                 1. Guess the alphabet based on the given range.
                 2. You are allowed to make one guess at a time.
                 3. Each game has 5 chances to guess the correct alphabet.
                 4. If you use your Chances, you lose the game.""");
        delay(4000);
    }

    public char getUserAlpha() {
        return userAlpha;
    }

    public void setUserAlpha(char userAlpha) {
        this.userAlpha = userAlpha;
    }

    public char getAnswer() {
        return answer;
    }

    public void setAnswer(char answer) {
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
        alphabetPlayed=true;
        while (Main.exit) {
            System.out.println("""
                    Start Menu 
                    ---------- 
                    Select a difficulty level 
                    1. Easy 
                    2. Medium 
                    3. Hard 
                    4. Return to main menu 
                    ===>
                    """);
            int choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    setChances(2);
                    vowelsSound = "aeiou";

                    alphanumeric (vowelsSound.length(), "Guess the vowel alphabet.");
                    break;
                case 2:
                    setChances(4);
                    consonantVowels ="bcdfghjklmnpqrstvwxyz";
                    alphanumeric (consonantVowels.length(), "Guess the consonant alphabet");
                    break;
                case 3:
                    setChances(5);
                    alphanumeric (26, "Guess the alphabet");
                    break;
                case 4:
                    Main.star();
                    break;
                default:
                    System.out.println("Invalid choice, please try again.");
                    break;
            }
        }
    }
    @Override
    public void alphanumeric (int length, String b) {
        switch (length){
            case 5->{setAnswer(vowelsSound.charAt(random.nextInt(length)));}
            case 21->{setAnswer(consonantVowels.charAt(random.nextInt(length)));}
            case 26->{ setAnswer((char) (random.nextInt(length) + 'a'));}
        }

        int score = 0;
        int tries = 0;
        boolean win = false;
        System.out.println("Guess the Alphabet! " + b);
        while (tries < chances) {
            System.out.println("tries left --> "+((tries-chances)*-1));

            setUserAlpha(scanner.next().charAt(0));
            if (!Character.isLetter(getUserAlpha())) {
                System.out.println("Non-alphabetic character entered!");
                break;
            }

            if (getUserAlpha() == getAnswer()) {
                win = true;
                score = 10 - tries;
                break;
            } else if (getUserAlpha() < getAnswer()) {
                System.out.println("Too close! Try again.");
            } else {
                System.out.println("Too far! Try again.");
            }
            tries++;
        }
        if (win) {
            System.out.println("Congratulations, you win!");
            System.out.println("You guessed the alphabet in " + (tries + 1) + " attempts.");
        } else {
            System.out.println("Sorry, you lost!");
            System.out.println("The secret alphabet was " + getAnswer());
        }
        Main.alphabetChances=tries+1;
        Main.alphabetScores += score;
        delay(4000);
    }
}
