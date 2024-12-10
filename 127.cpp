//Accordian Patience - 127
#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

int main(){
    vector<stack<string>>deck;
    stack<string> cards;
    string s;

    while(cin>>s && s != "#"){
        cards.push(s);
        deck.push_back(cards);
        cards.pop();

        for(int i = 1; i<52; i++){
            cin>>s;
            cards.push(s);
            deck.push_back(cards);
            cards.pop();
        }

        bool flag = true;
        for(int i = 0; i<deck.size(); i++){
            if(i>=3 && (deck[i].top()[0]==deck[i-3].top()[0] || deck[i].top()[1]==deck[i-3].top()[1])){
                deck[i-3].push(deck[i].top());
                deck[i].pop();
                if(deck[i].empty()){
                    deck.erase(deck.begin()+i);
                }
                flag = false;
                i = 0;
            }
            else if(i>=1 && (deck[i].top()[0] == deck[i-1].top()[0] || deck[i].top()[1] == deck[i-1].top()[1])){
                deck[i-1].push(deck[i].top());
                deck[i].pop();
                if(deck[i].empty()){
                    deck.erase(deck.begin()+i);
                }
                flag = false;
                i = 0;
            }
        }

        if(deck.size() == 1){
            cout<<"1 pile remaining: 52"<<endl;
        }else{
            cout<<deck.size()<<" "<<"piles remaining:";
            for(int i=0; i<deck.size(); ++i){
                cout<<" "<<deck[i].size();
            }
            cout<<endl;
        }   
        deck.clear();
    }
    return 0;
}   