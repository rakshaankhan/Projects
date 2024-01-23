import java.util.Scanner;
import java.util.Random;

public class NumberGuessingGame {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        int upperBound = 100; 
        int numberToGuess = random.nextInt(upperBound) + 1;
        int maxTries = 5; 
        int numberOfTries = 0;

        System.out.println("Welcome to the Number Guessing Game!");
        System.out.println("Guess a number between 1 and " + upperBound);
        System.out.println("You have " + maxTries + " attempts to guess the right number.");

        while (numberOfTries < maxTries) {
            System.out.print("Enter your guess (" + (maxTries - numberOfTries) + " tries left): ");
            int userGuess = scanner.nextInt();
            numberOfTries++;

            if (userGuess < 1 || userGuess > upperBound) {
                System.out.println("Invalid guess. Please try a number between 1 and " + upperBound + ".");
            } else if (userGuess < numberToGuess) {
                System.out.println("Too low! Try again.");
            } else if (userGuess > numberToGuess) {
                System.out.println("Too high! Try again.");
            } else {
                System.out.println("Congratulations! You guessed the number in " + numberOfTries + " tries.");
                break;
            }
        }

        if (numberOfTries == maxTries) {
            System.out.println("Sorry, you've run out of tries. The correct number was " + numberToGuess + ".");
        }

        scanner.close();
    }
}
