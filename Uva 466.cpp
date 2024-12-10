/*
Autor: Isabella Erazo Fernandez
Uva 466 - Mirror Mirror
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> rotated90(){
    //debo comparar las posiciones de la matriz original con la nueva?
    //el conteo como se hace? cada que encuentra uno que no es, aumenta el contador?
}

vector<string> verticalReflextion(){
    //y lo de la reflexion aun no lo he pensado
}

bool areEqual(vector<string>&a, vector<string>&b){
    return a == b;
}

int main(){
    int n, lenght,idCount = 1;
    bool flag;

    while(cin>>n){
        vector<string>ogMatrix(n), newMatrix(n);

        for(int i = 0; i < n; i++){
            cin>>ogMatrix[i]>>newMatrix[i]; 
        }

        if(areEqual(ogMatrix, newMatrix)){
            cout<<"Pattern"<<idCount<<"was preserved."<<endl; 
        }else if(rotated90()){//rotated90 function
            cout<<"Pattern"<<idCount<<"was rotated 09 degrees."<<endl;
        }else if(){//refleja verticalmente 90 grados
            cout<<"Pattern"<<idCount<<"was reflected vertically and rotated 90 degrees."<<endl;
        }else if(){//rotated180 function
            cout<<"Pattern"<<idCount<<"was rotated 180 degrees."<<endl;
        }else if(){
            cout<<"Pattern"<<idCount<<"was reflected vertically and rotated 180 degrees."<<endl;
        }else if(){//rotated270 function
            cout<<"Pattern"<<idCount<<"was rotated 270 degrees."<<endl;
        }else if(){
            cout<<"Pattern"<<idCount<<"was reflected vertically and rotated 270 degrees."<<endl;
        }else{
            cout<<"Pattern"<<idCount<<"was improperly transformed."<<endl;
        }
    }

    return 0;
}