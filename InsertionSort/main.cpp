#include <iostream>
using namespace std;
class Mountain{
public:
    string name;
    unsigned int height;
    Mountain(string n, unsigned int h){
        name = n;
        height = h;
    }
    Mountain(){}
};

void sortHeights(Mountain *mountains, int n){
    Mountain mountainKey;
    for(int i=1;i<n;++i){
        mountainKey = mountains[i];
        int target = i-1;
        while(mountainKey.height < mountains[target].height && target >=0 ){
            mountains[target+1] = mountains[target];
            target -= 1;
        }
        mountains[target+1] = mountainKey;
    }
}

void displayResults(Mountain* mountains, int n){
    for(int i=0;i<n;++i){
        cout << mountains[i].name <<"-"<< mountains[i].height << " ";
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int t,n,height;
    string name;
    Mountain mountain;
    Mountain *powerMountains;
    Mountain *otherMountains;
    cin >> t;
    for(int i=0;i<t;++i){
        cin >> n;
        powerMountains = new Mountain[n];
        otherMountains = new Mountain[n];
        int powerCount = 0;
        int otherCount = 0;
        for(int j=0;j<n;++j){
            cin >> mountain.name >> mountain.height;
            if(((mountain.height^(mountain.height-1))==2*mountain.height-1)){
                powerMountains[j-otherCount] = mountain;
                powerCount++;
            }else{
                otherMountains[j-powerCount] = mountain;
                otherCount++;
            }
        }
        sortHeights(powerMountains, powerCount);
        sortHeights(otherMountains, otherCount);
        displayResults(powerMountains,powerCount);
        displayResults(otherMountains,otherCount);
        cout<<"\n";
    }
    delete[] powerMountains;
    delete[] otherMountains;
    return 0;
}