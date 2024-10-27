#ifndef CONCRETECONSOLECHATTEXTS_H
#define CONCRETECONSOLECHATTEXTS_H

#include "ichattexts.h"

/**
 * @brief Textos de chat para Consola
 */
class ConcreteConsoleChatTexts: public IChatTexts
{
public:
    const QString & getHTML() override{
        return text();
    }
};

#endif // CONCRETECONSOLECHATTEXTS_H
