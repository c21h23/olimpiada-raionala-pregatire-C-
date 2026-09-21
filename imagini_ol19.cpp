/*
problema:
https://aee.edu.md/sites/default/files/ol19_info_z_01_cl_10_ro.pdf
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

void BFS(int p, int q, int n, int m, vector<vector<int>>& matrice, int k) {
    vector<vector<bool>> vizitat(n, vector<bool> (m, false));
    queue<pair<int, int>> ordine;
    vizitat[p][q] = true;
    ordine.push({p, q});
    int directii[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    pair<int, int> celCurent;
    while(!ordine.empty()) {
        celCurent = ordine.front();
        ordine.pop();
        for(int i = 0; i < 4; i++) {
            int randNou = celCurent.first + directii[i][0];
            int colNou = celCurent.second + directii[i][1];
            if (
                randNou >= 0 and
                colNou >= 0 and
                randNou < n and
                colNou < m and
                vizitat[randNou][colNou] == false and
                matrice[randNou][colNou] == matrice[p][q]            
            ) {
                vizitat[randNou][colNou] = true;
                ordine.push({randNou, colNou});
                matrice[randNou][colNou] = k;
            }
        }
    }
    matrice[p][q] = k;
}

int main() {

    cout << "introdu dimensiunile imaginii: " << endl;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrice(n, vector<int>(m));

    cout << "introdu imaginea: " << endl;

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> matrice[i][k];
        }
    }

    cout << "introdu coordonatele aplicarii instruemntului: " << endl;
    int p, q;
    cin >> p >> q;

    cout << "introdu culoarea instrumentului: " << endl;
    int k;
    cin >> k;

    BFS(p - 1, q - 1, n, m, matrice, k);

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cout << matrice[i][k] << " ";
        }
        cout << '\n';
    }

    return 0;
}

/*

exemplu de input:

7 8

1 1 0 0 0 2 2 2
1 0 0 1 0 2 0 2
1 1 0 1 0 2 2 2
0 0 0 1 1 0 0 0
3 3 0 1 0 1 1 0
3 0 0 1 0 1 0 0
3 3 3 0 0 1 1 1

2 2

*/
