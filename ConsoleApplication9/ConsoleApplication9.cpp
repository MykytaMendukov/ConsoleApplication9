#include <iostream> 
#include <string> 
#include <vector>


using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::ostream;


class Dish {
private:
    string name;
    vector<string> ingredients;
    double cost;

public:
    Dish(string name_, double cost_) : name(name_), cost(cost_) {}
    Dish() : name("None"), cost(0.0) {}

    ~Dish() { name = ""; cost = 0.0; ingredients.clear(); }

    void addIngredients(string obj) {
        string delimiter = ", ";
        size_t pos = 0;
        string token;
        while ((pos = obj.find(delimiter)) != string::npos) {
            token = obj.substr(0, pos);
            ingredients.push_back(token);
            obj.erase(0, pos + delimiter.length());
        }
        ingredients.push_back(obj);
    }

    friend ostream& operator <<(ostream& out, Dish& obj);

};


ostream& operator <<(ostream& out, Dish& obj) {

    out << obj.name << " ingredients: " << endl;
    for (string i : obj.ingredients) {
        cout << i << ", ";
    }
    cout << endl;
    out << "Cost: " << obj.cost << endl;
    return out;
}

class Cook {
private:
    string name;
    string speciality;
    double experience;
    vector<Dish> dishes;

public:
    Cook(string name_, string speciality_, double experience_)
        : name(name_), speciality(speciality_), experience(experience_) {}

    Cook() : name("None"), speciality("None"), experience(0.0) {}

    ~Cook() { name = ""; speciality = ""; experience = 0.0; }

    void addDish(Dish& dish) {
        dishes.push_back(dish);
    }

    void seeDishes() {
        cout << "Chefs' dishes: " << endl;
        int i = 1;
        for (Dish& dish : dishes) {
            cout << i << ". ";
            cout << dish << endl;
            i++;
        }
    }

    friend ostream& operator<<(ostream& out, const Cook& cook);
};

ostream& operator<<(ostream& out, const Cook& cook) {
    out << "Name: " << cook.name << endl;
    out << "Speciality: " << cook.speciality << endl;
    out << "Experience: " << cook.experience << " years" << endl;
    return out;
}


int main() {

    Cook cook1("Mykola Mykolaichuk", "Cher", 7.6);

    Dish Pizza("Pizza", 75);
    Pizza.addIngredients("Dough, Ketchup, Cheese, Chicken Meat, Paprika");

    Dish Salad("Salad", 60);
    Salad.addIngredients("Lettuce, Sauce, Tomatoes, Feta Cheese");

    cook1.addDish(Pizza);
    cook1.addDish(Salad);

    cout << cook1 << endl;
    cook1.seeDishes();

    return 0;
}

