#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// fonction de mélange de mot
string melange(string mot1){
    string mot2;
    int pos;
    while (mot1.size()!=0)
    {
        pos = rand()%mot1.size();
        mot2.push_back(mot1[pos]);
        mot1.erase(pos,1);
    }
 
    return mot2;
}

// fonvtion pour sauter des lignes et masquer le mot
void saut (int nb){
    for (int i = 0; i < nb; i++)
    {
        cout << endl ;
    }
    
}

// fonction pour la partie du jeu où devine le mot

int devineMot(string motMelange, string motEntre){

    string reponse;
    int exit = 0;
    int essaie(5);

    cout << "Joueur 2: Quel est ce mot ? " << motMelange << endl ;
    cout << "vous avez : " << essaie << " essaies"<< endl ;
    cin >> reponse ;
    cout << endl;


    do
    {
        
        if (reponse.compare(motEntre)!=0 )
        {
            essaie--;
            cout << "Ce n'est pas le bon mot !" << endl;
            cout << "il vous reste : " << essaie << " essaies \n" ;
            cout << endl;
            cout << "Joueur 2: Quel est ce mot ? " << motMelange << endl ;
            cin >> reponse ;
            cout << endl;
            

        }
        if (reponse.compare(motEntre)==0)
        {
            exit = 1 ;
        }
        else if (essaie == 0)
        {
            exit = 2 ;
        }
        
    } while (exit == 0);

    return exit ;
    
   
}

//Game : fonction qui prend en compte la partie jeu 

char game(){

    string motEntre;
    string motMelange;
    

    saut(10);
    cout << "GAME" << endl ;
    cout << "Joueur 1 : saisissez un mot :" << endl ;

    cin >> motEntre ;
    saut(10);
    motMelange = melange(motEntre); 
    
    int tentative = devineMot(motMelange, motEntre) ;

    if (tentative == 1){
        saut(4);
        cout << "bravo ! Vous  avez réussi à trouver le bon mot" << endl;
        saut(4);
    }
    else if ( tentative == 2)
    {
        saut(4);
        cout << "Perdu ! la solution etait :" << motEntre << " !" << endl;
        saut(4);
    }
    

    int exit = 0;
    string question ;
    char val;
    do{

        cout << "Voulez-vous rejouer ? [o/n] \n" ;
        cin >> question ;
        if (question == "o"){
            val = 'o';
            exit = 1;
        }
        else if (question.compare("n") == 0){
            val = 'n';
            exit = 1 ;
        }
    }while( exit = 0);

    return val ;
    
}

// Main
int main()
{
    srand(time(0));
    char value = 'o';
    do
    {
        value = game();
    } while (value == 'o');
        
    return 0;
}
