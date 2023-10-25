#include <iostream>
#include <iterator>
using std::end;

struct buffer
{
    char memory[10];
    buffer *next = nullptr;
};


int main()
{
    // считывание строки в специальный буфер
    buffer firstNode;
    buffer *current = &firstNode;
    char *bit = current->memory;
    unsigned k = 1;  // подсчёт числа звеньев буфера

    while (std::cin >> bit)
    {
        ++bit;
        if (bit == end(current->memory))
        {
            current->next = new buffer;
            current = current->next;
            ++k;
        }
    }

    // вставка строки в классическую строку
    char *total = new char[k * 10 + 1];
    bit = total;

    current = &firstNode;
    char *currentBit = current->memory;

    while (true)
    {
        *bit = *currentBit;
        ++bit;
        ++currentBit;
        if (currentBit == end(current->memory))
        {
            auto *temp = current->next;
            delete current;
            current = temp;
            if (!current)
                break;
            currentBit = current->memory;
        }
        
    }

    if (*bit != '\0')
        *++bit = '\0';
    char *endPtr = --bit;
    
    // удаление пробельных символов с концов
    char *result = new char [k * 10 + 1];
    char *beginPtr = total;
    while (true)
    {
        ++beginPtr;
        if (*beginPtr != ' ' && *beginPtr != '\t' && *beginPtr != '\n')
            break;
    }
    while (true)
    {
        --endPtr;
        if (*endPtr != ' ' && *endPtr != '\t' && *endPtr != '\n')
            break;
    }

    char *position = result;
    for (char *bit = beginPtr; bit != endPtr; ++bit, ++position)
    {
        *position = *bit;
    }
    ++position = '\0';

    std::cout << result << std::endl;
}
