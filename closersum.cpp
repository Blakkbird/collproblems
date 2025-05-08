#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> closer(vector <int>& v, int target){
    sort(v.begin(),v.end());
    int ref, min=1e9, ind;
    vector <int> ans;
    
    for(int i=0; i < v.size(); i++){ 
        int range=abs(v.at(i) - target);
        if (range < min){
            min = range;
            ref=v.at(i);
            ind = i;
        }
    } // reference num, closest to target

    ans.push_back(v.at(ind));

    min=0;
    int sum2=0, sum3=0;
    bool a=true, b=false;

    for(int i=ind; i < ind +2 ; i++){
        min+=v.at((ind)%v.size());
    }
    for(int i=ind; i > ind -2; i++){
        sum2+=v.at(ind%v.size());
    }
    if( sum2 < min){
        min=sum2;
        b=true;
        a=false;
    }
    sum3=v.at(ind)+v.at((ind-1)%v.size())+v.at((ind+1)%v.size());
    if(sum3 < min){
        b=false;
    }

    if(a==true){
        ans.push_back(v.at((ind+1)%v.size()));
        ans.push_back(v.at((ind+2)%v.size()));
    }
    else if(b==true){
        ans.push_back(v.at((ind-1+v.size())%v.size()));
        ans.push_back(v.at((ind-2+v.size())%v.size()));
    }
    else{
        ans.push_back(v.at((ind-1+v.size())%v.size()));
        ans.push_back(v.at((ind+1)%v.size()));
    }


    return ans;
}
int main(){
    vector <int> v ={-56, -1, 0, 56};
    int target =0;

    vector <int> ans = closer(v, target);

    cout << "Nums w/ sum closest to " << target << endl;
    for(int val : ans){cout << val << "\t";}

    return 0;
}
