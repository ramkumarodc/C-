#include<iostream>

using namespace std;

class car
{
    private:
        string colour;
        bool navigation;
        bool automatic;

    public:
        car()
        {
            colour = "white";
            navigation = false;
            automatic = false;
        }

        void setColour(string col)
        {
            this->colour = col;
        }
        void setNavigation(bool nav)
        {
            navigation = nav;
        }
        void setAutomatic(bool atom)
        {
            automatic = atom;
        }
};

class Builder
{

};

class carBuilder: public Builder
{
    car* carobj;
    public:
        carBuilder()
        {
            carobj = new car; 
        }

        void setColour(string col)
        {
            carobj->setColour(col);
        }
        void setNavigation(bool nav)
        {
            carobj->setNavigation(nav);
        }
        void setAutomatic(bool atom)
        {
            carobj->setAutomatic(atom);
        }
        car* getproduct()
        {
            return carobj;
        }
};

int main()
{
    Builder* builder = new carBuilder
    
    return 0;
}