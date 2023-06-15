#include <vector>
#include <iostream>
#include "customer.hh"

using namespace std;


struct Heap {
    private: 

        vector<customer> customers;
        bool isMax;
        
        int left(int i){

        return i * 2 + 1;
        }

        int right(int i){

            return i * 2 + 2;
        }

        int parent(int i){
            return (i - 1)/2;
        }

        void heapify(int i){

            int l = left(i);
            int r = right(i);

            int largest = i;
            int heapSize = customers.size();
            
            if(isMax){
                if(l < heapSize && customers[l] > customers[largest]){
                    largest = l;
                }
                if (r < heapSize && customers[r] > customers[largest]){
                    largest = r;
                }
            } else {
                if(l < heapSize && customers[largest] > customers[l]){
                    largest = l;
                }
                if (r < heapSize && customers[largest] > customers[r]){
                    largest = r;
                }
            }

            if(largest != i){
                customer previousParent = customers[i];
                customers[i] = customers[largest];
                customers[largest] = previousParent;


                
                heapify(largest);
            }

        }


        void buildHeap() {
            int heapSize = customers.size();
            for(int i = heapSize/2; i >= 0; i--){
                heapify(i);
            }
        }

    public:
        //Constructor     
        Heap(bool maxIfTrue) : isMax(maxIfTrue) {}
        
        void insert(customer person) {
            customers.push_back(person);

            int i = customers.size() - 1;
            if(isMax){
                while(i >= 1 && person > customers[parent(i)]){
                    customers[i] = customers[parent(i)];
                    i = parent(i);
                }
            } else {
                while(i >= 1 &&  customers[parent(i)] > person){
                    customers[i] = customers[parent(i)];
                    i = parent(i);
                }
            }
            customers[i] = person;
        }

        customer getTop() {
            return customers[0];
        }

        bool isEmpty() {
            return customers.size() == 0; // is equivalent to this->size() == 0; 
        }

        int size() {
            return customers.size(); 
        }

        customer extractTop() {
            if(customers.size() < 1){
                throw invalid_argument("Heap underflow");
            }

            customer top = customers[0];
            customers[0] = customers[customers.size() - 1];
            customers.pop_back();
            if(customers.size() != 0){
                heapify(0);
            }
            return top;    
        }

        bool getIsMaxQueue() {
            return isMax; // is equalient to this->isMax
        }
        

        void printCustomerQueue(){
            for(int i = 0; i < customers.size(); i++){
                cout << " Name: " <<  customers[i].name << ",  Phone: " <<  customers[i].phone << ",  Value: " << customers[i].money << " \n";
            }
        }

        vector<customer> getCustomers(){
            return customers;
        }
};


