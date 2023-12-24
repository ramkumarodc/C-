#include<iostream>
using namespace std;

class Button
{
    public:
        virtual void getButton()=0;
};

class winButton: public Button
{
    public:
        void getButton()
        {
            cout<<"Windows Button"<<endl;
        }
};

class macButton: public Button
{
    public:
        void getButton()
        {
            cout<<"Mac Button"<<endl;
        }
};

class checkBox
{
    public:
        virtual void getCheckBox()=0;    
};

class winCheckBox: public checkBox
{
    public:
        void getCheckBox()
        {
            cout<<"windows checkbox"<<endl;
        }
};

class macCheckBox: public checkBox
{
    public:
        void getCheckBox()
        {
            cout<<"Mac checkbox"<<endl;
        }
};


class GuiFactory
{
    public:
        virtual Button* createButton()=0;
        virtual checkBox* createCheckBox()=0;

        void render()
        {
            Button* button = this->createButton();
            checkBox* cb = this->createCheckBox();
            if(button)
                button->getButton();
            if(cb)
                cb->getCheckBox();
        }
};

class WinFactory: public GuiFactory
{
    public:
        Button* createButton()
        {
            return new winButton;
        }

        checkBox* createCheckBox()
        {
            return new winCheckBox();
        }
};

class macFactory: public GuiFactory
{
    public:
        Button* createButton()
        {
            return new macButton;
        }
        checkBox* createCheckBox()
        {
            return new macCheckBox;
        }
};

int main()
{
    GuiFactory* factory = new macFactory;
    factory->render();

    GuiFactory* winfac = new WinFactory;
    winfac->render();
    return 0;
}

