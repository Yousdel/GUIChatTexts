#ifndef CONCRETEGUICHATTEXTS_H
#define CONCRETEGUICHATTEXTS_H

#include "ChatTexts/ichattexts.h"

/**
 * @brief Textos de chat para GUI
 */
class ConcreteGUIChatTexts : public IChatTexts
{
private:
    QString html;
    const QString getHTMLfor(const QString &s);
    const QString workTextTypeChat(const QString &text);
public:
    const QString & getHTML() override;
};

#endif // CONCRETEGUICHATTEXTS_H
