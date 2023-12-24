#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

class Observer
{
    public:
        virtual void update(const string& message)= 0;
};

class subject
{
    public:
        virtual void addObserver(Observer* observer) = 0;
        virtual void removeObserver(Observer* observer) =0;
        virtual void changeState(const string & state) =0;
};

class concreteObserver: public Observer
{
    string name_;

    public:
        concreteObserver(const string& name): name_(name)
        {

        }
        void update(const string& message)
        {
            cout<<"Observer: "<< name_ <<" received message "<<message<<endl;
        }
};

class concreteSubject: public subject
{
    vector<Observer*> observers_;
    string state_;
    public:
        void addObserver(Observer* observer) override
        {
            observers_.push_back(observer);
        }
        void removeObserver(Observer* observer) override
        {
            auto it = std::find(observers_.begin(), observers_.end(), observer);
            if(it != observers_.end())
            {
                observers_.erase(it);
            }
        }
        void changeState(const string& state)
        {
            state_ = state;
            notifyObservers(state_);
        }
        void notifyObservers(const string& state)
        {
            for(auto observer: observers_)
            {
                observer->update("changed to state "+state);
            }
        }
};

int main()
{
    concreteSubject subject;

    concreteObserver observer1("observer1");
    concreteObserver observer2("observer2");
    subject.addObserver(&observer1);
    subject.addObserver(&observer2);
    subject.changeState("New State");
    subject.removeObserver(&observer1);
    subject.changeState("Another State");

    return 0;
}