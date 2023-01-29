//used builder pattren for ease of creation of multiple varsions of the car and extending its features.
//made carStore static to keep it one for all.

#include<map>
#include<iostream>
#include <iterator>
#include<vector>

using namespace std;

//Product class
class Car {
public:
    map<string, string> details;
    map<string, string> features;

    void ListFeatures()const {
        if (features.size() < 0)
        {
            cout << "No Features" << endl;
            return;
        }
        cout << "Car Features are as follows:" << endl;
        for (auto f : features) {
            cout << f.first << ": " << f.second << endl;
        }
    }

    void ListDetails()const {
        if (details.size() < 0)
        {
            cout << "No Details" << endl;
            return;
        }
        cout << "Car Details are as follows:" << endl;
        for (auto d : details) {
            cout << d.first << ": " << d.second << endl;
        }
    }

    string getMake() const {
        return details.find("Make")->second;
    }

    string getModel() const {
        return details.find("Model")->second;
    }

    string getBody() const {
        return details.find("Body")->second;
    }

    string getEngineType() const {
        return details.find("EngineType")->second;
    }

    string getEngineCC() const {
        return details.find("EngineCC")->second;
    }

    string getPaintColor() const {
        return details.find("PaintColor")->second;
    }

    string getTransmissionType() const {
        return details.find("TransmissionType")->second;
    }

    string getFeature(string featureName) const {
        return features.find(featureName)->second;
    }

};

class CarStore
{
    private:
    static map<int, Car*> collection;
    static int id;
    public:
        CarStore()
        {
            id = 0;
        }
        void addNewCar(Car* c)
        {
            id++;
            collection.insert({ id, c });
        }
        void viewACar(int id)
        {
            if (collection.find(id) == collection.end()) {
                cout << "Car Not Found!" << endl;
                return;
            }
            collection.find(id)->second->ListDetails();
        }
        void viewAllCars()
        {
            cout << endl << endl;
            if (collection.size() < 1)
                cout << "No Cars!" << endl;
            for (auto i : collection)
            {
                cout << "Car with id " << i.first << endl;
                i.second->ListDetails();
                cout << endl;
            }
        }
        int carWithParticularFeature(string feature)
        {
            int count = 0;
            for (auto i : collection)
            {
                if(i.second->getFeature(feature) != "")
                    count++;
            }
            return count;
        }
        ~CarStore()
        {
            for (auto i : collection)
            {
              // delete i.second;
            }
        }
};
int CarStore::id = 0;
map<int, Car*> CarStore::collection = map<int, Car*>();
//assembler interface
class Assembler {
public:
    virtual ~Assembler() {}
    virtual void setMake(string make) const = 0;
    virtual void setModel(string model) const = 0;
    virtual void setBody(string body) const = 0;
    virtual void setEngineType(string engineType) const = 0;
    virtual void setEngineCC(string engineCC) const = 0;
    virtual void setPaintColor(string paintColor) const = 0;
    virtual void setTransmissionType(string transmissionType) const = 0;
    virtual void setNewCustomFeature(string featureName, string featureValue) const = 0;
};

//concrete assembler
class carAssembler : public Assembler {
private:
    Car* car;

public:
    carAssembler() {
        this->Reset();
    }

    ~carAssembler() {
        //delete car;
    }

    void Reset() {
        this->car = new Car();
    }

    void setMake(string make) const override {
        this->car->details.insert({ "Make", make });
    }

    void setModel(string model) const override {
        this->car->details.insert({ "Model", model });
    }

    void setBody(string body) const override {
        this->car->details.insert({ "Body", body });
    }

    void setEngineType(string engineType) const override {
        this->car->details.insert({ "EngineType", engineType });
    }

    void setPaintColor(string paintColor) const override {
        this->car->details.insert({ "PaintColor", paintColor });
    }

    void setTransmissionType(string transmissionType) const override {
        this->car->details.insert({ "TransmissionType", transmissionType });
    }

    void setEngineCC(string engineCC) const override {
        this->car->details.insert({ "EngineCC", engineCC });
    }

    void setNewCustomFeature(string featureName, string featureValue) const override {
        this->car->details.insert({ featureName, featureValue });
    }

