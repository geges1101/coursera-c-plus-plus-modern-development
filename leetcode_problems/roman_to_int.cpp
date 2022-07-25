#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        vector<int> digits(s.size());

        for(auto it = s.begin(); it != s.end(); it++){

            if(*it == 'M'){
                digits.push_back(1000);
            }

            if(*it == 'D'){
                digits.push_back(500);
            }

            if(*it == 'C'){

                if(*(it + 1) == 'M'){
                    digits.push_back(900);

                    it++;
                }
                else if(*(it + 1) == 'D'){
                    digits.push_back(400);

                    it++;
                }
                else digits.push_back(100);
            }


            if(*it == 'L'){
                digits.push_back(50);
            }

            if(*it == 'X'){

                if(*(it + 1) == 'L'){
                    digits.push_back(40);

                    it++;
                }
                else if(*(it + 1) == 'C'){
                    digits.push_back(90);

                    it++;
                }
                else digits.push_back(10);
            }

            if(*it == 'V'){
                digits.push_back(5);
            }

            if(*it == 'I'){

                if(*(it + 1) == 'V'){
                    digits.push_back(4);

                    it++;
                }
                else if(*(it + 1) == 'X'){
                    digits.push_back(9);

                    it++;
                }
                else digits.push_back(1);
            }
        }

        int result = 0;

        for(auto i : digits){
            result += i;
        }

        return result;
    }
};
