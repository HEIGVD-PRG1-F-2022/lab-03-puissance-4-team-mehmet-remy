#include <iostream>
#include <vector>

using namespace std;


void afficher(vector<vector<int>> tableau){
    for (int i = tableau[0].size()-1; i >= 0; i--) { // dim Y
        for (int j = 0; j < tableau.size(); j++) {// dim X
            if(tableau[j][i] == 1){
                cout << "x";
            }else if(tableau[j][i] == 2) {
                cout << "O";
            }else{
                cout << ".";
            }
        }
        cout << endl;
    }
}

bool PlayerWin(vector<vector<int>> tableau, int x, int y, int player){ // retourne le numero du joueur gagnant ou 0 si non

    int fourToWin = 0;
    for (int i = 0; i < tableau[0].size(); ++i) { // boucle y
        if(tableau[x][i] == player){
            fourToWin++;
            if(fourToWin == 4){
                return true; //gagner
            }
        }else{
            fourToWin = 0;
        }
    }
    fourToWin = 0;

    for (int i = 0; i < tableau.size(); ++i) { // boucle x

        if(tableau[i][y] == player){
            fourToWin++;
            if(fourToWin == 4){
                return true; //gagner
            }
        }else{
            fourToWin = 0;
        }
    }

    return false;
}

bool addChoice(vector<vector<int>> &tableau, int player, string playerChoice ){

    try {
        int answerCase = stoi(playerChoice);


        if(answerCase > tableau.size()){
            return false;
        }
        for(int i = 0; i < tableau[0].size(); i++) { // Y
            cout << tableau[answerCase][i];
            if(tableau[answerCase][i] == 0){
                tableau[answerCase][i] = player;
                cout << "case : x " << answerCase << " y : " << i << "\n" ;
                return true;
            }
        }
        return false;
    } catch (const std::exception& e) {
        return false;
    }


}


int main(){
    string answerPlayer, playerChoice;
    vector<vector<int>> tableau(6, vector<int>(7, 0));
    int player;
    int nombreDeCaseRestant = (tableau.size() + 1) * (tableau[0].size() + 1);
    cout  << "  PUISSANCE 4\n"
             "Play 2 player: p \n"
             "exit : x\n";

    while (answerPlayer != "x") {
        if(answerPlayer == "p"){

            if(nombreDeCaseRestant % 2 == 0){
                player = 1;
            }else{
                player = 2;
            }
            afficher(tableau);
            cin >> playerChoice;

            if(addChoice(tableau,player,playerChoice)){
                nombreDeCaseRestant--;
            }else{
                cout << "case incorecte \n";
            }


        }else{
            cin >> answerPlayer;
        }
    }
}