#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) {
    std::cout << "\n\nYou are a secret agent breaking into a secure server room with Difficulty Level " << Difficulty << "!!";
    std::cout << std::endl;
    std::cout << "You need to Enter the correct code to continue..." << std::endl;
}

bool PlayGame(int Difficulty) {

    PrintIntroduction(Difficulty);

    int CodeA = rand() % (Difficulty + 1) + Difficulty;
    int CodeB = rand() % (Difficulty + 1) + Difficulty;
    int CodeC = rand() % (Difficulty + 1) + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code." << std::endl;
    std::cout << "+ The numbers add up to give: " << CodeSum << std::endl;
    std::cout << "+ And the numbers multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "You have made a correct code guess!" << std::endl;
        if (Difficulty < 6)
        {
            std::cout << "Lets Move On to next Phase!\n" << std::endl;
        }
        else
        {
            std::cout << "Good Work!\nYou have Penetrated the Server\nNow Copy all the files and get out fast\nbefore anyone sees you!\n" << std::endl;
        }
        return true;
    }
    else {
        std::cout << "Your guess was wrong!" << std::endl;
        if (Difficulty < 6)
        {
            std::cout << "You need to Retry to progress to Level-" << Difficulty + 1 << std::endl;
        }
        else
        {
            std::cout << "You need to Retry to Successfully Penetrate the server!" << std::endl;
        }

        return false;
    }
}

int main() {
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 6;
    while (LevelDifficulty <= MaxDifficulty) {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }

    }
    return 0;
}