#include <iostream>
#include <unordered_map>

/* Calculates the number of months before a rabbit population meets a target
   Based on the rules:
   Females are fertile at 4 months
   Every month, fertile females have 5 male and 9 female offspring
   Rabbits die at 8 years (96 months), rabbits at 7 years and 11 months have offspring before dying 
Note: current implementation only uses 2^32 for int types
*/
int main()
{
    int months, initMale, initFemale;
    unsigned long total, target, dead;
    std::unordered_map<int, unsigned long> femaleMap;
    std::unordered_map<int, unsigned long> maleMap;

    std::cout << "Enter male_rabbits female_rabbits rabbits_needed_alive" << std::endl;

    std::cin >> initMale;
    std::cin >> initFemale;
    std::cin >> target;

    total = initMale + initFemale;
    dead = 0;
    months = 0;
    femaleMap[2] = initFemale;
    maleMap[2] = initMale;

    while(total < target)
    {
        unsigned long newFemale = 0;
        unsigned long newMale = 0;

        // calculate offspring
        for (int i = 4; i <= 95; ++i)
        {
            newFemale += femaleMap[i] * 9;
            newMale += femaleMap[i] * 5;
        } 
        
       dead += femaleMap[95] + maleMap[95];
       total -= (femaleMap[95] + maleMap[95]);

        // calculate aging
        for (int j = 95; j > 0; --j) 
        {
            femaleMap[j] = femaleMap[j - 1];
            maleMap[j] = maleMap[j - 1];
        }

        // add new offspring
        femaleMap[0] = newFemale;
        maleMap[0] = newMale;
        total += newFemale + newMale;

        months++;
    }

    std::cout << "Number of months needed for target population: " << std::to_string(months) << std::endl;
    std::cout << "Number of rabbits that died: " << std::to_string(dead) << std::endl;
}
