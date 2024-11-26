#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;


class Patient {
private:
    string id, name, gender, disease;
    int age;

public:
    Patient() : id(""), name(""), gender(""), disease(""), age(0) {}
    Patient(string id, string name, int age, string gender, string disease)
        : id(id), name(name), age(age), gender(gender), disease(disease) {}

    
    friend istream& operator>>(istream& in, Patient& p) {
        cout << "Enter ID: ";
        in >> p.id;
        in.ignore();
        cout << "Enter Name: ";
        getline(in, p.name);
        cout << "Enter Age: ";
        in >> p.age;
        in.ignore();
        cout << "Enter Gender: ";
        getline(in, p.gender);
        cout << "Enter Disease: ";
        getline(in, p.disease);
        return in;
    }

    
    friend ostream& operator<<(ostream& out, const Patient& p) {
        out << "ID: " << p.id << ", Name: " << p.name
            << ", Age: " << p.age << ", Gender: " << p.gender
            << ", Disease: " << p.disease;
        return out;
    }

    // so sanh theo Age
    bool operator<(const Patient& other) const {
        return age < other.age;
    }

    // Getter
    string getId() const { return id; }
    int getAge() const { return age; }
};


class PatientManager {
private:
    vector<Patient> patients;

public:

    void addPatient(const Patient& p) {
        patients.push_back(p);
    }

    
    void displayAllPatients() const {
        if (patients.empty()) {
            cout << "No patients in the list.\n";
            return;
        }
        for (const auto& p : patients) {
            cout << p << endl;
        }
    }

    
    void sortPatientsByAge() {
        sort(patients.begin(), patients.end());
        cout << "Patients sorted by age.\n";
    }

    
    void findOldestPatient() const {
        if (patients.empty()) {
            cout << "No patients in the list.\n";
            return;
        }
        auto maxPatient = max_element(patients.begin(), patients.end(),
                                      [](const Patient& a, const Patient& b) {
                                          return a.getAge() < b.getAge();
                                      });
        cout << "Oldest Patient: " << *maxPatient << endl;
    }

    
    void findYoungestPatient() const {
        if (patients.empty()) {
            cout << "No patients in the list.\n";
            return;
        }
        auto minPatient = min_element(patients.begin(), patients.end(),
                                      [](const Patient& a, const Patient& b) {
                                          return a.getAge() < b.getAge();
                                      });
        cout << "Youngest Patient: " << *minPatient << endl;
    }

    
    void searchPatientById(const string& id) const {
        for (const auto& p : patients) {
            if (p.getId() == id) {
                cout << "Found: " << p << endl;
                return;
            }
        }
        cout << "Patient with ID " << id << " not found.\n";
    }

    
    void removePatientById(const string& id) {
        auto it = remove_if(patients.begin(), patients.end(),
                            [&id](const Patient& p) { return p.getId() == id; });
        if (it != patients.end()) {
            patients.erase(it, patients.end());
            cout << "Patient with ID " << id << " removed.\n";
        } else {
            cout << "Patient with ID " << id << " not found.\n";
        }
    }

    
    void loadPatientsFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error: Unable to open file \"" << filename << "\"\n";
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, name, gender, disease;
            int age;

            getline(ss, id, ',');
            getline(ss, name, ',');
            ss >> age;
            ss.ignore(); // Bỏ dấu phẩy
            getline(ss, gender, ',');
            getline(ss, disease);

            addPatient(Patient(id, name, age, gender, disease));
        }
        cout << "Patients loaded successfully from \"" << filename << "\"\n";
    }
};


class App {
private:
    PatientManager manager;

    void menu() const {
        cout << "\nMenu:\n";
        cout << "1. Add new patient\n";
        cout << "2. Display all patients\n";
        cout << "3. Sort patients by age\n";
        cout << "4. Find oldest patient\n";
        cout << "5. Find youngest patient\n";
        cout << "6. Search patient by ID\n";
        cout << "7. Remove patient by ID\n";
        cout << "8. Load patients from file\n";
        cout << "9. Exit\n";
        cout << "Choose an option: ";
    }

    void addNewPatient() {
        Patient p;
        cin >> p;
        manager.addPatient(p);
        cout << "Patient added successfully!\n";
    }

    void displayPatients() {
        manager.displayAllPatients();
    }

    void sortPatients() {
        manager.sortPatientsByAge();
    }

    void findOldestPatient() {
        manager.findOldestPatient();
    }

    void findYoungestPatient() {
        manager.findYoungestPatient();
    }

    void searchPatient() {
        string id;
        cout << "Enter ID to search: ";
        cin >> id;
        manager.searchPatientById(id);
    }

    void removePatient() {
        string id;
        cout << "Enter ID to remove: ";
        cin >> id;
        manager.removePatientById(id);
    }

    void loadFromFile() {
        string filename;
        cout << "Enter file name: ";
        cin >> filename;
        manager.loadPatientsFromFile(filename);
    }

public:
    void run() {
        int choice;
        do {
            menu();
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    addNewPatient();
                    break;
                case 2:
                    displayPatients();
                    break;
                case 3:
                    sortPatients();
                    break;
                case 4:
                    findOldestPatient();
                    break;
                case 5:
                    findYoungestPatient();
                    break;
                case 6:
                    searchPatient();
                    break;
                case 7:
                    removePatient();
                    break;
                case 8:
                    loadFromFile();
                    break;
                case 9:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 9);
    }
};

int main() {
    App app;
    app.run();
    return 0;
}
