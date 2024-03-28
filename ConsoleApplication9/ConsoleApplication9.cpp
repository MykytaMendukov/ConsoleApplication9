#include <iostream> 
#include <string> 
#include <vector>


using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::ostream;

class Pizza {
private:
    vector<string> ingredients;
    double cost;

public:
    Pizza(double cost_) : cost(cost_) {}
    Pizza() : cost(0.0) {}

    void addIngredients(string obj) {
        string delimiter = ", ";
        size_t pos = 0;
        string token;
        while ((pos = obj.find(delimiter)) != string::npos) {
            token = obj.substr(0, pos);
            cout << token << std::endl;
            obj.erase(0, pos + delimiter.length());
        }
        cout << obj << endl;
    }
};

class Cook {
private:
    string name;
    string speciality;
    double experience;

public:
    Cook(string name_, string speciality_, double experience_)
        : name(name_), speciality(speciality_), experience(experience_) {}

    Cook() : name("None"), speciality("None"), experience(0.0) {}

    friend ostream& operator<<(ostream& out, const Cook& cook);
};

ostream& operator<<(ostream& out, const Cook& cook) {
    out << "Name: " << cook.name << endl;
    out << "Speciality: " << cook.speciality << endl;
    out << "Experience: " << cook.experience << endl;
    return out;
}

int main() {
    Pizza pizza(16.7);
    pizza.addIngredients("Dough, Ketchup, Cheese");

    return 0;
}

