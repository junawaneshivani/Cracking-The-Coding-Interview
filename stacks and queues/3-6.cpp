/*
Animal Shelter: An animal shelter, which holds only dogs and cats, 
operates on a strictly"first in, first out" basis. People must 
adopt either the "oldest" (based on arrival time) of all animals 
at the shelter,or they can select whether they would prefer a dog 
or a cat (and will receive the oldest animal of that type). They 
cannot select which specific animal they would like. Create the 
data structures to maintain this system and implement operations 
such as enqueue, dequeueAny, dequeueDog,and dequeueCat. You may 
use the built-in Linked list data structure.
*/

#include <iostream>
#include <queue>
using namespace std;

enum Animal {DOG=1, CAT=2, ANY=3};

class AnimalShelter{
    queue<int> dogs,cats;
    int count;
public:
    AnimalShelter(){ count=0; };

    void enqueue(Animal animal);
    Animal dequeue(Animal animal);

    ~AnimalShelter(){};
};

void AnimalShelter::enqueue(Animal animal){
    if (animal==DOG) 
        dogs.push(++count);
    else if (animal==CAT)
        cats.push(++count);
    else
        cout << "Invalid Input" << endl;
}

Animal AnimalShelter::dequeue(Animal animal){
    Animal retAnimal;
    if (animal==DOG){
        retAnimal = DOG;
        dogs.pop();
    }
    else if (animal==CAT) {
        retAnimal = CAT;
        cats.pop();
    }else{
        if (cats.front()<dogs.front()) {
            retAnimal = CAT;
            cats.pop();
        }else{
            retAnimal = DOG;
            dogs.pop();
        } 
    }
    return retAnimal;
}

string printAnimal(Animal animal){
    return (animal==DOG) ? "DOG" : "CAT";
}

int main(){

    AnimalShelter as;

    as.enqueue(DOG);
    as.enqueue(CAT);
    as.enqueue(DOG);
    as.enqueue(DOG);
    as.enqueue(CAT);
    as.enqueue(ANY);

    cout << printAnimal(as.dequeue(DOG)) << endl;
    cout << printAnimal(as.dequeue(CAT)) << endl;
    cout << printAnimal(as.dequeue(ANY)) << endl;

    return 0;
}