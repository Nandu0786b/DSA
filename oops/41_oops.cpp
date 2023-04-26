// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class hero {
    private:
    string Health="Low";
    int level = 0;
    public:
    string area = "Backend";
    // getter and setter to manuplate private part of class 
    void setlevel(int new_level){
        level = new_level;
    }
    int getlevel(){
        return level;
    }
    string sethealth(string new_health){
        Health = new_health;
    }
    string gethealth(){
        return Health;
    }
    
};
int main() {
    // static allocation
    hero Rahul;
    // Write C++ code here
    cout<<Rahul.gethealth()<<endl;
    cout<<Rahul.getlevel()<<endl;
    Rahul.sethealth("strong");
    Rahul.setlevel(6);
    cout<<Rahul.gethealth()<<endl;
    cout<<Rahul.getlevel()<<endl;
    // dynamic allocation
    hero *Rohit = new hero;
    // 1st method
    cout<<(*Rohit).gethealth()<<endl;
    cout<<(*Rohit).getlevel()<<endl;
    (*Rohit).sethealth("strong");
    (*Rohit).setlevel(6);
    cout<<(*Rohit).gethealth()<<endl;
    cout<<(*Rohit).getlevel()<<endl;
    // 2nd method
    cout<<Rohit->gethealth()<<endl;
    cout<<Rohit->getlevel()<<endl;
    Rohit->sethealth("strong");
    Rohit->setlevel(6);
    cout<<Rohit->gethealth()<<endl;
    cout<<Rohit->getlevel()<<endl;
    return 0;
    /*
    object -> data member , behaviour/fynction,
    access modifier -> public,private,protect,
    static,dynamic allocation of object,
    constructor -> how to create , shallow and deep copy, default constructor , copy assignment,
    destructor
    const key word
    const function
    list initilisation
    static variable
    static function
    */
}