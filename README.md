# Quiz Game Project

## Introduction
This project is a **C++-based interactive quiz game** that allows users to log in, select a programming language, attempt quizzes, and view past scores. The system includes user authentication, quiz selection, and a leaderboard feature to track scores.

## Features
- **User Authentication:** Users can sign up and log in with a username and password.
- **Multiple Programming Languages:** Choose from C++, Java, Python, MERN, and C.
- **Quiz System:** Each language has multiple quizzes to attempt.
- **Leaderboard:** Users can view past scores.
- **Logout System:** Users can safely log out after playing quizzes.

## Installation
### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- Command-line terminal

### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/quiz-game.git
   ```
2. Navigate to the project directory:
   ```bash
   cd quiz-game
   ```
3. Compile the code using a C++ compiler:
   ```bash
   g++ -o quiz_game main.cpp -std=c++11
   ```
4. Run the executable:
   ```bash
   ./quiz_game
   ```

## How to Use
1. Run the program and choose **Login** or **Signup**.
2. Select a programming language from the menu.
3. Pick a quiz and start answering the questions.
4. View your past scores in the **Leaderboard**.
5. Logout when finished.

## File Structure
```
quiz-game/
│── main.cpp         # Core logic of the quiz game
│── users.txt        # Stores user credentials
│── leaderboard.txt  # Stores user scores
```

## Future Enhancements
- Add more programming languages and quizzes.
- Implement a **time limit** for answering questions.
- Improve UI with a **graphical interface**.

## License
This project is licensed under the **MIT License**.
