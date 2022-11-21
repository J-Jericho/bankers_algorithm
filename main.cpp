//Banker's Algorithm
//Jacob Jericho
//11/20/2022

#include <iostream>
#include <fstream>
using namespace std;


const int PROCESS_COUNT = 5;
const int RESOURCE_COUNT = 3;


//Function to find the need of each process
void findResourcesNeeded(int resources_needed[PROCESS_COUNT][RESOURCE_COUNT], 
				   int maximum_resources[PROCESS_COUNT][RESOURCE_COUNT], 
				   int allotted_resources[PROCESS_COUNT][RESOURCE_COUNT]) 
{
	for (int i = 0 ; i < PROCESS_COUNT ; i++) {
		for (int j = 0 ; j < RESOURCE_COUNT ; j++) {
			resources_needed[i][j] = maximum_resources[i][j] - allotted_resources[i][j];
		}
	}
}

//Function to find the system is in safe state or not
bool verifySafeState(int processes[], 
			int available_resources[], 
			int maximum_resources[][RESOURCE_COUNT], 
			int allotted_resources[][RESOURCE_COUNT]) 
{
	// Initialize Variables
	int  resources_needed[PROCESS_COUNT][RESOURCE_COUNT];
	int  stored_sequence[PROCESS_COUNT];
	int  work_needed[RESOURCE_COUNT];
	bool is_finished[PROCESS_COUNT];

	findResourcesNeeded(resources_needed, maximum_resources, allotted_resources);

	for(int i = 0; i < PROCESS_COUNT; i++){is_finished[i] = 0;}
	for(int i = 0; i < RESOURCE_COUNT; i++){work_needed[i] = available_resources[i];}

	int process_index = 0;
	while (process_index < PROCESS_COUNT) {
		bool is_found = false;
		for (int p = 0; p < PROCESS_COUNT; p++) {
			if (is_finished[p] == 0) 
			{
				int j;
				for (j = 0; j < RESOURCE_COUNT; j++) {if (resources_needed[p][j] > work_needed[j]) {break;}}

				if (j == RESOURCE_COUNT) {
					for (int k = 0 ; k < RESOURCE_COUNT ; k++) {work_needed[k] += allotted_resources[p][k];}
					stored_sequence[process_index++] = p;
					is_finished[p] = 1;
					is_found = true;
				}
			}
		}
		if (is_found == false) {
			cout << "This state is not safe.";
			return false;
		}
	}
	cout << "In a safe state.";
	cout << endl;
	cout << "The correct squence is: ";
	for (int i = 0; i < PROCESS_COUNT ; i++) {cout << stored_sequence[i] << " ";}
	cout << endl;
	return true;
}


int main()
{
	int processes[PROCESS_COUNT-1];
	for (int i = 0; i < PROCESS_COUNT; i++){processes[i] = i;}

	std::ifstream squence_file ("sequence_input.txt");
    if(!squence_file.is_open()) {
        std::cout << "Failed to open squence_file";
		std::cout << endl;
    }

    while(!squence_file.eof()) {
		//Available Resources
		int available_resources[RESOURCE_COUNT];
		for (int j = 0; j < RESOURCE_COUNT; j++) {squence_file >> available_resources[j];}

		//Alotted Resources
		int allotted_resources[PROCESS_COUNT][RESOURCE_COUNT];
		for (int i = 0; i < PROCESS_COUNT; i++) {
			for (int j = 0; j < RESOURCE_COUNT; j++) {squence_file >> allotted_resources[i][j];}
		}

		int maximum_resources[PROCESS_COUNT][RESOURCE_COUNT];
		for (int i = 0; i < PROCESS_COUNT; i++) {
			for (int j = 0; j < RESOURCE_COUNT; j++) {squence_file >> maximum_resources[i][j];}
		}
	
		//Check State
		verifySafeState(processes, available_resources, maximum_resources, allotted_resources);
	}
    squence_file.close();
	return 0;
}