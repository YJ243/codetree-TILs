#include <iostream>
using namespace std;
int main() {
    int height, weight;
    cin>>height>>weight;
    double h = height*0.01;
    int bmi = weight/(h*h);
    cout<<bmi<<'\n';
    if(bmi>=25)
        cout<<"Obesity";
    return 0;
}