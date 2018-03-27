//
//  duplicateChars.cpp
//  C++Practice
//
//  Created by Benjamin G Fields on 3/16/18.
//  Copyright © 2018 Benjamin G Fields. All rights reserved.
//

#include <vector>
#include <unordered_set>
#include <iostream>
#include <cctype>

std::unordered_set<char> duplicates(std::string phrase)
{
    std::unordered_set<char>duplicates;
    std::unordered_set<char> seen;
    for (int i = 0; i<phrase.length(); i++) {
        if (phrase[i] == ' '|| isalpha(phrase[i])==0) {
            continue;
        }
        int c = (int)seen.count(phrase[i]);
        if ( c == 1)
        {
            duplicates.insert(phrase[i]);
        }
        else
        {
            seen.insert(phrase[i]);
        }
    }
    
    return duplicates;
}

std::string reverse(std::string phrase)
{
    std::string ans = "";
    for (int i = 0; i<phrase.length(); i++) {
        ans = phrase[i] + ans;
    }
    return ans;
}

int main()
{
    std::string phrase = "my, name, is ben why do you care";
    
    std::unordered_set<char> ans = duplicates(phrase);
    std::unordered_set<char>::iterator it;
    for (it = ans.begin();it!=ans.end();it++) {
        std::cout<<*it<< " ";
    }
    std::cout<<"\n";
    
    std::cout<<reverse("Ben")<<std::endl;
    
    return 0;
}
