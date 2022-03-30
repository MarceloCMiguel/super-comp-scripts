#include <iostream>
#include <vector>
#include <bits/stdc++.h>
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

    // cout<< max_items << " " << max_peso << endl;
    for (int i = 0; i < max_items; i++)
    {
        int peso_temp, valor_temp;
        cin>>peso_temp>> valor_temp;
        // item item_temp = item(peso_temp,valor_temp);
        item item_temp;
        item_temp.peso = peso_temp;
        item_temp.valor = valor_temp;
        // cout<< item_temp.peso<<" "<<item_temp.valor<< endl;
        items.push_back(item_temp);
    }
    // cout<<endl;

    sort(items.begin(), items.end(), compareItem);
    
    item bag;
    bag.peso = 0;
    bag.valor = 0;
    for (int i =0; i< max_items ;i++){
        if (items[i].peso + bag.peso <= max_peso){
            bag.peso += items[i].peso;
            bag.valor += items[i].valor;
        }

        // cout<< items[i].peso<< " "<< items[i].valor<< endl;
    }
    // cout<<endl;
    cout<<bag.peso<<" "<<bag.valor << endl;

    

    
    
    return 0;

}