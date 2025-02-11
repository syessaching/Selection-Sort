#include<iostream>
#include <fstream>
#include "Employee.h"




using namespace std;

int main(int argc, char**  argv){
        ofstream ofs;
        // checks if a command line is provided
        if (argc<2)
        {
            cout<<"Please include a command line parameter"<<endl;
            exit(1); //exit the program if no parameter
        }
        

        ifstream ifs;
        //Open the file specified in the command line
        ifs.open(argv[1], ios::in);


        // error if file is not found
        if(!ifs){
            cout<<"File not found"<<endl;
            exit(1);
        }

        
        string tmp;
        //read the first line to determine the number of records
        getline(ifs, tmp);
        int n = stoi(tmp);//convert string to integer
        
        //open the file to write the sorted records
        ofs.open("sorted.txt", ios::out);
        // cout<< n <<endl;
        


        Employee** employees = new Employee*[n];//create an array of pointers to Employee objects
        
        //read the records from the file and create Employee objects
        for (int i = 0; i < n; i++) {
            string name, job;
            int id, age, year;

                
            getline(ifs, name, '|');
            getline(ifs, tmp, '|');
            id = stoi(tmp);
            getline(ifs, tmp, '|');
            age = stoi(tmp);
            getline(ifs, job, '|');
            getline(ifs, tmp);
            year = stoi(tmp);
                
            employees[i] = new Employee(name, id, age, job, year);
        }
        




        int comparison =0;
        //selection sort algorithm
        for(int i=0; i<n-1; i++){
            int minIndex = i;
            for(int j=i+1; j<n; j++){
                if(employees[j]->getID() < employees[minIndex]->getID()){
                    minIndex = j;
                }
            comparison++;
            }
            //swap the records
            Employee* temp = employees[i];
            employees[i] = employees[minIndex];
            employees[minIndex] = temp;
                
            

                //print the sorted records
                // if (n <= 10) { 
                //     cout << " ";
                //     for (int k = 0; k < n; k++) {
                //         cout << employees[k]->getID() << " ";
                //     }
                //     cout << endl;
                // }
    
    }
            
           
        
        
    //write the sorted records to the file
    for (int i = 0; i < n; i++) {
        ofs << employees[i]->getName() << "|" << employees[i]->getID() << "|" 
            << employees[i]->getJob() << "|" << employees[i]->getAge() << "|" 
            << employees[i]->getHireDate() << endl;
    }
    
    ofs << "Number of comparisons: " << comparison << endl;
    

    cout<<"Number of comparisons: " << comparison << endl;  //print the number of comparisons

    ifs.close();
    ofs.close();  
    return 0;
} 
