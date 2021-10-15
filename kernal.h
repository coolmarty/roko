#ifndef KERNAL_H_
#define KERNAL_H_

#include <vector>
#include <iostream>


class Kernal {
public:
    Kernal(std::vector<std::vector<float>> k);

    Kernal(int size, int set);

    Kernal(int size);

    Kernal();

    ~Kernal();

    void setAll(int set);

    int getSize();

    float get(int x, int y);

private:
    std::vector<std::vector<float>> kernal;

    int size;
};


#endif
