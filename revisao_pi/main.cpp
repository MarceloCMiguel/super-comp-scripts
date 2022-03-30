#include <iostream>
#include <vector>
#include <random>
#include <bits/stdc++.h>
using namespace std;

struct acao
{
    int id;
    int custo;
    int retorno;
    int imposto;
    int lucro;
};

int num_leaf=0, num_copy=0;

double acoes2(int W, vector<acao> items, vector<acao>& usados, vector<acao>& melhor){
    double lucro = 0.0;
    double custo = 0.0;
    double sem_i = 0.0, com_i = 0.0;
    vector<acao> items2 = items;
    if(items.empty() || W == 0)
        return 0;
    if(items[0].custo <= W){
        usados.push_back(items[0]);
        lucro = items[0].lucro;
        custo = items[0].custo;
        items.erase(items.begin());
        com_i = acoes2(W - custo, items, usados, melhor);
    }
    items2.erase(items2.begin());
    sem_i = acoes2(W, items2, usados, melhor);
    double lucro_atual = 0.0, lucro_melhor = 0.0;
    for(auto& el : usados){
        lucro_atual += el.lucro;
    }
    for(auto& el : melhor){
        lucro_melhor += el.lucro;
    }
    num_leaf++;
    if(lucro_atual > lucro_melhor){
        melhor = usados;
        num_copy++;
    }
    usados.clear();
    return max(sem_i, lucro + com_i);
    
}


int main(){
    int n, orcamento;
    cin>>n>>orcamento;
    vector<acao> acoes;
    vector<acao> usado;
    vector<acao> melhor;
    usado.reserve(n);
    acoes.reserve(n);
    for (int i = 0; i < n; i++){
        acao acao_tmp;
        int custo, retorno_, imposto_;
        cin>>custo>>retorno_>>imposto_;
        acao_tmp.custo = custo;
        acao_tmp.retorno = retorno_;
        acao_tmp.imposto = imposto_;
        acao_tmp.lucro = retorno_ - imposto_;
        acao_tmp.id = i;
        acoes.push_back(acao_tmp);
        cout<<acao_tmp.custo<<" "<<acao_tmp.lucro<<endl;
    }

    sort(acoes.begin(), acoes.end(), [](auto& i, auto& j){return i.lucro > j.lucro;});
    
    cout << "RESULTADO = " << acoes2(orcamento, acoes, usado, melhor) << endl;
    int valor = 0;
    for(auto& el: melhor) {
            valor+= el.lucro;
            cout << el.id<< " ";
    }
    cout<<valor;


}