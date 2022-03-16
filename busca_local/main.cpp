#include <iostream>
#include <vector>
#include <random>
#include <bits/stdc++.h>
using namespace std;


struct item
{
    int id;
    int peso;
    int valor;
    int entrou;
};
struct Bag{
    int id;
    int peso;
    int valor;
    vector<int> items;
};


// Compares two intervals according to ending times in descending order.
bool compareItem(Bag i1, Bag i2)
{
    return (i1.valor > i2.valor);
}


int main(){
    vector<item> items;
    vector<Bag> bags;
    int max_bags = 1000;
    bags.reserve(max_bags);
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
        item_temp.id = i;
        cout<< item_temp.peso<<" "<<item_temp.valor<< endl;
        items.push_back(item_temp);
    }

    cout<<endl;

    default_random_engine generator(10);
    uniform_real_distribution<double> distribution(0.0,1.0);
    double dice_roll;
    int last_i;
    int random_int;
    for (int number_bag = 0;number_bag <max_bags;number_bag++){
        Bag bag;
        bag.peso = 0;
        bag.valor = 0;
        bag.id = number_bag;
        for (int i =0; i< max_items ;i++){
            dice_roll = distribution(generator);
            if (items[i].peso + bag.peso <= max_peso && dice_roll <=0.5){
                bag.peso += items[i].peso;
                bag.valor += items[i].valor;
                bag.items.push_back(1);
            }
            else{
                bag.items.push_back(0);
            }
        }
        bags.push_back(bag);

    }

    sort(bags.begin(),bags.end(),compareItem);
    cout<<bags[0].id<<" "<<bags[0].peso <<" "<< bags[0].valor << endl;
    // for (int number_bag = 0; number_bag < max_bags;number_bag++){
    //     cout<<bags[number_bag].id<<" "<<bags[number_bag].peso <<" "<< bags[number_bag].valor << endl;
    // }
    // cout<<endl<<endl<<endl;

    // Mochila cheia
    for (int number_bag = 0; number_bag < max_bags;number_bag++){
        if (bags[number_bag].peso < max_peso){
            for (int i =0; i< max_items ;i++){
                int in_bag = bags[number_bag].items[i];
                if (items[i].peso + bags[number_bag].peso <= max_peso && in_bag == 1){
                    bags[number_bag].peso += items[i].peso;
                    bags[number_bag].valor += items[i].valor;
                    bags[number_bag].items[i] = 1;
                }
            }
        }   
    }
    sort(bags.begin(),bags.end(),compareItem);
    cout<<bags[0].id<<" "<<bags[0].peso <<" "<< bags[0].valor << endl;



    

    
    
    return 0;

}