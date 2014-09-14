#ifndef LAB_4_HEADER_H_INCLUDED
#define LAB_4_HEADER_H_INCLUDED

class City{
private:
    std::string place;
    std::string Msg;
    City *next;
public:
    City(std::string, std::string);   // constructor
    ~City();        // destructor

    // get and set next
    City *getNext();
    void setNext(City *n);

    // get and set message
    std::string getMsg();
    void setMsg(std::string);

    // get and set message
    std::string getPlace();
    void setPlace(std::string);

    // transmit function
    void transmitMsg(City*, std::string);

};
#endif // LAB_4_HEADER_H_INCLUDED
