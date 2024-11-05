#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Item {
    int value;  
    int weight; 
};


bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; 
}


double fractionalKnapsack(int W, vector<Item> &items) {
    
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0; 
    int currentWeight = 0;   

    
    for (const Item &item : items) {
        if (currentWeight + item.weight <= W) {
           
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            
            int remainingWeight = W - currentWeight;
            totalValue += item.value * ((double)remainingWeight / item.weight);
            break; 
        }
    }

    return totalValue;
}

int main() {
    int n; 
    int W; 

    
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    vector<Item> items(n); 

    
    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    
    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in the knapsack = " << maxValue << endl;

    return 0;
}
