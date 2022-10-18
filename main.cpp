#include <iostream>
#include <vector>

using namespace std;


void afficher(vector<vector<int>> tableau){
    for (int i = 0; i < tableau.size(); i++) {
        for (int j = 0; j < tableau[0].size(); j++) {// dimension y du tableau
            if(tableau[i][j] == 1){
                cout << "x";
            }else if(tableau[i][j] == 1) {
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


int main(){
    string answerPlayer;
    vector<vector<int>> tableau(4, vector<int>(4, 0));

    tableau[0][0] = 1;
    tableau[1][0] = 1;
    tableau[2][0] = 1;
    tableau[3][0] = 1;


    if(PlayerWin(tableau,0,0,1)){
        cout << "true";
    }else{
        cout << "false";
    }

    //afficher(tableau);
/*
    while (answerPlayer != "x") {
        cout  << "  PUISSANCE 4\n"
                 "Play 2 player: \n"
                 "exit : x\n";



        cin >> answerPlayer;

    }*/
}