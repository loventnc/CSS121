#include <iostream>
#include <list>

using namespace std;

struct PlayerScore 
{
    string name;
    int score;

    bool operator<(const PlayerScore &other) const 
    {
        return score > other.score;
    }
};

class ScoreBoard {
    private:
        list <PlayerScore> scores;
        
    public:
        void addScore(string name, int score) 
        {
            for (auto &playerScore : scores) 
            {
                if (playerScore.name == name) 
                {
                    if (score > playerScore.score) 
                    {
                        playerScore.score = score;
                    }
                    scores.sort();
                    return;
                }
            }
            scores.emplace_back(PlayerScore{name, score});
            scores.sort();
            while (scores.size() > 4) {
                scores.pop_back();
            }
        }
        
        void printScores() const {
            cout << "Score Board:" << std::endl;
            int number = 1;
            for (const auto &playerScore : scores) {
                cout << number << " : " << playerScore.name << " = " << playerScore.score << std::endl;
                number++;
            }
        }
};

int main()
{
    ScoreBoard scoreBoard;
    // declare variables
    std::string name;
    int score;
    int n = 4;
    // input
    for (int i = 0; i < n; i++)
    {
        cout << "Name " << i+1 << ": ";
        cin >> name;
        cout << "Score : ";
        cin >> score;
        scoreBoard.addScore(name, score);
    }
    scoreBoard.printScores();

    char addMore;
    cout << "add scores? (y/n) ";
    cin >> addMore;
    int i = n + 1;
    while (addMore == 'y')
    {
        cout << "Name " << i << ": ";
        cin >> name;
        cout << "Score : ";
        cin >> score;
        scoreBoard.addScore(name, score);
        scoreBoard.printScores();
        cout << "add score? (y/n) : ";
        cin >> addMore;
        i++;
    }
}
