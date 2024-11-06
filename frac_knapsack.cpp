#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int weight;
    int profit;
    double profitperweight;
};

double fractionalKnapsack(vector<Item> &items,int W){

    sort(items.begin(),items.end(),[](Item &a, Item &b){
        return a.profitperweight > b.profitperweight;
    });

    double maxProfit = 0.0;
    int curWeight = 0;

    for(auto &item : items){
        if(curWeight + item.weight <= W){
            curWeight += item.weight;
            maxProfit += item.profit;
        }
        else{
            int remWeight = W - curWeight;
            maxProfit += item.profitperweight * remWeight;
            break;
        }
    }

    return maxProfit;

}

int main(){
    int n,W;

    cout<<"Enter No. of Items: ";
    cin>>n;

    vector<Item> items(n);

    for(int i=0;i<n;i++){
        cout<<"Enter Weight of Item "<<i+1<<": ";
        cin>>items[i].weight;
        cout<<"Enter Profit of Item "<<i+1<<": ";
        cin>>items[i].profit;
        items[i].profitperweight = (double) items[i].profit / items[i].weight;
    }

        cout<<"Enter KnapSack Capacity: ";
        cin>>W;

        double maxProfit = fractionalKnapsack(items,W);

        cout<<"Maximum Profit: "<<maxProfit;

        return 0;

}
