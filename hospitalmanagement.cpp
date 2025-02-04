#include <iostream>
#include <string>
#include <vector>

using namespace std;

int pid, did; // Global patient and doctor IDs

class Patient {
public:
    string name;
    string gender;
    int age;
    int ID;

    // Constructor
    Patient(string n, int a, string g) {
        ID = pid;
        pid++;  // Increase patient ID
        name = n;
        age = a;
        gender = g;
    }
};

class Doctor {
public:
    string name;
    string gender;
    int age;
    int ID;

    // Constructor
    Doctor(string n, int a, string g) {
        ID = did;
        did++;  // Increase doctor ID
        name = n;
        age = a;
        gender = g;
    }
};

class Appointment {
public:
    int patientID;
    int doctorID;
    string date;

    // Constructor
    Appointment(int p, int d, string dt) {
        this->date = dt;
        this->patientID = p;
        this->doctorID = d;
    }
};

// Vectors to store all records
vector<Patient> allpatients;
vector<Doctor> alldoctors;
vector<Appointment> allappointments;

// Function to check if patient exists
bool isPatientPresent(int id) {
    for (int i = 0; i < allpatients.size(); i++) {
        if (allpatients[i].ID == id) {
            return true;
        }
    }
    return false;
}

// Function to check if doctor exists
bool isDoctorPresent(int id) {
    for (int i = 0; i < alldoctors.size(); i++) {
        if (alldoctors[i].ID == id) {
            return true;
        }
    }
    return false;
}

// Function to add a patient
void addPatient() {
    string n, g;
    int a;

    cout << "Enter patient name: ";
    cin.ignore();  // Fix for getline issue
    getline(cin, n);

    cout << "Enter patient age: ";
    cin >> a;

    cout << "Enter patient gender: ";
    cin >> g;

    Patient temp(n, a, g);
    allpatients.push_back(temp);
    cout << "Patient added successfully with ID: " << temp.ID << endl;
}

// Function to add a doctor
void addDoctor() {
    string n, g;
    int a;

    cout << "Enter doctor name: ";
    cin.ignore();
    getline(cin, n);

    cout << "Enter doctor age: ";
    cin >> a;

    cout << "Enter doctor gender: ";
    cin >> g;

    Doctor temp(n, a, g);
    alldoctors.push_back(temp);
    cout << "Doctor added successfully with ID: " << temp.ID << endl;
}

// Function to schedule an appointment
void addScheduleAppt() {
    int patientID, doctorID;
    string date;

    cout << "Enter patient ID: ";
    cin >> patientID;
    cout << "Enter doctor ID: ";
    cin >> doctorID;
    cout << "Enter appointment date (DD-MM-YYYY): ";
    cin >> date;

    if (!isPatientPresent(patientID) || !isDoctorPresent(doctorID)) {
        cout << "***** Invalid patient ID or doctor ID *****" << endl;
        return;
    }

    Appointment temp(patientID, doctorID, date);
    allappointments.push_back(temp);
    cout << "Appointment scheduled successfully!" << endl;
}

// Function to view all patients
void viewPatients() {
    if (allpatients.empty()) {
        cout << "No patients available." << endl;
        return;
    }
    for (int i = 0; i < allpatients.size(); i++) {
        cout << "Patient ID: " << allpatients[i].ID
             << " | Name: " << allpatients[i].name
             << " | Age: " << allpatients[i].age
             << " | Gender: " << allpatients[i].gender << endl;
    }
}

// Function to view all doctors
void viewDoctors() {
    if (alldoctors.empty()) {
        cout << "No doctors available." << endl;
        return;
    }
    for (int i = 0; i < alldoctors.size(); i++) {
        cout << "Doctor ID: " << alldoctors[i].ID
             << " | Name: " << alldoctors[i].name
             << " | Age: " << alldoctors[i].age
             << " | Gender: " << alldoctors[i].gender << endl;
    }
}

// Function to view all appointments
void viewAppointments() {
    if (allappointments.empty()) {
        cout << "No appointments scheduled." << endl;
        return;
    }
    for (int i = 0; i < allappointments.size(); i++) {
        cout << "Appointment " << (i + 1) << " => Patient ID: " 
             << allappointments[i].patientID 
             << " | Doctor ID: " << allappointments[i].doctorID
             << " | Date: " << allappointments[i].date << endl;
    }
}

int main() {
    pid = 1;
    did = 1;
    int choice;

    while (true) {
        cout << "\n==== Hospital Management System ====" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Add Doctor" << endl;
        cout << "3. Schedule Appointment" << endl;
        cout << "4. View Patients" << endl;
        cout << "5. View Doctors" << endl;
        cout << "6. View Appointments" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                addDoctor();
                break;
            case 3:
                addScheduleAppt();
                break;
            case 4:
                viewPatients();
                break;
            case 5:
                viewDoctors();
                break;
            case 6:
                viewAppointments();
                break;
            case 7:
                cout << "Exiting... Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }
}
