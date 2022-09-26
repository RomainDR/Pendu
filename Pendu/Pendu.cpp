#include <string>
#include <iostream>
using namespace std;

#pragma region variables
string wordGuest;
string letterFind;
int maxAttempt = 10;
bool wordFind = false;

#pragma endregion


/// <summary>
/// Set the guess word with verification of illegal caracters.
/// </summary>
void SetWordGuest() {
    string _temp;
    cout << "Ecrire le mot à deviner: ";
    cin >> _temp;
    for (int i = 0; i < _temp.length(); i++) {
        if ((_temp[i] >= 65 && _temp[i] <= 90) || (_temp[i] >= 97 && _temp[i] <= 122)) {
            _temp[i] = tolower(_temp[i]);
            letterFind += "-";
        }
        else {
            cout << "Vous avez saisir des caracteres speciaux. Merci de recommencer." << endl;
            SetWordGuest();
        }
    }
    wordGuest = _temp;
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
        for (int i = 0; i < _word.length(); i++) {
            if ((_word[i] >= 65 && _word[i] <= 90) || (_word[i] >= 97 && _word[i] <= 122))
                _word[i] = tolower(_word[i]);
            else {
                cout << "Vous avez saisir des caracteres speciaux. Merci de recommencer." << endl;
                maxAttempt = _maxAttempt;
                Game();
            }
        }

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