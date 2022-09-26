#include <string>
#include <iostream>
using namespace std;

string wordGuest;
string letterFind;
int maxAttempt = 10;
bool wordFind = false;

void SetWordGuest() {
    cout << "Ecrire le mot à deviner: ";
    cin >> wordGuest;
    for (int i = 0; i < wordGuest.length(); i++) {
        wordGuest[i] = tolower(wordGuest[i]);
        letterFind += "-";
    }
}

string GetCorrectLetter(char _letter) {

    string _finder = letterFind;
    string _guess = wordGuest;

    for (int i = 0; i < _guess.length(); i++)
    {
        if (_guess[i] == _letter) {
            _finder[i] = _letter;
            maxAttempt++;
        }
    }
    letterFind = _finder;
    return _finder;
}

void Finish() {
    cout << "=========================" << endl
        << "Le mot était " << endl
        << wordGuest << endl
        << "=========================" << endl;
}

string GetWord() {
    return wordGuest;
}
void Game()
{
    string _word;
    for (int _maxAttempt = maxAttempt; _maxAttempt != 0 && !wordFind; _maxAttempt--) {
        cout << "Saisir une lettre ou un mot: ";
        cin >> _word;
        system("CLS");
        if (_word.length() == 1) {
            char _letter = _word[0];
            cout << "=========================" << endl
                << GetCorrectLetter(_letter) << endl
                << "Il reste encore " << _maxAttempt - 1 << " essaie à rater" << endl
                << "=========================" << endl;
            if (letterFind == wordGuest)  wordFind = true;
        }
        else {
            cout << "=========================" << endl
                << letterFind << endl
                << "Il reste encore " << _maxAttempt - 1 << " essaie à rater" << endl
                << "=========================" << endl;
            if (_word == wordGuest) wordFind = true;
        }
    }
    Finish();
    cout << "Fin de partie." << endl;
    if (wordFind) cout << "Bravo, tu as trouver le mot.";
    else cout << "Le mot était: " << GetWord();
}
int main()
{
    SetWordGuest();
    Game();
}