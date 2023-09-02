// GameString.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{
    // Заранее заданный массив слов
    string words[] = { "apple", "banana", "cherry", "grape", "orange", "strawberry" };
    int num_words = sizeof(words) / sizeof(words[0]);

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));

    // Выбираем случайное слово из массива
    string word_to_guess = words[rand() % num_words];

    // Максимальное количество попыток
    int max_attempts = 5;

    // Приветствие и правила игры
    cout << "Welcome to the game <<Guess the word>>!" << endl;
    cout << "The word you need to guess, consist of " << word_to_guess.length() << " letters." << endl;
    cout << "You have " << max_attempts << " tryes." << endl;

    int attempts = 0;
    bool guessed_word = false;

    while (attempts < max_attempts)
    {
        string player_guess;
        cout << "Enter your guess: ";
        cin >> player_guess;

        if (player_guess.length() != word_to_guess.length()) 
        {
            cout << "The world contains " << word_to_guess.length() << " letters." << endl;
            continue;
        }

        string correct_letters(word_to_guess.length(), '_');

        for (size_t i = 0; i < word_to_guess.length(); ++i)
        {
            if (player_guess[i] == word_to_guess[i]) 
            {
                correct_letters[i] = player_guess[i];
            }
        }

        bool all_correct = true;
        for (char letter : correct_letters)
        {
            if (letter == '_') 
            {
                all_correct = false;
                break;
            }
        }

        if (all_correct) 
        {
            guessed_word = true;
            break;
        }

        cout << "Correct letters: " << correct_letters << endl;

        attempts++;
    }

    if (guessed_word) 
    {
        cout << "Congratulation! You have guessed the word '" << word_to_guess << "'!" << endl;
    }
    else
    {
        cout << "Game over! You didnt guess the word. It was: '" << word_to_guess << "'." << endl;
    }

    return 0;
}
