#include <iostream>
#include <fstream>
#include "binary_search_tree.h"
int main() {
    std::ifstream in("../input.txt");
    std::ofstream out("../output.txt");
    Elem* root = nullptr;
    std::string tmp;
    while(!in.eof())
    {
        in>>tmp;
        int number=0;
        unsigned int t=tmp.size()-1;
        while(t>0)
        {
            number += (tmp[t]-48)*pow(10,tmp.size()-t-1);
            t--;
        }
        if(tmp[0]=='+')
        {
            add(number,root);
        }
        else if(tmp[0]=='-')
        {
            Delete(number,root);
        }
        else if(tmp[0]=='?')
        {
            Elem* vsp = search(number,root);
            if(vsp != nullptr)
                out<<deep(vsp,vsp)<<" ";
            else
                out<<"n ";
        }
        else if(tmp[0]=='E')
            break;
    }
    pass(root);
    return 0;
}
