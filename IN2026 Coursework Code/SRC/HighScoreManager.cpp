#include "HighScoreManager.h"
#include <algorithm> 

HighScoreManager::HighScoreManager(size_t maxScores)
    : maxScores(maxScores) {}

void HighScoreManager::AddScore(int score) {
    if (highScores.size() < maxScores) {
        highScores.push_back(score);
        std::sort(highScores.begin(), highScores.end(), std::greater<int>());
    }
    else if (score > highScores.back()) {
        highScores.back() = score;
        std::sort(highScores.begin(), highScores.end(), std::greater<int>());
    }
}

std::vector<int> HighScoreManager::GetHighScores() const {
    return highScores;
}
