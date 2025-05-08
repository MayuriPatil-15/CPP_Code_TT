#include <iostream>

using namespace std;

class BowlingGame 
{
private:
    int iRolls[21]; // Maximum iRolls possible in a game
    int iCurrentRoll;

public:
    BowlingGame() : iCurrentRoll(0) 
	{
        for (int i = 0; i < 21; i++) 
		{
            iRolls[i] = 0;
        }
    }

    void Roll(int iPins) 
	{
        iRolls[iCurrentRoll++] = iPins;
    }

    int CalculateScore() {
        int iScore = 0;
        int iFrameIndex = 0;

        for (int iFrame = 0; iFrame < 10; iFrame++) 
		{
            if (iRolls[iFrameIndex] == 10) 
			{ 
				// Strike
                iScore += 10 + iRolls[iFrameIndex + 1] + iRolls[iFrameIndex + 2];
                iFrameIndex += 1;
            } 
			else if (iRolls[iFrameIndex] + iRolls[iFrameIndex + 1] == 10) 
			{ 
				// Spare
                iScore += 10 + iRolls[iFrameIndex + 2];
                iFrameIndex += 2;
            }
			else 
			{ 
				// Open iFrame
                iScore += iRolls[iFrameIndex] + iRolls[iFrameIndex + 1];
                iFrameIndex += 2;
            }
        }
        return iScore;
    }
};

int main(void) 
{
    BowlingGame game;
    int iRolls[] = {9, 1, 5, 5, 10, 3, 4, 7, 2, 6, 1, 10, 10, 9, 0}; // Example iRolls

    for (int i = 0; i < sizeof(iRolls) / sizeof(iRolls[0]); i++) 
	{
        game.Roll(iRolls[i]);
    }

    cout << "Total iScore: " << game.CalculateScore() << endl;

    return 0;
}
