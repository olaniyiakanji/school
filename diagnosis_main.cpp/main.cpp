#include "auxilliary.cpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::string;
using std::vector;

// primary functions
void guessvalue(int *score);
void guessalpha(int *score);

int main() {
  for (int i = 0; i < 10; i++) {
    cout << random() % 10;
  }
  int score = 0;
  int run = 1;
  while (run) {
    string _p =
        "Welcome to the Guessing Game!\n1. Guess the Number.\n2. Guess the "
        "Alphabet\n3. My Score.\n4. Credit.\n5. Exit\nChoose an option "
        "please!:\n";
    int whichgame = prompti(_p);

    switch (whichgame) {
    case 1:
      // go to the next point of control
      guessvalue(&score);
      break;

    case 2:

      guessalpha(&score);
      break;

    case 3:

      cout << "Your total score is " << score << "\n";
      break;

    case 4:
      cout << "this game was created by a wonderful team... kudos to all team "
              "members";
      break;

    case 5:
      run = 0;
      break;
    };
  };
  return 0;
}

/*
 * difficultyAndInstruction - an helper function that helps so that
 * difficulty level and the _prompt is prompted
 *
 * @difficulty: int*
 * @_prompt: string
 *
 * Return: void
 */
void difficultyAndInstruction(int *difficulty, string _prompt) {
  string _p = "Start Menu\n----------\nSelect a difficulty level\n1. Easy\n2. "
              "Medium\n3. Hard\n4. Return to main menu\n===>\n";
  int diff = prompti(_p);
  cout << _prompt;

  *difficulty = diff;
}

/*
 *
 * doYouWantToContinue - Does a very simple thing.
 * prompts the user if he wants to continue or not
 *
 * Return: void
 */
void doYouWantToContinue() {
  string prompt = "Do you want to continue? (yes/no) -->";
  string answer = prompts(prompt);

  while (!(answer == "yes" || answer == "no" || answer == ""))
    answer = prompts(prompt);

  if (answer == "yes")
    return;
  else
    exit(0);
}

/*
 * guessvalue - The guessing number mechanism of the game
 *
 * @difficulty: (int), the difficulty of the number
 * guessing game
 *
 * Documentation - the guessvalue function runs the game
 * independent of any other function in the namespace,
 * it's isolated. It contains a while loop to continue
 * running the game in case game requirements haven't been
 * fulfilled.
 */
void guessvalue(int *score) {
  int difficulty;
  string instruction;
  string instructionPrompt =
      "Instructions:\n1. Guess the alphabet based on the given "
      "range.\n2. You are allowed to make one guess at a time.\n3. "
      "Each game has 5 chances to guess the correct alphabet.\n4. If "
      "you use your Chances, you lose the game.\n";
  difficultyAndInstruction(&difficulty, instructionPrompt);
  int x, guess, trial = 1;
  string display;
  switch (difficulty) {
  case 1:
    display = "guess a random number between 1 and 10\n";
    x = 10;
    break;
  case 2:
    display = "guess a random between 1 and 25\n";
    x = 25;
    break;
  case 3:
    display = "guess a random number between 1 and 40\n";
    x = 40;
  case 4:
    cout << "To main menu\n" << endl;
    return;
  }

  int randomnum = rand() % x + 1;
  while (trial <= 5) {
    cout << display;
    cin >> guess;
    cout << "you have " << trial++ << " trials left. \n";
    if (randomnum == guess) {
      cout << "congratulations, you guessed right in the " << trial
           << " trials\n"
           << endl;
      *score += 10;
      break;

    } else {
      if (trial == 5)
        break;
      else if (guess < randomnum)
        cout << "too small." << endl;
      else
        cout << "too big" << endl;
    }
  }
  cout << "game end!" << endl;
  cout << "Your score is " << *score << endl;
  doYouWantToContinue();
}

void guessOp(string, int, string, int *);

void guessalpha(int *score) {
  string answer;
  string solutionSet;
  string prompt;
  vector<int> options = {5, 21, 26};
  int difficulty;
  string instruction;

  // Start game;
  cout << "Guess the Alphabet:" << endl;

  string _prompt =
      "Instructions:\n1. Guess the number based on the given "
      "range.\n2. You are allowed to make one guess at a time.\n3. "
      "You have 5 chances to guess the correct number.\n4. If "
      "you use your chances, you lose the game.\n";
OPTIONS_PLACE:
  difficultyAndInstruction(&difficulty, _prompt);

  switch (difficulty) {
  case 5:
    solutionSet = "aeiou";
    prompt = "Guess the vowel `aeiou`: ";
    break;

  case 21:
    solutionSet = "bcdfghjklmnpqrstvwxyz";
    solutionSet.append("BCDFHGJKLMNPQRSTVWXYZ");
    prompt = "Guess the Consonant character: ";
    break;

  case 26:
    solutionSet = "abcdefghijklmnopqrstuvwxyz\n"
                  "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
    prompt = "Guess the alphabet characters: ";
    break;

  case 4:
    cout << "To main menu\n" << endl;
    return;
  }
  if (find(options.begin(), options.end(), difficulty) != options.end()) {
    guessOp(prompt, difficulty, solutionSet, score);
  } else {
    cout << endl;
    cout << "You chose the wrong option, choose 5, 21 or 26" << endl;
    cout << "choose again!\n" << endl;
    goto OPTIONS_PLACE;
  }

  doYouWantToContinue();
}

void guessOp(string promptValue, int value, string solutionSet, int *score) {
  int lives = 5;
  int randomIndex = random() % value + 1;
  char answer = solutionSet.at(randomIndex);
  char left = 'a', right = 'z';

  while (lives > 0) {
    char c = prompts(promptValue).at(0);
    cout << "left: " << left << endl;
    cout << "right:" << right << endl;
    if (c == answer) {
      *score += 10;
      cout << "You have " << *score << " points" << endl;
      cout << "you are a genius, congratulations! guessed with " << lives
           << " live(s)" << endl;
      break;
    } else {
      if (c < answer) {
        if (c > left)
          left = c;
        cout << "Wrong. the answer is in the range [" << left << "-" << right
             << "]" << endl;
      } else {
        if (c < right)
          right = c;
        cout << "Wrong. the answer is in the range [" << left << "-" << right
             << "]" << endl;
      }
      cout << "Try again!" << endl;
      --lives;
    }
  }
  cout << "game end" << endl;
  cout << "Your score is " << *score << endl;
}
