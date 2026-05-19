#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"

#include "CRightTriangle.h"

using namespace std;

#define MAX_SHAPES 100

int main()
{
    Shape* shapes[MAX_SHAPES];

    int nShapes = 0;

    int choice;

    do
    {
        cout << endl;
        cout << "===== SHAPE MANAGER =====" << endl;

        cout << "1 - Visualizza poligoni" << endl;
        cout << "2 - Modifica poligono" << endl;
        cout << "3 - Sposta poligono" << endl;
        cout << "4 - Inserisci poligono" << endl;
        cout << "5 - Cancella poligono" << endl;
        cout << "6 - Cancella tutti i poligoni" << endl;
        cout << "0 - Esci" << endl;

        cin >> choice;

        switch(choice)
        {

        case 1:         //visualzizza poligoni
        {
            cout << endl;
            cout << "===== LISTA POLIGONI =====" << endl;

            for(int i = 0; i < nShapes; i++)
            {
                cout << endl;
                cout << "Indice: " << i << endl;

                shapes[i]->Dump();

                cout << "Area: "
                     << shapes[i]->GetArea()
                     << endl;

                cout << "Perimetro: "
                     << shapes[i]->GetPerimeter()
                     << endl;
            }
            break;
        }

        case 2:     //modifica dimensioni
        {
            int index;
            float w,h;

            cout << "Indice poligono: ";
            cin >> index;

            if(index >= 0 && index < nShapes)
            {
                cout << "Nuova width: ";
                cin >> w;

                cout << "Nuova height: ";
                cin >> h;

                shapes[index]->SetDim(w,h);
            }
            break;
        }

        case 3:         //sposta
        {
            int index;

            float x,y;

            cout << "Indice poligono: ";
            cin >> index;

            if(index >= 0 && index < nShapes)
            {
                cout << "Nuova x: ";
                cin >> x;

                cout << "Nuova y: ";
                cin >> y;

                shapes[index]->SetPosition(x,y);
            }
            break;
        }

        case 4:         //inserisci
        {
            int type;

            float x,y,w,h;

            cout << endl;
            cout << "1 - Rectangle" << endl;
            cout << "2 - Rhombus" << endl;
            cout << "3 - RightTriangle" << endl;

            cin >> type;

            cout << "x y width height: ";
            cin >> x >> y >> w >> h;

            if(type == 1)
            {
                shapes[nShapes++] =
                    new Rectangle(x,y,w,h);
            }

            else if(type == 2)
            {
                shapes[nShapes++] =
                    new Rhombus(x,y,w,h);
            }

            else if(type == 3)
            {
                shapes[nShapes++] =
                    new RightTriangle(x,y,w,h);
            }

            break;
        }

        case 5:             //cancella uno
        {
            int index;

            cout << "Indice da cancellare: ";
            cin >> index;

            if(index >= 0 && index < nShapes)
            {
                delete shapes[index];

                for(int i=index; i<nShapes-1; i++)
                {
                    shapes[i] = shapes[i+1];
                }

                nShapes--;

                cout << "Poligono cancellato" << endl;
            }

            break;
        }

        case 6:             //cancella tutti
        {
            for(int i=0; i<nShapes; i++)
            {
                delete shapes[i];
            }

            nShapes = 0;

            cout << "Tutti i poligoni cancellati" << endl;

            break;
        }

        }

    } while(choice != 0);

    for(int i=0; i<nShapes; i++)
    {
        delete shapes[i];
    }

    return 0;
}
