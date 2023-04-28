// https://www.codingninjas.com/codestudio/guided-paths/oops-in-c
// 1.single level inheritance
// #include<iostream>
// using namespace std;

// class Animal {
//     public:
//     int age ;
//     int weight;
//     public :
//     void speak(){
//         cout<<"speaking"<<endl;
//     }
// };
// class Dog: public Animal{

// };
// int main(){
//     Dog ramu;
//     ramu.speak();
//     return 0;
// }

// operator overloading
#include<iostream>
using namespace std;

class B{
    public:
    int a;
    int b;
    public:
    int add(){
        return a+b;
    }
    void operator+ (B &obj){
        int value1 = this->a;
        int value2 = obj.a;
        cout<<"out put is : "<< value2-value1<<endl;
    }
    void operator() (){
        cout<<"ma bracket hoo\t"<<this->a<<endl;
    }
};
int main(){
    B obj1,obj2;
    obj1.a=7;
    obj2.a=4;
    obj2+obj1;
    obj1();
}