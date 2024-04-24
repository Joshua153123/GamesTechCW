#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H

#include <vector>
#include <string>

class HighScoreManager {
private:
    std::vector<int> highScores; // Vector to store high scores
    std::string filename; // File to load/save high scores

    void LoadHighScores(); // Method to load high scores from a file
    void SaveHighScores(); // Method to save high scores to a file

public:
    HighScoreManager(const std::string& fname); // Constructor
    ~HighScoreManager(); // Destructor

    void UpdateHighScores(int newScore); // Update high scores with a new score
    void DisplayHighScores(); // Display high scores (for debugging or direct display)
};

#endif // HIGHSCOREMANAGER_H
