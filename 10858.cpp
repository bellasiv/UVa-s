//
//Isabella Erazo Fernandéz
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, f, a, num;
    vector<int>vec;
    bool flag = false;

    while(cin>>n && n != 0){
        
        a = 1;
        while(n % a == 0){
            n = n/a;
            vec.push_back(n);
            vec.push_back(a);
        }
        a++;

        
        
        
        cout<<"vector values of:"<< n <<endl;
        for(int i =0; vec.size(); i++){
            cout<< vec[i] << " ";
        }
    
    
    }
    return 0;
}