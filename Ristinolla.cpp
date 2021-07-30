#include <iostream>
#include <string>

using namespace std;

char ruudut[9];
int voitto;

void tulostaRuudukko(){
    cout << "\n\n"; 
    cout << " " << ruudut[1] << " | " << ruudut[2] << " | " << ruudut[3] << endl;
    cout << "-----------" << endl;
    cout << " " << ruudut[4] << " | " << ruudut[5] << " | " << ruudut[6] << endl;
    cout << "-----------" << endl;
    cout << " " << ruudut[7] << " | " << ruudut[8] << " | " << ruudut[9] << endl;
    cout << "\n\n";
}

int tarkistaVoitto(int vro){
    if((ruudut[1] == ruudut[2] && ruudut[2] == ruudut[3]) || (ruudut[4] == ruudut[5] && ruudut[5] == ruudut[6]) || (ruudut[7] == ruudut[8] && ruudut[8] == ruudut[9]) || (ruudut[1] == ruudut[4] && ruudut[4] == ruudut[7]) || (ruudut[2] == ruudut[5] && ruudut[5] == ruudut[8]) || (ruudut[3] == ruudut[6] && ruudut[6] == ruudut[9]) || (ruudut[1] == ruudut[5] && ruudut[5] == ruudut[9]) || (ruudut[3] == ruudut[5] && ruudut[5] == ruudut[7])){
        if(vro == 1){
            voitto = 1;
            vro = 0;
        }

        if(vro == 2){
            voitto = 2;
            vro = 0;
        }
        return vro;
    }

    else if(ruudut[1] != '1' && ruudut[2] != '2' && ruudut[3] != '3' && ruudut[4] != '4' && ruudut[5] != '5' && ruudut[6] != '6' && ruudut[7] != '7' && ruudut[8] != '8' && ruudut[9] != '9'){
        voitto = 3;
        vro = 0;
        return vro;
    }

    else{
        if(vro == 1){
            vro = 2;
        }

        else if(vro == 2){
            vro = 1;
        }
    }

    return vro;
}

int tarkistaRuutu(int truutu, int vro, char merkki){
    if(vro == 1){
        if(truutu < 10 && truutu > 0){
            if(ruudut[truutu] != 'X' && ruudut[truutu] != '0'){
                ruudut[truutu] = merkki;
                vro = tarkistaVoitto(vro);
                return vro;
            }
            else{
                cout << "Ruutu on jo t\x84ynn\x84." << endl;
                return vro;
            }
        }
        
        else {
            cout << "Ruutua ei ole olemassa.";
            return vro;
        }
    }

    if(vro == 2){
        if(truutu < 10 && truutu > 0){
            if(ruudut[truutu] != 'X' && ruudut[truutu] != '0'){
                ruudut[truutu] = merkki;
                vro = tarkistaVoitto(vro);
                return vro;
            }
            else{
                cout << "Ruutu on jo t\x84ynn\x84." << endl;
                return vro;
            }
        }
        else{
            cout << "Ruutua ei ole olemassa.";
            return vro;
        }
    }
    
    return vro;
}

int peli(int up){
    string py;  //Pelaajan 2 nimi//
    string pk;  //Pelaajan 1 nimi//
    int pr;  //Ruutu johon pelataan//
    char pmy; //Pelaajan 1 pelimerkki//
    char pmk; //Pelaajan 2 pelimerkki//
    int vuoro = 0;
    voitto = 0;
    cout << "----------\n\nPelaaja 1 sy\x94t\x84 nimesi: " << endl;
    cin >> py;
    
    while(vuoro == 0){
        cout << "\nPelaaja 1 valitse pelimerkkisi (X tai 0): " << endl;
        cin >> pmy;
    
        if (pmy == 'X' || pmy == 'x'){
            pmy = 'X';
            pmk = '0';
            vuoro = 1;
        }
        else if(pmy == '0' || pmy == 'o' || pmy == 'O'){
            pmy = '0';
            pmk = 'X';
            vuoro = 2;
        }
        else{
            cout << "Virheellinen sy\x94te!" << endl;
        }
    }
    
    cout << "\nPelaaja 2 sy\x94t\x84 nimesi: " << endl;
    cin >> pk;
    
    while(voitto == 0){
        if(vuoro == 1){
            tulostaRuudukko();
            cout << "Vuorossa: " << py << endl;
            cout << "Valitse ruutu: " << endl;
            cin >> pr;
            vuoro = tarkistaRuutu(pr, vuoro, pmy);
        }
    
        if(vuoro == 2){
            tulostaRuudukko();
            cout << "Vuorossa: " << pk << endl;
            cout << "Valitse ruutu: " << endl;
            cin >> pr;
            vuoro = tarkistaRuutu(pr, vuoro, pmk);
       }
    }

    if(voitto == 1){
        cout << py << " voitti!" << endl;
    }
    else if(voitto == 2){
        cout << pk << " voitti!" << endl;
    }
    else if(voitto == 3){
        cout << "Tasapeli!" << endl;
    }
    else{
        cout << "Tapahtui virhe..." << endl;
    }

    char yn;

    while(up == 1){
        cout << "Haluatko pelata uuden pelin? Y/N" << endl;
        cin >> yn;

        if(yn == 'y' || yn == 'Y'){
            up = 0;
        }
        else if(yn == 'n' || yn == 'N'){
            up = 2;
        }
        else{
            cout << "Virheellinen sy\x94te! Kokeillaan uudestaan." << endl;
        }
    }

    return up;
}

int main()
{
    int uusipeli = 0;

    while(uusipeli == 0){
        uusipeli = 1;
        ruudut[1] = '1';
        ruudut[2] = '2';
        ruudut[3] = '3';
        ruudut[4] = '4';
        ruudut[5] = '5';
        ruudut[6] = '6';
        ruudut[7] = '7';
        ruudut[8] = '8';
        ruudut[9] = '9';
        cout << "Ristinolla" << endl;
        uusipeli = peli(uusipeli);
    }

    return 0;
}