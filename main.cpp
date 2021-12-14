#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Service.h"

using namespace std;
int main() {
    Service s("1","09/07/2021","p");
    Service s2("1","06/05/2021","l");
    vector<Service> v;
    v.push_back(s);
    v.push_back(s2);
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++){
        cout<<v[i].getData()<<endl;
    }


    return 0;

}
