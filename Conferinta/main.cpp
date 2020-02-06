#include <iostream>
#include <stdlib.h>
#include "German.h"
#include "Francez.h"
#include "Roman.h"
#include <vector>

using namespace std;

void Meniu()
{
    system("CLS");
    cout << "Alegeti optiunea dorita: " <<endl<<endl;
    cout <<"1. Adaugare participant"<<endl<< endl;
    cout <<"2. Afisare sumar" <<endl<< endl;
    cout <<"0. Iesire" <<endl << endl;

}

Participant *CreazaParticipant()
{
    system("CLS");
    cout << "Alegeti nationalitatea: " <<endl;
    cout << "1. Roman" << endl;
    cout << "2. Francez" << endl;
    cout << "3. German" << endl;
    cout << "4. Alta" << endl;
    short user;
    cin >> user;
        switch(user)
            {
                case 1 : {Participant* part1 = new Roman(); return part1;}
                case 2 : {Participant* part2 = new Francez();return part2;}
                case 3 : {Participant* part3 = new German();return part3;}
                default : {Participant* part4 = new Participant();return part4;}
    }
}



int main()
{
    vector <Participant*> pntParticipanti;
    short user = 1;
    while (user!=0)
    {
        Meniu();
        cin >> user;
        if (user == 1)
        {
            Participant *participant = CreazaParticipant();
           pntParticipanti.push_back(participant);
           delete participant;
           participant = nullptr;

        }
        else if (user == 2)
        {
            system("CLS");

            int nrRomani = 0, nrFrancezi = 0, nrGermani = 0, nrAltii = 0;
            for ( Participant *parti : pntParticipanti)
            {
                switch(parti -> Vorbeste())
                {
                    case Limba::romana: nrRomani++; break;
                    case Limba::franceza: nrFrancezi++; break;
                    case Limba::germana: nrGermani++; break;
                    default: nrAltii++; break;
                }
            }

        if (nrRomani || nrFrancezi || nrGermani || nrAltii)
        {
            cout << "Participanti inscrisi pana acum:" << endl;

            if(nrRomani != 0) {
                    cout<<nrRomani<< " " << "romani" << endl;
                }
                if(nrFrancezi != 0) {
                    cout<<nrFrancezi<< " " << "francezi" << endl;
                }
                if(nrGermani != 0) {
                    cout<<nrGermani<< " " << "germani" << endl;
                }
                if(nrAltii != 0) {
                    cout<<nrAltii<< " " << "germani" << endl;
                }
        }
            system("pause");
        }
    }
    return 0;
}


