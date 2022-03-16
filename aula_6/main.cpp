#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <random>
using namespace std;

struct item
{
    int peso;
    int valor;
};

// Compares two intervals according to ending times in descending order.
bool compareItem(item i1, item i2)
{
    return (i1.valor > i2.valor);
}

int main(){
    vector<item> items;
    int max_items, max_peso;
    cin >> max_items >> max_peso;

    cout<< max_items << " " << max_peso << endl;
    for (int i = 0; i < max_items; i++)
    {
        int peso_temp, valor_temp;
        cin>>peso_temp>> valor_temp;
        item item_temp;
        item_temp.peso = peso_temp;
        item_temp.valor = valor_temp;
        cout<< item_temp.peso<<" "<<item_temp.valor<< endl;
        items.push_back(item_temp);
    }
    cout<<endl;

    sort(items.begin(), items.end(), compareItem);

    

    item bag;
    bag.peso = 0;
    bag.valor = 0;


    default_random_engine generator(123);
    uniform_real_distribution<double> distribution(0.0,1.0);
    double dice_roll;
    int last_i;
    int random_int;
    for (int i =0; i< max_items ;i++){
        dice_roll = distribution(generator);
        if (items[i].peso + bag.peso <= max_peso && dice_roll <=0.75){
            bag.peso += items[i].peso;
            bag.valor += items[i].valor;
        }
    }
    cout<<endl;
    cout<<bag.peso<<" "<<bag.valor << endl;

    

    
    
    return 0;

}