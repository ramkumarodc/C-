#include<iostream>
#include<cstring>
using namespace std;

class String
{
    unsigned int Len;
    char *Str;

    public:
        String():Len(0),Str(nullptr)
        {

        }

        String(const char* str1)
        {
            Len = strlen(str1);
            Str = new (nothrow) char[Len+1];
            if(Str)
            {
                strcpy(Str,str1);
            }
            else{
                Len =0;
                cerr<<"Memory allocation failed\n";
            }
        }

        String(const String& str)
        {
            Len = strlen(str.Str);
            Str = new(nothrow)char[Len+1];
            if(Str)
            {
                strcpy(Str,str.Str);
            }
            else
            {
                Len=0;
                cerr<<"Memory allocation failed\n";
            }
        }

        String& operator=(const String& str)
        {
            if(this != &str)
            {
                char* tmp = Str;
                int len = str.Len;
                Str = new(nothrow) char[Len+1];
                if(Str)
                {
                    strcpy(Str, str.Str);
                    delete[] tmp;
                }
                else
                {
                    Len = strlen(tmp);
                    Str = tmp;
                }
                
                
            }
            return *this;
        }

        unsigned int length()
        {
            return Len;
        }
        
        friend ostream& operator<<(ostream &out, const String& str);
        friend istream& operator>>(istream &in, const String& str);

        String(String&& str)
        {
            Str = str.Str;
            Len = str.Len;
            str.Str = nullptr;
            str.Len=0;
        }

        String& operator=(String&& str)
        {
            if(this!=&str)
            {
                char* tmp = this->Str;
                Len = str.Len;
                Str = new(nothrow)char[Len+1];
                if(Str)
                {
                    strcpy(Str, str.Str);
                    if(tmp)
                    delete[] tmp;
                }
                else
                {
                    Len=0;
                    cerr<<"Memory allocation failed\n";
                }
            }
            return *this;
        }
};

ostream& operator<<(ostream &out, const String &str)
{
    out<<str.Str;
    return out;
}

istream& operator>>(istream &in, const String &str)
{
    in>>str.Str;
    return in;
}
int main()
{
    String str1;
    String str2 = "abc";
    String str3 = str2;
    str1 = str2;
    cout<<str1.length();
    cout<<str1;
    cin>>str1;
    String str4 = std::move(str2);
    str3 = move(str2);
    String str5(str3);
    return 0;
}