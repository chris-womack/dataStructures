#ifndef LAB_4_HEADER_H_INCLUDED
#define LAB_4_HEADER_H_INCLUDED


class City{
private:
    std::string place;
    std::string Msg;
    City *next;
    City *prev;

public:
    City(std::string, std::string);   // constructor
    ~City();        // destructor

    // get and set next
    City *getNext();
    void setNext(City *n);

    // get and set previous
    City *getPrev();
    void setPrev(City *n);

    // get and set message
    std::string getMsg();
    void setMsg(std::string);

    // get and set Place
    std::string getPlace();
    void setPlace(std::string);

    // transmit function
    void transmitMsg(City*, std::string, int, int*);

    // delete node function
    void delete_node(std::string, City*);

    // add funtion
    void add_node(City*, City*);
};
#endif // LAB_4_HEADER_H_INCLUDED
