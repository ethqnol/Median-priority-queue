#include <iostream>
#include<vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "customer.hh"
#include "heap.hh"
using namespace std;





customer generateRandomCustomer(){

    string names[10] = {"Jack", "John", "Joe", "Matt", "Brian", "Olivia", "Oliver", "Theo", "Henry", "James"};
    string phoneNum[20] = { "46209451",
                            "461147242",
                            "461371049",
                            "461394424",
                            "461614222",
                            "462144214",
                            "462189439",
                            "462361439",
                            "463333521",
                            "463356423",
                            "463524829",
                            "463574393",
                            "463671295",
                            "464012314",
                            "464259538",
                            "466012022",
                            "468012312",
                            "468092022",
                            "468139942",
                            "468217666"
                        };
        customer person;
        person.name = names[rand() % 10];
        person.phone = phoneNum[rand() % 20];
        person.money = rand() % 500;
        return person;
}


int main(){
    srand(time(NULL));
    Heap upper(false);
    Heap lower(true);

    for(int i = 0; i < 80000000; i ++){
        cout << "\n\n\n";
        customer person = generateRandomCustomer();
        customer median;

        if(upper.isEmpty() && lower.isEmpty()){
            lower.insert(person);
            
        } else if (upper.size() == lower.size()){
            if(person > upper.getTop()){
                upper.insert(person);
                median = upper.getTop();
            } else {
                lower.insert(person);
                median = lower.getTop();
            }

        } else if (upper.size() > lower.size()){
            if(upper.isEmpty()){
                if(person > lower.getTop()){
                    upper.insert(person);
                } else {
                    lower.insert(person);
                }
            } else {
                if(person > upper.getTop()){
                    upper.insert(person);
                } else {
                    lower.insert(person);
                }
            }


            while(upper.size() != lower.size() + 1 && upper.size() != lower.size()){
                lower.insert(upper.extractTop());

            }


            median = upper.getTop();
        } else {
            if(upper.isEmpty()){
                if(person > lower.getTop()){
                    upper.insert(person);
                } else {
                    lower.insert(person);
                }
            } else {
                if(person > upper.getTop()){
                    upper.insert(person);
                } else {
                    lower.insert(person);
                }
            }

            while(upper.size() + 1 != lower.size() && upper.size() != lower.size()){
                upper.insert(lower.extractTop());
            }
            
            median = lower.getTop();
        }
        
        //cout << "Upper: \n";
        //upper.printCustomerQueue();
        //cout << "\nLower: \n";
        //lower.printCustomerQueue();
        cout << "\n";
        cout << "MEDIAN:   " << " Name: " <<  median.name << ",  Phone: " <<  median.phone << ",  Value: " << median.money << " \n";

    }


    return 0;
}