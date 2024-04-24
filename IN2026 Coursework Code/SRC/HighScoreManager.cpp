#include "HighScoreManager.h"
#include <fstream>
#include <algorithm>
#include <iostream>

// Constructor
HighScoreManager::HighScoreManager(const std::string& fname) : filename(fname) {
    LoadHighScores();
}

// Destructor
HighScoreManager::~HighScoreManager() {
    SaveHighScores();
}

// Load high scores from a file
void HighScoreManager::LoadHighScores() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for reading: " << filename << std::endl;
        return;
    }

    highScores.clear();
    int score;
    while (file >> score) {
        highScores.push_back(score);
    }
    file.close();
    std::sort(highScores.rbegin(), highScores.rend()); // Sort in descending order
}

// Save high scores to a file
void HighScoreManager::SaveHighScores() {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    for (int score : highScores) {
        file << score << std::endl;
    }
    file.close();
}

// Update high scores with a new score
void HighScoreManager::UpdateHighScores(int newScore) {
    highScores.push_back(newScore);
    std::sort(highScores.rbegin(), highScores.rend());
    if (highScores.size() > 10) highScores.resize(10); // Keep only top 10 scores
}

// Display high scores
void HighScoreManager::DisplayHighScores() {
    std::cout << "High Scores:" << std::endl;
    for (int score : highScores) {
        std::cout << score << std::endl;
    }
}
