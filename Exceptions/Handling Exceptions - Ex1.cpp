#include <string>
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

struct errorinfo {
    int id;
    int locationId;
    int level;
    std::string description;
    std::string reason;
};

class myexception : public std::exception {

public:

    myexception(const std::string& message) : msg(message) {

    }

    virtual char const* what() const {
        return msg.c_str();
    }

    virtual ~myexception() throw () {
        errorlist.clear();
    }

    void adderror(errorinfo info) throw(bad_alloc) {
        //try {
            errorlist.push_back(info);
        //}
        //catch (...) {
            //push_back has thrown an error. 
        //    cout << "Bad alloc in adderror function." << endl;
        //}    
    }

    vector<errorinfo>::iterator begin() { return errorlist.begin(); }
    vector<errorinfo>::iterator end() { return errorlist.end(); }

protected:
    std::string msg;
    std::vector<errorinfo> errorlist;
};

int main() {
    try {
        try {
            try {
                myexception myex("myexception object thrown.");  //Create myexception object
                throw myex;   //Throw myexception object
            }
            catch (myexception e) {    //Catch myexception object
                errorinfo firstinfo;    //Create errorinfo struct
                firstinfo.reason = "level 1 error";  
                firstinfo.id = 1;
                firstinfo.locationId = 0;
                firstinfo.level = 0;
                firstinfo.description = "First level exception thrown.";
                try {
                    e.adderror(firstinfo);  //Add errorinfo struct to myexception object
                }
                catch (bad_alloc) {
                    cout << "Out of memory myexception.adderror bad_alloc." << endl;
                }
                throw e;   //Throw myexceptionobject up call stack.
            }
        }
        catch (myexception e) {
            errorinfo secondinfo;
            secondinfo.reason = "level 2 error";
            secondinfo.id = 2;
            secondinfo.locationId = 1;
            secondinfo.level = 2;
            secondinfo.description = "Second level exception thrown.";
            try {
                e.adderror(secondinfo);
            }
            catch (bad_alloc) {
                cout << "Out of memory myexception.adderror bad_alloc." << endl;
            }
            throw e;
        }
    }
    catch (myexception e) {
        //Print out errorinfo structs in myexception object
        for (std::vector<errorinfo>::iterator iter = e.begin(); iter != e.end(); ++iter) {
            errorinfo next = *iter;
            cout << next.reason << " " << next.id << " " << next.locationId << " " << next.level << " " << next.description << endl;
        }
    }

}