    Car* GetCar() {
        Car* carCopy = this->car;
        this->Reset();
        return carCopy;
    }
};

class Director {
private:
    Assembler* builder;

public:
    void set_builder(Assembler* builder) {
        this->builder = builder;
    }

    void DeafultCar() {
        this->builder->setBody("Sedan");
        this->builder->setMake("Mercedes");
        this->builder->setTransmissionType("Manual");
        this->builder->setModel("S Class");
        this->builder->setEngineCC("1300");
        this->builder->setEngineType("V1");
        this->builder->setPaintColor("Pink:)");
    }

    void CarWithCustomDetails() {
        string temp;
        cout << "Please Provide these Details:" << endl;
        cout << "Model of your car:" << endl;
        cin >> temp;
        this->builder->setModel(temp);
        cout << "Make of your car:" << endl;
        cin >> temp;
        this->builder->setMake(temp);
        cout << "Body of your car:" << endl;
        cin >> temp;
        this->builder->setBody(temp);
        cout << "TransmissionType of your car:" << endl;
        cin >> temp;
        this->builder->setTransmissionType(temp);
        cout << "EngineCC of your car:" << endl;
        cin >> temp;
        this->builder->setEngineCC(temp);
        cout << "EngineType of your car:" << endl;
        cin >> temp;
        this->builder->setEngineType(temp);
        cout << "PaintColor of your car:" << endl;
        cin >> temp;
        this->builder->setPaintColor(temp);
    }

    void CarWithCustomDetailsAndFeatures() {
        CarWithCustomDetails();
        cout << "How Many features you want to add?";
        int featuresCount;
        cin >> featuresCount;
        for (int i = 0; i < featuresCount; ++i)
        {
            string featureName, featureValue;
            cout << "Enter Feature Name" << endl;
            cin >> featureName;
            cout << "Enter Feature Value" << endl;
            cin >> featureValue;
            this->builder->setNewCustomFeature(featureName, featureValue);
        }
    }
};

void ClientCode(Director& director, CarStore store)
{
    carAssembler* builder = new carAssembler();
    director.set_builder(builder);

    cout << "Choose the type of car you want to assemble:" << endl;
    cout << "1. Standard Default Car" << endl;
    cout << "2. Standard Car With Custom Details" << endl;
    cout << "3. Standard Car With Custom Details & Custom Features" << endl;
    int type;
    cin >> type;
    if (type == 1)
    {
        cout << "Your Standard Default Car:\n";
        director.DeafultCar();
        Car* p = builder->GetCar();
        p->ListDetails();
        store.addNewCar(p);
        //store.viewAllCars();
    }
    else if (type == 2)
    {
        cout << "Your Standard Car With Custom Details:\n";
        director.CarWithCustomDetails();
        Car* p = builder->GetCar();
        p->ListDetails();
        store.addNewCar(p);
       // store.viewAllCars();
    }
    else if (type == 3)
    {
        cout << "Your Standard Car With Custom Details & Custom Features:\n";
        director.CarWithCustomDetailsAndFeatures();
        Car* p = builder->GetCar();
        p->ListDetails();
        p->ListFeatures();
        store.addNewCar(p);
       // store.viewAllCars();
    }
    else
    {
        cout << "Sorry! Your requested type is not available. Kindy revisit in future again to check availabiliy. Thanks for coming!" << endl;
    }
    delete builder;
}

int main() {
    cout << "\t\tWelcome to Arbisoft Car Manufactring System!" << endl;
    Director* director = new Director();
    CarStore store;
    int choice = 0;
    cout << "What do you want to perform?\n1 to Assemble New Car\n2 to View All Cars\n3 to View A Car Details\n4 to Exit" << endl;
    while (choice != -1)
    {
        cout << "Your Choice::";
        cin >> choice;
        if (choice == 1)
        {
            ClientCode(*director, store);
        }
        else if (choice == 2)
        {
            store.viewAllCars();
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Id to View" << endl;
            cin >> id;
            store.viewACar(id);
        }
        else if (choice == 4)
            break;
        else
            cout << "Operation does not exist!";
    }
    delete director;
    return 0;
}
