#include<iostream>
#include<unordered_map>

using namespace std;

int  main()
{
    unordered_map<int, int> pos = {{1,3},{2,4},{3,5}};
    unordered_map<int,int>::const_iterator got = pos.find(1);
    cout<<got->first << "is" << got->second<<endl;
    for ( auto it = pos.begin(); it != pos.end(); ++it )
        cout << " " << it->first << ":" << it->second;
    cout<<endl;
    auto it = pos.begin();
    cout<<it->first << ":" << it->second;
    //do not work
    auto it2 = pos.end();
    cout<<it2->first << ":" << it2->second;
}