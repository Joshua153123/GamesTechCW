#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H

#include <vector>

class HighScoreManager {
private:
    std::vector<int> highScores;
    size_t maxScores;

public:
    HighScoreManager(size_t maxScores = 5); // Constructor with default maximum score count
    void AddScore(int score);
    std::vector<int> GetHighScores() const;
};

#endif // HIGHSCOREMANAGER_H
