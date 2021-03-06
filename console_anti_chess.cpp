# include <iostream>
# include <string>
# include <vector>
# include <map>

using namespace std;

char table[50][50];

// l == ladya
// k = kon
// s = slon
// f = ferz
// x = korol
// p = peshki

int main(){

    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            table[i][j] = ' ';
        }
    }

    table[1][1] = 'l';
    table[1][2] = 'k';
    table[1][3] = 's';
    table[1][4] = 'f';
    table[1][5] = 'x';
    table[1][6] = 's';
    table[1][7] = 'k';
    table[1][8] = 'l';

    table[2][1] = table[2][2] = table[2][3] = table[2][4] = table[2][5] = table[2][6] = table[2][7] = table[2][8] = 'p';



    table[8][1] = 'l';
    table[8][2] = 'k';
    table[8][3] = 's';
    table[8][4] = 'f';
    table[8][5] = 'x';
    table[8][6] = 's';
    table[8][7] = 'k';
    table[8][8] = 'l';

    table[7][1] = table[7][2] = table[7][3] = table[7][4] = table[7][5] = table[7][6] = table[7][7] = table[7][8] = 'p';


    int cnt1 = 16;
    int cnt2 = 16;

    int cur = 1;

    int hodwhite = 0;
    int hodblack = 0;

    int q;
    cin >> q;

    while(q--){
        cnt1 = 0;
        bool curhod = false;
        for(int i = 8; i >= 1; i--){
            for(int j = 1; j <= 8; j++){
                cout << table[i][j] << " ";
            }
            cout << "\n";
        }

        if(cur % 2 == 1){
            cout << "White's turn: ";
            curhod = true;
            hodwhite++;
        } else {
            cout << "Black's turn: ";
            hodblack++;
        }
        cur++;

        int fromx;
        char fromc;

        cin >> fromx >> fromc;

        int fromy = (fromc - 'a' + 1);

        char curfigure = table[fromx][fromy];

        if(curfigure == 'k'){
            if(table[fromx + 2][fromy + 1] == ' ' && fromx + 2 <= 8 && fromy + 1 <= 8){
                table[fromx + 2][fromy + 1] = '*';
            }
            if(table[fromx + 2][fromy - 1] == ' ' && fromx + 2 <= 8 && fromy - 1 >= 1){
                table[fromx + 2][fromy - 1] = '*';
            }
            if(table[fromx - 2][fromy - 1] == ' ' && fromx - 2 >= 1 && fromy - 1 >= 1){
                table[fromx - 2][fromy + 1] = '*';
            }
            if(table[fromx - 2][fromy + 1] == ' ' && fromx - 2 >= 8 && fromy + 1 <= 8){
                table[fromx - 2][fromy + 1] = '*';
            }
            if(table[fromx + 1][fromy - 2] == ' ' && fromx + 1 <= 8 && fromy - 2 >= 1){
                table[fromx + 1][fromy + 2] = '*';
            }
            if(table[fromx + 1][fromy + 2] == ' ' && fromx + 1 <= 8 && fromy + 2 <= 8){
                table[fromx + 1][fromy + 2] = '*';
            }
            if(table[fromx - 1][fromy + 2] == ' ' && fromx - 1 >= 1 && fromy + 2 <= 8){
                table[fromx - 1][fromy + 2] = '*';
            }
        } else if(curfigure == 'f'){
            for(int j = 1; j <= 8; j++){
                if(table[fromx][j] == ' '){
                    table[fromx][j] = '*';
                }
                if(table[j][fromy] == ' '){
                    table[j][fromy] = '*';
                }
            }
            for(int j = 1; j <= 8; j++){
                if(fromx + j <= 8 && fromy + j <= 8 && table[fromx + j][fromy + j] == ' '){
                    table[fromx + j][fromy + j] = '*';
                }
            }
            for(int j = 1; j <= 8; j++){
                if(fromx - j >= 1 && fromy - j >= 1 && table[fromx - j][fromy - j] == ' '){
                    table[fromx - j][fromy - j] = '*';
                }
            }

            for(int j = 1; j <= 8; j++){
                if(fromx - j >= 1 && fromy + j <= 8 && table[fromx - j][fromy + j] == ' '){
                    table[fromx - j][fromy + j] = '*';
                }
            }
            for(int j = 1; j <= 8; j++){
                if(fromx + j <= 8 && fromy - j >= 1 && table[fromx + j][fromy - j] == ' '){
                    table[fromx + j][fromy - j] = '*';
                }
            }

        } else if(curfigure == 's'){
            for(int j = 1; j <= 8; j++){
                if(fromx + j <= 8 && fromy + j <= 8 && table[fromx + j][fromy + j] == ' '){
                    table[fromx + j][fromy + j] = '*';
                }
            }
            for(int j = 1; j <= 8; j++){
                if(fromx - j >= 1 && fromy - j >= 1 && table[fromx - j][fromy - j] == ' '){
                    table[fromx - j][fromy - j] = '*';
                }
            }

            for(int j = 1; j <= 8; j++){
                if(fromx - j >= 1 && fromy + j <= 8 && table[fromx - j][fromy + j] == ' '){
                    table[fromx - j][fromy + j] = '*';
                }
            }
            for(int j = 1; j <= 8; j++){
                if(fromx + j <= 8 && fromy - j >= 1 && table[fromx + j][fromy - j] == ' '){
                    table[fromx + j][fromy - j] = '*';
                }
            }
        } else if(curfigure == 'l'){
            for(int j = 1; j <= 8; j++){
                if(table[fromx][j] == ' '){
                    table[fromx][j] = '*';
                }
                if(table[j][fromy] == ' '){
                    table[j][fromy] = '*';
                }
            }
        } else if(curfigure == 'x'){
            if(fromx - 1 >= 1 && table[fromx - 1][fromy] == ' '){
                table[fromx - 1][fromy] = '*';
            }
            if(fromx + 1 <= 8 && table[fromx + 1][fromy] == ' '){
                table[fromx + 1][fromy] = '*';
            }
            if(fromy + 1 <= 8 && table[fromx][fromy + 1] == ' '){
                table[fromx][fromy + 1] = '*';
            }
            if(fromy - 1 >= 1 && table[fromx][fromy - 1] == ' '){
                table[fromx][fromy - 1] = '*';
            }
            if(fromx - 1 >= 1 && fromy + 1 <= 8 && table[fromx - 1][fromy + 1] == ' '){
                table[fromx - 1][fromy + 1] = '*';
            }
            if(fromx - 1 >= 1 && fromy - 1 >= 1 && table[fromx - 1][fromy - 1] == ' '){
                table[fromx - 1][fromy - 1] = '*';
            }
            if(fromx + 1 <= 8 && fromy - 1 >= 1 && table[fromx + 1][fromy - 1] == ' '){
                table[fromx + 1][fromy - 1] = '*';
            }
            if(fromx + 1 <= 8 && fromy + 1 <= 8 && table[fromx + 1][fromy + 1] == ' '){
                table[fromx + 1][fromy + 1] = '*';
            }
        } else if(curfigure == 'p'){
            if(curhod == true && hodwhite == 1){
                if(fromx + 1 <= 8 && table[fromx + 1][fromy] == ' '){
                    table[fromx + 1][fromy] = '*';
                }
                if(fromx + 2 <= 8 && table[fromx + 2][fromy] == ' '){
                    table[fromx + 2][fromy] = '*';
                }
            } else if(curhod == false && hodblack == 1){
                if(fromx + 1 <= 8 && table[fromx + 1][fromy] == ' '){
                    table[fromx + 1][fromy] = '*';
                }
                if(fromx + 2 <= 8 && table[fromx + 2][fromy] == ' '){
                    table[fromx + 2][fromy] = '*';
                }
            } else {
                if(fromx + 1 <= 8 && table[fromx + 1][fromy] == ' '){
                    table[fromx + 1][fromy] = '*';
                }
            }
        }
        for(int i = 8; i >= 1; i--){
            for(int j = 1; j <= 8; j++){
                cout << table[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
