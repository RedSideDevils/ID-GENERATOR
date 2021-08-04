#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Apple {
    private:
        int weight;
        string color;
        int id;

    public: 
        static int Count;

        Apple(int weight, string color){
            this->weight = weight;
            this->color  = color;
            Count++;
            id = Count;
        }

        int GetId(){
            cout << id << "\t" << color << "\t" << weight << endl;
        }
};

int Apple::Count = 0;

int main(){
    srand ( time(NULL) );
    const int SIZE = 3;
    string Colors[SIZE] = {"RED", "GREEN", "YELLOW"};
    Apple** Arr = new Apple*[5];

    for (int i = 0; i < 5; i++){
        int weight = rand() % 250 + 1;
        int RandIndex = rand() % SIZE;
        Arr[i] = new Apple(weight, Colors[RandIndex]); 
    }
    cout << "ID" << "\t" << "COLOR" << "\t" << "WEIGHT" << endl;
    for (int i = 0; i < 5; i++){
       Arr[i]->GetId(); 
    }

    for( int i = 0; i < 5; i++ )
    {
        delete[] Arr[i];
    }

    delete[] Arr;
    return 0;
}
